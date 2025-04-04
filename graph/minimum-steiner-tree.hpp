#pragma once
#include "graph-template.hpp"
/**
 * @brief 最小シュタイナー木
 * @see https://www.slideshare.net/wata_orz/ss-12131479#50
 * @see
 * https://ei1333.github.io/library/graph/others/minimum-steiner-tree.hpp.html
 */
template <class T> struct MinimumSteinerTree {
    int n, k;
    // 必要に応じて&外す
    const Graph<T> &g;
    const vector<int> &terminal;
    T cost;
    const T infty = numeric_limits<T>::max();
    vector<vector<T>> dp;
    vector<vector<pair<int, int>>> prev;
    MinimumSteinerTree(const Graph<T> &g, const vector<int> &terminal)
        : n(g.size()), k(terminal.size()), g(g), terminal(terminal), cost(0),
          dp(1 << k, vector<T>(n, infty)),
          prev(1 << k, vector<pair<int, int>>(n)) {
        assert(!terminal.empty());
        rep(i, k) { dp[1 << i][terminal[i]] = 0; }
        rep(bit, 1, 1 << k) {
            rep(i, n) {
                for(int sub = (bit - 1) & bit; sub > 0; sub = (sub - 1) & bit) {
                    if(dp[sub][i] != infty and dp[bit ^ sub][i] != infty)
                        if(chmin(dp[bit][i], dp[sub][i] + dp[bit ^ sub][i])) {
                            prev[bit][i] = {sub, -1};
                        }
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
                for(int i = 0; i < ssize(g[v]); ++i) {
                    auto &e = g[v][i];
                    T nc = c + e.cost;
                    if(chmin(dp[bit][e.to], nc)) {
                        pq.push(pti(nc, e.to));
                        prev[bit][e.to] = {v, i};
                    }
                }
            }
        }
        cost = dp.back()[terminal.front()];
    }
    // 最小シュタイナー木に使われた辺たちを返す
    // 順序・向きは未定義
    vector<Edge<T>> restore() const {
        vector<Edge<T>> res;
        vector<pair<int, int>> que;
        que.emplace_back((1 << k) - 1, terminal[0]);
        while(!que.empty()) {
            auto [bit, cur] = que.back();
            que.pop_back();
            if(dp[bit][cur] == T(0))
                continue;
            auto [x, y] = prev[bit][cur];
            if(y == -1) {
                que.emplace_back(x, cur);
                que.emplace_back(bit ^ x, cur);
            } else {
                res.emplace_back(g[x][y]);
                que.emplace_back(bit, x);
            }
        }
        return res;
    }
};