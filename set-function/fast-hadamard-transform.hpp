#pragma once
#include "../template.hpp"
// https://sapphire15.hatenablog.com/entry/2021/09/13/114900
template <class T> void fast_hadamard_transform(vector<T> &a, bool inv = false) {
    if(a.empty())
        return;
    int n = a.size();
    assert((n & (n - 1)) == 0);
    for(int i = 1; i < n; i <<= 1) {
        for(int j = 0; j < n; j++) {
            if((i & j) == 0) {
                tie(a[j], a[i | j]) =
                    make_pair(a[j] + a[i | j], a[j] - a[i | j]);
            }
        }
    }
    if(inv) {
        T invn = T(1) / T(n);
        for(auto &ai : a)
            ai *= invn;
    }
}