// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/2873
#include "../../string/aho-corasick.hpp"
#include "../../template.hpp"
// https://atcoder.jp/contests/abc268/tasks/abc268_hと同じ問題
void solve() {
    STR(s);
    INT(n);
    AhoCorasick aho;
    rep(i, n) {
        STR(pi);
        aho.add(pi);
    }
    aho.build();
    int ans = 0;
    auto cur = aho.root;
    for(auto c : s) {
        cur = aho(cur, c - 'a');
        if(cur->cnt) {
            ++ans;
            cur = aho.root;
        }
    }
    print(ans);
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    solve();
}