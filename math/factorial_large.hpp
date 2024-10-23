#pragma once
#include "poly/shift_of_sampling_points.hpp"
#include "template.hpp"
#include <atcoder/modint>
template <class mint> struct factorial_large {
    const ll K = 9;
    // const ll K = 2;
    vector<vector<mint>> f;
    vector<mint> g;
    factorial_large() {
        // f_i(x) = (2^i x + 1) * ... * (2^i x + 2^i - 1)
        // f_i(0) , ... , f_i(2^i - 1) の値が分かればシフトできる
        f = vector(K + 1, vector<mint>());
        f[0] = {1};
        // f_0(x) = 1
        rep(i, K) {
            // cul f_(i+1)
            ll ti = 1LL << i;
            auto f1 = shift_of_sampling_points<mint>(f[i], 3 * ti, ti);
            f[i].insert(f[i].end(), all(f1));
            // debug(i, f[i].size());
            f[i + 1].resize(2 * ti);
            rep(j, 2 * ti) {
                f[i + 1][j] = f[i][2 * j] * f[i][2 * j + 1] * ti * (2 * j + 1);
            }
            // if(i <= 3) {
            //     rep(j, ti) cout << f[i][j].val() << " ";
            //     cout << endl;
            // }
        }
        // g_i = (i*2^K)!
        {
            ll sz = ll(mint::mod()) / (1LL << K) + 1;
            auto g1 = shift_of_sampling_points(f[K], sz - 1, 0);
            g.resize(sz);
            g[0] = 1;
            mint tK = 1 << K;
            for(int i = 1; i < sz; i++) {
                g[i] = g[i - 1] * g1[i - 1] * tK * i;
            }
        }
    }
    mint fac(ll n) {
        if(n >= mint::mod())
            return 0;
        ll r = n / (1LL << K);
        ll q = n - (1LL << K) * r;
        mint res = g[r];
        for(ll i = (1LL << K) * r + 1; i <= n; i++) {
            res *= i;
        }
        return res;
    }
};