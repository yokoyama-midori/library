#pragma once
#include "../graph/graph-template.hpp"
#include "../template.hpp"
/**
 * @brief ブロックカット木的な
 * https://maspypy.github.io/library/graph/block_cut.hpp
 * https://twitter.com/noshi91/status/1529858538650374144
 * N頂点の無向グラフがC個の二重連結成分を持つとき(N+C)頂点の森を作る
 * [0,N)のidxは元のグラフの頂点を表し[N,N+C)のidxは二重連結成分を表す
 * 辺(u,N+v)は頂点uがv番目の二重連結成分に属することを表す
 * 関節点<->次数2以上
 */
template <class G> Graph<bool> block_cut_tree(const G &g) {
    int n = g.size();
    Graph<bool> tree(n);
    vector<int> low(n, -1), ord(n, -1);
    int id = 0;
    vector<int> tmp;
    tree.g.reserve(2 * n);
    tmp.reserve(n);
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
                    int k = tree.size();
                    tree.g.emplace_back();
                    tree.add_edge(cur, k);
                    while(ssize(tmp) > sz) {
                        tree.add_edge(tmp.back(), k);
                        tmp.pop_back();
                    }
                }
            } else {
                chmin(low[cur], ord[to]);
            }
        }
        if(p == -1) {
            int k = tree.size();
            tree.g.emplace_back();
            for(auto &i : tmp)
                tree.add_edge(i, k);
            tmp.clear();
        }
    };
    for(int i = 0; i < n; ++i) {
        if(ord[i] == -1)
            dfs(dfs, i, -1);
    }
    return tree;
}