// competitive-verifier: PROBLEM https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
#include "../../graph/flow/edmonds-karp.hpp"
#include "../../template.hpp"
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<unordered_map<int, int>> graph(n);
    rep(i, 0, m) {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u][v] = c;
    }
    int ans = edmonds_karp(graph, 0, n - 1);
    cout << ans << endl;
}