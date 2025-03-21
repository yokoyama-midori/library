// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/point_add_range_sum
#include "../../../data_structure/segtree.hpp"
#include "../../../template.hpp"

ll e() { return 0; }
ll op(ll a, ll b) { return a + b; }
void solve() {
    LL(n, q);
    vl a(n);
    input(a);
    segtree<ll, op, e> seg(a);
    rep(_, q) {
        LL(flag);
        if(flag == 0) {
            LL(p, x);
            seg.set(p, seg.get(p) + x);
        } else {
            LL(l, r);
            print(seg.prod(l, r));
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
