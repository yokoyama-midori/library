#pragma once
#include "../template.hpp"
#include "./compress.hpp"
#include "./lazy-segtree.hpp"
template <class T = int, class ans_type = ll> struct RectangleUnionArea {
  private:
    using S = pair<T, T>;
    static S op(S s, S t) {
        if(s.first == t.first)
            return S(s.first, s.second + t.second);
        return s.first < t.first ? s : t;
    }
    static S e() {
        return S(numeric_limits<T>::max(), 0);
    }
    using F = T;
    static F comp(F f, F g) {
        return f + g;
    }
    static S mapping(F f, S s) {
        s.first += f;
        return s;
    }
    static F id() {
        return 0;
    }
    struct Rectangle {
        T l, d, r, u;
    };
    vector<Rectangle> rectangles;

  public:
    void add_rect(T l, T d, T r, T u) {
        assert(l < r and d < u);
        rectangles.emplace_back(l, d, r, u);
    }
    ans_type cul() {
        int n = rectangles.size();
        if(n == 0)
            return 0;
        Compress<T> cp;
        vector<int> ord(2 * n);
        iota(begin(ord), end(ord), -n);
        // 下から平面走査 i : d[i]でin, -i-1 : u[i]でout
        for(auto [l, d, r, u] : rectangles)
            cp.add(l), cp.add(r);
        cp.build();
        ranges::sort(ord, [&](int i, int j) {
            T x = i < 0 ? rectangles[-i - 1].u : rectangles[i].d;
            T y = j < 0 ? rectangles[-j - 1].u : rectangles[j].d;
            return x < y;
        });
        lazy_segtree<S, op, e, F, mapping, comp, id> seg(cp.size());
        ans_type ans = 0;
        for(int i = 0; i + 1 < cp.size(); i++) {
            seg.set(i, S(0, cp[i + 1] - cp[i]));
        }
        seg.set(cp.size() - 1, S(0, 0));
        ans_type width = cp[cp.size() - 1] - cp[0];
        for(int i = 0; i < 2 * n - 1; i++) {
            T x = ord[i] < 0 ? rectangles[-ord[i] - 1].u : rectangles[ord[i]].d;
            T y = ord[i + 1] < 0 ? rectangles[-ord[i + 1] - 1].u
                                 : rectangles[ord[i + 1]].d;
            if(ord[i] < 0) {
                auto &rec = rectangles[-ord[i] - 1];
                seg.apply(cp.get(rec.l), cp.get(rec.r), -1);
            } else {
                auto &rec = rectangles[ord[i]];
                seg.apply(cp.get(rec.l), cp.get(rec.r), 1);
            }
            ans += (y - x) * (width - (seg.all_prod_commute().first == 0
                                           ? seg.all_prod_commute().second
                                           : 0));
        }
        return ans;
    }
};