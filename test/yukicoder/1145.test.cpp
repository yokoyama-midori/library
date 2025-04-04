// competitive-verifier: PROBLEM https://yukicoder.me/problems/no/1145
#include "../../poly/sum-of-powers.hpp"
#include "../../template.hpp"
#include <atcoder/modint>
using mint = atcoder::modint998244353;
void solve() {
    INT(n, m);
    vector<mint> a(n);
    rep(i, n) {
        INT(ai);
        a[i] = ai;
    }
    auto f = sum_of_powers(a, m);
    rep(i, 1, m + 1) cout << f[i].val() << " \n"[i == m];
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    solve();
}