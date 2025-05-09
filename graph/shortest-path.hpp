#pragma once
#include "../graph/graph-template.hpp"
#include "../template.hpp"
template <class T> struct ShortestPath {
    int n;
    const Graph<T> &g;
    vector<int> from;
    vector<T> dist;
    ShortestPath(const Graph<T> &g, int s)
        : n(g.size()), g(g), from(n, -1), dist(n, -1) {
        using Pti = pair<T, int>;
        priority_queue<Pti, vector<Pti>, greater<Pti>> que;
        que.push(Pti(0, s));
        dist[s] = 0;
        while(que.size()) {
            auto [cost, idx] = que.top();
            que.pop();
            if(dist[idx] < cost)
                continue;
            for(auto to : g[idx]) {
                if(dist[to] == -1 or cost + to.cost < dist[to]) {
                    dist[to] = cost + to.cost;
                    que.push(Pti(dist[to], to));
                    from[to] = idx;
                }
            }
        }
    }
    const T &operator[](int i) const { return dist[i]; }
    vector<int> restore(int t) const {
        assert(dist[t] != -1);
        vector<int> res = {t};
        while(from[t] != -1) {
            t = from[t];
            res.emplace_back(t);
        }
        ranges::reverse(res);
        return res;
    }
};
