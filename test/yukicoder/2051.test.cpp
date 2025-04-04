// competitive-verifier: PROBLEM https://yukicoder.me/problems/no/2051
#include "../../math/pollard-rho.hpp"
void solve() {
    LL(a, b);
    ll ans = 0;
    for(auto &x : divisors(a)) {
        if(x % b == 0) {
            ans++;
        }
    }
    print(ans);
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll t = 1;
    rep(_, t) solve();
}
