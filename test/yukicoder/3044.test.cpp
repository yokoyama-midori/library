#define PROBLEM "https://yukicoder.me/problems/no/3044"
#include "poly/bostan_mori.hpp"
using mint = atcoder::modint998244353;
void solve() {
    INT(n, t, k, l);
    using fps = vector<mint>;
    fps p = {1};
    fps q = {1, -mint(k - 1) / 6, -mint(l - k) / 6};
    q.resize(t + 1);
    q.back() = -mint(7 - l) / mint(6);
    mint ans = bostanMori(p, q, n - 1);
    print(ans.val());
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << std::setprecision(16);
    int t = 1;
    rep(_, t) { solve(); }
}
