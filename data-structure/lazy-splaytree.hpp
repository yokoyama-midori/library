#pragma once
#include "../template.hpp"
template <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),
          F (*composition)(F, F), F (*id)()>
//   composition(f,g)(x) = f∘g(x) = f(g(x))
struct SplayTree {
  private:
    struct Node;
    using pNode = unique_ptr<Node>;
    struct Node {
        Node *left, *right, *parent;
        int size;
        S a, prod;
        F lazy;
        bool rev;
        Node()
            : left(nullptr), right(nullptr), parent(nullptr), size(1), a(e()),
              prod(e()), lazy(id()), rev(false) {}
        Node(const S &s)
            : left(nullptr), right(nullptr), parent(nullptr), size(1), a(s),
              prod(s), lazy(id()), rev(false) {}
        int state() {
            if(!this->parent)
                return 0;
            if(this->parent->left == this)
                return 1;
            if(this->parent->right == this)
                return 2;
            return 0;
        }
        void apply(const F &f) {
            a = mapping(f, a);
            prod = mapping(f, prod);
            lazy = composition(f, lazy);
        }
        void reverse() {
            swap(left, right);
            rev = !rev;
        }
        void push() {
            if(lazy != id()) {
                if(left)
                    left->apply(lazy);
                if(right)
                    right->apply(lazy);
                lazy = id();
            }
            if(rev) {
                if(left)
                    left->reverse();
                if(right)
                    right->reverse();
                rev = false;
            }
        }
        void update() {
            size = 1;
            prod = a;
            if(left) {
                size += left->size;
                prod = op(left->prod, prod);
            }
            if(right) {
                size += right->size;
                prod = op(prod, right->prod);
            }
        }
    };
    void rotate(Node *me) {
        Node *pp, *p, *c;
        p = me->parent;
        pp = p->parent;
        if(p->left == me) {
            c = me->right;
            me->right = p;
            p->left = c;
        } else {
            c = me->left;
            me->left = p;
            p->right = c;
        }
        if(pp) {
            if(pp->right == p) {
                pp->right = me;
            } else {
                pp->left = me;
            }
        }
        me->parent = pp;
        p->parent = me;
        if(c) {
            c->parent = p;
        }
    }
    void push_from_root(Node *node) {
        // 根からトップダウンにpush
        // https://qiita.com/ngtkana/items/4d0b84d45210771aa074#32-%E3%81%99%E3%81%B9%E3%81%A6%E3%83%88%E3%83%83%E3%83%97%E3%83%80%E3%82%A6%E3%83%B3%E3%83%95%E3%82%A7%E3%83%BC%E3%82%BA%E3%81%AB-push
        if(!node)
            return;
        if(node->parent)
            push_from_root(node->parent);
        node->push();
    }
    void splay(Node *me, bool push_from_root_done = false) {
        if(push_from_root_done)
            me->push();
        else
            push_from_root(me);
        while(me->parent) {
            Node *p = me->parent, *pp = p->parent;
            if(me->parent->state() == 0) {
                rotate(me);
                p->update();
                break;
            } else if(me->state() == me->parent->state()) {
                rotate(me->parent), rotate(me);
            } else {
                rotate(me), rotate(me);
            }
            pp->update(), p->update();
        }
        me->update();
    }
    Node *splay_kth(int k, Node *node) {
        assert(0 <= k and k < node->size);
        while(1) {
            node->push();
            int l_size = node->left ? node->left->size : 0;
            if(k < l_size) {
                node = node->left;
            } else if(k == l_size) {
                splay(node, true);
                return node;
            } else {
                k -= l_size + 1;
                node = node->right;
            }
        }
    }
    Node *merge(Node *l_root, Node *r_root) {
        if(!l_root)
            return r_root;
        if(!r_root)
            return l_root;
        l_root = splay_kth(l_root->size - 1, l_root);
        l_root->update();
        l_root->right = r_root;
        r_root->parent = l_root;
        l_root->update();
        return l_root;
    }
    pair<Node *, Node *> split(int l_size, Node *node) {
        if(l_size == 0)
            return {nullptr, node};
        if(l_size == node->size)
            return {node, nullptr};
        node = splay_kth(l_size, node);
        Node *l, *r;
        l = node->left, r = node;
        r->left = l->parent = nullptr;
        r->update();
        return {l, r};
    }
    Node *insert(int k, Node *node, Node *root) {
        Node *l, *r;
        tie(l, r) = split(k, root);
        return merge(merge(l, node), r);
    }
    pair<Node *, Node *> remove(int k, Node *node) {
        node = splay_kth(k, node);
        Node *l = node->left, *r = node->right;
        if(l)
            l->parent = nullptr;
        if(r)
            r->parent = nullptr;
        node->left = node->right = nullptr;
        node->update();
        return {merge(l, r), node};
    }
    vector<pNode> pool;
    Node *root;
    void between(Node *&l_root, Node *&c_root, Node *&r_root, int l, int r) {
        // c_rootを[l,r)の部分木の根としてsplit、l,r_rootは左右の木の根
        // 呼び出したあとmergeしてrootをきちんと更新する
        tie(c_root, r_root) = split(r, root);
        tie(l_root, c_root) = split(l, c_root);
        return;
    }

  public:
    void insert_at(int k, const S &s) {
        pool.push_back(move(make_unique<Node>(s)));
        // ↑moveいる？
        Node *node = pool.back().get();
        root = insert(k, node, root);
    }
    void remove_at(int k) {
        root = remove(k, root).first;
        // .secondは放置されてますが...
    }
    void set(int k, const S &s) {
        root = splay_kth(k, root);
        root->a = s;
        root->update();
    }
    int size() { return root ? root->size : 0; }
    S get(int k) {
        root = splay_kth(k, root);
        return root->a;
    }
    S prod(int l, int r) {
        if(l == r)
            return e();
        Node *l_root, *c_root, *r_root;
        between(l_root, c_root, r_root, l, r);
        S res = c_root->prod;
        root = merge(merge(l_root, c_root), r_root);
        return res;
    }
    void reverse(int l, int r) {
        if(l == r)
            return;
        Node *l_root, *c_root, *r_root;
        between(l_root, c_root, r_root, l, r);
        c_root->reverse();
        root = merge(merge(l_root, c_root), r_root);
    }
    void apply(int l, int r, F f) {
        if(l == r)
            return;
        Node *l_root, *c_root, *r_root;
        between(l_root, c_root, r_root, l, r);
        c_root->apply(f);
        root = merge(merge(l_root, c_root), r_root);
    }

    SplayTree() : root(nullptr) {}
    SplayTree(const vector<S> &v) : root(nullptr) {
        Node *prev = nullptr;
        for(const auto &s : v) {
            pool.push_back(move(make_unique<Node>(s)));
            Node *node = pool.back().get();
            if(prev)
                prev->parent = node;
            node->left = prev;
            node->update();
            root = prev = node;
        }
    }
};