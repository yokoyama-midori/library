#pragma once
#include "template.hpp"
// https://nyaannyaan.github.io/library/data-structure/rollback-union-find.hpp.html
// snapshot/rollback いるかな？
struct RollbackUnionFind {
    int n;
    vector<int> p;
    using T = tuple<int, int, int, int>;
    stack<T> history;
    RollbackUnionFind(int n) : n(n), p(n, -1) {}
    int leader(int x) {
        while(p[x] >= 0)
            x = p[x];
        return x;
    }
    int merge(int x, int y) {
        x = leader(x), y = leader(y);
        history.push(T(x, y, p[x], p[y]));
        if(x == y)
            return x;
        if(-p[x] < -p[y])
            swap(x, y);
        p[x] += p[y];
        p[y] = x;
        return x;
    }
    void undo(int k = 1) {
        assert(history.size() >= k);
        while(k--) {
            auto [x, y, px, py] = history.top();
            history.pop();
            p[x] = px, p[y] = py;
        }
    }
    int size(int x) { return -p[leader(x)]; }
    bool same(int x, int y) { return leader(x) == leader(y); }
};