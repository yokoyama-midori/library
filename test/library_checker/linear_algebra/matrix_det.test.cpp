// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/matrix_det
#include "../../../math/matrix.hpp"
#include "../../../template.hpp"
#include <atcoder/modint>
using mint = atcoder::modint998244353;
void solve() {
    INT(n);
    Matrix<mint> a(n, n);
    rep(i, n) rep(j, n) {
        INT(aij);
        a(i, j) = aij;
    }
    print(a.determinant());
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
    rep(t) solve();
}