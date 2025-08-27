#pragma once
#include "../template.hpp"
// 参考 https://suisen-cp.github.io/cp-library-cpp/library/math/factorial.hpp
template <class T> struct factorial {
    factorial() {};
    void ensure(int n) {
        auto &fac = get_fac();
        auto &fac_inv = get_fac_inv();
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
        return get_fac()[i];
    }
    T inv(int i) {
        ensure(i);
        return get_fac_inv()[i];
    }
    T binom(int n, int i) {
        if(n < 0 or i < 0 or n < i) {
            return T(0);
        }
        ensure(n);
        return get_fac()[n] * get_fac_inv()[i] * get_fac_inv[n - i];
    }
    T perm(int n, int i) {
        if(n < 0 or i < 0 or n < i) {
            return T(0);
        }
        ensure(n);
        return get_fac()[n] * get_fac_inv()[n - i];
    }

  private:
    /*
     inline static vector<T> fac{1};
     のように書くと static initialization order fiasco と呼ばれる問題が起きる
     この問題を避けるため、関数内の static 変数として定義するイディオム
     (Construct on First Use / Meyers' Singleton) を用いる

     https://in-neuro.hatenablog.com/entry/2020/12/12/001244
    */
    static auto &get_fac() {
        static vector<T> fac_{1};
        return fac_;
    }
    static auto &get_fac_inv() {
        static vector<T> fac_inv_{1};
        return fac_inv_;
    }
};