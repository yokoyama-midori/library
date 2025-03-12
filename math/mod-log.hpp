#include "template.hpp"
#include <atcoder/math>
https://qiita.com/suisen_cp/items/d597c8ec576ae32ee2d7
ll discrete_log_coprime(ll x, ll y, ll mod) {
    // gcd(x,mod) == 1
    assert(0 <= x and x < mod and 0 <= y and y < mod);
    if(x == 0) {
        if(y == 0)
            return 1;
        else if(y == 1)
            return 0;
        else
            return -1;
    }
    ll p = 0, xp = 1, ixp = 1;
    unordered_map<ll, ll> mp;
    for(; p * p < mod; p++) {
        if(!mp.contains(xp))
            mp[xp] = p;
        xp = ll(xp) * x % mod;
    }
    ll ix = atcoder::inv_mod(x, mod);
    ix = atcoder::pow_mod(ix, p, mod);
    for(ll i = 0; i < p; i++) {
        if(mp.contains(y * ixp % mod)) {
            return i * p + mp[y * ixp % mod];
        }
        ixp = ixp * ix % mod;
    }
    return -1;
}
// min k s.t. x^k==y mod mod
// なければ -1
ll discrete_log(ll x, ll y, ll mod) {
    assert(0 < mod and mod < numeric_limits<int>::max());
    // mod でかすぎると128bit必要
    if(x < 0 or mod <= x) {
        x %= mod;
        if(x < 0)
            x += mod;
    }
    if(y < 0 or mod <= y) {
        y %= mod;
        if(y < 0)
            y += mod;
    }
    if(mod == 1 or y == 1)
        return 0;
    ll g = gcd(x, mod);
    if(g == 1)
        return discrete_log_coprime(x, y, mod);
    if(y % g)
        return -1;
    y /= g, mod /= g;
    ll ix = atcoder::inv_mod(x / g, mod);
    ll z = y * ix % mod;
    ll l = discrete_log(x % mod, z, mod);
    return l == -1 ? l : l + 1;
}