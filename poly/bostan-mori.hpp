#pragma once
#include "../template.hpp"
#include <atcoder/convolution>
#include <atcoder/modint>
template <class T> T bostanMori(vector<T> p, vector<T> q, ll n) {
    // return [x^n]P(x)/Q(x)
    using namespace atcoder;
    assert(p.size() < q.size());
    int k = ssize(q) - 1;
    if(p.size() < k - 1)
        p.resize(k);
    while(n) {
        auto q_minus(q);
        for(int i = 1; i < k + 1; i += 2) {
            q_minus[i] *= -1;
        }
        if(T::mod() == 998244353) {
            p = convolution(p, q_minus);
            q = convolution(q, q_minus);
        } else {
            p = convolution_naive(p, q_minus);
            q = convolution_naive(q, q_minus);
        }
        int n1 = n & 1;
        rep(i, k) p[i] = p[2 * i + n1];
        rep(i, k + 1) q[i] = q[2 * i];
        p.resize(k);
        q.resize(k + 1);
        n >>= 1;
    }
    return p[0] / q[0];
}