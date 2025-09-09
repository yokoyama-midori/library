// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/static_range_sum
#include "../../../dp/cumulative-sum.hpp"
#include "../../../template.hpp"
void solve() {
    LL(n, q);
    CumulativeSum<ll> cs(n);
    rep(i, n) {
        LL(a);
        cs.add(i, a);
    }
    cs.build();
    rep(_, q) {
        INT(l, r);
        print(cs.sum(l, r));
    }
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
