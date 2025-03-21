// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/bitwise_xor_convolution
#include "set-function/xor-convolution.hpp"
#include <atcoder/modint>
using mint = atcoder::modint998244353;
void solve() {
    INT(n);
    vector<mint> a(1 << n), b(1 << n);
    rep(i, 1 << n) {
        INT(ai);
        a[i] = ai;
    }
    rep(i, 1 << n) {
        INT(bi);
        b[i] = bi;
    }
    auto c = xor_convolution(a, b);
    for(auto ci : c)
        cout << ci.val() << " ";
    cout << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
