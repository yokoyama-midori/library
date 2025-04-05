// competitive-verifier: PROBLEM https://yukicoder.me/problems/no/880
#include "../../data-structure/segtree-beats.hpp"
#include "../../template.hpp"
struct S {
    ll mini, maxi, lcm, num, sum;
    bool fail;
    S(ll a, ll num_ = 1)
        : mini(a), maxi(a), lcm(a), num(num_), sum(a * num_), fail(false) {};
    S() = default;
};
S e() { return S(0, 0); }
S op(S a, S b) {
    S res = e();
    res.mini = min(a.mini, b.mini);
    res.maxi = max(a.maxi, b.maxi);
    res.lcm = lcm(a.lcm, b.lcm);
    if(a.lcm == inf or b.lcm == inf or
       __int128_t(a.lcm) * b.lcm / (1 + gcd(a.lcm, b.lcm)) >= inf)
        res.lcm = inf;
    res.num = a.num + b.num;
    res.sum = a.sum + b.sum;
    res.fail = a.fail or b.fail;
    return res;
}
struct F {
    // gcdやってassign
    bool gcd_q, assing_q;
    ll g, x;
};
S mapping(F f, S s) {
    if(s.fail) {
        return s;
    }
    if(f.assing_q) {
        return S(f.x, s.num);
    }
    if(f.gcd_q) {
        if(s.mini == s.maxi) {
            ll val = gcd(s.mini, f.g);
            return S(val, s.num);
        }
        if(f.g % s.lcm)
            s.fail = true;
    }
    return s;
}
F id() { return F(false, false, 0, 0); }
F composition(F f1, F f2) {
    if(f1.assing_q or (!f2.assing_q and !f2.gcd_q)) {
        return f1;
    }
    if(!f1.gcd_q) {
        return f2;
    }
    if(f2.assing_q) {
        return F(false, true, 0, gcd(f1.g, f2.x));
    }
    f1.g = gcd(f1.g, f2.g);
    return f1;
}
void solve() {
    LL(n, q);
    vector<S> a(n);
    rep(i, n) {
        LL(ai);
        a[i] = S(ai);
    }
    segtree_beats<S, op, e, F, mapping, composition, id> seg(a);
    while(q--) {
        LL(flag);
        LL(l, r);
        l--;
        if(flag == 1) {
            LL(x);
            seg.apply(l, r, F(false, true, 0, x));
        } else if(flag == 2) {
            LL(x);
            seg.apply(l, r, F(true, false, x, 0));
        } else if(flag == 3) {
            print(seg.prod(l, r).maxi);
        } else {
            print(seg.prod(l, r).sum);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll t = 1;
    rep(_, t) solve();
}
