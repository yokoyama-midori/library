#pragma once
#include "template.hpp"
// https://ei1333.github.io/library/graph/graph-template.hpp
template <class T = ll> struct Edge {
    int from, to;
    T cost;
    int idx;
    Edge() = default;
    Edge(int from, int to, T cost = 1, int idx = -1)
        : from(from), to(to), cost(cost), idx(idx) {}
};
template <class T = ll> struct Graph {
    vector<vector<Edge<T>>> g;
    int es; // edge_size
    Graph(int n) : g(n), es(0) {};
    int size() const { return ssize(g); }
    void add_directed_edge(int from, int to, T cost = 1) {
        g[from].emplace_back(from, to, cost, es++);
    }
    void add_edge(int from, int to, T cost = 1) {
        g[from].emplace_back(from, to, cost, es);
        g[to].emplace_back(to, from, cost, es++);
    }
    vector<Edge<T>> &operator[](const int &k) { return g[k]; }
    const vector<Edge<T>> &operator[](const int &k) const { return g[k]; }
    void read(int m, int padding = -1, bool weighted = false,
              bool directed = false) {
        rep(i, m) {
            int a, b;
            T c(1);
            cin >> a >> b;
            a += padding;
            b += padding;
            if(weighted)
                cin >> c;
            if(directed)
                add_directed_edge(a, b, c);
            else
                add_edge(a, b, c);
        }
    }
};
