#define PROBLEM "https://atcoder.jp/contests/arc123/tasks/arc123_d"
#include "data_structure/slope-trick.hpp"
void solve() {
    LL(n);
    vl a(n + 1, 0);
    rep1(i, n) cin >> a[i];
    SlopeTrick st;
    rep1(i, n) {
        ll c = min(0LL, a[i - 1] - a[i]);
        st.shift(-c);
        st.clear_right();
        st.add_abs(0);
        st.add_abs(a[i]);
    }
    print(st.min_f);
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}