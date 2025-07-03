#pragma once
#include "../template.hpp"
// https://nyaannyaan.github.io/library/data-structure/rollback-union-find.hpp.html
// snapshot/rollback いるかな？
struct UnionFindWithUndo {
    int n, num_groups;
    vector<int> p;
    using T = tuple<int, int, int, int>;
    stack<T> history;
    UnionFindWithUndo(int n) : n(n), num_groups(n), p(n, -1) {}
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
        --num_groups;
        if(-p[x] < -p[y])
            swap(x, y);
        p[x] += p[y];
        p[y] = x;
        return x;
    }
    void undo(int k = 1) {
        assert((int)history.size() >= k);
        while(k--) {
            auto [x, y, px, py] = history.top();
            history.pop();
            p[x] = px, p[y] = py;
            if(x != y)
                ++num_groups;
        }
    }
    int size(int x) { return -p[leader(x)]; }
    bool same(int x, int y) { return leader(x) == leader(y); }
};