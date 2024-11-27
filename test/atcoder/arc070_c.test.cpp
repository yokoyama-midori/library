#define PROBLEM "https://atcoder.jp/contests/arc070/tasks/arc070_c"
#include "data_structure/slope-trick.hpp"
void solve() {
    LL(n);
    SlopeTrick st;
    while(n--) {
        LL(l, r);
        st.shift(-r, -l);
        st.add_abs(0);
        st.shift(l, r);
    }
    print(st.min_f);
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}