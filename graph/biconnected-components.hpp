#pragma once
#include "../template.hpp"
/**
 * @brief 二重頂点連結成分分解
 * 連結・単純でなくても良い
 * 各辺と関節点以外の頂点はちょうど一つの連結成分に属する、関節点は複数の連結成分に属する
 * groupsに連結成分ごとの頂点集合が入る
 * 二重辺連結分解より非自明
 * https://www.hackerearth.com/practice/algorithms/graphs/biconnected-components/tutorial/
 * をよく読む
 */
template <class G> struct BiConnectedComponents {
    const G &g;
    vector<int> low, ord;
    using T = typename G::cost_type;
    vector<vector<int>> groups;
    BiConnectedComponents(const G &g)
        : g(g), low(g.size(), -1), ord(g.size(), -1), comp_id(g.size(), -1) {
        for(int i = 0; i < g.size(); ++i) {
            if(ord[i] == -1) {
                if(g[i].size())
                    dfs(i, -1);
                else
                    groups.emplace_back(vi({i}));
            }
        }
    }

  private:
    int id = 0;
    vector<Edge<T>> tmp;
    vector<int> comp_id;
    void dfs(int cur, int p) {
        ord[cur] = low[cur] = id++;
        bool second = false;
        for(auto &to : g[cur]) {
            if(to == p and !exchange(second, true))
                continue;
            if(ord[to] != -1 and ord[to] >= ord[cur])
                continue;
            tmp.emplace_back(to);
            if(ord[to] == -1) {
                dfs(to, cur);
                chmin(low[cur], low[to]);
            } else {
                chmin(low[cur], ord[to]);
            }
            if(low[to] >= ord[cur]) {
                int k = ssize(groups);
                groups.emplace_back();
                for(bool end = false; !end;) {
                    end = tmp.back().idx == to.idx;
                    int x = tmp.back().from, y = tmp.back().to;
                    if(chmax(comp_id[x], k)) {
                        groups.back().emplace_back(x);
                    }
                    if(chmax(comp_id[y], k)) {
                        groups.back().emplace_back(y);
                    }
                    tmp.pop_back();
                }
            }
        }
    }
};
