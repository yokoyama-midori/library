// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_B
#include "../../graph/graph-template.hpp"
#include "../../graph/lowlink.hpp"
#include "../../template.hpp"
void solve() {
    INT(n, m);
    Graph<bool> g(n);
    g.read(m, 0);
    LowLink lowlink(g);
    ranges::sort(lowlink.bridge);
    for(auto [s, t] : lowlink.bridge)
        print(s, t);
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    solve();
}