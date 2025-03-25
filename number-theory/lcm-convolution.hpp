#pragma once
#include "divisor-multiple-transform.hpp"
template <class T> vector<T> lcm_convolution(vector<T> a, vector<T> b) {
    assert(a.size() == b.size());
    divisor_zeta(a);
    divisor_zeta(b);
    rep(i, a.size()) a[i] *= b[i];
    divisor_mebius(a);
    return a;
}