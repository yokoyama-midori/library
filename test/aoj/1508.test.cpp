// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/1508
#include "../../data_structure/splaytree.hpp"
void solve() {
    LL(n, q);
    vl a(n);
    input(a);
    SplayTree<ll, [](ll a, ll b) { return min(a, b); },
              []() { return numeric_limits<ll>::min(); }>
        spt(a);
    while(q--) {
        LL(x, y, z);
        if(x == 0) {
            spt.shift(y, z + 1);
        } else if(x == 1) {
            print(spt.prod(y, z + 1));
        } else {
            spt.set(y, z);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
