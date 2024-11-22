#define PROBLEM "https://atcoder.jp/contests/abc113/tasks/abc113_c"
#include "data_structure/compress.hpp"
string make_str(ll n) {
    string suf = to_string(n);
    string res;
    rep(i, 6 - ssize(suf)) { res += '0'; }
    res += suf;
    return res;
}
void solve() {
    LL(n, m);
    vector<Compress<int>> vc(n + 1);
    vector<int> p(m), y(m);
    rep(i, m) {
        cin >> p[i] >> y[i];
        vc[p[i]].add(y[i]);
    }
    rep(i, n + 1) { vc[i].build(); }
    rep(i, m) {
        string ans = make_str(p[i]);
        ans += make_str(vc[p[i]].get(y[i]) + 1);
        cout << ans << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
