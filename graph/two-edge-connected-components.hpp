#pragma once
#include "../template.hpp"
#include "./lowlink.hpp"
template <class G> struct TwoEdgeConnectedComponents {
    const G &g;
    LowLink<G> low;
    vector<int> comp;
    int k;
    vector<vector<int>> groups;
    G tree; // 非連結なら森
    TwoEdgeConnectedComponents(const G &g)
        : g(g), low(g), comp(g.size(), -1), k(0) {
        for(int i = 0; i < g.size(); ++i) {
            if(comp[i] == -1)
                dfs(i, -1);
        }
        groups.resize(k);
        for(int i = 0; i < g.size(); ++i) {
            groups[comp[i]].emplace_back(i);
        }
        tree = G(k);
        for(auto [u, v] : low.bridge)
            tree.add_edge(comp[u], comp[v]); // cost未対応
    }
    int operator[](int i) const { return comp[i]; }
    void dfs(int cur, int p) {
        if(p >= 0 and low.low[cur] <= low.ord[p]) {
            comp[cur] = comp[p];
        } else {
            comp[cur] = k++;
        }
        for(auto &to : g[cur]) {
            if(comp[to] == -1)
                dfs(to, cur);
        }
    }
};