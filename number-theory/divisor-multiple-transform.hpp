#pragma once
#include "../number-theory/enumerate-primes.hpp"
#include "../template.hpp"
template <class mint> void divisor_zeta(vector<mint> &a) {
    // a = {0,a_1,...,a_n};
    int n = ssize(a) - 1;
    for(auto &p : enumerate_primes(n)) {
        for(int i = 1; i * p <= n; i++) {
            a[i * p] += a[i];
        }
    }
}
template <class mint> void divisor_mebius(vector<mint> &a) {
    int n = ssize(a) - 1;
    for(auto &p : enumerate_primes(n)) {
        for(int i = n / p; i > 0; i--) {
            a[i * p] -= a[i];
        }
    }
}
template <class mint> void multiple_zeta(vector<mint> &a) {
    int n = ssize(a) - 1;
    for(auto &p : enumerate_primes(n)) {
        for(int i = n / p; i > 0; i--) {
            a[i] += a[i * p];
        }
    }
}
template <class mint> void multiple_mebius(vector<mint> &a) {
    int n = ssize(a) - 1;
    for(auto &p : enumerate_primes(n)) {
        for(int i = 1; i * p <= n; i++) {
            a[i] -= a[i * p];
        }
    }
}