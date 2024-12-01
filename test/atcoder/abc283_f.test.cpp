#define PROBLEM "https://atcoder.jp/contests/abc283/tasks/abc283_f"
#include "geometry/manhattan-mst.hpp"
void solve() {
    int n;
    cin >> n;
    vector<int> I(n), p(n);
    iota(all(I), 1);
    input(p);
    auto wxy = manhattan_mst<int>(I, p);
    vector<int> ans(n, 1e9);
    for(auto [w, x, y] : wxy) {
        chmin(ans[x], w);
        chmin(ans[y], w);
    }
    print(ans);
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
