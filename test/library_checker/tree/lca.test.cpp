// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/lca
#include "../../../tree/euler-tour.hpp"
void solve() {
    INT(n, q);
    vector<vector<int>> g(n);
    rep(i, 1, n) {
        INT(p);
        g[p].push_back(i), g[i].push_back(p);
    }
    EulerTour et(g);
    while(q--) {
        INT(x, y);
        print(et.lca(x, y));
    }
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}