#define PROBLEM "https://atcoder.jp/contests/abc373/tasks/abc373_e"
#include "dp/cumulative-sum.hpp"
#include "template.hpp"
void solve() {
    LL(n, m, k);
    vl a(n), ord(n);
    iota(all(ord), 0);
    input(a);
    sort(all(ord), [&a](ll i, ll j) { return a[i] < a[j]; });
    CumulativeSum<ll> cs(n);
    rep(i, n) { cs.add(i, a[ord[i]]); }
    sort(all(a));
    cs.build();
    auto check = [&](ll i, ll plus) {
        if(n == m)
            return true;
        ll x = cs[i] + plus;
        ll cnt = upper_bound(all(a), x) - begin(a);
        // x+1 以上のインデックス
        if(n - cnt >= m) {
            return false;
        }
        if(i >= n - m) {
            ll ness = cs.sum(0, n - m - 1) + (x + 1) * (cnt - (n - m - 1)) +
                      cs.sum(cnt, n);
            ness--;
            return ness > k;
        } else {
            ll ness = cs.sum(0, n - m) + (x + 1) * (cnt - (n - m)) +
                      cs.sum(cnt, n) + plus;
            return ness > k;
        }
    };
    vl ans(n);
    rep(i, n) {
        if(!check(i, k - cs.all_sum())) {
            ans[ord[i]] = -1;
            continue;
        }
        ll ok = k - cs.all_sum(), ng = -1;
        while(ok > ng + 1) {
            ll mid = (ok + ng) / 2;
            if(check(i, mid)) {
                ok = mid;
            } else
                ng = mid;
        }
        ans[ord[i]] = ok;
    }
    print(ans);
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}