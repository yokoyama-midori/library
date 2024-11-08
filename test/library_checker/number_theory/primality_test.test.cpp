#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"
#include "template.hpp"
#include "math/miller_rabin.hpp"
void solve() {
    LL(n);
    rep(_, n) {
        LL(a);
        print(is_prime(a) ? "Yes" : "No");
    }
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
