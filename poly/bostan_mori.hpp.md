---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/other/kth_term_of_linearly_recurrent_sequence.test.cpp
    title: test/library_checker/other/kth_term_of_linearly_recurrent_sequence.test.cpp
  - icon: ':x:'
    path: test/yukicoder/3044.test.cpp
    title: test/yukicoder/3044.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
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
    \ dy = {0, 0, 1, -1};\n#line 3 \"poly/bostan_mori.hpp\"\n#include <atcoder/convolution>\n\
    #include <atcoder/modint>\ntemplate <class T> T bostanMori(vector<T> p, vector<T>\
    \ q, ll n) {\n    // return [x^n]P(x)/Q(x)\n    using namespace atcoder;\n   \
    \ assert(p.size() < q.size());\n    int k = ssize(q) - 1;\n    if(p.size() < k\
    \ - 1)\n        p.resize(k);\n    while(n) {\n        auto q_minus(q);\n     \
    \   for(int i = 1; i < k + 1; i += 2) {\n            q_minus[i] *= -1;\n     \
    \   }\n        if(T::mod() == 998244353) {\n            p = convolution(p, q_minus);\n\
    \            q = convolution(q, q_minus);\n        } else {\n            p = convolution_naive(p,\
    \ q_minus);\n            q = convolution_naive(q, q_minus);\n        }\n     \
    \   int n1 = n & 1;\n        rep(i, k) p[i] = p[2 * i + n1];\n        rep(i, k\
    \ + 1) q[i] = q[2 * i];\n        p.resize(k);\n        q.resize(k + 1);\n    \
    \    n >>= 1;\n    }\n    return p[0] / q[0];\n}\n"
  code: "#pragma once\n#include \"template.hpp\"\n#include <atcoder/convolution>\n\
    #include <atcoder/modint>\ntemplate <class T> T bostanMori(vector<T> p, vector<T>\
    \ q, ll n) {\n    // return [x^n]P(x)/Q(x)\n    using namespace atcoder;\n   \
    \ assert(p.size() < q.size());\n    int k = ssize(q) - 1;\n    if(p.size() < k\
    \ - 1)\n        p.resize(k);\n    while(n) {\n        auto q_minus(q);\n     \
    \   for(int i = 1; i < k + 1; i += 2) {\n            q_minus[i] *= -1;\n     \
    \   }\n        if(T::mod() == 998244353) {\n            p = convolution(p, q_minus);\n\
    \            q = convolution(q, q_minus);\n        } else {\n            p = convolution_naive(p,\
    \ q_minus);\n            q = convolution_naive(q, q_minus);\n        }\n     \
    \   int n1 = n & 1;\n        rep(i, k) p[i] = p[2 * i + n1];\n        rep(i, k\
    \ + 1) q[i] = q[2 * i];\n        p.resize(k);\n        q.resize(k + 1);\n    \
    \    n >>= 1;\n    }\n    return p[0] / q[0];\n}"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: poly/bostan_mori.hpp
  requiredBy: []
  timestamp: '2025-03-17 22:44:15+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library_checker/other/kth_term_of_linearly_recurrent_sequence.test.cpp
  - test/yukicoder/3044.test.cpp
documentation_of: poly/bostan_mori.hpp
layout: document
redirect_from:
- /library/poly/bostan_mori.hpp
- /library/poly/bostan_mori.hpp.html
title: poly/bostan_mori.hpp
---
