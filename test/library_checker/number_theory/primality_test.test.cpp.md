---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/miller_rabin.hpp
    title: math/miller_rabin.hpp
  - icon: ':heavy_check_mark:'
    path: math/mod-pow.hpp
    title: math/mod-pow.hpp
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/primality_test
    links:
    - https://judge.yosupo.jp/problem/primality_test
  bundledCode: "#line 1 \"test/library_checker/number_theory/primality_test.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/primality_test\"\n#line 2\
    \ \"template.hpp\"\n// #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"\
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
    \ dy = {0, 0, 1, -1};\n#line 3 \"math/mod-pow.hpp\"\nint mod_pow(int x, ll n,\
    \ int mod) {\n    assert(n >= 0);\n    ll res = 1, xpow = x;\n    while(n) {\n\
    \        if(n & 1) {\n            res = res * xpow % mod;\n        }\n       \
    \ xpow = xpow * xpow % mod;\n        n >>= 1;\n    }\n    return res;\n}\nll mod_pow_ll(ll\
    \ x, ll n, ll mod) {\n    assert(n >= 0);\n    __int128 res = 1, xpow = x;\n \
    \   while(n) {\n        if(n & 1) {\n            res = res * xpow % mod;\n   \
    \     }\n        xpow = xpow * xpow % mod;\n        n >>= 1;\n    }\n    return\
    \ res;\n}\n#line 4 \"math/miller_rabin.hpp\"\n// https://drken1215.hatenablog.com/entry/2023/05/23/233000\n\
    // todo \u30E2\u30F3\u30B4\u30E1\u30EA\u4E57\u7B97\nbool is_prime(ll n) {\n  \
    \  if(n == 2 or n == 7 or n == 61) {\n        return true;\n    }\n    if(n %\
    \ 2 == 0 or n == 1) {\n        return false;\n    }\n    ll d = n - 1;\n    ll\
    \ s = 0;\n    while(d % 2 == 0) {\n        d >>= 1;\n        s++;\n    }\n   \
    \ auto check = [&](ll a) {\n        ll ad = mod_pow_ll(a, d, n);\n        if(ad\
    \ == 1) {\n            return true;\n        }\n        rep(i, s) {\n        \
    \    if(ad == n - 1) {\n                return true;\n            }\n        \
    \    if(i < s - 1)\n                ad = mod_pow_ll(ad, 2, n);\n        }\n  \
    \      return false;\n    };\n    if(n < 4759123141) {\n        for(auto a : vl{2,\
    \ 7, 61}) {\n            if(!check(a)) {\n                return false;\n    \
    \        }\n        }\n        return true;\n    } else {\n        for(auto a\
    \ : vl{2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {\n            if(n\
    \ == a) {\n                return true;\n            }\n            if(!check(a))\
    \ {\n                return false;\n            }\n        }\n        return true;\n\
    \    }\n}\n#line 4 \"test/library_checker/number_theory/primality_test.test.cpp\"\
    \nvoid solve() {\n    LL(n);\n    rep(_, n) {\n        LL(a);\n        print(is_prime(a)\
    \ ? \"Yes\" : \"No\");\n    }\n}\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/primality_test\"\n#include\
    \ \"template.hpp\"\n#include \"math/miller_rabin.hpp\"\nvoid solve() {\n    LL(n);\n\
    \    rep(_, n) {\n        LL(a);\n        print(is_prime(a) ? \"Yes\" : \"No\"\
    );\n    }\n}\nint main() {\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    solve();\n}\n"
  dependsOn:
  - template.hpp
  - math/miller_rabin.hpp
  - math/mod-pow.hpp
  isVerificationFile: true
  path: test/library_checker/number_theory/primality_test.test.cpp
  requiredBy: []
  timestamp: '2025-03-17 22:44:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/number_theory/primality_test.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/number_theory/primality_test.test.cpp
- /verify/test/library_checker/number_theory/primality_test.test.cpp.html
title: test/library_checker/number_theory/primality_test.test.cpp
---
