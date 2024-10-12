#pragma once
#include "template.hpp"

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
    ll n;
    vector<S> v;
    segtree(ll n_) : segtree(vector<S>(n_, e())) {}
    segtree(vector<S> &v_) : n(v_.size()) {
        v = vector<S>(2 * n, e());
        rep(i, n) v[n + i] = v_[i];
        for(ll i = n - 1; i >= 0; i--) {
            v[i] = op(v[i << 1], v[i << 1 | 1]);
        }
    }
    void set(ll x, S p) {
        assert(0 <= x && x < n);
        v[n + x] = p;
        while(x > 1) {
            x >>= 1;
            v[x] = op(v[x << 1], v[x << 1 | 1]);
        }
    }
    S prod(ll l, ll r) {
        assert(0 <= l && l <= r && r <= n);
        S pl(e()), pr(e());
        l += n, r += n;
        while(l < r) {
            if(l & 1) {
                pl = op(pl, v[l]);
            }
            if(r & 1) {
                pr = op(v[r - 1], pr);
            }
            l = (l + 1) >> 1;
            r >>= 1;
        }
        return op(pl, pr);
    }
};