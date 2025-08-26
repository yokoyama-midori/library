#pragma once
#include "../template.hpp"
// https://suisen-cp.github.io/cp-library-cpp/library/math/factorial.hpp
template <class T> struct factorial {
    factorial() {};
    void ensure(int n) {
        int sz = size(fac);
        if(sz > n) {
            return;
        }
        int new_sz = max(2 * sz, n + 1);
        fac.resize(new_sz), fac_inv.resize(new_sz);
        for(int i = sz; i < new_sz; ++i) {
            fac[i] = fac[i - 1] * i;
        }
        fac_inv[new_sz - 1] = T(1) / fac[new_sz - 1];
        for(int i = new_sz - 2; i >= sz; --i) {
            fac_inv[i] = fac_inv[i + 1] * (i + 1);
        }
    }
    T operator[](int i) {
        ensure(i);
        return fac[i];
    }
    T inv(int i) {
        ensure(i);
        return fac_inv[i];
    }
    T binom(int n, int i) {
        if(n < 0 or i < 0 or n < i) {
            return T(0);
        }
        ensure(n);
        return fac[n] * fac_inv[i] * fac_inv[n - i];
    }
    T perm(int n, int i) {
        if(n < 0 or i < 0 or n < i) {
            return T(0);
        }
        ensure(n);
        return fac[n] * fac_inv[n - i];
    }

  private:
    inline static vector<T> fac{1}, fac_inv{1};
};