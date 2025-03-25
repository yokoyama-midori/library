// competitive-verifier: PROBLEM https://yukicoder.me/problems/no/924
#include "../../data_structure/persistent-segtree.hpp"
#include "../../template.hpp"
P operator-(const P &p, const P &q) {
    return P(p.first - q.first, p.second - q.second);
}
void solve() {
    INT(n, q);
    vl a(n);
    input(a);
    vector<int> ord(n), rev(n);
    iota(all(ord), 0);
    ranges::sort(ord, {}, [&a](int i) { return a[i]; });
    for(int i = 0; i < n; i++)
        rev[ord[i]] = i;
    persistent_segtree<
        P, [](P x, P y) { return P(x.first + y.first, x.second + y.second); },
        [] { return P(0, 0); }>
        seg(n);
    using pointer = decltype(seg)::node_type *;
    vector<pointer> v{seg.build(vector<P>(n))};
    for(int i = 0; i < n; i++) {
        v.emplace_back(seg.set(v.back(), rev[i], P(a[i], 1)));
    }
    ranges::sort(a);
    auto cul = [&](int l, int r) -> ll {
        int ok = 0, ng = n;
        while(ng > ok + 1) {
            int mid = (ok + ng) >> 1;
            if(seg.prod(v[r], 0, mid).second - seg.prod(v[l], 0, mid).second <=
               (r - l) / 2) {
                ok = mid;
            } else
                ng = mid;
        }
        P small = seg.prod(v[r], 0, ok) - seg.prod(v[l], 0, ok);
        P large = seg.prod(v[r], ok, n) - seg.prod(v[l], ok, n);
        ll ans =
            large.first - small.first + a[ok] * (small.second - large.second);
        return ans;
    };
    while(q--) {
        INT(l, r);
        --l;
        print(cul(l, r));
    }
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    solve();
}
