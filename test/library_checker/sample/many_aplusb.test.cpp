// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/many_aplusb
#include "../../../template.hpp"
void solve() {
    LL(a, b);
    print(a + b);
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    LL(t);
    rep(_, t) solve();
}
