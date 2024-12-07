#define PROBLEM "https://atcoder.jp/contests/abc369/tasks/abc369_c"
#include "string/run-length-encoding.hpp"
#include "template.hpp"
void solve() {
    LL(n);
    vl a(n);
    input(a);
    ll ans = n;
    vl dif;
    rep(i, n - 1) { dif.push_back(a[i + 1] - a[i]); }
    auto enc = RunLengthEncoding(dif);
    for(auto [k, c] : enc) {
        ans += c * (c + 1) / 2;
    }
    print(ans);
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}