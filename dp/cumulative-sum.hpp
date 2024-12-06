#pragma once
#include "template.hpp"
// https://ei1333.github.io/library/dp/cumulative-sum.hpp
template <class T = long long> struct CumulativeSum {
    bool is_built = false;
    size_t sz;
    vector<T> data;
    CumulativeSum(size_t maxi) : sz(maxi + 1), data(maxi + 1, 0) {}
    void add(size_t x, T dx) {
        assert(0 <= x and x < sz);
        data[x + 1] += dx;
        is_built = false;
    }
    void build() {
        is_built = true;
        rep(i, sz - 1) { data[i + 1] += data[i]; }
    }
    T sum(ll r) {
        // 区間[0,r)の和
        assert(0 <= r and r < sz);
        return data[r];
    }
    T sum(ll l, ll r) {
        // 区間[l,r)の和
        assert(0 <= l and l <= r and r < sz);
        return sum(r) - sum(l);
    }
    T all_sum() { return data.back(); }
    const T operator[](size_t t) {
        // "累積和をとる前の" t での値
        assert(0 <= t and t < sz);
        return data[t + 1] - data[t];
    }
};