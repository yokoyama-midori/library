#pragma once
#include "../graph/graph-template.hpp"
#include "../template.hpp"
// https://ei1333.github.io/library/graph/others/cycle-detection.hpp
// 辺素なサイクルを1つ返す なければ空
// Edgeのidxが必要
// 有向/無効 どちらでもok
template <class T> vector<Edge<T>> cycle_detection(const Graph<T> &g) {
    int n = g.size();
    using edge_type = Edge<T>;
    vector<char> used(n, 0);
    vector<edge_type> prev(n, edge_type(-1, -1)), cycle;
    auto dfs = [&](auto &&dfs, edge_type cur) -> bool {
        used[cur] = 1;
        for(edge_type e : g[cur]) {
            if(e.idx == cur.idx)
                continue;
            prev[e] = e;
            if(used[e] == 0) {
                if(dfs(dfs, e)) {
                    return true;
                }
            } else if(used[e] == 1) {
                int s = e.to;
                while(cycle.empty() or e.to != s) {
                    cycle.emplace_back(e);
                    e = prev[e.from];
                }
                return true;
            }
        }
        used[cur] = 2;
        return false;
    };
    rep(i, n) {
        if(cycle.empty() and used[i] == 0)
            dfs(dfs, edge_type(-1, i));
    }
    ranges::reverse(cycle);
    return cycle;
}
