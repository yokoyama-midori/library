#define PROBLEM "https://atcoder.jp/contests/abc235/tasks/abc235_c"
#include "data_structure/hash-map-variable-length.hpp"
void solve() {
    LL(n, q);
    HashMap<vl> mp;
    rep1(i, n) {
        LL(a);
        mp[a].push_back(i);
    }
    rep(i, q) {
        LL(x, k);
        if(mp[x].size() < k) {
            print(-1);
        } else {
            print(mp[x][k - 1]);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll t = 1;
    rep(_, t) solve();
}
