// competitive-verifier: PROBLEM https://yukicoder.me/problems/no/1634
#include "data_structure/hash-map-variable-length.hpp"
void solve() {
    LL(n, k);
    vl c(10);
    rep1(i, 9) { cin >> c[i]; }
    ll half = n / 2;
    ll ans = 0;
    auto make_map = [&k](vl &x, const ll base = 1) {
        HashMap<ll> mp;
        do {
            ll now = 0;
            for(auto i : x) {
                now = 10 * now + i * base;
                now %= k;
            }
            mp[now]++;
        } while(next_permutation(all(x)));
        return mp;
    };
    ll ten = [&] {
        ll res = 1;
        rep(i, half) res *= 10;
        return res % k;
    }();
    vl cnt = {0};
    auto cul = [&]() {
        vl x, y;
        rep1(i, 9) {
            rep(j, cnt[i]) x.push_back(i);
            rep(j, c[i] - cnt[i]) y.push_back(i);
        }
        auto mx = make_map(x, ten);
        auto my = make_map(y);
        for(auto [key, val] : mx.enumerate()) {
            ll rem = key ? k - key : 0;
            ans += my[rem] * val;
        }
    };
    auto dfs = [&](auto &self, int sum) {
        if(ssize(cnt) == 10) {
            if(sum == n - half) {
                cul();
            }
            return;
        }
        ll num = ssize(cnt);
        rep(i, c[num] + 1) {
            if(sum + i > n)
                break;
            cnt.push_back(i);
            self(self, sum + i);
            cnt.pop_back();
        }
    };
    dfs(dfs, 0);
    print(ans);
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll t = 1;
    rep(_, t) solve();
}
