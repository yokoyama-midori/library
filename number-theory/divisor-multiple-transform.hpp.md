---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: number-theory/enumerate-primes.hpp
    title: number-theory/enumerate-primes.hpp
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: number-theory/gcd-convolution.hpp
    title: number-theory/gcd-convolution.hpp
  - icon: ':heavy_check_mark:'
    path: number-theory/lcm-convolution.hpp
    title: number-theory/lcm-convolution.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/number_theory/gcd_convolution.test.cpp
    title: test/library_checker/number_theory/gcd_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/number_theory/lcm_convolution.test.cpp
    title: test/library_checker/number_theory/lcm_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ dy = {0, 0, 1, -1};\n#line 3 \"number-theory/enumerate-primes.hpp\"\n// https://nyaannyaan.github.io/library/prime/prime-enumerate.hpp\n\
    template <class T = int> vector<T> enumerate_primes(int n) {\n    // Returns primes\
    \ less than or equal to n in ascending order\n    if(n < 2)\n        return {};\n\
    \    if(n < 3)\n        return {2};\n    vector<bool> sieve(n / 3 + 1, true);\n\
    \    // prime candidates : 6*i \xB1 1 (for p >= 5)\n    // sieve[i] : is i-th\
    \ element of {1,5,7,11,13,...,6*j-1,6*j+1,...} prime?\n    for(int i = 1, p =\
    \ 5, d = 4; p * p <= n; i++, p += d = 6 - d) {\n        if(!sieve[i])\n      \
    \      continue;\n        for(int q = p * p, e = d; q <= n; q += (e = 6 - e) *\
    \ p) {\n            sieve[q / 3] = false;\n        }\n    }\n    vector<T> primes\
    \ = {2, 3};\n    for(int i = 1, p = 5, d = 4; p <= n; i++, p += d = 6 - d) {\n\
    \        if(sieve[i]) {\n            primes.emplace_back(p);\n        }\n    }\n\
    \    return primes;\n}\n#line 4 \"number-theory/divisor-multiple-transform.hpp\"\
    \ntemplate <class mint> void divisor_zeta(vector<mint> &a) {\n    // a = {0,a_1,...,a_n};\n\
    \    int n = ssize(a) - 1;\n    for(auto &p : enumerate_primes(n)) {\n       \
    \ for(int i = 1; i * p <= n; i++) {\n            a[i * p] += a[i];\n        }\n\
    \    }\n}\ntemplate <class mint> void divisor_mebius(vector<mint> &a) {\n    int\
    \ n = ssize(a) - 1;\n    for(auto &p : enumerate_primes(n)) {\n        for(int\
    \ i = n / p; i > 0; i--) {\n            a[i * p] -= a[i];\n        }\n    }\n\
    }\ntemplate <class mint> void multiple_zeta(vector<mint> &a) {\n    int n = ssize(a)\
    \ - 1;\n    for(auto &p : enumerate_primes(n)) {\n        for(int i = n / p; i\
    \ > 0; i--) {\n            a[i] += a[i * p];\n        }\n    }\n}\ntemplate <class\
    \ mint> void multiple_mebius(vector<mint> &a) {\n    int n = ssize(a) - 1;\n \
    \   for(auto &p : enumerate_primes(n)) {\n        for(int i = 1; i * p <= n; i++)\
    \ {\n            a[i] -= a[i * p];\n        }\n    }\n}\n"
  code: "#pragma once\n#include \"number-theory/enumerate-primes.hpp\"\n#include \"\
    template.hpp\"\ntemplate <class mint> void divisor_zeta(vector<mint> &a) {\n \
    \   // a = {0,a_1,...,a_n};\n    int n = ssize(a) - 1;\n    for(auto &p : enumerate_primes(n))\
    \ {\n        for(int i = 1; i * p <= n; i++) {\n            a[i * p] += a[i];\n\
    \        }\n    }\n}\ntemplate <class mint> void divisor_mebius(vector<mint> &a)\
    \ {\n    int n = ssize(a) - 1;\n    for(auto &p : enumerate_primes(n)) {\n   \
    \     for(int i = n / p; i > 0; i--) {\n            a[i * p] -= a[i];\n      \
    \  }\n    }\n}\ntemplate <class mint> void multiple_zeta(vector<mint> &a) {\n\
    \    int n = ssize(a) - 1;\n    for(auto &p : enumerate_primes(n)) {\n       \
    \ for(int i = n / p; i > 0; i--) {\n            a[i] += a[i * p];\n        }\n\
    \    }\n}\ntemplate <class mint> void multiple_mebius(vector<mint> &a) {\n   \
    \ int n = ssize(a) - 1;\n    for(auto &p : enumerate_primes(n)) {\n        for(int\
    \ i = 1; i * p <= n; i++) {\n            a[i] -= a[i * p];\n        }\n    }\n\
    }"
  dependsOn:
  - number-theory/enumerate-primes.hpp
  - template.hpp
  isVerificationFile: false
  path: number-theory/divisor-multiple-transform.hpp
  requiredBy:
  - number-theory/lcm-convolution.hpp
  - number-theory/gcd-convolution.hpp
  timestamp: '2025-03-17 22:44:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/number_theory/gcd_convolution.test.cpp
  - test/library_checker/number_theory/lcm_convolution.test.cpp
documentation_of: number-theory/divisor-multiple-transform.hpp
layout: document
redirect_from:
- /library/number-theory/divisor-multiple-transform.hpp
- /library/number-theory/divisor-multiple-transform.hpp.html
title: number-theory/divisor-multiple-transform.hpp
---
