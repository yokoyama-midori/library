// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/two_edge_connected_components
#include "../../../graph/graph-template.hpp"
#include "../../../graph/two-edge-connected-components.hpp"
#include "../../../template.hpp"
void solve() {
    INT(n, m);
    Graph<bool> g(n);
    g.read(m, 0);
    TwoEdgeConnectedComponents graph(g);
    print(graph.k);
    for(auto &v : graph.groups) {
        cout << ssize(v) << " ";
        print(v);
    }
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
