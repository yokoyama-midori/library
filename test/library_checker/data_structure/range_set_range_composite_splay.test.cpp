// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/range_set_range_composite
#include "../../../data-structure/lazy-splaytree.hpp"
#include <atcoder/modint>
using mint = atcoder::modint998244353;
struct S {
    mint b, c;
    ll sz;
};
S e() { return S(1, 0, 0); };
S op(S g, S f) { return S(f.b * g.b, f.b * g.c + f.c, g.sz + f.sz); }
struct F {
    bool used;
    mint b, c;
    bool operator==(const F &other) const {
        return used == other.used and b == other.b and c == other.c;
    }
};
S mapping(F f, S s) {
    if(!f.used)
        return s;
    S res(e());
    S ff(f.b, f.c);
    ll sz = s.sz;
    while(sz) {
        if(sz & 1) {
            res = op(res, ff);
        }
        ff = op(ff, ff);
        sz >>= 1;
    }
    res.sz = s.sz;
    return S(res);
}
F composition(F f, F g) {
    if(!f.used)
        return g;
    return f;
}
F id() { return F(false, 0, 0); }

void solve() {
    LL(n, q);
    vector<S> v(n);
    rep(i, n) {
        LL(b, c);
        v[i] = S(b, c, 1);
    }
    SplayTree<S, op, e, F, mapping, composition, id> seg(v);
    rep(_, q) {
        LL(flag, l, r);
        if(flag == 0) {
            LL(b, c);
            seg.apply(l, r, F(true, b, c));
        } else {
            LL(x);
            S p = seg.prod(l, r);
            mint ans = p.b * x + p.c;
            print(ans.val());
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
