// competitive-verifier: PROBLEM https://yukicoder.me/problems/no/2677
#include "../../graph/graph-template.hpp"
#include "../../template.hpp"
#include "../../tree/rerooting.hpp"
struct Data {
    int w, b;
};
void solve() {
    INT(n);
    Graph<bool> g(n);
    g.read(n - 1);
    auto merge = [](Data a, Data b) { return Data(a.w + b.w, a.b + b.b); };
    auto apply = [](Data data, int, int, bool) {
        Data res;
        res.b = data.w;
        res.w = max(data.w, 1 + data.b);
        return res;
    };
    Rerooting<Data, decltype(g), decltype(merge), decltype(apply)> dp(
        g, merge, apply, Data(0, 0));
    int ans = n;
    rep(i, n) { chmin(ans, 1 + dp[i].b); }
    print(ans);
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
