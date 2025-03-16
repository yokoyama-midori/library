#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "data_structure/segtree.hpp"
#include "template.hpp"

void solve() {
    INT(n, q);
    vector<int> a(n);
    input(a);
    segtree<int, static_cast<int (*)(int, int)>(min),
            [] { return numeric_limits<int>::max(); }>
        seg(a);
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
