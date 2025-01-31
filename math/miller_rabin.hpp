#pragma once
#include "math/mod-pow.hpp"
#include "template.hpp"
// https://drken1215.hatenablog.com/entry/2023/05/23/233000
// todo モンゴメリ乗算
bool is_prime(ll n) {
    if(n == 2 or n == 7 or n == 61) {
        return true;
    }
    if(n % 2 == 0 or n == 1) {
        return false;
    }
    ll d = n - 1;
    ll s = 0;
    while(d % 2 == 0) {
        d >>= 1;
        s++;
    }
    auto check = [&](ll a) {
        ll ad = mod_pow_ll(a, d, n);
        if(ad == 1) {
            return true;
        }
        rep(i, s) {
            if(ad == n - 1) {
                return true;
            }
            if(i < s - 1)
                ad = mod_pow_ll(ad, 2, n);
        }
        return false;
    };
    if(n < 4759123141) {
        for(auto a : vl{2, 7, 61}) {
            if(!check(a)) {
                return false;
            }
        }
        return true;
    } else {
        for(auto a : vl{2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
            if(n == a) {
                return true;
            }
            if(!check(a)) {
                return false;
            }
        }
        return true;
    }
}