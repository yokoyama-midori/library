#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"
#include "math/mod-log.hpp"
void solve() {
    INT(x, y, mod);
    print(discrete_log(x, y, mod));
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << std::setprecision(16);
    INT(T);
    while(T--)
        solve();
}
