// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/manhattanmst
#include "../../../data-structure/union-find.hpp"
#include "../../../geometry/manhattan-mst.hpp"
void solve() {
    LL(n);
    vl xs(n), ys(n);
    rep(i, n) input(xs[i], ys[i]);
    auto dxy = manhattan_mst(xs, ys);
    UnionFind g(n);
    ll w = 0;
    vector<pll> edge;
    edge.reserve(n - 1);
    for(auto &[d, i, j] : dxy) {
        if(!g.same(i, j)) {
            g.merge(i, j);
            w += d;
            edge.emplace_back(i, j);
        }
    }
    print(w);
    for(auto [i, j] : edge) {
        print(i, j);
    }
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
