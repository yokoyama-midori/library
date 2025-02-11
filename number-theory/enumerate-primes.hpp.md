---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: number-theory/divisor-multiple-transform.hpp
    title: number-theory/divisor-multiple-transform.hpp
  - icon: ':heavy_check_mark:'
    path: number-theory/gcd-convolution.hpp
    title: number-theory/gcd-convolution.hpp
  - icon: ':heavy_check_mark:'
    path: number-theory/lcm-convolution.hpp
    title: number-theory/lcm-convolution.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/number_theory/enumerate_primes.test.cpp
    title: test/library_checker/number_theory/enumerate_primes.test.cpp
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
    links:
    - https://nyaannyaan.github.io/library/prime/prime-enumerate.hpp
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
    vl dx = {1, -1, 0, 0};\nvl dy = {0, 0, 1, -1};\n#line 3 \"number-theory/enumerate-primes.hpp\"\
    \n// https://nyaannyaan.github.io/library/prime/prime-enumerate.hpp\ntemplate\
    \ <class T = int> vector<T> enumerate_primes(int n) {\n    // Returns primes less\
    \ than or equal to n in ascending order\n    if(n < 2)\n        return {};\n \
    \   if(n < 3)\n        return {2};\n    vector<bool> sieve(n / 3 + 1, true);\n\
    \    // prime candidates : 6*i \xB1 1 (for p >= 5)\n    // sieve[i] : is i-th\
    \ element of {1,5,7,11,13,...,6*j-1,6*j+1,...} prime?\n    for(int i = 1, p =\
    \ 5, d = 4; p * p <= n; i++, p += d = 6 - d) {\n        if(!sieve[i])\n      \
    \      continue;\n        for(int q = p * p, e = d; q <= n; q += (e = 6 - e) *\
    \ p) {\n            sieve[q / 3] = false;\n        }\n    }\n    vector<T> primes\
    \ = {2, 3};\n    for(int i = 1, p = 5, d = 4; p <= n; i++, p += d = 6 - d) {\n\
    \        if(sieve[i]) {\n            primes.emplace_back(p);\n        }\n    }\n\
    \    return primes;\n}\n"
  code: "#pragma once\n#include \"template.hpp\"\n// https://nyaannyaan.github.io/library/prime/prime-enumerate.hpp\n\
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
    \    return primes;\n}\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: number-theory/enumerate-primes.hpp
  requiredBy:
  - number-theory/lcm-convolution.hpp
  - number-theory/gcd-convolution.hpp
  - number-theory/divisor-multiple-transform.hpp
  timestamp: '2025-01-08 13:17:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/number_theory/lcm_convolution.test.cpp
  - test/library_checker/number_theory/gcd_convolution.test.cpp
  - test/library_checker/number_theory/enumerate_primes.test.cpp
documentation_of: number-theory/enumerate-primes.hpp
layout: document
redirect_from:
- /library/number-theory/enumerate-primes.hpp
- /library/number-theory/enumerate-primes.hpp.html
title: number-theory/enumerate-primes.hpp
---
