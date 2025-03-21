// competitive-verifier: PROBLEM https://yukicoder.me/problems/no/1077
#include "data_structure/slope-trick.hpp"
void solve() {
    LL(n);
    SlopeTrick st;
    while(n--) {
        LL(y);
        st.clear_right();
        st.add_abs(y);
    }
    print(st.min_f);
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll t = 1;
    rep(_, t) solve();
}
