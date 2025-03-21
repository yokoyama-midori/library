#include "../template.hpp"
// Hai Zhou, Narendra Shenoy, and William Nicholls. 2001. Efficient minimum
// spanning tree construction without Delaunay triangulation.
template <class T = long long>
vector<tuple<T, int, int>> manhattan_mst(vector<T> xs, vector<T> ys) {
    // O(N)個の最小全域木の辺の候補{(重み,i,j)}
    assert(ssize(xs) == ssize(ys));
    vector<tuple<T, int, int>> res;
    int n = ssize(xs);
    res.reserve(2 * n);
    vector<int> ord(n);
    iota(all(ord), 0);
    auto cul = [&]() -> void {
        map<T, int, greater<T>> mp;
        for(auto i : ord) {
            for(auto itr = mp.lower_bound(xs[i]); itr != end(mp);
                itr = mp.erase(itr)) {
                int j = itr->second;
                if(xs[j] - ys[j] < xs[i] - ys[i]) {
                    break;
                }
                T dist = (ys[i] - ys[j]) + (xs[i] - xs[j]);
                res.emplace_back(dist, i, j);
            }
            mp[xs[i]] = i;
        }
    };
    rep(cnt, 4) {
        if(cnt & 1) {
            swap(xs, ys);
        } else {
            if(cnt == 2) {
                for(auto &&x : xs)
                    x *= -1;
            }
            sort(all(ord),
                 [&](int i, int j) { return xs[i] + ys[i] < xs[j] + ys[j]; });
        }
        cul();
    }
    sort(all(res));
    return res;
}