// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/vertex_add_path_sum
#include "../../../data_structure/segtree.hpp"
#include "../../../graph/graph-template.hpp"
#include "../../../template.hpp"
#include "../../../tree/heavy-light-decomposition.hpp"
void solve() {
    INT(n, q);
    vector<int> a(n);
    input(a);
    Graph<bool> g(n);
    g.read(n - 1, 0);
    HLD hld(g);
    segtree<ll, [](ll x, ll y) { return x + y; }, [] { return 0LL; }> seg(n);
    rep(i, n) seg.set(hld.in[i], a[i]);
    while(q--) {
        INT(f);
        if(f == 0) {
            INT(p, x);
            a[p] += x;
            seg.set(hld.in[p], a[p]);
        } else {
            INT(u, v);
            ll ans = 0;
            hld.path_query(
                u, v, [&](int x, int y) { ans += seg.prod(x, y); }, true);
            print(ans);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
