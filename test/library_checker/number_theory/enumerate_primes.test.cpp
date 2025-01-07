#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"
#include "number-theory/enumerate-primes.hpp"
#include "template.hpp"
void solve() {
    LL(n, a, b);
    auto primes = enumerate_primes(n);
    vector<int> ans;
    for(int i = b; i < primes.size(); i += a) {
        ans.emplace_back(primes[i]);
    }
    print(primes.size(), ans.size());
    print(ans);
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
