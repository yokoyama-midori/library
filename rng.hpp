#pragma once
// https://maspypy.github.io/library/random/base.hpp
#include "template.hpp"
unsigned long long RNG_64() {
    static unsigned long long x_ =
        (unsigned long long)(chrono::duration_cast<chrono::nanoseconds>(
                                 chrono::high_resolution_clock::now()
                                     .time_since_epoch())
                                 .count()) *
        10150724397891781847ULL;
    x_ ^= x_ << 7;
    return x_ ^= x_ >> 9;
}

unsigned long long RNG(unsigned long long lim) { return RNG_64() % lim; }

ll rng(ll l, ll r) {
    // [l,r)
    return l + RNG_64() % (r - l);
}
/*
1e18くらいの素数
1000000000000000003
1000000000000000009
1000000000000000031
*/