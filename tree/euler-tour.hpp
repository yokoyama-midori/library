#pragma once
#include "../data-structure/sparse-table.hpp"
#include "../template.hpp"
// https://maspypy.com/euler-tour-%E3%81%AE%E3%81%8A%E5%8B%89%E5%BC%B7
// https://nyaannyaan.github.io/library/tree/euler-tour.hpp

template <class G> struct EulerTour {
    int root, id;
    vector<int> in, out, dep;
    using pii = pair<int, int>; // depth,vartex
    SparseTable<pii, [](pii a, pii b) { return a.first < b.first ? a : b; }>
        rmq;
    EulerTour(G &g, int root = 0)
        : root(root), id(0), in(g.size(), -1), out(g.size(), -1),
          dep(g.size(), 0), rmq([&] {
              vector<pii> vec;
              vec.reserve(2 * g.size());
              dfs(g, root, -1, vec);
              return vec;
          }()) {}
    int lca(int x, int y) const {
        int ix = in[x], iy = in[y];
        if(ix > iy)
            swap(ix, iy);
        return rmq.prod(ix, iy + 1).second;
    }
    int dist(int x, int y) const {
        int l = lca(x, y);
        return dep[x] + dep[y] - 2 * dep[l];
    }

  private:
    void dfs(G &g, int now, int prev, vector<pii> &vec) {
        vec.push_back({dep[now], now});
        in[now] = id++;
        for(auto nex : g[now]) {
            if(nex == prev)
                continue;
            dep[nex] = dep[now] + 1;
            dfs(g, nex, now, vec);
        }
        vec.push_back({dep[now] - 1, prev});
        out[now] = id++;
    }
};