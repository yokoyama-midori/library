// competitive-verifier: PROBLEM https://yukicoder.me/problems/no/1718
#include "../../graph/graph-template.hpp"
#include "../../template.hpp"
#include "../../tree/rerooting.hpp"
struct Data {
    bool exist;
    int max_len, val;
};
void solve() {
    INT(n, k);
    Graph<bool> g(n);
    g.read(n - 1);
    vector<bool> d(n);
    rep(i, k) {
        INT(di);
        d[--di] = true;
    }
    auto merge = [](Data a, Data b) {
        return Data(a.exist or b.exist, max(a.max_len, b.max_len),
                    a.val + b.val);
    };
    auto apply = [&](Data data, int from, int /*to*/, bool) {
        if(data.exist |= d[from])
            data.val += 2, data.max_len++;
        return data;
    };
    Data leaf(false, 0, 0);
    Rerooting<Data, decltype(g), decltype(merge), decltype(apply)> dp(
        g, merge, apply, leaf);
    rep(i, n) print(dp.dp[i].val - dp.dp[i].max_len);
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
