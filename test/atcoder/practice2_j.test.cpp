#define PROBLEM "https://atcoder.jp/contests/practice2/tasks/practice2_j"
#include "data_structure/segtree.hpp"

ll e() { return -1; }
void solve() {
    LL(n, q);
    vl a(n);
    input(a);
    segtree<ll, max, e> seg(a);
    rep(_, q) {
        LL(flag);
        if(flag == 1) {
            LL(x, v);
            x--;
            seg.set(x, v);
        } else if(flag == 2) {
            LL(l, r);
            l--;
            print(seg.prod(l, r));
        } else {
            LL(x, v);
            x--;
            ll ng = x, ok = n;
            if(seg.prod(x, n) < v) {
                print(n + 1);
                continue;
            }
            while(ok > ng + 1) {
                ll mid = (ok + ng) / 2;
                if(seg.prod(x, mid) >= v) {
                    ok = mid;
                } else
                    ng = mid;
            }
            print(ok);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
