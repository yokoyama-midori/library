// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/tree_path_composite_sum
#include "../../../graph/graph-template.hpp"
#include "../../../template.hpp"
#include "../../../tree/rerooting.hpp"
#include <atcoder/modint>
using mint = atcoder::modint998244353;
struct Data {
    mint a, size;
};
struct Cost {
    mint b, c;
};
void solve() {
    INT(n);
    vector<Data> a(n);
    Graph<Cost> g(n);
    rep(i, n) {
        INT(ai);
        a[i] = {ai, 1};
    }
    rep(i, n - 1) {
        INT(u, v, b, c);
        g.add_edge(u, v, Cost(b, c));
    }
    auto merge = [](Data a, Data b) {
        return Data(a.a + b.a, a.size + b.size);
    };
    auto apply = [&](Data data, int from, int, Cost cost) {
        data = merge(data, a[from]);
        return Data{cost.b * data.a + cost.c * data.size, data.size};
    };
    Data leaf(0, 0);
    Rerooting<Data, decltype(g), decltype(merge), decltype(apply)> dp(
        g, merge, apply, leaf);
    rep(i, n) cout << (dp[i].a + a[i].a).val() << " \n"[i + 1 == n];
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
