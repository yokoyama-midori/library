#define PROBLEM "https://atcoder.jp/contests/abc273/tasks/abc273_d"
#include "data_structure/hash-map-variable-length.hpp"
void solve() {
    LL(h, w, rs, cs, n);
    HashMap<vl> rc, cr;
    rep(i, n) {
        LL(r, c);
        rc[r].emplace_back(c);
        cr[c].emplace_back(r);
    }
    for(auto [key, val] : rc.enumerate())
        sort(all(val));
    for(auto [key, val] : cr.enumerate())
        sort(all(val));
    LL(q);
    rep(_, q) {
        char d;
        ll l;
        cin >> d >> l;
        if(d == 'D') {
            if(!cr.contains(cs)) {
                rs += l;
                goto pr;
            }
            auto &v = cr[cs];
            auto itr = upper_bound(all(v), rs);
            if(itr == v.end() or *itr > rs + l) {
                rs += l;
            } else {
                rs = *itr - 1;
            }
        } else if(d == 'U') {
            if(!cr.contains(cs)) {
                rs -= l;
                goto pr;
            }
            auto &v = cr[cs];
            auto itr = upper_bound(v.begin(), v.end(), rs);
            itr--;
            if(itr < v.begin() or *itr < rs - l) {
                rs -= l;
            } else {
                rs = *itr + 1;
            }
        } else if(d == 'R') {
            if(!rc.contains(rs)) {
                cs += l;
                goto pr;
            }
            auto &v = rc[rs];
            auto itr = upper_bound(all(v), cs);
            if(itr == v.end() or *itr > cs + l) {
                cs += l;
            } else {
                cs = *itr - 1;
            }
        } else if(d == 'L') {
            if(!rc.contains(rs)) {
                cs -= l;
                goto pr;
            }
            auto &v = rc[rs];
            auto itr = upper_bound(v.begin(), v.end(), cs);
            itr--;
            if(itr < v.begin() or *itr < cs - l) {
                cs -= l;
            } else {
                cs = *itr + 1;
            }
        }
    pr:;
        chmax(rs, 1LL);
        chmax(cs, 1LL);
        chmin(cs, w);
        chmin(rs, h);
        print(rs, cs);
    }
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << std::setprecision(16);
    solve();
}