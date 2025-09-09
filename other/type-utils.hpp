#pragma once
#include <bits/stdc++.h>
using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
using vi = std::vector<int>;
using vii = std::vector<std::vector<int>>;
using pii = std::pair<int, int>;
using vl = std::vector<ll>;
using vll = std::vector<vl>;
using pll = std::pair<ll, ll>;

template <class T>
concept extended_integral =
    std::integral<T> || std::same_as<std::remove_cv_t<T>, i128> ||
    std::same_as<std::remove_cv_t<T>, u128>;
template <class T>
concept extended_signed_integral =
    std::signed_integral<T> || std::same_as<std::remove_cv_t<T>, i128>;
template <class T>
concept extended_unsigned_integral =
    std::unsigned_integral<T> || std::same_as<std::remove_cv_t<T>, u128>;

template <class T>
concept Streamable =
    requires(std::ostream &os, T &x) { os << x; } || extended_integral<T>;
template <class mint>
concept is_modint = requires(mint &x) {
    { x.val() } -> std::convertible_to<int>;
};