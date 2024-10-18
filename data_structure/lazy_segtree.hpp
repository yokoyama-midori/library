#include "template.hpp"

template <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),
          F (*composition)(F, F), F (*id)()>
struct lazy_segtree {
    vector<S> v;
    vector<F> vf;
    ll n;
    lazy_segtree(ll n)
        : n(n), v(vector<S>(2 * n, e())), vf(vector<F>(2 * n, id())) {};
    lazy_segtree(vector<S> v_) : n(v_.size()) {
        vf = vector<F>(2 * n, id());
        v = vector<S>(2 * n, e());
        rep(i, n) { v[i + n] = v_[i]; }
        for(ll i = n - 1; i > 0; i--) {
            v[i] = op(v[i << 1], v[i << 1 | 1]);
        }
    }
    void apply(ll l, ll r, F f) {
        l += n;
        r += n;
        ll l0 = l / (l & -l);
        ll r0 = r / (r & -r) - 1;
        propagate_above(l0);
        propagate_above(r0);
        while(l < r) {
            if(l & 1) {
                vf[l] = composition(vf[l], f);
                l++;
            }
            if(r & 1) {
                r--;
                vf[r] = composition(vf[r], f);
            }
            l >>= 1;
            r >>= 1;
        }
        recul_above(l0);
        recul_above(r0);
    }
    S get(ll x) {
        x += n;
        ll maxi = bit_length(x) - 1;
        for(ll i = maxi; i > 0; i--) {
            propagate_at(x >> i);
        }
        return mapping(vf[x], v[x]);
    }
    void set(ll x, S s) {
        x += n;
        propagate_above(x);
        v[x] = s;
        vf[x] = id();
        recul_above(x);
    }
    S prod(ll l, ll r) {
        l += n;
        r += n;
        ll l0 = l / (l & -l);
        ll r0 = r / (r & -r) - 1;
        propagate_above(l0);
        propagate_above(r0);
        S sl = e(), sr = e();
        while(l < r) {
            if(l & 1) {
                sl = op(sl, mapping(vf[l], v[l]));
                l++;
            }
            if(r & 1) {
                r--;
                sr = op(mapping(vf[r], v[r]), sr);
            }
            l >>= 1;
            r >>= 1;
        }
        return op(sl, sr);
    }

  private:
    S eval_at(ll x) { return mapping(vf[x], v[x]); }
    void propagate_at(ll x) {
        v[x] = mapping(vf[x], v[x]);
        vf[x << 1] = composition(vf[x << 1], vf[x]);
        vf[x << 1 | 1] = composition(vf[x << 1 | 1], vf[x]);
        vf[x] = id();
    }
    ll bit_length(unsigned long long x) { return 64 - countl_zero(x); }
    void propagate_above(ll x) {
        ll maxi = bit_length(x) - 1;
        for(ll i = maxi; i > 0; i--) {
            propagate_at(x >> i);
        }
        return;
    }
    void recul_above(ll x) {
        while(x > 1) {
            x >>= 1;
            v[x] = op(eval_at(x << 1), eval_at(x << 1 | 1));
        }
    }
};