#pragma once
// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
template <class T>
concept Streamable = requires(ostream os, T &x) { os << x; };
template <class mint>
concept is_modint = requires(mint &x) {
    { x.val() } -> std::convertible_to<int>;
};
#ifdef LOCAL
#include <debug.hpp>
#else
#define debug(...)
#endif
template <Streamable T> void print_one(const T &value) { cout << value; }
template <is_modint T> void print_one(const T &value) { cout << value.val(); }
void print() { cout << '\n'; }
template <class T, class... Ts> void print(const T &a, const Ts &...b) {
    print_one(a);
    ((cout << ' ', print_one(b)), ...);
    cout << '\n';
}
template <ranges::range Iterable>
    requires(!Streamable<Iterable>)
void print(const Iterable &v) {
    for(auto it = v.begin(); it != v.end(); ++it) {
        if(it != v.begin())
            cout << " ";
        print_one(*it);
    }
    cout << '\n';
}
using ll = long long;
using vi = vector<int>;
using vii = vector<vector<int>>;
using pii = pair<int, int>;
using vl = vector<ll>;
using vll = vector<vl>;
using pll = pair<ll, ll>;
#define all(v) begin(v), end(v)
#define UNIQUE(v) ranges::sort(v), v.erase(unique(all(v)), end(v))
template <typename T> inline bool chmax(T &a, T b) {
    return ((a < b) ? (a = b, true) : (false));
}
template <typename T> inline bool chmin(T &a, T b) {
    return ((a > b) ? (a = b, true) : (false));
}
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
#define rep1(i, n) for(ll i = 1; i <= ((ll)n); ++i)
ll inf = 3e18;
vl dx = {1, -1, 0, 0};
vl dy = {0, 0, 1, -1};
template <class T> T floor(T x, T y) {
    auto d = div(x, y);
    return d.quot - (x ^ y < 0 and d.rem);
}
template <class T> T ceil(T x, T y) { return floor(x + y - 1, y); }
// yの符号に関わらず非負で定義
template <class T> T remainder(T x, T y) {
    T m = x % y;
    return (m < 0) ? m + abs(y) : m;
}