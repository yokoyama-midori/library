#pragma once
#include "./other/fastio.hpp"
#include "./other/type-utils.hpp"
// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include <debug.hpp>
#else
#define debug(...)
#endif
template <Streamable T> void print_one(const T &value) { fastio::write(value); }
template <is_modint T> void print_one(const T &value) {
    print_one(value.val());
}
void print() { print_one('\n'); }
template <class T, class... Ts> void print(const T &a, const Ts &...b) {
    print_one(a);
    ((print_one(' '), print_one(b)), ...);
    print();
}
template <ranges::range Iterable>
    requires(!Streamable<Iterable>)
void print(const Iterable &v) {
    for(auto it = v.begin(); it != v.end(); ++it) {
        if(it != v.begin())
            print_one(' ');
        print_one(*it);
    }
    print();
}
#define all(v) begin(v), end(v)
template <class T> void UNIQUE(T &v) {
    ranges::sort(v);
    v.erase(unique(all(v)), end(v));
}
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
void input() {}
template <class Head, class... Tail> void input(Head &head, Tail &...tail) {
#ifdef LOCAL
    cin >> head;
#elif
    fastio::read(head);
#endif
    input(tail...);
}
template <class T> void input(vector<T> &a) {
    for(T &x : a)
        input(x);
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
#define REP1_0(n, c) REP1_1(n, c)
#define REP1_1(n, c)                                                           \
    for(ll REP_COUNTER_##c = 0; REP_COUNTER_##c < (ll)(n); REP_COUNTER_##c++)
#define REP1(n) REP1_0(n, __COUNTER__)
#define REP2(i, a) for(ll i = 0; i < (ll)(a); i++)
#define REP3(i, a, b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define REP4(i, a, b, c) for(ll i = (ll)(a); i < (ll)(b); i += (ll)(c))
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, REP4, REP3, REP2, REP1)(__VA_ARGS__)
ll inf = 3e18;
vl dx = {1, -1, 0, 0};
vl dy = {0, 0, 1, -1};
template <class T> constexpr T floor(T x, T y) noexcept {
    return x / y - ((x ^ y) < 0 and x % y);
}
template <class T> constexpr T ceil(T x, T y) noexcept {
    return x / y + ((x ^ y) >= 0 and x % y);
}
// yの符号に関わらず非負で定義 \bmod:texコマンド
template <class T> constexpr T bmod(T x, T y) noexcept {
    T m = x % y;
    return (m < 0) ? m + (y > 0 ? y : -y) : m;
}
template <std::signed_integral T> constexpr int bit_width(T x) noexcept {
    return std::bit_width((uint64_t)x);
}
template <std::signed_integral T> constexpr int popcount(T x) noexcept {
    return std::popcount((uint64_t)x);
}
constexpr bool kth_bit(auto n, auto k) { return (n >> k) & 1; }