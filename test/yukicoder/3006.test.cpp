#define PROBLEM "https://yukicoder.me/problems/no/3006"
#include "math/matrix.hpp"
#include <atcoder/modint>
using mint = atcoder::modint998244353;
using mat = Matrix<mint>;
void solve() {
    LL(x1, y1, n);
    mint x = x1, y = y1;
    mat a(2), id(2);
    a[0][0] = a[1][1] = x;
    a[0][1] = -5 * y;
    a[1][0] = y;
    id[0][0] = id[1][1] = 1, id[0][1] = id[0][1] = 0;
    mat b(4);
    rep(i, 2) rep(j, 2) {
        b[i][j] = a[i][j];
        b[i][j + 2] = id[i][j];
        b[i + 2][j + 2] = id[i][j];
    }
    b = b.pow(n);
    mat v(2);
    rep(i, 2) rep(j, 2) v[i][j] = b[i][j + 2];
    mint ax = v[0][0] * x + v[0][1] * y;
    mint ay = v[1][0] * x + v[1][1] * y;
    print(ax.val(), ay.val());
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
