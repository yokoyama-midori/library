---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy:
  - icon: ':question:'
    path: math/miller_rabin.hpp
    title: math/miller_rabin.hpp
  - icon: ':heavy_check_mark:'
    path: math/mod-sqrt.hpp
    title: math/mod-sqrt.hpp
  - icon: ':question:'
    path: math/pollard_rho.hpp
    title: math/pollard_rho.hpp
  - icon: ':heavy_check_mark:'
    path: math/primitive-root.hpp
    title: math/primitive-root.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/atcoder/abc180_c.test.cpp
    title: test/atcoder/abc180_c.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc249_d.test.cpp
    title: test/atcoder/abc249_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/number_theory/factorize.test.cpp
    title: test/library_checker/number_theory/factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/number_theory/primality_test.test.cpp
    title: test/library_checker/number_theory/primality_test.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/number_theory/primitive_root.test.cpp
    title: test/library_checker/number_theory/primitive_root.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/number_theory/sqrt_mod.test.cpp
    title: test/library_checker/number_theory/sqrt_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2051.test.cpp
    title: test/yukicoder/2051.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/888.test.cpp
    title: test/yukicoder/888.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template.hpp\"\n// #pragma GCC target(\"avx2\")\n// #pragma\
    \ GCC optimize(\"O3\")\n// #pragma GCC optimize(\"unroll-loops\")\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n// https://xn--kst.jp/blog/2019/08/29/cpp-comp/\n\
    // debug methods\n// usage: debug(x,y);\n// vector \u51FA\u529B\u3067\u304D\u308B\
    \u3088\u3046\u306B\u4FEE\u6B63\ntemplate <typename T>\nostream& debug_print(ostream&\
    \ os, const vector<T>& v) {\n    os << \"[\";\n    for (size_t i = 0; i < v.size();\
    \ ++i) {\n        os << v[i];\n        if (i < v.size() - 1) os << \", \";\n \
    \   }\n    os << \"]\";\n    return os;\n}\ntemplate <typename T>\nostream& debug_print(ostream&\
    \ os, const T& var) {\n    os << var;\n    return os;\n}\n#define CHOOSE(a) CHOOSE2\
    \ a\n#define CHOOSE2(a0, a1, a2, a3, a4, x, ...) x\n#define debug_1(x1) { cout\
    \ << #x1 << \": \"; debug_print(cout, x1) << endl; }\n#define debug_2(x1, x2)\
    \ { cout << #x1 << \": \"; debug_print(cout, x1) << \", \" << #x2 << \": \"; debug_print(cout,\
    \ x2) << endl; }\n#define debug_3(x1, x2, x3) { cout << #x1 << \": \"; debug_print(cout,\
    \ x1) << \", \" << #x2 << \": \"; debug_print(cout, x2) << \", \" << #x3 << \"\
    : \"; debug_print(cout, x3) << endl; }\n#define debug_4(x1, x2, x3, x4) { cout\
    \ << #x1 << \": \"; debug_print(cout, x1) << \", \" << #x2 << \": \"; debug_print(cout,\
    \ x2) << \", \" << #x3 << \": \"; debug_print(cout, x3) << \", \" << #x4 << \"\
    : \"; debug_print(cout, x4) << endl; }\n#define debug_5(x1, x2, x3, x4, x5) {\
    \ cout << #x1 << \": \"; debug_print(cout, x1) << \", \" << #x2 << \": \"; debug_print(cout,\
    \ x2) << \", \" << #x3 << \": \"; debug_print(cout, x3) << \", \" << #x4 << \"\
    : \"; debug_print(cout, x4) << \", \" << #x5 << \": \"; debug_print(cout, x5)\
    \ << endl; }\n\n#ifdef LOCAL\n#define debug(...) CHOOSE((__VA_ARGS__, debug_5,\
    \ debug_4, debug_3, debug_2, debug_1, ~))(__VA_ARGS__)\n#else\n#define debug(...)\n\
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
    \    cout << '\\n';\n}\nvoid print(const string &s) {\n    cout << s << '\\n';\n\
    }\ntemplate <class Container, typename = void>\nstruct is_container : std::false_type\
    \ {};\ntemplate <class Container>\nstruct is_container<Container, std::void_t<decltype(std::declval<Container>().begin()),\
    \ decltype(std::declval<Container>().end())>> : std::true_type {};\ntemplate <class\
    \ Container>\ntypename enable_if<is_container<Container>::value>::type print(const\
    \ Container& x) {\n    if (!x.empty()) {\n        auto it = x.begin();\n     \
    \   for (; it != prev(x.end()); ++it) {\n            cout << *it << \" \";\n \
    \       }\n        cout << *it << \"\\n\";  // \u6700\u5F8C\u306E\u8981\u7D20\u3092\
    \u51FA\u529B\u3057\u3066\u6539\u884C\n    }\n}\n#define INT(...)             \
    \                                                  \\\n    int __VA_ARGS__;  \
    \                                                         \\\n    input(__VA_ARGS__)\n\
    #define LL(...)                                                              \
    \  \\\n    long long __VA_ARGS__;                                            \
    \         \\\n    input(__VA_ARGS__)\n#define STR(...)                       \
    \                                        \\\n    string __VA_ARGS__;         \
    \                                               \\\n    input(__VA_ARGS__)\n#define\
    \ REP1(a) for(ll i = 0; i < a; i++)\n#define REP2(i, a) for(ll i = 0; i < a; i++)\n\
    #define REP3(i, a, b) for(ll i = a; i < b; i++)\n#define REP4(i, a, b, c) for(ll\
    \ i = a; i < b; i += c)\n#define overload4(a, b, c, d, e, ...) e\n#define rep(...)\
    \ overload4(__VA_ARGS__, REP4, REP3, REP2, REP1)(__VA_ARGS__)\n\nll inf = 3e18;\n\
    vl dx = {1, -1, 0, 0};\nvl dy = {0, 0, 1, -1};\n#line 3 \"math/mod-pow.hpp\"\n\
    int mod_pow(int x, ll n, int mod) {\n    assert(n >= 0);\n    ll res = 1, xpow\
    \ = x;\n    while(n) {\n        if(n & 1) {\n            res = res * xpow % mod;\n\
    \        }\n        xpow = xpow * xpow % mod;\n        n >>= 1;\n    }\n    return\
    \ res;\n}\nll mod_pow_ll(ll x, ll n, ll mod) {\n    assert(n >= 0);\n    __int128\
    \ res = 1, xpow = x;\n    while(n) {\n        if(n & 1) {\n            res = res\
    \ * xpow % mod;\n        }\n        xpow = xpow * xpow % mod;\n        n >>= 1;\n\
    \    }\n    return res;\n}\n"
  code: "#pragma once\n#include \"template.hpp\"\nint mod_pow(int x, ll n, int mod)\
    \ {\n    assert(n >= 0);\n    ll res = 1, xpow = x;\n    while(n) {\n        if(n\
    \ & 1) {\n            res = res * xpow % mod;\n        }\n        xpow = xpow\
    \ * xpow % mod;\n        n >>= 1;\n    }\n    return res;\n}\nll mod_pow_ll(ll\
    \ x, ll n, ll mod) {\n    assert(n >= 0);\n    __int128 res = 1, xpow = x;\n \
    \   while(n) {\n        if(n & 1) {\n            res = res * xpow % mod;\n   \
    \     }\n        xpow = xpow * xpow % mod;\n        n >>= 1;\n    }\n    return\
    \ res;\n}"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: math/mod-pow.hpp
  requiredBy:
  - math/pollard_rho.hpp
  - math/primitive-root.hpp
  - math/miller_rabin.hpp
  - math/mod-sqrt.hpp
  timestamp: '2025-01-31 17:56:36+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/888.test.cpp
  - test/yukicoder/2051.test.cpp
  - test/library_checker/number_theory/primitive_root.test.cpp
  - test/library_checker/number_theory/sqrt_mod.test.cpp
  - test/library_checker/number_theory/factorize.test.cpp
  - test/library_checker/number_theory/primality_test.test.cpp
  - test/atcoder/abc180_c.test.cpp
  - test/atcoder/abc249_d.test.cpp
documentation_of: math/mod-pow.hpp
layout: document
redirect_from:
- /library/math/mod-pow.hpp
- /library/math/mod-pow.hpp.html
title: math/mod-pow.hpp
---
