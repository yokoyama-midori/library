#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include <bits/stdc++.h>
using namespace std;
// https://xn--kst.jp/blog/2019/08/29/cpp-comp/
// debug methods
// usage: debug(x,y);
#define CHOOSE(a) CHOOSE2 a
#define CHOOSE2(a0, a1, a2, a3, a4, x, ...) x
#define debug_1(x1) cout << #x1 << ": " << x1 << endl
#define debug_2(x1, x2)                                                        \
    cout << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << endl
#define debug_3(x1, x2, x3)                                                    \
    cout << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << ", " #x3 << ": "    \
         << x3 << endl
#define debug_4(x1, x2, x3, x4)                                                \
    cout << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << ", " #x3 << ": "    \
         << x3 << ", " #x4 << ": " << x4 << endl
#define debug_5(x1, x2, x3, x4, x5)                                            \
    cout << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << ", " #x3 << ": "    \
         << x3 << ", " #x4 << ": " << x4 << ", " #x5 << ": " << x5 << endl
#ifdef LOCAL
#define debug(...)                                                             \
    CHOOSE((__VA_ARGS__, debug_5, debug_4, debug_3, debug_2, debug_1, ~))      \
    (__VA_ARGS__)
#else
#define debug(...)
#endif

using ll = long long;
using vl = vector<ll>;
using Graph = vector<vector<ll>>;
using P = pair<ll, ll>;
#define all(v) v.begin(), v.end()
template <typename T> inline bool chmax(T &a, T b) {
    return ((a < b) ? (a = b, true) : (false));
}
template <typename T> inline bool chmin(T &a, T b) {
    return ((a > b) ? (a = b, true) : (false));
}
#define rep1(i, n) for(ll i = 1; i <= ((ll)n); ++i)
// https://trap.jp/post/1224/
template <class... T> constexpr auto min(T... a) {
    return min(initializer_list<common_type_t<T...>>{a...});
}
template <class... T> constexpr auto max(T... a) {
    return max(initializer_list<common_type_t<T...>>{a...});
}
template <class... T> void input(T &...a) {
    (cin >> ... >> a);
}
void print() {
    cout << '\n';
}
template <class T, class... Ts> void print(const T &a, const Ts &...b) {
    cout << a;
    (cout << ... << (cout << ' ', b));
    cout << '\n';
}
#define INT(...)                                                               \
    int __VA_ARGS__;                                                           \
    input(__VA_ARGS__)
#define LL(...)                                                                \
    long long __VA_ARGS__;                                                     \
    input(__VA_ARGS__)
#define STRING(...)                                                            \
    string __VA_ARGS__;                                                        \
    input(__VA_ARGS__)
#define REP1(a) for(int i = 0; i < a; i++)
#define REP2(i, a) for(int i = 0; i < a; i++)
#define REP3(i, a, b) for(int i = a; i < b; i++)
#define REP4(i, a, b, c) for(int i = a; i < b; i += c)
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, REP4, REP3, REP2, REP1)(__VA_ARGS__)

ll inf = 3e18;
vl dx = {1, -1, 0, 0};
vl dy = {0, 0, 1, -1};
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;
void solve() {
    LL(a, b);
    print(a + b);
}
int main() {
    ll t = 1;
    rep(_, t) solve();
}
