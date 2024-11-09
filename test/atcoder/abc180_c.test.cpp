#define PROBLEM "https://atcoder.jp/contests/abc180/tasks/abc180_c"
#include "math/pollard_rho.hpp"
void solve() {
    LL(n);
    auto ans = divisors(n);
    for(auto &x : ans)
        cout << x << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll t = 1;
    rep(_, t) solve();
}
