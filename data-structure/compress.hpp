#pragma once
#include "../template.hpp"
// https://ei1333.github.io/library/other/compress.hpp
template <class T> struct Compress {
    bool is_built = false;
    vector<T> data;
    Compress() = default;
    explicit Compress(const vector<T> &v) { add(v); }
    void add(const T &x) {
        is_built = false;
        data.emplace_back(x);
    }
    void add(const vector<T> &v) {
        is_built = false;
        ranges::copy(v, back_inserter(data));
    }
    void build() {
        is_built = true;
        ranges::sort(data);
        data.erase(unique(begin(data), end(data)), end(data));
    }
    // x 以上となる最小のインデックスを返す
    int get(const T &x) const {
        assert(is_built);
        return ranges::lower_bound(data, x) - begin(data);
    }
    const T &operator[](int t) {
        assert(is_built);
        return data[t];
    }
    int size() const { return ssize(data); }
};