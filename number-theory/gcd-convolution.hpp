#pragma once
#include "divisor-multiple-transform.hpp"
template <class T> vector<T> gcd_convolution(vector<T> a, vector<T> b) {
    assert(a.size() == b.size());
    multiple_zeta(a);
    multiple_zeta(b);
    rep(i, a.size()) a[i] *= b[i];
    multiple_mebius(a);
    return a;
}