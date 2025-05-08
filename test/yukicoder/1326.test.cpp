// competitive-verifier: PROBLEM https://yukicoder.me/problems/no/1326
#include "../../graph/block-cut-tree.hpp"
#include "../../graph/graph-template.hpp"
#include "../../template.hpp"
#include "../../tree/euler-tour.hpp"
void solve() {
    INT(n, m);
    Graph<bool> g(n);
    g.read(m);
    auto bct = block_cut_tree(g);
    EulerTour tour(bct);
    INT(q);
    while(q--) {
        INT(x, y);
        --x, --y;
        print((tour.dist(x, y) - 1) / 2);
    }
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    solve();
}