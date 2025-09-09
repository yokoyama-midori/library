// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/associative_array
#include "../../../data-structure/hash-map-variable-length.hpp"
#include "../../../template.hpp"
void solve() {
    INT(q);
    HashMap<ll> a(q);
    // or HashMap<ll> a;
    bool flag;
    ll k, v;
    rep(q) {
        input(flag, k);
        if(flag == 0) {
            input(v);
            a[k] = v;
        } else {
            print(a[k]);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}