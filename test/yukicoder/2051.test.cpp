#define PROBLEM "https://yukicoder.me/problems/no/2051"
#include "math/pollard_rho.hpp"
void solve() {
    LL(a, b);
    auto div = divisors(a);
    set<ll> s(all(div));
    ll ans = 0;
    for(auto &x : divisors(b)) {
        ans += s.count(x);
    }
    print(ans);
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll t = 1;
    rep(_, t) solve();
}
