#define PROBLEM "https://atcoder.jp/contests/abc249/tasks/abc249_d"
#include "data_structure/hash-map-variable-length.hpp"
#include "math/pollard_rho.hpp"
#include "template.hpp"
void solve() {
    LL(n);
    HashMap<ll> mp;
    rep(i, n) {
        LL(a);
        mp[a]++;
    }
    ll ans = 0;
    for(auto [key, val] : mp.enumerate()) {
        for(auto j : divisors(key)) {
            ll k = key / j;
            if(!mp.contains(j) or !mp.contains(k))
                continue;
            ans += val * mp[j] * mp[k];
        }
    }
    print(ans);
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}