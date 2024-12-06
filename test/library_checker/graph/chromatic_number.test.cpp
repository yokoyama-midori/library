#define PROBLEM "https://judge.yosupo.jp/problem/chromatic_number"
#include "graph/chromatic-number.hpp"
void solve() {
    LL(n, m);
    vector g(n, vector<bool>(n, false));
    rep(i, m) {
        LL(a, b);
        g[a][b] = g[b][a] = true;
    }
    print(ChromaticNumber(g));
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
