// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/gcd_convolution
#include "../../../number-theory/gcd-convolution.hpp"
#include "../../../template.hpp"
#include <atcoder/modint>
using mint = atcoder::modint998244353;
void solve() {
    LL(n);
    vector<mint> a(n + 1), b(n + 1);
    rep(i, 1, n + 1) {
        LL(ai);
        a[i] = ai;
    }
    rep(i, 1, n + 1) {
        LL(bi);
        b[i] = bi;
    }
    auto c = gcd_convolution(a, b);
    rep(i, 1, n + 1) { cout << c[i].val() << " \n"[i == n]; }
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
