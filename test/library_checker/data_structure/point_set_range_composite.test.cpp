#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include "data_structure/segtree.hpp"
#include "template.hpp"
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;

struct S {
    mint a, b;
};
S op(S fl,S fr){
    S res;
    res.a = fr.a * fl.a;
    res.b = fr.a * fl.b + fr.b;
    return res;
}
S e() { return S{1, 0}; }
void solve() {
    LL(n, q);
    segtree<S, op, e> seg(n);
    rep(i, n) {
        LL(a, b);
        seg.set(i, S{a, b});
    }
    rep(_, q) {
        LL(flag);
        if(flag == 0) {
            LL(p, c, d);
            seg.set(p, S{c, d});
        } else {
            LL(l, r, x);
            S p = seg.prod(l, r);
            mint ans = p.a * x + p.b;
            print(ans.val());
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
