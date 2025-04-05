// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/staticrmq
#include "../../../data-structure/sparse-table.hpp"
#include "../../../template.hpp"

void solve() {
    INT(n, q);
    vector<int> a(n);
    input(a);
    SparseTable<int, [](int a, int b) { return min(a, b); }> seg(a);
    rep(_, q) {
        INT(l, r);
        print(seg.prod(l, r));
    }
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
