#pragma once
#include "../template.hpp"
#include "./graph/graph-template.hpp"
/**
 * @brief Low Link(橋・関節点)
 * articulation(関節点) 削除すると連結成分が増える頂点
 * bridge(橋) 削除すると連結成分が増える辺(u,v)(u < v)
 * 未ソート
 */
template <class G> struct LowLink {
    const G &g;
    vector<int> ord, low, articulation;
    vector<pair<int, int>> bridge;
    LowLink(const G &g) : g(g), ord(g.size(), -1), low(g.size()) {
        for(int i = 0; i < ssize(g); ++i) {
            if(ord[i] == -1) {
                dfs(i, -1);
            }
        }
    }

  private:
    int id = 0;
    void dfs(int cur, int p) {
        ord[cur] = low[cur] = id++;
        bool is_articulation = false,
             second =
                 false; // 多重辺がある場合にDFS木の辺と後退辺を区別する必要がる
        int cnt = 0;
        for(auto &to : g[cur]) {
            if(to == p and !exchange(second, true))
                continue;
            if(ord[to] == -1) {
                dfs(to, cur);
                ++cnt;
                chmin(low[cur], low[to]);
                is_articulation |= p != -1 and ord[cur] <= low[to];
                if(ord[cur] < low[to]) {
                    bridge.emplace_back(minmax(cur, (int)to));
                }
            } else {
                chmin(low[cur], ord[to]);
            }
        }
        is_articulation |= p == -1 and cnt > 1;
        if(is_articulation)
            articulation.emplace_back(cur);
    }
};