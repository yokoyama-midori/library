// competitive-verifier: PROBLEM https://yukicoder.me/problems/no/2459
#include "../../math/factorial.hpp"
#include "../../poly/sum-of-powers.hpp"
#include "../../template.hpp"
#include <atcoder/modint>
using mint = atcoder::modint998244353;
factorial<mint> fac;
void solve() {
    INT(h, w, n, k);
    mint ans = 0;
    int imax = min(k, h - k), jmax = min(k, w - k);
    mint linv = mint(mint(h - k + 1) * (w - k + 1)).inv();
    // 四隅
    ans += mint(4) * imax * jmax;
    vector<mint> sh = sum_of_powers_iota<mint>(imax + 1, n),
                 sw = sum_of_powers_iota<mint>(jmax + 1, n);
    sh[0]--, sw[0]--;
    for(int m = 0; m <= n; ++m) {
        ans -= 4 * fac.binom(n, m) * (-linv).pow(m) * sh[m] * sw[m];
    }
    mint hl = abs(h - 2 * k), wl = abs(w - 2 * k);
    mint hr = (h >= 2 * k ? k : h - k + 1), wr = (w >= 2 * k ? k : w - k + 1);
    // 中
    mint p = 1 - linv * hr * wr;
    ans += hl * wl * (1 - p.pow(n));
    // 上下左右
    ans += 2 * (wl * imax + hl * jmax);
    for(int m = 0; m <= n; ++m) {
        ans -= 2 * fac.binom(n, m) * (-linv).pow(m) *
               (hl * (hr.pow(m)) * sw[m] + wl * (wr.pow(m)) * sh[m]);
    }
    print(ans);
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    solve();
}
