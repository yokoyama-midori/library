// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/range_kth_smallest
#include "../../../data-structure/persistent-segtree.hpp"
#include "../../../template.hpp"
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    INT(n, q);
    vector<int> a(n);
    input(a);
    persistent_segtree<int, [](int i, int j) { return i + j; },
                       []() { return 0; }>
        seg(n);
    using pointer = decltype(seg)::node_type *;
    vector<pointer> v{seg.build(vector<int>(n, 0))};
    vector<int> ord(n), rev;
    iota(all(ord), 0);
    ranges::sort(ord, {}, [&a](int i) { return a[i]; });
    for(auto i : ord) {
        v.emplace_back(seg.set(v.back(), i, 1));
        rev.emplace_back(a[i]);
    }
    while(q--) {
        INT(l, r, k);
        ++k;
        int ok = n + 1, ng = 0;
        while(ok > ng + 1) {
            int mid = (ok + ng) >> 1;
            if(seg.prod(v[mid], l, r) >= k) {
                ok = mid;
            } else
                ng = mid;
        }
        print(rev[ok-1]);
    }
}