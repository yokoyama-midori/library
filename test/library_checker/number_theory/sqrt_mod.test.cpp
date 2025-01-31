#define PROBLEM "https://judge.yosupo.jp/problem/primitive_root"
#include "math/mod-sqrt.hpp"
#include "template.hpp"
void solve() {
    INT(y, p);
    print(mod_sqrt(y, p));
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    LL(t);
    rep(_, t) solve();
}
