#define PROBLEM "https://atcoder.jp/contests/abc248/tasks/abc248_d"
#include "data_structure/hash-map-variable-length.hpp"
// segtree 改造
// https://atcoder.jp/contests/abc248/editorial/3819
template <class S, S (*op)(S, S), S (*e)()> struct segtree {
    ll n;
    vector<S> v;
    segtree(ll n_) : segtree(vector<S>(n_, e())) {}
    segtree(const vector<S> &v_) : n(v_.size()) {
        v = vector<S>(2 * n, e());
        rep(i, n) v[n + i] = v_[i];
        for(ll i = n - 1; i >= 0; i--) {
            v[i] = op(v[i << 1], v[i << 1 | 1]);
        }
    }
    void set(ll x, S p) {
        assert(0 <= x && x < n);
        x += n;
        v[x] = p;
        while(x > 1) {
            x >>= 1;
            v[x] = op(v[x << 1], v[x << 1 | 1]);
        }
    }
    ll prod(ll l, ll r, ll x) {
        assert(0 <= l && l <= r && r <= n);
        ll pl(0), pr(0);
        l += n, r += n;
        while(l < r) {
            if(l & 1) {
                if(v[l].contains(x))
                    pl += v[l][x];
            }
            if(r & 1) {
                if(v[r - 1].contains(x))
                    pr += v[r - 1][x];
            }
            l = (l + 1) >> 1;
            r >>= 1;
        }
        return pl + pr;
    }
    S get(ll x) { return v[n + x]; }
};
using S = HashMap<ll>;
S op(S s, S t) {
    if(t.sz > s.sz)
        swap(s, t);
    for(auto [key, val] : t.enumerate()) {
        s[key] += val;
    }
    return s;
};
S e() { return S(); }

void solve() {
    LL(n);
    Graph g(n);
    vector<S> mp(n);
    rep(i, n) {
        LL(a);
        mp[i][--a] = 1;
    }
    segtree<S, op, e> seg(mp);
    LL(q);
    rep(_, q) {
        LL(l, r, x);
        l--, x--;
        ll ans = seg.prod(l, r, x);
        print(ans);
    }
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}