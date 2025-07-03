#pragma once
#include "../set-function/fast-hadamard-transform.hpp"
template <class T> vector<T> xor_convolution(vector<T> a, vector<T> b) {
    assert(a.size() == b.size());
    fast_hadamard_transform(a);
    fast_hadamard_transform(b);
    for(int i = 0; i < (int)a.size(); i++)
        a[i] *= b[i];
    fast_hadamard_transform(a, true);
    return a;
}
