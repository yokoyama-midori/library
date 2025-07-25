// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/matrix_product
#include "../../../math/matrix.hpp"
#include "../../../template.hpp"
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;

void solve() {
    INT(n, m, k);
    Matrix<mint> a(n, m), b(m, k);
    rep(i, n) rep(j, m) {
        INT(p);
        a(i, j) = p;
    }
    rep(i, m) rep(j, k) {
        INT(p);
        b(i, j) = p;
    }
    auto c = a * b;
    c.show();
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
