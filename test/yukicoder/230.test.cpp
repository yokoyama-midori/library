// competitive-verifier: PROBLEM https://yukicoder.me/problems/no/230
#include "../../data_structure/lazy-segtree.hpp"
#include "../../template.hpp"
struct S {
    ll a, b, sz;
};
struct F {
    ll f;
    // 0 e,1 a,2 b
};
S op(S s, S t) { return S(s.a + t.a, s.b + t.b, s.sz + t.sz); }
S mapping(F f, S s) {
    if(f.f == 0) {
        return s;
    } else if(f.f == 1) {
        return S(s.sz, 0, s.sz);
    } else {
        return S(0, s.sz, s.sz);
    }
}
F composition(F f, F g) {
    if(f.f == 0) {
        return g;
    } else
        return f;
}
S e() { return S(0, 0, 0); }
F id() { return F(0); }
void solve() {
    LL(n, q);
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(
        vector<S>(n, S(0, 0, 1)));
    ll ans_a = 0, ans_b = 0;
    // rep(i, n) { seg.set(i, S(0, 0, 1)); }
    rep(_, q) {
        LL(x, l, r);
        if(x == 0) {
            S res = seg.prod(l, r + 1);
            if(res.a > res.b) {
                ans_a += res.a;
            } else if(res.a < res.b) {
                ans_b += res.b;
            }
        } else if(x == 1) {
            seg.apply(l, r + 1, F(1));
        } else {
            seg.apply(l, r + 1, F(2));
        }
    }
    {
        S res = seg.prod(0, n);
        ans_a += res.a;
        ans_b += res.b;
    }
    print(ans_a, ans_b);
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
