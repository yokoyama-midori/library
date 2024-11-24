#define PROBLEM "https://atcoder.jp/contests/abc329/tasks/abc329_c"
#include "string/run-length-encoding.hpp"
void solve() {
    LL(n);
    STR(s);
    vl cnt(26, 0);
    auto rle = RunLengthEncoding(s);
    for(auto [c, sz] : rle) {
        chmax(cnt[c - 'a'], (ll)sz);
    }
    print(accumulate(all(cnt), 0LL));
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
