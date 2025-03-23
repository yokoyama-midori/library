#pragma once
#include "data_structure/persistent-segtree.hpp"
#include "template.hpp"
// https://nyaannyaan.github.io/library/data-structure-2d/rectangle-sum.hpp
// T 座標の型, (S, op, e) モノイド
template <class T, class S, auto op, auto e> struct rectangle_sum {
    persistent_segtree<S, op, e> seg;
    using pointer = decltype(seg)::node_type *;
    vector<T> xs, ys;
    vector<S> ws;
    vector<pointer> ps;
    rectangle_sum(const vector<T> &xs_, const vector<T> &ys_,
                  const vector<S> &ws_)
        : seg(xs_.size()) {
        assert(xs_.size() == ys_.size() and xs_.size() == ws_.size());
        const int n = xs_.size();
        xs.reserve(n);
        ys.reserve(n);
        ws.reserve(n);
        vector<int> ord(n);
        iota(begin(ord), end(ord), 0);
        ranges::sort(ord, {}, [&xs_](int i) { return xs_[i]; });
        for(auto i : ord) {
            xs.emplace_back(xs_[i]);
            ys.emplace_back(ys_[i]);
            ws.emplace_back(ws_[i]);
        }
        ranges::sort(ord, {}, [&](int i) { return ys[i]; });
        ps.reserve(n + 1);
        ps.emplace_back(seg.build(vector<S>(n, e())));
        for(auto i : ord) {
            ps.emplace_back(seg.set(ps.back(), i, ws[i]));
        }
        ranges::sort(ys);
    };
    // op([l,r)×[0,u))
    S sum(T l, T r, T u) {
        l = lower_bound(begin(xs), end(xs), l) - begin(xs);
        r = lower_bound(begin(xs), end(xs), r) - begin(xs);
        u = lower_bound(begin(ys), end(ys), u) - begin(ys);
        return seg.prod(ps[u], l, r);
    }
    // op([l,r)×[0,u)) - op([l,r)×[0,d))
    // opが足し算じゃない場合は引数3つのsum2回取って勝手にやって
    S sum(T l, T d, T r, T u) {
        l = lower_bound(begin(xs), end(xs), l) - begin(xs);
        r = lower_bound(begin(xs), end(xs), r) - begin(xs);
        d = lower_bound(begin(ys), end(ys), d) - begin(ys);
        u = lower_bound(begin(ys), end(ys), u) - begin(ys);
        return seg.prod(ps[u], l, r) - seg.prod(ps[d], l, r);
    }
};