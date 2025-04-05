#pragma once
#include "../template.hpp"
struct UnionFind {
    int n;
    vector<int> p;
    UnionFind(int n) : n(n), p(n, -1) {}
    int leader(int x) {
        if(p[x] < 0)
            return x;
        return p[x] = leader(p[x]);
    }
    int merge(int x, int y) {
        x = leader(x), y = leader(y);
        if(x == y)
            return x;
        if(-p[x] < -p[y])
            swap(x, y);
        p[x] += p[y];
        p[y] = x;
        return x;
    }
    int size(int x) { return -p[leader(x)]; }
    bool same(int x, int y) { return leader(x) == leader(y); }
};