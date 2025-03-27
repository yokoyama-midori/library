#pragma once
#include "../template.hpp"
template <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),
          F (*composition)(F, F), F (*id)()>
//   composition(f,g)(x) = f∘g(x) = f(g(x))
// aclと同じ、maspyさん記事と逆
struct lazy_segtree {
    int n;
    vector<S> v;
    vector<F> vf;
    lazy_segtree(int n)
        : n(n), v(vector<S>(2 * n, e())), vf(vector<F>(2 * n, id())) {};
    lazy_segtree(vector<S> v_) : n(v_.size()) {
        vf = vector<F>(2 * n, id());
        v = vector<S>(2 * n, e());
        rep(i, n) { v[i + n] = v_[i]; }
        for(int i = n - 1; i > 0; i--) {
            v[i] = op(v[i << 1], v[i << 1 | 1]);
        }
    }
    void apply(int l, int r, F f) {
        l += n;
        r += n;
        int l0 = l / (l & -l);
        int r0 = r / (r & -r) - 1;
        propagate_above(l0);
        propagate_above(r0);
        while(l < r) {
            if(l & 1) {
                apply_at(l, f);
                l++;
            }
            if(r & 1) {
                r--;
                apply_at(r, f);
            }
            l >>= 1;
            r >>= 1;
        }
        recul_above(l0);
        recul_above(r0);
    }
    S get(int x) {
        x += n;
        int maxi = (int)bit_width((unsigned)x) - 1;
        for(int i = maxi; i > 0; i--) {
            propagate_at(x >> i);
        }
        return v[x];
    }
    void set(int x, S s) {
        x += n;
        propagate_above(x);
        v[x] = s;
        recul_above(x);
    }
    S prod(int l, int r) {
        l += n;
        r += n;
        int l0 = l / (l & -l);
        int r0 = r / (r & -r) - 1;
        propagate_above(l0);
        propagate_above(r0);
        S sl = e(), sr = e();
        while(l < r) {
            if(l & 1) {
                sl = op(sl, v[l]);
                l++;
            }
            if(r & 1) {
                r--;
                sr = op(v[r], sr);
            }
            l >>= 1;
            r >>= 1;
        }
        return op(sl, sr);
    }
    S all_prod_commute() {
        // 可換なモノイド専用
        // 2冪にすれば非可換でも良さそう
        return v[1];
    }

  private:
    void apply_at(int x, F f) {
        v[x] = mapping(f, v[x]);
        if(x < n)
            vf[x] = composition(f, vf[x]);
    }
    void propagate_at(int x) {
        apply_at(x << 1, vf[x]);
        apply_at(x << 1 | 1, vf[x]);
        vf[x] = id();
    }
    void propagate_above(int x) {
        int maxi = (int)bit_width((unsigned)x) - 1;
        for(int i = maxi; i > 0; i--) {
            propagate_at(x >> i);
        }
        return;
    }
    void recul_above(int x) {
        while(x > 1) {
            x >>= 1;
            v[x] = op(v[x << 1], v[x << 1 | 1]);
        }
    }
};