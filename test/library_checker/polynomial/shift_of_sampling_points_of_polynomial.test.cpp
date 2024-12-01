#define PROBLEM                                                                \
    "https://judge.yosupo.jp/problem/shift_of_sampling_points_of_polynomial"
#include <atcoder/modint>
using mint = atcoder::modint998244353;
#include "poly/shift_of_sampling_points.hpp"
#include "template.hpp"

void solve() {
    LL(n, m, c);
    vector<mint> f(n);
    rep(i, n) {
        LL(fi);
        f[i] = fi;
    }
    auto res = shift_of_sampling_points(f, m, c);
    rep(i, m) cout << res[i].val() << " ";
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}