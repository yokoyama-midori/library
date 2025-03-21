#pragma once
#include "../template.hpp"
// https://suisen-cp.github.io/cp-library-cpp/library/math/factorial.hpp
template <class T> struct factorial {
    factorial() {};
    void ensure(const int n) {
        int sz = size(fac);
        if(sz > n) {
            return;
        }
        int new_sz = max(2 * sz, n + 1);
        fac.resize(new_sz), fac_inv.resize(new_sz);
        for(int i = sz; i < new_sz; i++) {
            if(i == 0) {
                fac[i] = 1;
                continue;
            }
            fac[i] = fac[i - 1] * i;
        }
        fac_inv[new_sz - 1] = T(1) / fac[new_sz - 1];
        for(int i = new_sz - 2; i >= sz; i--) {
            fac_inv[i] = fac_inv[i + 1] * (i + 1);
        }
        return;
    }
    T get(int i) {
        ensure(i);
        return fac[i];
    }
    T operator[](int i) { return get(i); }
    T inv(int i) {
        ensure(i);
        return fac_inv[i];
    }
    T binom(int n, int i) {
        if(n < 0 || i < 0 || n < i) {
            return T(0);
        }
        ensure(n);
        return fac[n] * fac_inv[i] * fac_inv[n - i];
    }
    T perm(int n, int i) {
        if(n < 0 || i < 0 || n < i) {
            return T(0);
        }
        ensure(n);
        return fac[n] * fac_inv[n - i];
    }

  private:
    vector<T> fac, fac_inv;
};