// competitive-verifier: PROBLEM
// https://judge.yosupo.jp/problem/biconnected_components
#include "../../../graph/block-cut-tree.hpp"
#include "../../../graph/graph-template.hpp"
#include "../../../template.hpp"
void solve() {
    INT(n, m);
    Graph<bool> g(n);
    g.read(m, 0);
    auto tree = block_cut_tree(g);
    cout << tree.size() - n << '\n';
    for(int i = n; i < tree.size(); ++i) {
        cout << tree[i].size() << " ";
        for(auto j : tree[i])
            cout << j << " ";
        cout << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
