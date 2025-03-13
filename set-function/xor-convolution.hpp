#pragma once
#include "set-function/fast-hadamard-transform.hpp"
template <class T> vector<T> xor_convolution(vector<T> a, vector<T> b) {
    assert(a.size() == b.size());
    fast_hadmard_transform(a);
    fast_hadmard_transform(b);
    for(int i = 0; i < a.size(); i++)
        a[i] *= b[i];
    fast_hadmard_transform(a, true);
    return a;
}
