#pragma once
#include "template.hpp"
// https://drken1215.hatenablog.com/entry/2023/05/23/233000
// todo モンゴメリ乗算
bool is_prime(ll n) {
    auto pow_mod = [&n](__int128 a, ll d) {
        __int128 res = 1;
        while(d) {
            if(d & 1) {
                res *= a;
                if(res >= n)
                    res %= n;
            }
            a *= a;
            if(a >= n)
                a %= n;
            d >>= 1;
        }
        return res;
    };
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
        ll ad = pow_mod(a, d);
        if(ad == 1) {
            return true;
        }
        rep(i, s) {
            if(ad == n - 1) {
                return true;
            }
            if(i < s - 1)
                ad = pow_mod(ad, 2);
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