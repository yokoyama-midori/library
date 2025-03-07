#pragma once
#include "template.hpp"
// https://atcoder.jp/contests/abc222/editorial/2749
// https://nyaannyaan.github.io/library/tree/rerooting.hpp
// TreeType : Graph<Cost>
// MergeFunc : Data(Data,Data)
// ApplyFunc : Data(Data,int from,int to,Cost)
/*
using Data = ;
using Cost = ;
Graph<Cost> g;
Data leaf = ;
auto merge = [](Data a, Data b) {};
auto apply = [](Data data, int from, int to, Cost cost) {};
Rerooting<Data, decltype(g), decltype(merge), decltype(apply)> dp(
    g, merge, apply, leaf);
*/
template <class Data, class TreeType, class MergeFunc, class ApplyFunc>
struct Rerooting {
    const TreeType &g;
    const MergeFunc merge;
    const ApplyFunc apply;
    const Data leaf;
    vector<Data> dp, memo;
    Rerooting(const TreeType &g, MergeFunc merge, ApplyFunc apply, Data leaf)
        : g(g), merge(merge), apply(apply), leaf(leaf), dp(g.size(), leaf),
          memo(g.size(), leaf) {
        dfs1(0, -1);
        dfs2(0, -1, leaf);
    }
    const Data &operator[](int i) const { return dp[i]; }

    void dfs1(int cur, int p) {
        for(auto &d : g[cur]) {
            if(d.to == p)
                continue;
            dfs1(d.to, cur);
            memo[cur] = merge(memo[cur], apply(memo[d.to], d.to, cur, d.cost));
        }
    }
    void dfs2(int cur, int p, const Data &val) {
        vector<Data> ds{val};
        for(auto &d : g[cur]) {
            if(d.to == p)
                continue;
            ds.emplace_back(apply(memo[d.to], d.to, cur, d.cost));
        }
        vector<Data> left(ds.size() + 1, leaf), right(ds.size() + 1, leaf);
        for(int i = 0; i + 1 < left.size(); i++)
            left[i + 1] = merge(left[i], ds[i]);
        for(int i = ssize(right) - 2; 0 < i; i--)
            right[i] = merge(right[i + 1], ds[i]);
        dp[cur] = left.back();
        int idx = 1;
        for(auto &d : g[cur]) {
            if(d.to == p)
                continue;
            Data tmp = merge(left[idx], right[idx + 1]);
            tmp = apply(tmp, cur, d.to, d.cost);
            dfs2(d.to, cur, tmp);
            idx++;
        }
    }
};