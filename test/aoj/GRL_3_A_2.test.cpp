// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_A
#include "../../graph/block-cut-tree.hpp"
#include "../../graph/graph-template.hpp"
#include "../../template.hpp"
void solve() {
    INT(n, m);
    Graph<bool> g(n);
    g.read(m, 0);
    auto bct = block_cut_tree(g);
    for(int i = 0; i < n; ++i) {
        if(bct[i].size() > 1) {
            print(i);
        }
    }
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    solve();
}