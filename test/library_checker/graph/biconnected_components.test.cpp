// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/biconnected_components
#include "../../../graph/biconnected-components.hpp"
#include "../../../graph/graph-template.hpp"
#include "../../../template.hpp"
void solve() {
    INT(n, m);
    Graph<bool> g(n);
    g.read(m, 0);
    BiConnectedComponents graph(g);
    auto &groups = graph.groups;
    print(groups.size());
    for(auto &v : groups) {
        cout << ssize(v) << " ";
        print(v);
    }
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
