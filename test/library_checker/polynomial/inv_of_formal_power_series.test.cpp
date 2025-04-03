// competitive-verifier: PROBLEM
// https://judge.yosupo.jp/problem/inv_of_formal_power_series
#include "../../../poly/formal-power-series.hpp"
#include "../../../template.hpp"
#include <atcoder/modint>
using mint = atcoder::modint998244353;
int main() {
    INT(n);
    FormalPowerSeries<mint> a(n);
    rep(i, n) {
        INT(ai);
        a[i] = ai;
    }
    a = a.inv(n);
    print(a);
}