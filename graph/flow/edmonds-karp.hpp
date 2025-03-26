/**
 * @brief Edmonds Karp(最大流)
 * @see
 * https://github.com/kth-competitive-programming/kactl/blob/main/content/graph/EdmondsKarp.h
 */
#pragma once
#include "../../template.hpp"
// graphにたいして破壊的
template <class T>
T edmonds_karp(vector<unordered_map<int, T>> &graph, int source, int sink) {
    assert(source != sink);
    T flow = 0;
    vector<int> par(graph.size()), q = par;
    while(true) {
        ranges::fill(par, -1);
        par[source] = 0;
        int ptr = 1;
        q[0] = source;
        rep(i, 0, ptr) {
            int x = q[i];
            for(auto e : graph[x]) {
                if(par[e.first] == -1 and e.second > 0) {
                    par[e.first] = x;
                    q[ptr++] = e.first;
                    if(e.first == sink)
                        goto out;
                }
            }
        }
        return flow;
    out:
        T inc = numeric_limits<T>::max();
        for(int y = sink; y != source; y = par[y])
            chmin(inc, graph[par[y]][y]);
        flow += inc;
        for(int y = sink; y != source; y = par[y]) {
            int p = par[y];
            if((graph[p][y] -= inc) == 0) {
                graph[p].erase(y);
            }
            graph[y][p] += inc;
        }
    }
}
