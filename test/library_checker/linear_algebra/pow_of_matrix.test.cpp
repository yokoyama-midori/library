#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_matrix"
#include "math/matrix.hpp"
#include "template.hpp"
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;

void solve() {
    LL(n, k);
    Matrix<mint> a(n);
    rep(i, n) rep(j, n) {
        LL(p);
        a[i][j] = p;
    }
    a ^= k;
    a.show();
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
