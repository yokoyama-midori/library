#pragma once
#include "../template.hpp"
template <class S, class count_type = ll>
vector<pair<typename S::value_type, count_type>> RunLengthEncoding(const S &s) {
    using C = S::value_type;
    vector<pair<C, count_type>> res;
    for(const C &c : s) {
        if(res.empty() or res.back().first != c) {
            res.emplace_back(c, 0);
        }
        res.back().second++;
    }
    return res;
}