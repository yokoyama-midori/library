#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#include "math/pollard_rho.hpp"
#include "template.hpp"
void solve() {
    LL(n);
    if(n == 1) {
        print(0);
        return;
    }
    auto ans = factorize(n);
    cout << ssize(ans) << " ";
    print(ans);
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    LL(t);
    rep(_, t) solve();
}
