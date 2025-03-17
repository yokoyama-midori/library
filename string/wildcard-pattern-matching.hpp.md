---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: rng.hpp
    title: rng.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/wildcard_pattern_matching.test.cpp
    title: test/library_checker/string/wildcard_pattern_matching.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/utpc2024/tasks/utpc2024_k
    - https://noshi91.hatenablog.com/entry/2024/05/26/060854
  bundledCode: "#line 2 \"rng.hpp\"\n// https://maspypy.github.io/library/random/base.hpp\n\
    #line 2 \"template.hpp\"\n// #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"\
    O3\")\n// #pragma GCC optimize(\"unroll-loops\")\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\ntemplate <class T>\nconcept Streamable = requires(ostream os,\
    \ T &x) { os << x; };\ntemplate <class mint>\nconcept is_modint = requires(mint\
    \ &x) {\n    { x.val() } -> std::convertible_to<int>;\n};\n#ifdef LOCAL\n#include\
    \ <debug.hpp>\n#else\n#define debug(...) 42\n#endif\n\ntemplate <Streamable T>\
    \ void print_one(const T &value) { cout << value; }\ntemplate <is_modint T> void\
    \ print_one(const T &value) { cout << value.val(); }\nvoid print() { cout << '\\\
    n'; }\ntemplate <class T, class... Ts> void print(const T &a, const Ts &...b)\
    \ {\n    print_one(a);\n    ((cout << ' ', print_one(b)), ...);\n    cout << '\\\
    n';\n}\nvoid print(const string &s) { cout << s << '\\n'; }\ntemplate <ranges::range\
    \ Iterable> void print(const Iterable &v) {\n    auto it = v.begin();\n    for(;\
    \ it != v.end(); ++it) {\n        if(it != v.begin())\n            cout << \"\
    \ \";\n        print_one(*it);\n    }\n    cout << '\\n';\n}\nusing ll = long\
    \ long;\nusing vl = vector<ll>;\nusing vll = vector<vl>;\nusing P = pair<ll, ll>;\n\
    #define all(v) v.begin(), v.end()\ntemplate <typename T> inline bool chmax(T &a,\
    \ T b) {\n    return ((a < b) ? (a = b, true) : (false));\n}\ntemplate <typename\
    \ T> inline bool chmin(T &a, T b) {\n    return ((a > b) ? (a = b, true) : (false));\n\
    }\n#define rep1(i, n) for(ll i = 1; i <= ((ll)n); ++i)\n// https://trap.jp/post/1224/\n\
    template <class... T> constexpr auto min(T... a) {\n    return min(initializer_list<common_type_t<T...>>{a...});\n\
    }\ntemplate <class... T> constexpr auto max(T... a) {\n    return max(initializer_list<common_type_t<T...>>{a...});\n\
    }\ntemplate <class... T> void input(T &...a) { (cin >> ... >> a); }\ntemplate\
    \ <class T> void input(vector<T> &a) {\n    for(T &x : a)\n        cin >> x;\n\
    }\n#define INT(...)                                                          \
    \     \\\n    int __VA_ARGS__;                                               \
    \            \\\n    input(__VA_ARGS__)\n#define LL(...)                     \
    \                                           \\\n    long long __VA_ARGS__;   \
    \                                                  \\\n    input(__VA_ARGS__)\n\
    #define STR(...)                                                             \
    \  \\\n    string __VA_ARGS__;                                               \
    \         \\\n    input(__VA_ARGS__)\n#define REP1(a) for(ll i = 0; i < a; i++)\n\
    #define REP2(i, a) for(ll i = 0; i < a; i++)\n#define REP3(i, a, b) for(ll i =\
    \ a; i < b; i++)\n#define REP4(i, a, b, c) for(ll i = a; i < b; i += c)\n#define\
    \ overload4(a, b, c, d, e, ...) e\n#define rep(...) overload4(__VA_ARGS__, REP4,\
    \ REP3, REP2, REP1)(__VA_ARGS__)\n\nll inf = 3e18;\nvl dx = {1, -1, 0, 0};\nvl\
    \ dy = {0, 0, 1, -1};\n#line 4 \"rng.hpp\"\nunsigned long long RNG_64() {\n  \
    \  static unsigned long long x_ =\n        (unsigned long long)(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                                 chrono::high_resolution_clock::now()\n     \
    \                                .time_since_epoch())\n                      \
    \           .count()) *\n        10150724397891781847ULL;\n    x_ ^= x_ << 7;\n\
    \    return x_ ^= x_ >> 9;\n}\n\nunsigned long long RNG(unsigned long long lim)\
    \ { return RNG_64() % lim; }\n\nll rng(ll l, ll r) {\n    // [l,r)\n    return\
    \ l + RNG_64() % (r - l);\n}\n#line 4 \"string/wildcard-pattern-matching.hpp\"\
    \n#include <atcoder/convolution>\n#include <atcoder/modint>\n// https://noshi91.hatenablog.com/entry/2024/05/26/060854\n\
    // \u554F\u984C\u4F8B https://atcoder.jp/contests/utpc2024/tasks/utpc2024_k\n\
    // O(|S|log|S|)\ntemplate <class T>\nenable_if_t<is_integral_v<T>, vector<bool>>\n\
    wildcard_pattern_matching(const vector<T> &_s, const vector<T> &_t) {\n    assert(_s.size()\
    \ >= _t.size());\n    using mint = atcoder::modint998244353;\n    int ns = _s.size(),\
    \ nt = _t.size();\n    vector<mint> s(ns), s01(ns), t(nt), t01(nt);\n    for(int\
    \ i : views::iota(0, ns))\n        s[i] = _s[i], s01[i] = _s[i] ? 1 : 0;\n   \
    \ for(int i : views::iota(0, nt)) {\n        mint r = rng(0, mint::mod());\n \
    \       t[i] = _t[nt - 1 - i] * r, t01[i] = _t[nt - 1 - i] ? r : 0;\n    }\n \
    \   auto c1 = atcoder::convolution(s, t01);\n    auto c2 = atcoder::convolution(s01,\
    \ t);\n    vector<bool> res(ns - nt + 1);\n    for(int i : views::iota(0, ssize(res)))\n\
    \        res[i] = c1[nt - 1 + i] == c2[nt - 1 + i];\n    return res;\n}\nvector<bool>\
    \ wildcard_pattern_matching(const string &str, const string &str2,\n         \
    \                              const char &wildcard = '*') {\n    vector<char>\
    \ _s(begin(str), end(str)), _t(begin(str2), end(str2));\n    for(char &c : _s)\n\
    \        if(c == wildcard)\n            c = 0;\n    for(char &c : _t)\n      \
    \  if(c == wildcard)\n            c = 0;\n    return wildcard_pattern_matching(_s,\
    \ _t);\n}\n"
  code: "#pragma once\n#include \"rng.hpp\"\n#include \"template.hpp\"\n#include <atcoder/convolution>\n\
    #include <atcoder/modint>\n// https://noshi91.hatenablog.com/entry/2024/05/26/060854\n\
    // \u554F\u984C\u4F8B https://atcoder.jp/contests/utpc2024/tasks/utpc2024_k\n\
    // O(|S|log|S|)\ntemplate <class T>\nenable_if_t<is_integral_v<T>, vector<bool>>\n\
    wildcard_pattern_matching(const vector<T> &_s, const vector<T> &_t) {\n    assert(_s.size()\
    \ >= _t.size());\n    using mint = atcoder::modint998244353;\n    int ns = _s.size(),\
    \ nt = _t.size();\n    vector<mint> s(ns), s01(ns), t(nt), t01(nt);\n    for(int\
    \ i : views::iota(0, ns))\n        s[i] = _s[i], s01[i] = _s[i] ? 1 : 0;\n   \
    \ for(int i : views::iota(0, nt)) {\n        mint r = rng(0, mint::mod());\n \
    \       t[i] = _t[nt - 1 - i] * r, t01[i] = _t[nt - 1 - i] ? r : 0;\n    }\n \
    \   auto c1 = atcoder::convolution(s, t01);\n    auto c2 = atcoder::convolution(s01,\
    \ t);\n    vector<bool> res(ns - nt + 1);\n    for(int i : views::iota(0, ssize(res)))\n\
    \        res[i] = c1[nt - 1 + i] == c2[nt - 1 + i];\n    return res;\n}\nvector<bool>\
    \ wildcard_pattern_matching(const string &str, const string &str2,\n         \
    \                              const char &wildcard = '*') {\n    vector<char>\
    \ _s(begin(str), end(str)), _t(begin(str2), end(str2));\n    for(char &c : _s)\n\
    \        if(c == wildcard)\n            c = 0;\n    for(char &c : _t)\n      \
    \  if(c == wildcard)\n            c = 0;\n    return wildcard_pattern_matching(_s,\
    \ _t);\n}"
  dependsOn:
  - rng.hpp
  - template.hpp
  isVerificationFile: false
  path: string/wildcard-pattern-matching.hpp
  requiredBy: []
  timestamp: '2025-03-17 22:06:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/string/wildcard_pattern_matching.test.cpp
documentation_of: string/wildcard-pattern-matching.hpp
layout: document
redirect_from:
- /library/string/wildcard-pattern-matching.hpp
- /library/string/wildcard-pattern-matching.hpp.html
title: string/wildcard-pattern-matching.hpp
---
