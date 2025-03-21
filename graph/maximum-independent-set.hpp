#pragma once
#include "../graph/graph-template.hpp"
// https://maspypy.github.io/library/graph/maximum_independent_set.hpp
// https://yukicoder.me/problems/no/382
// https://www.slideshare.net/wata_orz/ss-12131479 より高速
// n=120 5sec
template <int n_max, class edge_type>
vector<int> max_independent_set(int n, const vector<edge_type> &edges) {
    using BS = bitset<n_max>;
    BS res;
    auto dfs = [&n, &res](auto &&dfs, vector<BS> nbd, BS rem, BS cur) {
        while(1) {
            bool upd = false;
            for(int i : views::iota(0, n) | views::filter([&](int i) {
                            return rem[i] and (rem & nbd[i]).count() <= 1;
                        })) {
                rem[i] = 0;
                cur[i] = 1;
                upd = true;
                rem &= ~nbd[i];
            }
            if(!upd)
                break;
        }
        if(rem.none()) {
            if(res.count() < cur.count())
                res = cur;
            return;
        }
        int max_idx = ranges::max(
            views::iota(0, n) | views::filter([&](int i) { return rem[i]; }),
            {}, [&](int i) { return (rem & nbd[i]).count(); });
        assert(rem[max_idx] and nbd[max_idx].any());
        rem[max_idx] = 0;
        // max_idx 使わない
        if(nbd[max_idx].count() > 2) // 2以下->全部2->どれ使っても一緒
            dfs(dfs, nbd, rem, cur);
        // 使う
        cur[max_idx] = 1;
        rem &= ~nbd[max_idx];
        dfs(dfs, nbd, rem, cur);
    };
    vector<BS> nbd(n);
    BS rem;
    for(int i : views::iota(0, n))
        rem[i] = 1;
    for(auto &e : edges) {
        assert(0 <= min(e, e.from) and max(e, e.from) < n);
        if(e.from == e)
            rem[e] = 0;
        nbd[e.from][e] = nbd[e][e.from] = 1;
    }
    dfs(dfs, nbd, rem, BS(0));
    vector<int> res_v;
    for(int i :
        views::iota(0, n) | views::filter([&](int i) { return res[i]; }))
        res_v.emplace_back(i);
    return res_v;
}