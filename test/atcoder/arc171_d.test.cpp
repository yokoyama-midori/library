#define PROBLEM "https://atcoder.jp/contests/arc171/tasks/arc171_d"
// https://drken1215.hatenablog.com/entry/2024/02/05/024500
#include "graph/chromatic-number.hpp"
void solve() {
    LL(p, b, n, m);
    vector g(n + 1, vector<bool>(n + 1, 0));
    while(m--) {
        LL(l, r);
        l--;
        g[l][r] = g[r][l] = 1;
    }
    ll cn = ChromaticNumber(g);
    print(cn <= p ? "Yes" : "No");
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
