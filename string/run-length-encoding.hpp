#pragma once
#include "../template.hpp"
template <class S>
vector<pair<typename S::value_type, ll>> RunLengthEncoding(S &s) {
    using C = S::value_type;
    vector<pair<C, ll>> res;
    for(auto &&c : s) {
        if(res.empty() or res.back().first != c) {
            res.emplace_back(c, 0);
        }
        res.back().second++;
    }
    return res;
}