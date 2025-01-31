#define PLOBLEM "https://judge.yosupo.jp/problem/primitive_root"
#include "math/primitive-root.hpp"
#include "template.hpp"
void solve() {
    LL(p);
    if(p <= numeric_limits<int>::max()) {
        print(primitive_root(p));
    } else {
        print(primitive_root_ll(p));
    }
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    LL(t);
    rep(_, t) solve();
}
