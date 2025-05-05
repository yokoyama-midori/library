// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_A
#include "../../graph/graph-template.hpp"
#include "../../graph/lowlink.hpp"
#include "../../template.hpp"
void solve() {
    INT(n, m);
    Graph<bool> g(n);
    g.read(m, 0);
    LowLink lowlink(g);
    ranges::sort(lowlink.articulation);
    for(auto i : lowlink.articulation)
        print(i);
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    solve();
}