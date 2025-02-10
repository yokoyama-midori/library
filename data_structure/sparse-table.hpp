#pragma once
#include "template.hpp"
template <class T, auto op> struct SparseTable {
    SparseTable(const vector<T> &vec) {
        int n = vec.size();
        int b = bit_width(unsigned(n));
        v.resize(b);
        v[0] = vec;
        rep(i, b - 1) {
            v[i + 1].resize(n - (1 << i));
            for(int j = 0; j + (1 << i) < n; j++) {
                v[i + 1][j] = op(v[i][j], v[i][j + (1 << i)]);
            }
        }
    }
    T prod(int l, int r) const {
        if(l + 1 == r)
            return v[0][l];
        int b = bit_width(unsigned(r - l - 1)) - 1;
        return op(v[b][l], v[b][r - (1 << b)]);
    }

  private:
    vector<vector<T>> v;
};
