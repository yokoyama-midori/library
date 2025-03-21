#pragma once
#include "../rng.hpp"
#include "../template.hpp"
#include <atcoder/convolution>
#include <atcoder/modint>
// https://noshi91.hatenablog.com/entry/2024/05/26/060854
// 問題例 https://atcoder.jp/contests/utpc2024/tasks/utpc2024_k
// O(|S|log|S|)
template <class T>
enable_if_t<is_integral_v<T>, vector<bool>>
wildcard_pattern_matching(const vector<T> &_s, const vector<T> &_t) {
    assert(_s.size() >= _t.size());
    using mint = atcoder::modint998244353;
    int ns = _s.size(), nt = _t.size();
    vector<mint> s(ns), s01(ns), t(nt), t01(nt);
    for(int i : views::iota(0, ns))
        s[i] = _s[i], s01[i] = _s[i] ? 1 : 0;
    for(int i : views::iota(0, nt)) {
        mint r = rng(0, mint::mod());
        t[i] = _t[nt - 1 - i] * r, t01[i] = _t[nt - 1 - i] ? r : 0;
    }
    auto c1 = atcoder::convolution(s, t01);
    auto c2 = atcoder::convolution(s01, t);
    vector<bool> res(ns - nt + 1);
    for(int i : views::iota(0, ssize(res)))
        res[i] = c1[nt - 1 + i] == c2[nt - 1 + i];
    return res;
}
vector<bool> wildcard_pattern_matching(const string &str, const string &str2,
                                       const char &wildcard = '*') {
    vector<char> _s(begin(str), end(str)), _t(begin(str2), end(str2));
    for(char &c : _s)
        if(c == wildcard)
            c = 0;
    for(char &c : _t)
        if(c == wildcard)
            c = 0;
    return wildcard_pattern_matching(_s, _t);
}