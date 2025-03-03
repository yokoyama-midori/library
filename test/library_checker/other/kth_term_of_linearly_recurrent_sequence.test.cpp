#define PROBLEM                                                                \
    "https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence"
#include "poly/bostan_mori.hpp"
using namespace atcoder;
using mint = modint998244353;
void solve() {
    LL(d, k);
    vector<mint> a(d);
    vector<mint> q(d + 1);
    rep(i, d) {
        LL(ai);
        a[i] = ai;
    }
    q[0] = 1;
    rep1(i, d) {
        LL(qi);
        q[i] = -qi;
    }
    auto p = convolution(a, q);
    p.resize(d);
    print(bostanMori(p, q, k).val());
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
