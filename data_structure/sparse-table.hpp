#pragma once
#include "template.hpp"
template <class T, auto op> struct SparseTable {
    SparseTable(const vector<T> &vec) {
        int n = vec.size();
        int b = 32 - countl_zero(unsigned(n > 1 ? n - 1 : n));
        v = vector(b, vector<T>(n));
        v[0] = vec;
        rep(i, b - 1) {
            for(int j = 0; j + (1 << i) < n; j++) {
                v[i + 1][j] = op(v[i][j], v[i][j + (1 << i)]);
            }
        }
    }
    T prod(int l, int r) const {
        if(l + 1 == r)
            return v[0][l];
        int b = 31 - countl_zero(unsigned(r - l - 1));
        return op(v[b][l], v[b][r - (1 << b)]);
    }

  private:
    vector<vector<T>> v;
};
