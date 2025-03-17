---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1077.test.cpp
    title: test/yukicoder/1077.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2304.test.cpp
    title: test/yukicoder/2304.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://ei1333.github.io/library/structure/others/slope-trick.hpp
    - https://maspypy.com/slope-trick-1-%E8%A7%A3%E8%AA%AC%E7%B7%A8
    - https://maspypy.com/slope-trick-1-%E8%A7%A3%E8%AA%AC%E7%B7%A8#toc18:~:text=%E3%81%B0%E3%82%88%E3%81%84%E3%81%A7%E3%81%99%E3%80%82-,%E3%82%B9%E3%83%A9%E3%82%A4%E3%83%89%E6%9C%80%E5%B0%8F%E5%80%A4%E9%96%A2%E6%95%B0,-%EF%BC%9A
  bundledCode: "#line 2 \"template.hpp\"\n// #pragma GCC target(\"avx2\")\n// #pragma\
    \ GCC optimize(\"O3\")\n// #pragma GCC optimize(\"unroll-loops\")\n#include <bits/stdc++.h>\n\
    using namespace std;\ntemplate <class T>\nconcept Streamable = requires(ostream\
    \ os, T &x) { os << x; };\ntemplate <class mint>\nconcept is_modint = requires(mint\
    \ &x) {\n    { x.val() } -> std::convertible_to<int>;\n};\n#ifdef LOCAL\n#include\
    \ <debug.hpp>\n#else\n#define debug(...) 42\n#endif\n\ntemplate <Streamable T>\
    \ void print_one(const T &value) { cout << value; }\ntemplate <is_modint T> void\
    \ print_one(const T &value) { cout << value.val(); }\nvoid print() { cout << '\\\
    n'; }\ntemplate <class T, class... Ts> void print(const T &a, const Ts &...b)\
    \ {\n    print_one(a);\n    ((cout << ' ', print_one(b)), ...);\n    cout << '\\\
    n';\n}\nvoid print(const string &s) { cout << s << '\\n'; }\ntemplate <ranges::range\
    \ Iterable>\n    requires(!Streamable<Iterable>)\nvoid print(const Iterable &v)\
    \ {\n    for(auto it = v.begin(); it != v.end(); ++it) {\n        if(it != v.begin())\n\
    \            cout << \" \";\n        print_one(*it);\n    }\n    cout << '\\n';\n\
    }\nusing ll = long long;\nusing vl = vector<ll>;\nusing vll = vector<vl>;\nusing\
    \ P = pair<ll, ll>;\n#define all(v) v.begin(), v.end()\ntemplate <typename T>\
    \ inline bool chmax(T &a, T b) {\n    return ((a < b) ? (a = b, true) : (false));\n\
    }\ntemplate <typename T> inline bool chmin(T &a, T b) {\n    return ((a > b) ?\
    \ (a = b, true) : (false));\n}\n#define rep1(i, n) for(ll i = 1; i <= ((ll)n);\
    \ ++i)\n// https://trap.jp/post/1224/\ntemplate <class... T> constexpr auto min(T...\
    \ a) {\n    return min(initializer_list<common_type_t<T...>>{a...});\n}\ntemplate\
    \ <class... T> constexpr auto max(T... a) {\n    return max(initializer_list<common_type_t<T...>>{a...});\n\
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
    \ dy = {0, 0, 1, -1};\n#line 3 \"data_structure/slope-trick.hpp\"\n// https://maspypy.com/slope-trick-1-%E8%A7%A3%E8%AA%AC%E7%B7%A8\n\
    // https://ei1333.github.io/library/structure/others/slope-trick.hpp\nstruct SlopeTrick\
    \ {\n    multiset<ll> L, R;\n    ll min_f;\n    ll add_L, add_R;\n    SlopeTrick()\
    \ {\n        L = {-inf};\n        R = {inf};\n        add_L = add_R = min_f =\
    \ 0;\n    }\n    ll size() { return ssize(L) + ssize(R); }\n    // add \\____\n\
    \    // f(x) <- f(x) + max(a-x,0)\n    void add_a_minus_x(ll a) {\n        ll\
    \ r0 = *begin(R);\n        min_f += max(0LL, a - (r0 + add_R));\n        R.insert(a\
    \ - add_R);\n        auto itr = begin(R);\n        L.insert(*itr + add_R - add_L);\n\
    \        R.erase(itr);\n    }\n    // add ___/\n    // f(x) <- f(x) + max(x-a,0)\n\
    \    void add_x_minus_a(ll a) {\n        ll l0 = *L.rbegin();\n        min_f +=\
    \ max(0LL, l0 + add_L - a);\n        L.insert(a - add_L);\n        auto itr =\
    \ prev(end(L));\n        R.insert(*itr + add_L - add_R);\n        L.erase(itr);\n\
    \    }\n    // add \\/\n    // f(x) <- f(x) + |x-a|\n    void add_abs(ll a) {\n\
    \        add_a_minus_x(a);\n        add_x_minus_a(a);\n    }\n    // f(x) <- f(x)\
    \ + a\n    void add_all(ll a) { min_f += a; }\n    // f(x) = min_f \u3092\u3068\
    \u308B\u9589\u533A\u9593[l,r]\n    P min_range() { return P(*rbegin(L) + add_L,\
    \ *begin(R) + add_R); }\n    // f(x) <- f(x) + g(x)\n    void merge(SlopeTrick\
    \ &g) {\n        min_f += g.min_f;\n        for(auto l : g.L) {\n            if(l\
    \ == -inf)\n                continue;\n            add_a_minus_x(l + g.add_R);\n\
    \        }\n        for(auto r : g.R) {\n            if(r == inf)\n          \
    \      continue;\n            add_x_minus_a(r + g.add_L);\n        }\n    }\n\
    \    // https://maspypy.com/slope-trick-1-%E8%A7%A3%E8%AA%AC%E7%B7%A8#toc18:~:text=%E3%81%B0%E3%82%88%E3%81%84%E3%81%A7%E3%81%99%E3%80%82-,%E3%82%B9%E3%83%A9%E3%82%A4%E3%83%89%E6%9C%80%E5%B0%8F%E5%80%A4%E9%96%A2%E6%95%B0,-%EF%BC%9A\n\
    \    // f(x) <- min[x-b <= y <= x-a]f(y)\n    // \\./ -> \\_/\n    void shift(ll\
    \ a, ll b) {\n        assert(a <= b);\n        add_L += a;\n        add_R += b;\n\
    \    }\n    // f(x) <- f(x-a)\n    void shift(ll a) { shift(a, a); }\n    ll get(ll\
    \ a) {\n        ll res = min_f;\n        for(auto l : L) {\n            res +=\
    \ max(0LL, l + add_L - a);\n        }\n        for(auto r : R) {\n           \
    \ res += max(0LL, a - (r + add_R));\n        }\n        return res;\n    }\n \
    \   // \\__/ -> \\___\n    // f(x) <- min[y<=x]f(y)\n    void clear_right() {\
    \ R = {inf}; }\n    // \\__/ -> __/\n    // f(x) <- min[y>=x]f(y)\n    void clear_left()\
    \ { L = {-inf}; }\n};\n"
  code: "#pragma once\n#include \"template.hpp\"\n// https://maspypy.com/slope-trick-1-%E8%A7%A3%E8%AA%AC%E7%B7%A8\n\
    // https://ei1333.github.io/library/structure/others/slope-trick.hpp\nstruct SlopeTrick\
    \ {\n    multiset<ll> L, R;\n    ll min_f;\n    ll add_L, add_R;\n    SlopeTrick()\
    \ {\n        L = {-inf};\n        R = {inf};\n        add_L = add_R = min_f =\
    \ 0;\n    }\n    ll size() { return ssize(L) + ssize(R); }\n    // add \\____\n\
    \    // f(x) <- f(x) + max(a-x,0)\n    void add_a_minus_x(ll a) {\n        ll\
    \ r0 = *begin(R);\n        min_f += max(0LL, a - (r0 + add_R));\n        R.insert(a\
    \ - add_R);\n        auto itr = begin(R);\n        L.insert(*itr + add_R - add_L);\n\
    \        R.erase(itr);\n    }\n    // add ___/\n    // f(x) <- f(x) + max(x-a,0)\n\
    \    void add_x_minus_a(ll a) {\n        ll l0 = *L.rbegin();\n        min_f +=\
    \ max(0LL, l0 + add_L - a);\n        L.insert(a - add_L);\n        auto itr =\
    \ prev(end(L));\n        R.insert(*itr + add_L - add_R);\n        L.erase(itr);\n\
    \    }\n    // add \\/\n    // f(x) <- f(x) + |x-a|\n    void add_abs(ll a) {\n\
    \        add_a_minus_x(a);\n        add_x_minus_a(a);\n    }\n    // f(x) <- f(x)\
    \ + a\n    void add_all(ll a) { min_f += a; }\n    // f(x) = min_f \u3092\u3068\
    \u308B\u9589\u533A\u9593[l,r]\n    P min_range() { return P(*rbegin(L) + add_L,\
    \ *begin(R) + add_R); }\n    // f(x) <- f(x) + g(x)\n    void merge(SlopeTrick\
    \ &g) {\n        min_f += g.min_f;\n        for(auto l : g.L) {\n            if(l\
    \ == -inf)\n                continue;\n            add_a_minus_x(l + g.add_R);\n\
    \        }\n        for(auto r : g.R) {\n            if(r == inf)\n          \
    \      continue;\n            add_x_minus_a(r + g.add_L);\n        }\n    }\n\
    \    // https://maspypy.com/slope-trick-1-%E8%A7%A3%E8%AA%AC%E7%B7%A8#toc18:~:text=%E3%81%B0%E3%82%88%E3%81%84%E3%81%A7%E3%81%99%E3%80%82-,%E3%82%B9%E3%83%A9%E3%82%A4%E3%83%89%E6%9C%80%E5%B0%8F%E5%80%A4%E9%96%A2%E6%95%B0,-%EF%BC%9A\n\
    \    // f(x) <- min[x-b <= y <= x-a]f(y)\n    // \\./ -> \\_/\n    void shift(ll\
    \ a, ll b) {\n        assert(a <= b);\n        add_L += a;\n        add_R += b;\n\
    \    }\n    // f(x) <- f(x-a)\n    void shift(ll a) { shift(a, a); }\n    ll get(ll\
    \ a) {\n        ll res = min_f;\n        for(auto l : L) {\n            res +=\
    \ max(0LL, l + add_L - a);\n        }\n        for(auto r : R) {\n           \
    \ res += max(0LL, a - (r + add_R));\n        }\n        return res;\n    }\n \
    \   // \\__/ -> \\___\n    // f(x) <- min[y<=x]f(y)\n    void clear_right() {\
    \ R = {inf}; }\n    // \\__/ -> __/\n    // f(x) <- min[y>=x]f(y)\n    void clear_left()\
    \ { L = {-inf}; }\n};"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: data_structure/slope-trick.hpp
  requiredBy: []
  timestamp: '2025-03-17 22:44:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1077.test.cpp
  - test/yukicoder/2304.test.cpp
documentation_of: data_structure/slope-trick.hpp
layout: document
redirect_from:
- /library/data_structure/slope-trick.hpp
- /library/data_structure/slope-trick.hpp.html
title: data_structure/slope-trick.hpp
---
