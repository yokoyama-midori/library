#define PROBLEM "https://judge.yosupo.jp/problem/longest_increasing_subsequence"
#include "dp/longest-increasing-sequence.hpp"
void solve() {
    LL(n);
    vector<int> a(n);
    input(a);
    vector<int> ans = longest_increasing_sequence(a);
    print(ans.size());
    print(ans);
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
