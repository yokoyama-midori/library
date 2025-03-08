#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "tree/tree-query.hpp"
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    INT(n, q);
    Graph<bool> g(n);
    vector<int> p(n, -1);
    rep(i, 1, n) {
        input(p[i]);
        g.add_edge(i, p[i]);
    }
    Tree<bool> tree(g);
    while(q--) {
        INT(s, t);
        print(tree.lca(s, t));
    }
    rep(i, n) assert(p[i] == tree.par(i));
}
