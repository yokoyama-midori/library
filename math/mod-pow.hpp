#pragma once
#include "../template.hpp"
int mod_pow(int x, ll n, int mod) {
    assert(n >= 0);
    ll res = 1, xpow = x;
    while(n) {
        if(n & 1) {
            res = res * xpow % mod;
        }
        xpow = xpow * xpow % mod;
        n >>= 1;
    }
    return res;
}
ll mod_pow_ll(ll x, ll n, ll mod) {
    assert(n >= 0);
    __int128 res = 1, xpow = x;
    while(n) {
        if(n & 1) {
            res = res * xpow % mod;
        }
        xpow = xpow * xpow % mod;
        n >>= 1;
    }
    return res;
}