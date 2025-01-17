#define PROBLEM "https://yukicoder.me/problems/no/3004"
#include "math/factorial_large.hpp"
#include <atcoder/modint>
using mint = atcoder::modint998244353;
factorial_large<mint> fac;
void solve() {
    LL(k);
    ll sum = 0;
    mint ans = 1;
    rep(i, k) {
        LL(l, m);
        sum += l * m;
        ans *= fac.fac(m);
        ans *= fac.fac(l).pow(m);
    }
    ans = fac.fac(sum) / ans;
    print(ans.val());
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
