// competitive-verifier: PROBLEM https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1040
#include "../../graph/graph-template.hpp"
#include "../../graph/minimum-steiner-tree.hpp"
ll h, w, c;
void solve() {
    if(h == 0 and w == 0)
        exit(0);
    Graph<ll> g(h * w);
    rep(i, h) rep(j, w) {
        if(i + 1 < h)
            g.add_edge(i * w + j, (i + 1) * w + j);
        if(j + 1 < w)
            g.add_edge(i * w + j, i * w + j + 1);
    }
    vector<int> term;
    rep(i, h) rep(j, w) {
        cin >> c;
        if(c)
            term.emplace_back(i * w + j);
    }
    MinimumSteinerTree<ll> mst(g, term);
    print(h * w - mst.cost - 1);
    // 木になるのでコスト(辺数)+1が頂点数
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // LL(t);
    while(cin >> h >> w)
        solve();
}
