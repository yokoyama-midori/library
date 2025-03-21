// competitive-verifier: PROBLEM https://yukicoder.me/problems/no/2304
#include "../../data_structure/slope-trick.hpp"
#include "../../template.hpp"
void solve() {
    INT(n);
    vl a(n);
    input(a);
    ranges::sort(a);
    SlopeTrick v;
    for(auto ai : a) {
        v.shift(1);
        v.clear_right();
        v.add_abs(ai);
    }
    print(v.min_f);
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << std::setprecision(16);
    solve();
}
