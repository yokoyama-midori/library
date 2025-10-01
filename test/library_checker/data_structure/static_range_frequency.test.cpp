// clang-format off
// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/static_range_frequency
// clang-format on
#include "../../../data-structure/wavelet-matrix.hpp"
#include "../../../template.hpp"
int main() {
    INT(n, q);
    vector<int> a(n);
    input(a);
    WaveletMatrix wm(a);
    WaveletMatrix<int, false> wm2(a);
    rep(q) {
        INT(l, r, x);
        int ans = wm.freq(l, r, x), ans2 = wm2.freq(l, r, x);
        assert(ans == ans2);
        print(ans);
    }
}