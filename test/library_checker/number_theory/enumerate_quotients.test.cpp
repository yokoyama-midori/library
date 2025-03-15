#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_quotients"
#include "number-theory/enumerate-quotients.hpp"
void solve() {
    LL(n);
    auto ans = enumerate_quotients<ll>(n);
    print(ans.size());
    for(int i : views::iota(0, ssize(ans))) {
        auto [q, l, r] = ans[i];
        cout << q << " \n"[i + 1 == ssize(ans)];
        assert(1 <= l and l < r and r <= n + 1);
        assert(q == (n / l) and q == (n / (r - 1)));
        assert(q != n / r);
        assert(i + 1 == ssize(ans) or l == get<2>(ans[i + 1]));
    }
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << std::setprecision(16);
    solve();
}
