// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/sqrt_of_formal_power_series
#include "../../../math/mod-sqrt.hpp"
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
    a = a.sqrt(a.size(),
               [](mint x) { return (mint)mod_sqrt(x.val(), mint::mod()); });
    if(a.empty())
        print(-1);
    else
        print(a);
}