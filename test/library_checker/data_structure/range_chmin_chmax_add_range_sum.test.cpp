// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
#include "../../../data_structure/range-chminmaxaddsum-segtree-beats.hpp"
void solve() {
    LL(n, q);
    vector<S> a(n);
    rep(i, n) {
        LL(ai);
        a[i] = S(ai, 1);
    }
    segtree seg(a);
    rep(_, q) {
        LL(flag, l, r);
        if(flag == 0) {
            LL(b);
            seg.apply(l, r, F(b, -inf, 0));
        } else if(flag == 1) {
            LL(b);
            seg.apply(l, r, F(inf, b, 0));
        } else if(flag == 2) {
            LL(b);
            seg.apply(l, r, F(inf, -inf, b));
        } else {
            print(seg.prod(l, r).sum);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
