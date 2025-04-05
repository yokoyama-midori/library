#pragma once
#include "../template.hpp"
// https://ei1333.github.io/library/structure/segment-tree/persistent-segment-tree.hpp.html
// https://37zigen.com/persistent-segment-tree/
template <class S, auto op, auto e> struct persistent_segtree {
  private:
    int n;
    struct Node {
        S s;
        Node *l, *r;
    };
    vector<unique_ptr<Node>> pool;
    Node *make_node_ptr(Node node) {
        pool.emplace_back(make_unique<Node>(node));
        return pool.back().get();
    }
    // 区間[l,r)がノードに対応する
    // [0,v.size())が根
    Node *build(int l, int r, const vector<S> &v) {
        if(l + 1 == r) {
            return make_node_ptr(Node(v[l]));
        }
        int m = (l + r) >> 1;
        Node *lp = build(l, m, v), *rp = build(m, r, v);
        return make_node_ptr(Node(op(lp->s, rp->s), lp, rp));
    }
    // [a,b) 積を取る区間
    // [l,r) pが対応する区間
    S prod(int a, int b, Node *p, int l, int r) {
        if(r <= a or b <= l)
            return e();
        if(a <= l and r <= b)
            return p->s;
        int m = (l + r) >> 1;
        return op(prod(a, b, p->l, l, m), prod(a, b, p->r, m, r));
    }
    Node *merge(Node *lp, Node *rp) {
        return make_node_ptr(Node(op(lp->s, rp->s), lp, rp));
    }
    Node *set(int k, const S &s, Node *p, int l, int r) {
        assert(p);
        if(k < l or r <= k)
            return p;
        if(l == k and k + 1 == r) {
            return make_node_ptr(Node(s));
        }
        int m = (l + r) >> 1;
        Node *lp = set(k, s, p->l, l, m), *rp = set(k, s, p->r, m, r);
        return merge(lp, rp);
    }

  public:
    using node_type = Node;
    persistent_segtree(int n) : n(n) {}
    Node *build(const vector<S> &v) { return build(0, v.size(), v); }
    // [a,b) の総積を計算
    S prod(Node *p, int a, int b) { return prod(a, b, p, 0, n); }
    Node *set(Node *p, int k, const S &s) { return set(k, s, p, 0, n); }
    void dump(Node *p, vector<S> &res) {
        assert((p->l == nullptr) == (p->r == nullptr));
        if(p->l) {
            dump(p->l, res);
            dump(p->r, res);
        } else {
            res.emplace_back(p->s);
        }
    }
};