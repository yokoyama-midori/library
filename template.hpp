#pragma once
// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
// https://xn--kst.jp/blog/2019/08/29/cpp-comp/
// debug methods
// usage: debug(x,y);
// vector 出力できるように修正
template <typename T>
ostream& debug_print(ostream& os, const vector<T>& v) {
    os << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i < v.size() - 1) os << ", ";
    }
    os << "]";
    return os;
}
template <typename T>
ostream& debug_print(ostream& os, const T& var) {
    os << var;
    return os;
}
#define CHOOSE(a) CHOOSE2 a
#define CHOOSE2(a0, a1, a2, a3, a4, x, ...) x
#define debug_1(x1) { cout << #x1 << ": "; debug_print(cout, x1) << endl; }
#define debug_2(x1, x2) { cout << #x1 << ": "; debug_print(cout, x1) << ", " << #x2 << ": "; debug_print(cout, x2) << endl; }
#define debug_3(x1, x2, x3) { cout << #x1 << ": "; debug_print(cout, x1) << ", " << #x2 << ": "; debug_print(cout, x2) << ", " << #x3 << ": "; debug_print(cout, x3) << endl; }
#define debug_4(x1, x2, x3, x4) { cout << #x1 << ": "; debug_print(cout, x1) << ", " << #x2 << ": "; debug_print(cout, x2) << ", " << #x3 << ": "; debug_print(cout, x3) << ", " << #x4 << ": "; debug_print(cout, x4) << endl; }
#define debug_5(x1, x2, x3, x4, x5) { cout << #x1 << ": "; debug_print(cout, x1) << ", " << #x2 << ": "; debug_print(cout, x2) << ", " << #x3 << ": "; debug_print(cout, x3) << ", " << #x4 << ": "; debug_print(cout, x4) << ", " << #x5 << ": "; debug_print(cout, x5) << endl; }

#ifdef LOCAL
#define debug(...) CHOOSE((__VA_ARGS__, debug_5, debug_4, debug_3, debug_2, debug_1, ~))(__VA_ARGS__)
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
template <class... T> void input(T &...a) { (cin >> ... >> a); }
template <class T> void input(vector<T> &a) {
    for(T &x : a)
        cin >> x;
}
void print() { cout << '\n'; }
template <class T, class... Ts> void print(const T &a, const Ts &...b) {
    cout << a;
    (cout << ... << (cout << ' ', b));
    cout << '\n';
}
template <class T> void print(vector<T> &x) {
    if(x.size()) {
        for(ll i = 0; i < x.size(); i++) {
            cout << x[i] << " \n"[i + 1 == x.size()];
        }
    }
}
#define INT(...)                                                               \
    int __VA_ARGS__;                                                           \
    input(__VA_ARGS__)
#define LL(...)                                                                \
    long long __VA_ARGS__;                                                     \
    input(__VA_ARGS__)
#define STR(...)                                                               \
    string __VA_ARGS__;                                                        \
    input(__VA_ARGS__)
#define REP1(a) for(ll i = 0; i < a; i++)
#define REP2(i, a) for(ll i = 0; i < a; i++)
#define REP3(i, a, b) for(ll i = a; i < b; i++)
#define REP4(i, a, b, c) for(ll i = a; i < b; i += c)
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, REP4, REP3, REP2, REP1)(__VA_ARGS__)

ll inf = 3e18;
vl dx = {1, -1, 0, 0};
vl dy = {0, 0, 1, -1};