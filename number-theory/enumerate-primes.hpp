#pragma once;
#include "template.hpp"
// https://nyaannyaan.github.io/library/prime/prime-enumerate.hpp
template <class T = int> vector<T> enumerate_primes(int n) {
    // Returns primes less than or equal to n in ascending order
    if(n < 2)
        return {};
    if(n < 3)
        return {2};
    vector<bool> sieve(n / 3 + 1, true);
    // prime candidates : 6*i ± 1 (for p >= 5)
    // sieve[i] : is i-th element of {1,5,7,11,13,...,6*j-1,6*j+1,...} prime?
    for(int i = 1, p = 5, d = 4; p * p <= n; i++, p += d = 6 - d) {
        if(!sieve[i])
            continue;
        for(int q = p * p, e = d; q <= n; q += (e = 6 - e) * p) {
            sieve[q / 3] = false;
        }
    }
    vector<T> primes = {2, 3};
    for(int i = 1, p = 5, d = 4; p <= n; i++, p += d = 6 - d) {
        if(sieve[i]) {
            primes.emplace_back(p);
        }
    }
    return primes;
}
