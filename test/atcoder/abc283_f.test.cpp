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
    rep(i, n) { cout << ans[i] << " "; }
    cout << '\n';
    // オプションがよく分からないのでとりあえず修正
    // https://github.com/yokoyama-midori/library/actions/runs/12106843024/job/33753048069#step:7:1610
    // Warning:  This was AC if spaces and newlines were ignored. Please use
    // --ignore-spaces (-S) option or --ignore-spaces-and-newline (-N) option.
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
