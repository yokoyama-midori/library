// https://discuss.codechef.com/t/freqxor-editorial/121327
// https://www.codechef.com/problems/MEXXOR?tab=statement
#pragma once
#include "../template.hpp"
namespace range_xor {
void form(vector<P> &v) {
    sort(all(v));
    vector<P> res;
    for(auto [l, r] : v) {
        if(res.empty() or res.back().second + 1 != l) {
            res.push_back(P(l, r));
        } else {
            res.back().second = r;
        }
    }
    swap(v, res);
}
vector<P> RangeXor(ll r, ll x) {
    // 0^x,1^x,...,r^xを[li,ri](i < O(log2(X)))の和に分解
    ll now = 0;
    ll up = 0;
    vector<P> res;
    for(int i = 62; i >= 0; i--) {
        if((r >> i) & 1) {
            ll mask = ~((1LL << i) - 1);
            ll t = (now ^ x) & mask;
            res.push_back(P(t, t + (1LL << i) - 1));
            now += 1 << i;
        }
    }
    res.push_back(P(r ^ x, r ^ x));
    form(res);
    return res;
}
} // namespace range_xor
using range_xor::RangeXor;