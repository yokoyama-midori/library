#pragma once
#include "../template.hpp"
// dist : distance from d1
template <class TreeType> struct TreeDiamter {
    TreeType &g;
    using T = typename TreeType::cost_type;
    vector<T> dist;
    int d1, d2;
    TreeDiamter(TreeType &g) : g(g), dist(g.size(), -1) {
        d1 = bfs(0);
        dist = vector<T>(g.size(), -1);
        d2 = bfs(d1);
    }
    TreeDiamter() = default;
    vector<int> get_path() const {
        vector<int> res = {d2};
        int cur = d2;
        while(cur != d1) {
            for(auto &e : g[cur]) {
                if(dist[e.to] + e.cost == dist[cur]) {
                    cur = e.to;
                    res.emplace_back(cur);
                    break;
                }
            }
        }
        ranges::reverse(res);
        return res;
    }

  private:
    int bfs(int root) {
        queue<int> que;
        que.push(root);
        dist[root] = 0;
        while(que.size()) {
            int cur = que.front();
            que.pop();
            for(auto &e : g[cur]) {
                if(dist[e.to] != -1)
                    continue;
                dist[e.to] = dist[cur] + e.cost;
                que.push(e.to);
            }
        }
        return ranges::max_element(dist) - begin(dist);
    }
};
