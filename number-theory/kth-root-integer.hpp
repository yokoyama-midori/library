#pragma once
#include "../template.hpp"
/**
 * @brief Kth Root (Integer)
 * @see https://ei1333.github.io/library/math/number-theory/kth-root-integer.hpp
 * @return floor(n^(1/k))
 * 浮動小数点数で計算してから調整する方法もあるが...
 */
uint64_t kth_root_integer(uint64_t n, int k) {
    assert(k > 0);
    if(n <= 1 or k == 1)
        return n;
    if(k >= 64)
        return 1;
    if(k == 2)
        return sqrtl(n);
    auto check = [&](uint32_t x) {
        uint64_t mul = 1;
        for(int i = 0; i < k; ++i)
            if(__builtin_mul_overflow(mul, x, &mul))
                return false;
        return mul <= n;
    };
    uint64_t res = 0;
    // res <=  (2^64-1)^(1/3) < 2^(64/4) < 2^22
    for(int i = 21; i >= 0; --i) {
        if(check(res | (1U << i)))
            res |= 1U << i;
    }
    return res;
}
uint64_t isqrt(uint64_t n){
    return sqrtl(n);
}