#pragma once
#include "template.hpp"
// https://maspypy.com/slope-trick-1-%E8%A7%A3%E8%AA%AC%E7%B7%A8
// https://ei1333.github.io/library/structure/others/slope-trick.hpp
struct SlopeTrick {
    multiset<ll> L, R;
    ll min_f;
    ll add_L, add_R;
    SlopeTrick() {
        L = {-inf};
        R = {inf};
        add_L = add_R = min_f = 0;
    }
    ll size() { return ssize(L) + ssize(R); }
    // add \____
    // f(x) <- f(x) + max(a-x,0)
    void add_a_minus_x(ll a) {
        ll r0 = *begin(R);
        min_f += max(0LL, a - (r0 + add_R));
        R.insert(a - add_R);
        auto itr = begin(R);
        L.insert(*itr + add_R - add_L);
        R.erase(itr);
    }
    // add ___/
    // f(x) <- f(x) + max(x-a,0)
    void add_x_minus_a(ll a) {
        ll l0 = *L.rbegin();
        min_f += max(0LL, l0 + add_L - a);
        L.insert(a - add_L);
        auto itr = prev(end(L));
        R.insert(*itr + add_L - add_R);
        L.erase(itr);
    }
    // add \/
    // f(x) <- f(x) + |x-a|
    void add_abs(ll a) {
        add_a_minus_x(a);
        add_x_minus_a(a);
    }
    // f(x) <- f(x) + a
    void add_all(ll a) { min_f += a; }
    // f(x) = min_f をとる閉区間[l,r]
    P min_range() { return P(*rbegin(L) + add_L, *begin(R) + add_R); }
    // f(x) <- f(x) + g(x)
    void merge(SlopeTrick &g) {
        min_f += g.min_f;
        for(auto l : g.L) {
            if(l == -inf)
                continue;
            add_a_minus_x(l + g.add_R);
        }
        for(auto r : g.R) {
            if(r == inf)
                continue;
            add_x_minus_a(r + g.add_L);
        }
    }
    // https://maspypy.com/slope-trick-1-%E8%A7%A3%E8%AA%AC%E7%B7%A8#toc18:~:text=%E3%81%B0%E3%82%88%E3%81%84%E3%81%A7%E3%81%99%E3%80%82-,%E3%82%B9%E3%83%A9%E3%82%A4%E3%83%89%E6%9C%80%E5%B0%8F%E5%80%A4%E9%96%A2%E6%95%B0,-%EF%BC%9A
    // f(x) <- min[x-b <= y <= x-a]f(y)
    // \./ -> \_/
    void shift(ll a, ll b) {
        assert(a <= b);
        add_L += a;
        add_R += b;
    }
    // f(x) <- f(x-a)
    void shift(ll a) { shift(a, a); }
    ll get(ll a) {
        ll res = min_f;
        for(auto l : L) {
            res += max(0LL, l + add_L - a);
        }
        for(auto r : R) {
            res += max(0LL, a - (r + add_R));
        }
        return res;
    }
    // \__/ -> \___
    // f(x) <- min[y<=x]f(y)
    void clear_right() { R = {inf}; }
    // \__/ -> __/
    // f(x) <- min[y>=x]f(y)
    void clear_left() { L = {inf}; }
};