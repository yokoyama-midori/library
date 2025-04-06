// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/kth_root_integer
#include "../../../number-theory/kth-root-integer.hpp"
#include "../../../template.hpp"
void solve() {
    uint64_t a, k;
    cin >> a >> k;
    print(kth_root_integer(a, k));
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    INT(t);
    while(t--)
        solve();
}
