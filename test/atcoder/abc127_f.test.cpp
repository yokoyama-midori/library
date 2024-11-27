#define PROBLEM "https://atcoder.jp/contests/abc127/tasks/abc127_f"
#include "data_structure/slope-trick.hpp"
void solve() {
    LL(q);
    SlopeTrick st;
    while(q--) {
        LL(flag);
        if(flag == 1) {
            LL(a, b);
            st.add_abs(a);
            st.add_all(b);
        } else {
            print(st.min_range().first, st.min_f);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
