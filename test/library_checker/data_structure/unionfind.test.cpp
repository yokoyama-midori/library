// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/unionfind
#include "../../../data_structure/union-find.hpp"
#include "../../../template.hpp"
void solve() {
    INT(n, q);
    UnionFind dsu(n);
    while(q--) {
        INT(t, x, y);
        if(t) {
            print(dsu.same(x, y));
        } else {
            dsu.merge(x, y);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
