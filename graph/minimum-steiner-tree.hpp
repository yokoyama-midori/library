#pragma once
#include "../graph/graph-template.hpp"
template <class T = ll> struct MinimumSteinerTree {
    int n, k;
    vector<int> terminal;
    T cost;
    const T infty = numeric_limits<T>::max();
    vector<vector<T>> dp;
    MinimumSteinerTree(const Graph<T> &g, const vector<int> terminal)
        : n(g.size()), k(terminal.size()), terminal(terminal), cost(0),
          dp(1 << k, vector<T>(n, infty)) {
        assert(!terminal.empty());
        rep(i, k) { dp[1 << i][terminal[i]] = 0; }
        rep(bit, 1, 1 << k) {
            rep(i, n) {
                for(int sub = (bit - 1) & bit; sub > 0; sub = (sub - 1) & bit) {
                    if(dp[sub][i] != infty and dp[bit ^ sub][i] != infty)
                        chmin(dp[bit][i], dp[sub][i] + dp[bit ^ sub][i]);
                }
            }
            using pti = pair<T, int>;
            priority_queue<pti, vector<pti>, greater<pti>> pq;
            rep(i, n) pq.push(pti(dp[bit][i], i));
            while(pq.size()) {
                auto [c, v] = pq.top();
                pq.pop();
                if(c != dp[bit][v] or c == infty)
                    continue;
                for(auto &e : g[v]) {
                    T nc = c + e.cost;
                    if(chmin(dp[bit][e.to], nc))
                        pq.push(pti(nc, e.to));
                }
            }
        }
        cost = dp.back()[terminal.front()];
    }
};