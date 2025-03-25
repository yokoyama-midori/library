// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/vertex_add_subtree_sum
#include "data_structure/segtree.hpp"
#include "graph/graph-template.hpp"
#include "template.hpp"
#include "tree/euler-tour.hpp"
void solve() {
    // inしかつかってないからsegの長さは半分にできるけどEulerTourを柔軟にしたほうがいい？
    INT(n, q);
    vl a(n);
    input(a);
    Graph<bool> g(n);
    rep(i, 1, n) {
        INT(p);
        g.add_directed_edge(p, i);
    }
    EulerTour tour(g);
    segtree<ll, [](ll x, ll y) { return x + y; }, [] { return 0LL; }> seg(2 *
                                                                          n);
    rep(i, n) { seg.set(tour.in[i], a[i]); }
    while(q--) {
        INT(flag);
        if(flag == 0) {
            INT(p, x);
            a[p] += x;
            seg.set(tour.in[p], a[p]);
        } else {
            INT(p);
            ll ans = seg.prod(tour.in[p], tour.out[p]);
            print(ans);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
