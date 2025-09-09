// competitive-verifier: PROBLEM https://yukicoder.me/problems/no/565
#include "../../other/grid-rotate-expansion.hpp"
#include "../../rng.hpp"
#include "../../template.hpp"
void solve() {
    INT(r, k, h, w);
    vector<string> c(h);
    input(c);
    c = grid_rotate(c, r / 90);
    c = grid_expansion(c, k);
    for(auto &ci : c)
        print(ci);
}
void solve2() {
    INT(r, k, h, w);
    vector c(h, vector<char>(w));
    rep(i, h) input(c[i]);
    c = grid_rotate(c, r / 90);
    c = grid_expansion(c, k);
    for(auto &ci : c) {
        for(auto j : ci)
            write(j);
        print();
    }
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    if(rng(0, 2))
        solve();
    else
        solve2();
}