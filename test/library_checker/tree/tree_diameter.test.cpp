#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"
#include "graph/graph-template.hpp"
#include "tree/tree-diameter.hpp"
void solve() {
    INT(n);
    Graph<ll> g(n);
    g.read(n - 1, 0, true);
    TreeDiamter<decltype(g), ll> td(g);
    auto path = td.get_path();
    print(td.dist[td.d2], path.size());
    print(path);
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << setprecision(16);
    solve();
}
