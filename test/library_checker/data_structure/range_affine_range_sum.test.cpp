#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include "data_structure/lazy-segtree.hpp"
#include "template.hpp"
#include <atcoder/modint>
using mint = atcoder::modint998244353;
struct S {
    mint a, sz;
};
S e() { return S(0, 0); };
S op(S a, S b) { return S(a.a + b.a, a.sz + b.sz); }
struct F {
    mint b, c;
};
S mapping(F f, S s) { return S(f.b * s.a + s.sz * f.c, s.sz); }
F composition(F f, F g) { return F(f.b * g.b, f.b * g.c + f.c); }
F id() { return F(1, 0); }

void solve() {
    LL(n, q);
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);
    rep(i, n) {
        LL(a);
        seg.set(i, S(a, 1));
    }
    rep(_, q) {
        LL(flag, l, r);
        if(flag == 0) {
            LL(b, c);
            seg.apply(l, r, F(b, c));
        } else {
            print(seg.prod(l, r).a.val());
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
