// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/associative_array
#include "../../../data_structure/hash-map-variable-length.hpp"
#include "../../../template.hpp"
void solve() {
    LL(q);
    HashMap<ll> a(q);
    // or HashMap<ll> a;
    rep(_, q) {
        LL(flag, k);
        if(flag == 0) {
            LL(v);
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