// clang-format off
// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/range_kth_smallest
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
        INT(l, r, k);
        int ans = wm.kth_smallest(l, r, k);
        int ans2 = wm2.kth_smallest(l, r, k);
        assert(ans == ans2);
        print(ans);
    }
}