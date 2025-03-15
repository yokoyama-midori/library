#pragma once
#include "template.hpp"
// 商がqの範囲[l,r)をqの昇順に返す
template <class T> vector<tuple<T, T, T>> enumerate_quotients(T n) {
    vector<tuple<T, T, T>> res;
    T q = n;
    while(q > 0) {
        T l = n / (q + 1) + 1, r = n / q + 1;
        res.emplace_back(q, l, r);
        q = n / r;
    }
    ranges::reverse(res);
    return res;
}