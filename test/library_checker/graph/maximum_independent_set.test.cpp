// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/maximum_independent_set
#include "../../../graph/maximum-independent-set.hpp"
void solve() {
    INT(n, m);
    using edge_type = Edge<bool>;
    vector<edge_type> edges;
    rep(i, m) {
        INT(a, b);
        edges.emplace_back(a, b);
    }
    auto ans = max_independent_set<40, edge_type>(n, edges);
    print(ans.size());
    print(ans);
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
