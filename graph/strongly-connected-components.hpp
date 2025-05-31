#pragma once
#include "../template.hpp"
/**
 * @brief 強連結成分分解(Tarjan)
 * https://en.wikipedia.org/wiki/Tarjan%27s_strongly_connected_components_algorithm
 * comp[i] : 頂点iが属する強連結成分のid
 * groups : 各強連結成分の頂点集合
 * トポロジカルソートソート済み
 * cul_dag() : 強連結成分を1つの頂点に縮約したときのDAGを作る DAGの頂点iが元のグラフのgroups[i]に対応
 *             verify:https://atcoder.jp/contests/abc357/submissions/66283840
 */
template <class G> struct StronglyConnectedComponents {
    const G &g;
    vector<int> comp;
    vector<vector<int>> groups;
    StronglyConnectedComponents(const G &g)
        : g(g), comp(g.size()), low(g.size()), ord(g.size(), -1) {
        for(int i = 0; i < g.size(); ++i) {
            if(ord[i] == -1) {
                dfs(i);
            }
        }
        ranges::reverse(groups);
        for(int i = 0; i < ssize(groups); ++i) {
            for(auto j : groups[i])
                comp[j] = i;
        }
    }
    G cul_dag() const {
        G dag(groups.size());
        for(int i = 0; i < g.size(); ++i) {
            int x = comp[i];
            for(auto &to : g[i]) {
                int y = comp[to];
                if(x != y) {
                    dag.add_directed_edge(x, y, to.cost);
                }
            }
        }
        return dag;
    }

  private:
    int id = 0;
    vector<int> low, ord; // lowは計算後g.size()に置き換えられる
    vector<int> tmp;
    void dfs(int cur) {
        low[cur] = ord[cur] = id++;
        tmp.emplace_back(cur);
        for(auto &to : g[cur]) {
            if(ord[to] == -1) {
                dfs(to);
                chmin(low[cur], low[to]);
            } else {
                chmin(low[cur], ord[to]);
            }
        }
        if(low[cur] == ord[cur]) {
            groups.emplace_back();
            while(true) {
                groups.back().emplace_back(tmp.back());
                ord[tmp.back()] =
                    g.size(); // 今後訪れる頂点はこの強連結成分とは別の強連結成分に属する
                tmp.pop_back();
                if(groups.back().back() == cur) {
                    break;
                }
            }
        }
    }
};