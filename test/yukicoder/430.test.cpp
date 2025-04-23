// competitive-verifier: PROBLEM https://yukicoder.me/problems/no/430
#include "../../string/aho-corasick.hpp"
#include "../../template.hpp"
void solve() {
    STR(s);
    INT(n);
    AhoCorasick<26, 'A'> aho;
    rep(i, n) {
        STR(t);
        aho.add(t);
    }
    aho.build();
    ll ans = 0;
    using pNode = decltype(aho)::pNode;
    pNode cur = aho.root;
    for(auto c : s) {
        cur = aho(cur, c - 'A');
        ans += cur->cnt;
    }
    print(ans);
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    solve();
}