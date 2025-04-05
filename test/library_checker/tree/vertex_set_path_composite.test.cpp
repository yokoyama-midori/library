// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/vertex_set_path_composite
#include "../../../data-structure/segtree.hpp"
#include "../../../graph/graph-template.hpp"
#include "../../../template.hpp"
#include "../../../tree/heavy-light-decomposition.hpp"
#include <atcoder/modint>
using mint = atcoder::modint998244353;
struct S {
    mint a, b;
    mint ra, rb;
};
S e() { return S(1, 0, 1, 0); }
S op(S x, S y) {
    S res;
    tie(res.a, res.b) = make_pair(y.a * x.a, y.a * x.b + y.b);
    tie(res.ra, res.rb) = make_pair(x.ra * y.ra, x.ra * y.rb + x.rb);
    return res;
}
S rev(S s) { return S(s.ra, s.rb, s.a, s.b); }
void solve() {
    INT(n, q);
    vector<int> a(n), b(n);
    rep(i, n) input(a[i], b[i]);
    Graph<bool> g(n);
    g.read(n - 1, 0);
    HLD hld(g);
    segtree<S, op, e> seg(n);
    rep(i, n) seg.set(hld.in[i], S(a[i], b[i], a[i], b[i]));
    while(q--) {
        INT(f);
        if(f == 0) {
            INT(p, a, b);
            seg.set(hld.in[p], S(a, b, a, b));
        } else {
            INT(u, v, x);
            S res = e();
            auto f = [&](int x, int y) {
                if(x < y) {
                    res = op(res, seg.prod(x, y + 1));
                } else {
                    res = op(res, rev(seg.prod(y, x + 1)));
                }
            };
            hld.path_query_noncommutative(u, v, f, true);
            mint ans = res.a * x + res.b;
            print(ans);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
