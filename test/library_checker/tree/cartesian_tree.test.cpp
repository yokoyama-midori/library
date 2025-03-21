// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/cartesian_tree
#include "../../../template.hpp"
#include "../../../tree/cartesian-tree.hpp"
void solve() {
    INT(n);
    vector<int> a(n);
    input(a);
    auto p = cartesian_tree(a);
    rep(i, n) cout << (p[i] == -1 ? i : p[i]) << " \n"[i + 1 == n];
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
