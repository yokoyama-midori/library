#include "../template.hpp"
// https://kokiymgch.hatenablog.com/entry/2018/01/27/235959
// https://www.slideshare.net/wata_orz/ss-12131479
// TODO ↓　hist辺りで何やってるか理解する
// https://nyaannyaan.github.io/library/graph/chromatic-number.hpp
// https://ei1333.github.io/library/graph/others/chromatic-number.hpp
#include <atcoder/modint>
template <class T> int ChromaticNumber(vector<vector<T>> &g) {
    using mint = atcoder::modint;
    // g 隣接行列
    ll n = g.size();
    vl adj(n, 0);
    rep(i, n) {
        adj[i] |= 1LL << i;
        for(ll j = i + 1; j < n; j++)
            if(g[i][j]) {
                adj[j] |= 1LL << i;
                adj[i] |= 1LL << j;
            }
    }
    vl ind_cnt(1LL << n, 0);
    // ind_cnt[s] = sの部分集合であって、独立なものの数
    ind_cnt[0] = 1;
    for(ll s = 1; s < (1LL << n); s++) {
        ll i = __builtin_ctz(s);
        // sの下からi桁目が(初めて)1
        ll j = s & (s - 1);
        // j = s ^ (1LL << i)
        ind_cnt[s] = ind_cnt[j] + ind_cnt[j & (~adj[i])];
        // ind_cnt[s] = ind_cnt[j](iを使わない) + ind_cnt[..](iを使う)
        // iを使う場合iと隣接した頂点は使えないので .. = j & (~adj[i])
    }
    ll res = n;
    vector<int> ps = {1000000007, 1000000009};
    for(auto &p : ps) {
        mint::set_mod(p);
        rep(k, n) {
            mint cc = 0;
            ll s = (1LL << n) - 1;
            for(ll t = s;; t = (t - 1) & s) {
                ll sign = n - __popcount(t);
                cc += ((sign & 1) ? -1 : 1) * mint(ind_cnt[t]).pow(k);
                if(t == 0)
                    break;
            }
            if(cc.val()) {
                chmin(res, k);
                break;
            }
        }
    }
    return res;
}