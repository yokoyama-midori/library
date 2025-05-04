// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/manhattanmst
#include "../../../geometry/manhattan-mst.hpp"
#include <atcoder/dsu>
void solve() {
    LL(n);
    vl xs(n), ys(n);
    rep(i, n) cin >> xs[i] >> ys[i];
    const auto &dxy = manhattan_mst(xs, ys);
    atcoder::dsu g(n);
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
