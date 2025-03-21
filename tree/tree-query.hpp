#pragma once
#include "../graph/graph-template.hpp"
// https://nyaannyaan.github.io/library/tree/tree-query.hpp
template <class T> struct Tree {
    int n, root, lg;
    Graph<T> &g;
    vector<int> depth;
    vector<vector<int>> table;
    Tree(Graph<T> &g, int root = 0)
        : n(g.size()), root(root), lg(bit_width((unsigned)n)), g(g),
          depth(n, 0), table(lg, vector<int>(n, -1)) {
        dfs(root, -1);
    }
    // root -> -1
    int par(int u) const { return table[0][u]; }
    int kth_ancestor(int u, int k) const {
        if(depth[u] < k)
            return -1;
        while(k) {
            int t = countr_zero((unsigned)k);
            u = table[t][u], k ^= 1 << t;
        }
        return u;
    }
    int lca(int s, int t) const {
        if(depth[s] > depth[t])
            swap(s, t);
        t = kth_ancestor(t, depth[t] - depth[s]);
        if(s == t)
            return s;
        for(int i = lg - 1; i >= 0; i--) {
            if(table[i][s] != table[i][t])
                s = table[i][s], t = table[i][t];
        }
        return table[0][s];
    }
    // sからt方向にk進む
    // dist(s,t) < k なら -1
    int jump(int s, int t, int k) const {
        int lc = lca(s, t);
        if(depth[s] - depth[lc] >= k)
            return kth_ancestor(s, k);
        k = depth[s] + depth[t] - 2 * depth[lc] - k;
        if(k >= 0 and depth[t] - depth[lc] >= k)
            return kth_ancestor(t, k);
        return -1;
    }

  private:
    void dfs(int cur, int par) {
        for(int i = 0; i + 1 < lg and table[i][cur] != -1; i++)
            table[i + 1][cur] = table[i][table[i][cur]];
        for(auto &to : g[cur]) {
            if(to == par)
                continue;
            depth[to] = depth[cur] + 1;
            table[0][to] = cur;
            dfs(to, cur);
        }
    }
};