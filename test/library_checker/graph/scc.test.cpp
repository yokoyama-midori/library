// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/scc
#include "../../../graph/graph-template.hpp"
#include "../../../graph/strongly-connected-components.hpp"
#include "../../../template.hpp"
void solve() {
    INT(n, m);
    Graph<bool> g(n);
    g.read(m, 0, 0, 1);
    StronglyConnectedComponents scc(g);
    print(ssize(scc.groups));
    for(auto &v : scc.groups) {
        cout << ssize(v) << " ";
        print(v);
    }
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
