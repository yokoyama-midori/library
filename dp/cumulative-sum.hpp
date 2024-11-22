#pragma once
#include "template.hpp"
// https://ei1333.github.io/library/dp/cumulative-sum.hpp
template <class T> struct CumulativeSum {
    bool is_built = false;
    size_t sz;
    vector<T> data;
    CumulativeSum(size_t maxi) : sz(maxi + 1), data(maxi + 1, 0) {}
    void add(size_t x, T dx) {
        assert(0 <= x and x < sz);
        data[x] += dx;
        is_built = false;
    }
    void build() {
        is_built = true;
        rep(i, sz - 1) { data[i + 1] += data[i]; }
    }
    T sum(ll r) {
        // 区間[0,r)の和
        assert(0 <= r and r <= sz);
        if(r == 0) {
            return 0;
        }
        return data[r - 1];
    }
    T sum(ll l, ll r) {
        // 区間[l,r)の和
        assert(0 <= l and l <= r and r <= sz);
        return sum(r) - sum(l);
    }
};