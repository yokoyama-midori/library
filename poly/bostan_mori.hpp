#pragma once
#include "template.hpp"
#include <atcoder/modint>
#include <atcoder/convolution>
template <class T> T bostanMori(vector<T> p, vector<T> q, ll n) {
    // return [x^n]P(x)/Q(x)
    ll k = p.size();
    while(n) {
        auto q_minus(q);
        rep(i, k + 1) {
            if(i & 1)
                q_minus[i] *= -1;
        }
        if(T::mod() == 998244353) {
            p = convolution(p, q_minus);
            q = convolution(q, q_minus);
        } else {
            p = convolution_naive(p, q_minus);
            q = convolution_naive(q, q_minus);
        }
        vector<T> q_nex(k + 1), p_nex(k);
        rep(i, k + 1) { q_nex[i] = q[2 * i]; }
        ll n1 = n & 1;
        rep(i, k) { p_nex[i] = p[2 * i + n1]; }
        swap(p, p_nex);
        swap(q, q_nex);
        n /= 2;
    }
    return p[0] / q[0];
}