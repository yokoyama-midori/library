#pragma once
#include "math/factorial.hpp"
#include <atcoder/convolution>
// https://suisen-cp.github.io/cp-library-cpp/library/polynomial/shift_of_sampling_points.hpp
template <class Mint>
vector<Mint> shift_of_sampling_points(const vector<Mint> &f, const int m,
                                      const int c) {
    // n次未満の多項式fのn個の点f(0),...,f(n-1)に対して
    // f(c),...,f(c+m-1)を計算
    factorial<Mint> fac;
    const int n = f.size();
    auto a = [&] {
        vector<Mint> a1(n), a2(n);
        rep(i, n) {
            a1[i] = f[i] * fac.inv(i);
            a2[i] = ((i & 1) ? -1 : 1) * fac.inv(i);
        }
        auto a = convolution(a1, a2);
        a.resize(n);
        return a;
    }();
    vector<Mint> a_(n);
    rep(i, n) { a_[i] = a[n - 1 - i] * fac[n - 1 - i]; }
    vector<Mint> b2 = [&] {
        // b2[i] = c*(c-1)*...*(c-i+1)/i!
        vector<Mint> b2(n);
        Mint ci = 1;
        b2[0] = ci;
        for(int i = 1; i < n; i++) {
            ci *= c - i + 1;
            b2[i] = ci * fac.inv(i);
        }
        return b2;
    }();
    auto b = convolution(a_, b2);
    vector<Mint> fc = [&] {
        vector<Mint> f1(n);
        vector<Mint> f2(m);
        rep(i, n) { f1[i] = b[n - 1 - i] * fac.inv(i); }
        rep(i, m) { f2[i] = fac.inv(i); }
        return convolution(f1, f2);
    }();
    vector<Mint> res(m);
    rep(i, m) { res[i] = fac[i] * fc[i]; }
    return res;
}
