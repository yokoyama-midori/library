#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "data_structure/segtree.hpp"
#include "template.hpp"

ll e() { return inf; }
void solve() {
    LL(n, q);
    vl a(n);
    input(a);
    segtree<ll, min, e> seg(a);
    rep(_, q) {
        LL(l, r);
        print(seg.prod(l, r));
    }
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
