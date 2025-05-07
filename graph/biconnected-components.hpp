#pragma once
#include "../template.hpp"
#include "./graph-template.hpp"
/**
 * @brief 二重頂点連結成分分解
 * 連結・単純でなくても良い
 * 各辺と関節点以外の頂点はちょうど一つの連結成分に属する、関節点は複数の連結成分に属する
 * block-cut-tree.hppとだいたい同じ
 * https://www.hackerearth.com/practice/algorithms/graphs/biconnected-components/tutorial/
 */
template <class G> vector<vector<int>> biconnected_components(const G &g) {
    int n = g.size();
    vector<vector<int>> res;
    vector<int> low(n, -1), ord(n, -1);
    int id = 0;
    vector<int> tmp;
    auto dfs = [&](auto &dfs, int cur, int p) -> void {
        ord[cur] = low[cur] = id++;
        tmp.emplace_back(cur);
        int cnt = 0;
        for(auto &to : g[cur]) {
            if(to == p)
                continue;
            if(ord[to] == -1) {
                int sz = ssize(tmp);
                ++cnt;
                dfs(dfs, to, cur);
                chmin(low[cur], low[to]);
                if((p == -1 and cnt > 1) or (p != -1 and low[to] >= ord[cur])) {
                    res.emplace_back();
                    res.back().emplace_back(cur);
                    while(ssize(tmp) > sz) {
                        res.back().emplace_back(tmp.back());
                        tmp.pop_back();
                    }
                }
            } else {
                chmin(low[cur], ord[to]);
            }
        }
        if(p == -1) {
            res.emplace_back();
            for(auto &i : tmp)
                res.back().emplace_back(i);
            tmp.clear();
        }
    };
    for(int i = 0; i < n; ++i) {
        if(ord[i] == -1)
            dfs(dfs, i, -1);
    }
    return res;
}
