// competitive-verifier: PROBLEM https://yukicoder.me/problems/no/2896
#include "math/factorial.hpp"
#include "math/linear-sieve.hpp"
#include <atcoder/modint>
factorial<atcoder::modint998244353> fac;
void solve() {
    INT(q);
    LinearSieve ls(1.1e5);
    int num = 0;
    rep(i, q) {
        INT(a, b);
        auto fa = ls.factorize(a);
        assert(ranges::is_sorted(fa));
        num += fa.size();
        print(fac.binom(num - 1, b - 1).val());
    }
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
