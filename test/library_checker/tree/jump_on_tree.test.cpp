// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/jump_on_tree
#include "../../../tree/tree-query.hpp"
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    INT(n, q);
    Graph<bool> g(n);
    g.read(n - 1, 0);
    Tree<bool> tree(g);
    while(q--) {
        INT(s, t, k);
        print(tree.jump(s, t, k));
    }
}
