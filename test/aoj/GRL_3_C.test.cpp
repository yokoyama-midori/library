// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C
#include "../../graph/graph-template.hpp"
#include "../../graph/strongly-connected-components.hpp"
#include "../../template.hpp"
void solve() {
    INT(n, m);
    Graph<bool> g(n);
    g.read(m, 0, 0, 1);
    StronglyConnectedComponents scc(g);
    INT(q);
    while(q--) {
        INT(u, v);
        print(scc.comp[u] == scc.comp[v]);
    }
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    solve();
}