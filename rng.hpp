#pragma once
#include "./template.hpp"
/**
 * @brief 乱数
 * @see https://maspypy.github.io/library/random/base.hpp
 */
namespace rng_internal {
unsigned long long x_ =
    (unsigned long long)(chrono::duration_cast<chrono::nanoseconds>(
                             chrono::high_resolution_clock::now()
                                 .time_since_epoch())
                             .count()) *
    10150724397891781847ULL;
}

unsigned long long RNG_64() {
    using namespace rng_internal;
    x_ ^= x_ << 7;
    return x_ ^= x_ >> 9;
}
void init_rng(unsigned long long seed = 10'000'000'000'000'000'000ULL) {
    rng_internal::x_ = seed;
}

unsigned long long RNG(unsigned long long lim) { return RNG_64() % lim; }

/*
1e18くらいの素数
1000000000000000003
1000000000000000009
1000000000000000031
*/
// [l,r)
ll rng(ll l, ll r) { return l + RNG_64() % (r - l); }
// [0,1]
double rnd() { return RNG_64() * 5.42101086242752217e-20; }