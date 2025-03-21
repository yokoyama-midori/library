// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
#include "data_structure/lazy-splaytree.hpp"
#include <atcoder/modint>
using mint = atcoder::modint998244353;
struct S {
    mint a, sz;
};
static S op(S s, S t) { return S(s.a + t.a, s.sz + t.sz); }
static S e() { return S(0, 0); }
struct F {
    mint b, c;
    bool operator==(const F &other) const {
        return b == other.b && c == other.c;
    }
};
static S mapping(F f, S s) { return S(f.b * s.a + f.c * s.sz, s.sz); }
static F composition(F f, F g) {
    // composition(f,g)(s) = f(g(s))
    return F(f.b * g.b, f.b * g.c + f.c);
}
static F id() { return F(1, 0); }

void solve() {
    LL(n, q);
    vector<S> v(n);
    rep(i, n) {
        LL(val);
        v[i] = S(val, 1);
    }
    SplayTree<S, op, e, F, mapping, composition, id> st(v);
    rep(t, q) {
        LL(flag);
        if(flag == 0) {
            LL(i, x);
            st.insert_at(i, S(x, 1));
        } else if(flag == 1) {
            LL(i);
            st.remove_at(i);
        } else if(flag == 2) {
            LL(l, r);
            st.reverse(l, r);
        } else if(flag == 3) {
            LL(l, r, b, c);
            st.apply(l, r, F(b, c));
        } else {
            LL(l, r);
            print(st.prod(l, r).a.val());
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
