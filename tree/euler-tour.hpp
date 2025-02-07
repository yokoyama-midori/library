#pragma once
#include "data_structure/segtree.hpp"
#include "template.hpp"
// https://maspypy.com/euler-tour-%E3%81%AE%E3%81%8A%E5%8B%89%E5%BC%B7
// https://nyaannyaan.github.io/library/tree/euler-tour.hpp
// TODO 高速なRMQ e.g. sparse table
// 今のところ LCA O(log N)
namespace et_internal {
using pii = pair<int, int>; // depth,vartex
pii op(pii a, pii b) {
    if(a.first < b.first)
        return a;
    else
        return b;
}
pii e() { return pii(numeric_limits<int>::max(), -1); }
using RMQ_seg = segtree<pii, op, e>;
}; // namespace et_internal
template <class G> struct EulerTour {
    int root, id;
    vector<int> in, out;
    et_internal::RMQ_seg seg;
    EulerTour(G &g, int root = 0)
        : root(root), id(0), in(g.size(), -1), out(g.size(), -1),
          seg(2 * g.size()) {
        dfs(g, root, -1, 0);
    }
    int lca(int x, int y) const {
        int ix = in[x], iy = in[y];
        if(ix > iy)
            swap(ix, iy);
        return seg.prod(ix, iy + 1).second;
    }

  private:
    void dfs(G &g, int now, int prev, int depth) {
        seg.set(id, {depth, now});
        in[now] = id++;
        for(auto nex : g[now]) {
            if(nex == prev)
                continue;
            dfs(g, nex, now, depth + 1);
        }
        seg.set(id, {depth - 1, prev});
        out[now] = id++;
    }
};