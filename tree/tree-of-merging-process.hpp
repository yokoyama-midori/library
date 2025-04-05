#pragma once
#include "../data-structure/union-find.hpp"
#include "../template.hpp"
template <class T>
pair<vector<vector<T>>, vector<T>>
tree_of_merging_process(int n, vector<pair<T, T>> &edges) {
    vector<vector<T>> res(2 * n - 1);
    vector<T> root(2 * n - 1);
    iota(begin(root), end(root), 0);
    UnionFind dsu(n);
    int aux = n; // マージする際親とする仮の頂点
    for(auto [i, j] : edges) {
        i = dsu.leader(i), j = dsu.leader(j);
        if(i == j)
            continue;
        res[aux].emplace_back(root[i]);
        res[aux].emplace_back(root[j]);
        root[dsu.merge(i, j)] = aux++;
    }
    assert(aux == 2 * n - 1);
    rep(i, n, 2 * n - 1) for(auto j : res[i]) root[j] = i;
    // 各辺について対応するaux idxを返す？
    // 連結にさせる？
    return {res, root};
}