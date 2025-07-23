#pragma once
#include "./miller-rabin.hpp"
// https://manabitimes.jp/math/1192
// https://wacchoz.hatenablog.com/entry/2019/01/05/230128
// https://nyaannyaan.github.io/library/prime/fast-factorize.hpp
namespace fast_factorize {
ll pollard_rho(ll n) {
    // nの素因数を１つ返す
    // 1には1を返す
    if(n == 1) {
        return 1;
    }
    if(~n & 1) {
        return 2;
    }
    if(is_prime(n)) {
        return n;
    }
    ll r = 1;
    auto f = [&n, &r](ll m) { return ((__int128)m * m + r) % n; };
    ll x = 1, y = f(x);
    while(1) {
        ll g = gcd(n, abs(x - y));
        if(1 < g and g < n) {
            return pollard_rho(g);
        } else if(g == 1) {
            x = f(x);
            y = f(f(y));
        } else {
            r = rand() % (n - 2) + 2;
            x = 1;
            y = f(x);
        }
    }
}
vl inner_factorize(ll n) {
    vl res;
    if(n == 1) {
        return res;
    }
    while(n > 1 and !is_prime(n)) {
        ll p = pollard_rho(n);
        while(n % p == 0) {
            res.push_back(p);
            n /= p;
        }
    }
    if(n > 1) {
        res.push_back(n);
    }
    return res;
}
vl factorize(ll n) {
    auto res = inner_factorize(n);
    ranges::sort(res);
    return res;
}
map<ll, ll> factor_count(ll n) {
    auto res = inner_factorize(n);
    map<ll, ll> mp;
    for(auto &x : res) {
        mp[x]++;
    }
    return mp;
}
vl divisors(ll n) {
    vl res = {1};
    auto mp = factor_count(n);
    for(auto [p, cnt] : mp) {
        ll sz = ssize(res);
        rep(i, sz) {
            ll pi = p;
            rep(_, cnt) {
                res.push_back(res[i] * pi);
                if(_ + 1 != cnt)
                    pi *= p;
            }
        }
    }
    ranges::sort(res);
    return res;
}
} // namespace fast_factorize
using fast_factorize::divisors;
using fast_factorize::factor_count;
using fast_factorize::factorize;