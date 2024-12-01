#pragma once
#include "template.hpp"
// https://ei1333.github.io/library/other/compress.hpp
template <class T> struct Compress {
    bool is_built = false;
    vector<T> data;
    Compress() = default;
    Compress(const vector<T> &v) {
        add(v);
    }
    void add(const T &x) {
        is_built = false;
        data.push_back(x);
    }
    void add(const vector<T> &v) {
        for(auto x : v)
            add(x);
    }
    void build() {
        is_built = true;
        sort(data.begin(), data.end());
        data.erase(unique(data.begin(), data.end()), data.end());
    }
    ll get(const T &x) const {
        assert(is_built);
        ll res = lower_bound(data.begin(), data.end(), x) - data.begin();
        assert(data[res] == x);
        return res;
    }
    const T &operator[](size_t t) {
        assert(is_built);
        assert(0 <= t and t < ssize(data));
        data[t];
    }
    ll size() {
        return ssize(data);
    }
};