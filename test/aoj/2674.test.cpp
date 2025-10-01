// clang-format off
// competitive-verifier: PROBLEM https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2674
// clang-format on
#include "../../data-structure/wavelet-matrix.hpp"
#include "../../template.hpp"
int main() {
    INT(d);
    vector<int> a(d);
    input(a);
    auto a2 = a;
    for(int &i : a2) {
        i += 100'000'000;
    }
    WaveletMatrix<int, true> wm(a);
    WaveletMatrix<int, false> wm2(a2);
    INT(q);
    rep(q) {
        INT(l, r, e);
        --l;
        auto [mini, maxi] = minmax(a[l], a[r - 1]);
        int ans = r - l - wm.count(l, r, mini - e, maxi + e + 1);
        auto [mini2, maxi2] = minmax(a2[l], a2[r - 1]);
        int ans2 = r - l - wm2.count(l, r, max(0, mini2 - e), maxi2 + e + 1);
        print(ans);
    }
}
