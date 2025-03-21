// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/many_factorials
// https://suisen-kyopro.hatenablog.com/entry/2023/11/22/201600#:~:text=%E3%81%93%E3%81%A8%E3%81%8C%E3%81%82%E3%82%8B-,%E6%96%B9%E6%B3%95%E2%91%A1,-(
#include "math/factorial_large.hpp"
#include <atcoder/modint>
factorial_large<atcoder::modint998244353> fac;
void solve() {
    LL(n);
    print(fac.fac(n));
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    LL(t);
    rep(_, t) solve();
}
