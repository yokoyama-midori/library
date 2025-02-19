#define PROBLEM "https://judge.yosupo.jp/problem/area_of_union_of_rectangles"
#include "data_structure/rectangle-union-area.hpp"
void solve() {
    INT(n);
    RectangleUnionArea<int, ll> area_rec;
    rep(i, n) {
        INT(l, d, r, u);
        area_rec.add_rect(l, d, r, u);
    }
    print(area_rec.cul());
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}