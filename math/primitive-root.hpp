#pragma once
#include "../math/mod-pow.hpp"
#include "../math/pollard_rho.hpp"
int primitive_root(int p) {
    // p:prime
    if(p == 2)
        return 1;
    auto fc = factor_count(p - 1);
    for(int r = 2; r < p; r++) {
        bool flag = true;
        for(auto [pi, ei] : fc) {
            if(mod_pow(r, (p - 1) / pi, p) == 1) {
                flag = false;
                break;
            }
        }
        if(flag) {
            return r;
        }
    }
    assert(false);
}
ll primitive_root_ll(ll p) {
    if(p == 2)
        return 1;
    auto fc = factor_count(p - 1);
    for(ll r = 2; r < p; r++) {
        bool flag = true;
        for(auto [pi, ei] : fc) {
            if(mod_pow_ll(r, (p - 1) / pi, p) == 1) {
                flag = false;
                break;
            }
        }
        if(flag) {
            return r;
        }
    }
    assert(false);
}