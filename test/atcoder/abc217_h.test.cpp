#define PROBLEM "https://atcoder.jp/contests/abc217/tasks/abc217_h"
#include "data_structure/slope-trick.hpp"
void solve() {
    LL(n);
    vl t(n + 1), d(n + 1), x(n + 1);
    rep1(i, n) cin >> t[i] >> d[i] >> x[i];
    SlopeTrick st;
    rep(i, 2 * n) st.add_abs(0);
    rep1(i, n) {
        ll dt = t[i] - t[i - 1];
        st.shift(-dt, dt);
        if(d[i]) {
            st.add_x_minus_a(x[i]);
        } else {
            st.add_a_minus_x(x[i]);
        }
    }
    print(st.min_f);
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}