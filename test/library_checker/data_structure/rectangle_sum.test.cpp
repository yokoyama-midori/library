// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/rectangle_sum
#include "../../../data-structure/rectangle-sum.hpp"
#include "../../../template.hpp"
void solve() {
    INT(n, q);
    vector<int> xs(n), ys(n);
    vector<ll> ws(n);
    rep(i, n) { input(xs[i], ys[i], ws[i]); }
    rectangle_sum<int, ll, [](ll x, ll y) { return x + y; },
                  []() { return 0ll; }>
        rect(xs, ys, ws);
    while(q--) {
        INT(l, d, r, u);
        print(rect.sum(l, d, r, u));
    }
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    solve();
}