---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder/tdpc_fibonacci.test_.cpp
    title: test/atcoder/tdpc_fibonacci.test_.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/other/kth_term_of_linearly_recurrent_sequence.test.cpp
    title: test/library_checker/other/kth_term_of_linearly_recurrent_sequence.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template.hpp\"\n// #pragma GCC target(\"avx2\")\n// #pragma\
    \ GCC optimize(\"O3\")\n// #pragma GCC optimize(\"unroll-loops\")\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n// https://xn--kst.jp/blog/2019/08/29/cpp-comp/\n\
    // debug methods\n// usage: debug(x,y);\n#define CHOOSE(a) CHOOSE2 a\n#define\
    \ CHOOSE2(a0, a1, a2, a3, a4, x, ...) x\n#define debug_1(x1) cout << #x1 << \"\
    : \" << x1 << endl\n#define debug_2(x1, x2)                                  \
    \                      \\\n    cout << #x1 << \": \" << x1 << \", \" #x2 << \"\
    : \" << x2 << endl\n#define debug_3(x1, x2, x3)                              \
    \                      \\\n    cout << #x1 << \": \" << x1 << \", \" #x2 << \"\
    : \" << x2 << \", \" #x3 << \": \"    \\\n         << x3 << endl\n#define debug_4(x1,\
    \ x2, x3, x4)                                                \\\n    cout << #x1\
    \ << \": \" << x1 << \", \" #x2 << \": \" << x2 << \", \" #x3 << \": \"    \\\n\
    \         << x3 << \", \" #x4 << \": \" << x4 << endl\n#define debug_5(x1, x2,\
    \ x3, x4, x5)                                            \\\n    cout << #x1 <<\
    \ \": \" << x1 << \", \" #x2 << \": \" << x2 << \", \" #x3 << \": \"    \\\n \
    \        << x3 << \", \" #x4 << \": \" << x4 << \", \" #x5 << \": \" << x5 <<\
    \ endl\n#ifdef LOCAL\n#define debug(...)                                     \
    \                        \\\n    CHOOSE((__VA_ARGS__, debug_5, debug_4, debug_3,\
    \ debug_2, debug_1, ~))      \\\n    (__VA_ARGS__)\n#else\n#define debug(...)\n\
    #endif\n\nusing ll = long long;\nusing vl = vector<ll>;\nusing Graph = vector<vector<ll>>;\n\
    using P = pair<ll, ll>;\n#define all(v) v.begin(), v.end()\ntemplate <typename\
    \ T> inline bool chmax(T &a, T b) {\n    return ((a < b) ? (a = b, true) : (false));\n\
    }\ntemplate <typename T> inline bool chmin(T &a, T b) {\n    return ((a > b) ?\
    \ (a = b, true) : (false));\n}\n#define rep1(i, n) for(ll i = 1; i <= ((ll)n);\
    \ ++i)\n// https://trap.jp/post/1224/\ntemplate <class... T> constexpr auto min(T...\
    \ a) {\n    return min(initializer_list<common_type_t<T...>>{a...});\n}\ntemplate\
    \ <class... T> constexpr auto max(T... a) {\n    return max(initializer_list<common_type_t<T...>>{a...});\n\
    }\ntemplate <class... T> void input(T &...a) { (cin >> ... >> a); }\ntemplate\
    \ <class T> void input(vector<T> &a) {\n    for(T &x : a)\n        cin >> x;\n\
    }\nvoid print() { cout << '\\n'; }\ntemplate <class T, class... Ts> void print(const\
    \ T &a, const Ts &...b) {\n    cout << a;\n    (cout << ... << (cout << ' ', b));\n\
    \    cout << '\\n';\n}\ntemplate <class T> void print(vector<T> &x) {\n    if(x.size())\
    \ {\n        for(ll i = 0; i < x.size(); i++) {\n            cout << x[i] << \"\
    \ \\n\"[i + 1 == x.size()];\n        }\n    }\n}\n#define INT(...)           \
    \                                                    \\\n    int __VA_ARGS__;\
    \                                                           \\\n    input(__VA_ARGS__)\n\
    #define LL(...)                                                              \
    \  \\\n    long long __VA_ARGS__;                                            \
    \         \\\n    input(__VA_ARGS__)\n#define STR(...)                       \
    \                                        \\\n    string __VA_ARGS__;         \
    \                                               \\\n    input(__VA_ARGS__)\n#define\
    \ REP1(a) for(ll i = 0; i < a; i++)\n#define REP2(i, a) for(ll i = 0; i < a; i++)\n\
    #define REP3(i, a, b) for(ll i = a; i < b; i++)\n#define REP4(i, a, b, c) for(ll\
    \ i = a; i < b; i += c)\n#define overload4(a, b, c, d, e, ...) e\n#define rep(...)\
    \ overload4(__VA_ARGS__, REP4, REP3, REP2, REP1)(__VA_ARGS__)\n\nll inf = 3e18;\n\
    vl dx = {1, -1, 0, 0};\nvl dy = {0, 0, 1, -1};\n#line 3 \"poly/bostan_mori.hpp\"\
    \n#include <atcoder/modint>\n#include <atcoder/convolution>\nusing namespace atcoder;\n\
    template <class T> T bostanMori(vector<T> p, vector<T> q, ll n) {\n    // return\
    \ [x^n]P(x)/Q(x)\n    ll k = p.size();\n    while(n) {\n        auto q_minus(q);\n\
    \        rep(i, k + 1) {\n            if(i & 1)\n                q_minus[i] *=\
    \ -1;\n        }\n        if(T::mod() == 998244353) {\n            p = convolution(p,\
    \ q_minus);\n            q = convolution(q, q_minus);\n        } else {\n    \
    \        p = convolution_naive(p, q_minus);\n            q = convolution_naive(q,\
    \ q_minus);\n        }\n        vector<T> q_nex(k + 1), p_nex(k);\n        rep(i,\
    \ k + 1) { q_nex[i] = q[2 * i]; }\n        ll n1 = n & 1;\n        rep(i, k) {\
    \ p_nex[i] = p[2 * i + n1]; }\n        swap(p, p_nex);\n        swap(q, q_nex);\n\
    \        n >>= 1;\n    }\n    return p[0] / q[0];\n}\n"
  code: "#pragma once\n#include \"template.hpp\"\n#include <atcoder/modint>\n#include\
    \ <atcoder/convolution>\nusing namespace atcoder;\ntemplate <class T> T bostanMori(vector<T>\
    \ p, vector<T> q, ll n) {\n    // return [x^n]P(x)/Q(x)\n    ll k = p.size();\n\
    \    while(n) {\n        auto q_minus(q);\n        rep(i, k + 1) {\n         \
    \   if(i & 1)\n                q_minus[i] *= -1;\n        }\n        if(T::mod()\
    \ == 998244353) {\n            p = convolution(p, q_minus);\n            q = convolution(q,\
    \ q_minus);\n        } else {\n            p = convolution_naive(p, q_minus);\n\
    \            q = convolution_naive(q, q_minus);\n        }\n        vector<T>\
    \ q_nex(k + 1), p_nex(k);\n        rep(i, k + 1) { q_nex[i] = q[2 * i]; }\n  \
    \      ll n1 = n & 1;\n        rep(i, k) { p_nex[i] = p[2 * i + n1]; }\n     \
    \   swap(p, p_nex);\n        swap(q, q_nex);\n        n >>= 1;\n    }\n    return\
    \ p[0] / q[0];\n}"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: poly/bostan_mori.hpp
  requiredBy:
  - test/atcoder/tdpc_fibonacci.test_.cpp
  timestamp: '2024-10-18 23:31:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/other/kth_term_of_linearly_recurrent_sequence.test.cpp
documentation_of: poly/bostan_mori.hpp
layout: document
redirect_from:
- /library/poly/bostan_mori.hpp
- /library/poly/bostan_mori.hpp.html
title: poly/bostan_mori.hpp
---
