#include "template.hpp"
template <class S, auto op = [](S a, S b) { return S(0); },
          auto e = []() { return S(0); }>
struct SplayTree {
  private:
    struct Node;
    using pNode = unique_ptr<Node>;
    struct Node {
        Node *left, *right, *parent;
        S a, prod;
        int size;
        Node()
            : left(nullptr), right(nullptr), parent(nullptr), size(1), a(e()),
              prod(e()) {}
        Node(const S &s)
            : left(nullptr), right(nullptr), parent(nullptr), size(1), a(s),
              prod(s) {}
        int state() {
            if(!this->parent)
                return 0;
            if(this->parent->left == this)
                return 1;
            if(this->parent->right == this)
                return 2;
            return 0;
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
    void splay(Node *me) {
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
            int l_size = node->left ? node->left->size : 0;
            if(k < l_size) {
                node = node->left;
            } else if(k == l_size) {
                splay(node);
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
    void dfs(Node *node, vector<S> &res) {
        if(node->left)
            dfs(node->left, res);
        res.push_back(node->a);
        if(node->right)
            dfs(node->right, res);
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
    S all_prod() { return root->prod; }
    void shift(int l, int r) {
        //    ...,a[l]  ,    ... ,a[r-1],a[r],...
        // -> ...,a[r-1],a[l],...,a[r-2],a[r],...
        Node *node;
        tie(root, node) = remove(r - 1, root);
        root = insert(l, node, root);
    }
    void swap(ll l, ll r) {
        // swap(a[l],a[r])
        if(l == r)
            return;
        if(l > r)
            std::swap(l, r);
        Node *al, *ar;
        tie(root, ar) = remove(r, root);
        tie(root, al) = remove(l, root);
        root = insert(l, ar, root);
        root = insert(r, al, root);
    }
    vector<S> get_vec() {
        vector<S> res;
        dfs(root, res);
        return res;
    }
    int find(const S &s, auto &&comp) {
        // comp(s,t) <==> s < t
        // 昇順にソートされていることを仮定する
        // comp(a[i],s)が成り立たない最小のi(s以上の最初のidx)を返す
        // なければsize()を返す
        // amortized O(log size)
        Node *cur = root;
        Node *res = nullptr;
        while(cur) {
            if(comp(cur->a, s)) {
                cur = cur->right;
            } else {
                res = cur;
                cur = cur->left;
            }
        }
        if(res) {
            splay(res);
            root = res;
            return res->left ? res->left->size : 0;
        } else {
            return size();
        }
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