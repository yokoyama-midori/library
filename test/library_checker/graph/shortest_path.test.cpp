#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include "graph/graph-template.hpp"
#include "graph/shortest-path.hpp"
#include "template.hpp"
void solve() {
    INT(n, m, s, t);
    Graph<ll> g(n);
    g.read(m, 0, 1, 1);
    ShortestPath<ll> dijkstra(g, s);
    if(dijkstra[t] == -1)
        print(-1);
    else {
        auto path = dijkstra.restore(t);
        print(dijkstra[t], ssize(path) - 1);
        rep(i, ssize(path) - 1) { print(path[i], path[i + 1]); }
    }
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
