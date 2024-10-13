#define PROBLEM "https://atcoder.jp/contests/tdpc/tasks/tdpc_fibonacci"
// 行列累乗では無理 (高速)きたまさ法,Bostan-Moriが必要
int main(){}
// #include "template.hpp"
// #include <atcoder/modint>
// using namespace atcoder;
// using mint = modint1000000007;
// #include "math/matrix.hpp"
// void solve() {
//     LL(k, n);
//     if(n <= k) {
//         print(1);
//         return;
//     }
//     Matrix<mint> A(k);
//     rep(i, k) A[0][i] = 1;
//     rep(i, 1, k) A[i][i - 1] = 1;
//     A ^= (n - k);
//     print(accumulate(all(A[0]), mint(0)).val());
// }
// int main() {
//     ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);
//     cout << std::setprecision(16);
//     int t = 1;
//     rep(_, t) { solve(); }
// }
