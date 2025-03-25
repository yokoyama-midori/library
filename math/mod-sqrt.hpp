#pragma once
#include "mod-pow.hpp"
#include "../rng.hpp"
#include "../template.hpp"
// Cipolla のアルゴリズム O(log p)
// https://suu-0313.hatenablog.com/entry/2021/10/01/024229
// https://37zigen.com/cipolla-algorithm/
// https://maspypy.github.io/library/mod/mod_sqrt.hpp
int mod_sqrt(int y, int p) {
    // return x (x^2 = y mod p)
    // なければ -1 を返す
    assert(0 <= y and y < p);
    if(p == 2 or y <= 1) {
        return y;
    }
    if(mod_pow(y, (p - 1) / 2, p) != 1) {
        return -1;
    }
    int b, x2;
    while(1) {
        b = rng(1, p);
        x2 = ((ll)b * b - y) % p;
        if(x2 < 0)
            x2 += p;
        if(mod_pow(x2, (p - 1) / 2, p) != 1)
            break;
    }
    if(x2 == 0)
        return b;
    int k = (p + 1) / 2;
    ll f1 = 1, f2 = 0;
    // (b + √x2)^k
    ll pow1 = b, pow2 = 1;
    while(k) {
        // 2*int_max*int_max < ll_max
        if(k & 1) {
            tie(f1, f2) =
                P{f1 * pow1 + f2 * pow2 % p * x2, f1 * pow2 + f2 * pow1};
            f1 %= p, f2 %= p;
        }
        tie(pow1, pow2) =
            P{pow1 * pow1 + pow2 * pow2 % p * x2, 2 * pow1 % p * pow2};
        pow1 %= p, pow2 %= p;
        k >>= 1;
    }
    // assert(f2 == 0);
    return f1;
}
int mod_sqrt_ll(ll y, ll p) {
    // return x (x^2 = y mod p)
    // なければ -1 を返す
    assert(0 <= y and y < p);
    if(p == 2 or y <= 1) {
        return y;
    }
    if(mod_pow_ll(y, (p - 1) / 2, p) != 1) {
        return -1;
    }
    ll b, x2;
    while(1) {
        b = rng(1, p);
        x2 = ((ll)b * b - y) % p;
        if(x2 < 0)
            x2 += p;
        if(mod_pow_ll(x2, (p - 1) / 2, p) != 1)
            break;
    }
    if(x2 == 0)
        return b;
    ll k = (p + 1) / 2;
    __int128 f1 = 1, f2 = 0;
    // (b + √x2)^k
    __int128 pow1 = b, pow2 = 1;
    while(k) {
        // 2*int_max*int_max < ll_max
        if(k & 1) {
            tie(f1, f2) =
                P{f1 * pow1 + f2 * pow2 % p * x2, f1 * pow2 + f2 * pow1};
            f1 %= p, f2 %= p;
        }
        tie(pow1, pow2) =
            P{pow1 * pow1 + pow2 * pow2 % p * x2, 2 * pow1 % p * pow2};
        pow1 %= p, pow2 %= p;
        k >>= 1;
    }
    // assert(f2 == 0);
    return f1;
}