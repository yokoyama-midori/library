// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/wildcard_pattern_matching
#include "string/wildcard-pattern-matching.hpp"
void solve() {
    STR(s, t);
    auto ans = wildcard_pattern_matching(s, t);
    for(auto i : ans)
        cout << i;
    print();
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
