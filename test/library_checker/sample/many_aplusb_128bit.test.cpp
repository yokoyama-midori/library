// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/many_aplusb_128bit
#include "../../../template.hpp"
void solve() {
    i128 a, b;
    input(a, b);
    print(a + b);
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    LL(t);
    rep(_, t) solve();
}
