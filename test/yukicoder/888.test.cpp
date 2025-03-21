// competitive-verifier: PROBLEM https://yukicoder.me/problems/no/888
#include "../../math/pollard_rho.hpp"
void solve() {
    LL(n);
    auto div = divisors(n);
    ll ans = accumulate(all(div), 0LL);
    print(ans);
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll t = 1;
    rep(_, t) solve();
}
