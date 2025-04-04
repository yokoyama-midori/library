// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/minimum_steiner_tree
#include "../../../graph/graph-template.hpp"
#include "../../../graph/minimum-steiner-tree.hpp"
#include "../../../template.hpp"
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    INT(n, m);
    Graph<ll> graph(n);
    graph.read(m, 0, 1, 0);
    INT(k);
    vector<int> terminal(k);
    input(terminal);
    MinimumSteinerTree mst(graph, terminal);
    auto edges = mst.restore();
    print(mst.cost, edges.size());
    for(auto &e : edges)
        cout << e.idx << " ";
    print();
}