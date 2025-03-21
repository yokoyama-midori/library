#pragma once
#include "../template.hpp"
/*
    auto opには
    [](int i,int j){return min(i,j);}や(int(*)(int,int))min
    を渡す
    ↑このmin,std::minじゃないな
    prod 単位元を渡していないので l==rは不可
*/
template <class T, auto op> struct SparseTable {
    SparseTable(const vector<T> &vec) {
        int n = vec.size();
        int b = bit_width(unsigned(n));
        v.resize(b);
        v[0] = vec;
        rep(i, b - 1) {
            v[i + 1].resize(n - (1 << i));
            rep(j, ssize(v[i]) - (1 << i)) {
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
