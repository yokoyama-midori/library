#define PROBLEM "https://atcoder.jp/contests/tdpc/tasks/tdpc_fibonacci"
#define IGNORE
// 行列累乗では無理 (高速)きたまさ法,Bostan-Moriが必要
#include "template.hpp"
#include "poly/bostan_mori.hpp"
using mint = modint1000000007;
void solve() {
    LL(k, n);
    vector<mint> f(k), q(k + 1);
    rep(i, k) f[i] = 1;
    q[0] = 1;
    rep1(i, k) q[i] = -1;
    auto p = convolution_naive(f,q);
    p.resize(k);
    print(bostanMori(p,q,n-1).val());
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << std::setprecision(16);
    int t = 1;
    rep(_, t) { solve(); }
}
