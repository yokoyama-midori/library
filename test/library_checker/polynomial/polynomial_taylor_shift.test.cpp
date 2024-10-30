#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift"
#include <atcoder/convolution>
#include <atcoder/modint>
using mint = atcoder::modint998244353;
#include "poly/poly_taylor_shift.hpp"
#include "template.hpp"
factorial<mint> fac;
void solve() {
    LL(n, c);
    vector<mint> a(n);
    rep(i, n) {
        LL(ai);
        a[i] = ai;
    }
    auto b = poly_taylor_shift(a, mint(c));
    rep(i, n) cout << b[i].val() << " \n"[i == n - 1];
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
