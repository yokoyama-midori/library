---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/mod-sqrt.hpp
    title: math/mod-sqrt.hpp
  - icon: ':heavy_check_mark:'
    path: string/wildcard-pattern-matching.hpp
    title: string/wildcard-pattern-matching.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/number_theory/sqrt_mod.test.cpp
    title: test/library_checker/number_theory/sqrt_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/wildcard_pattern_matching.test.cpp
    title: test/library_checker/string/wildcard_pattern_matching.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/my-test/splaytree.test.cpp
    title: test/my-test/splaytree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://maspypy.github.io/library/random/base.hpp
  bundledCode: "#line 2 \"rng.hpp\"\n// https://maspypy.github.io/library/random/base.hpp\n\
    #line 2 \"template.hpp\"\n// #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"\
    O3\")\n// #pragma GCC optimize(\"unroll-loops\")\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n// https://xn--kst.jp/blog/2019/08/29/cpp-comp/\n\ntemplate\
    \ <class Container, typename = void>\nstruct is_container : std::false_type {};\n\
    template <class Container>\nstruct is_container<Container, std::void_t<decltype(std::declval<Container>().begin()),\
    \ decltype(std::declval<Container>().end())>> : std::true_type {};\n\ntemplate\
    \ <typename Container>\nenable_if_t<is_container<Container>::value, ostream&>\
    \ \ndebug_print(ostream& os, const Container& container) {\n    os << \"[\";\n\
    \    auto it = container.begin();\n    for (; it != container.end(); ++it) {\n\
    \        if (it != container.begin()) os << \", \";\n        os << *it;\n    }\n\
    \    os << \"]\";\n    return os;\n}\ntemplate <typename T>\nenable_if_t<!is_container<T>::value,\
    \ ostream&> \ndebug_print(ostream& os, const T& var) {\n    os << var;\n    return\
    \ os;\n}\n#define CHOOSE(a) CHOOSE2 a\n#define CHOOSE2(a0, a1, a2, a3, a4, x,\
    \ ...) x\n#define debug_1(x1) { cout << #x1 << \": \"; debug_print(cout, x1) <<\
    \ endl; }\n#define debug_2(x1, x2) { cout << #x1 << \": \"; debug_print(cout,\
    \ x1) << \", \" << #x2 << \": \"; debug_print(cout, x2) << endl; }\n#define debug_3(x1,\
    \ x2, x3) { cout << #x1 << \": \"; debug_print(cout, x1) << \", \" << #x2 << \"\
    : \"; debug_print(cout, x2) << \", \" << #x3 << \": \"; debug_print(cout, x3)\
    \ << endl; }\n#define debug_4(x1, x2, x3, x4) { cout << #x1 << \": \"; debug_print(cout,\
    \ x1) << \", \" << #x2 << \": \"; debug_print(cout, x2) << \", \" << #x3 << \"\
    : \"; debug_print(cout, x3) << \", \" << #x4 << \": \"; debug_print(cout, x4)\
    \ << endl; }\n#define debug_5(x1, x2, x3, x4, x5) { cout << #x1 << \": \"; debug_print(cout,\
    \ x1) << \", \" << #x2 << \": \"; debug_print(cout, x2) << \", \" << #x3 << \"\
    : \"; debug_print(cout, x3) << \", \" << #x4 << \": \"; debug_print(cout, x4)\
    \ << \", \" << #x5 << \": \"; debug_print(cout, x5) << endl; }\n\n#ifdef LOCAL\n\
    #define debug(...) CHOOSE((__VA_ARGS__, debug_5, debug_4, debug_3, debug_2, debug_1,\
    \ ~))(__VA_ARGS__)\n#else\n#define debug(...)\n#endif\n\nusing ll = long long;\n\
    using vl = vector<ll>;\nusing vll = vector<vl>;\nusing P = pair<ll, ll>;\n#define\
    \ all(v) v.begin(), v.end()\ntemplate <typename T> inline bool chmax(T &a, T b)\
    \ {\n    return ((a < b) ? (a = b, true) : (false));\n}\ntemplate <typename T>\
    \ inline bool chmin(T &a, T b) {\n    return ((a > b) ? (a = b, true) : (false));\n\
    }\n#define rep1(i, n) for(ll i = 1; i <= ((ll)n); ++i)\n// https://trap.jp/post/1224/\n\
    template <class... T> constexpr auto min(T... a) {\n    return min(initializer_list<common_type_t<T...>>{a...});\n\
    }\ntemplate <class... T> constexpr auto max(T... a) {\n    return max(initializer_list<common_type_t<T...>>{a...});\n\
    }\ntemplate <class... T> void input(T &...a) { (cin >> ... >> a); }\ntemplate\
    \ <class T> void input(vector<T> &a) {\n    for(T &x : a)\n        cin >> x;\n\
    }\nvoid print() { cout << '\\n'; }\ntemplate <class T, class... Ts> void print(const\
    \ T &a, const Ts &...b) {\n    cout << a;\n    (cout << ... << (cout << ' ', b));\n\
    \    cout << '\\n';\n}\nvoid print(const string &s) {\n    cout << s << '\\n';\n\
    }\ntemplate <class Container>\nenable_if_t<is_container<Container>::value> print(const\
    \ Container& container) {\n    auto it = container.begin();\n    for(;it != container.end();\
    \ ++it){\n        if(it != container.begin())\n            cout << \" \";\n  \
    \      cout << *it;\n    }\n    cout << '\\n';\n}\n#define INT(...)          \
    \                                                     \\\n    int __VA_ARGS__;\
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
    vl dx = {1, -1, 0, 0};\nvl dy = {0, 0, 1, -1};\n#line 4 \"rng.hpp\"\nunsigned\
    \ long long RNG_64() {\n    static unsigned long long x_ =\n        (unsigned\
    \ long long)(chrono::duration_cast<chrono::nanoseconds>(\n                   \
    \              chrono::high_resolution_clock::now()\n                        \
    \             .time_since_epoch())\n                                 .count())\
    \ *\n        10150724397891781847ULL;\n    x_ ^= x_ << 7;\n    return x_ ^= x_\
    \ >> 9;\n}\n\nunsigned long long RNG(unsigned long long lim) { return RNG_64()\
    \ % lim; }\n\nll rng(ll l, ll r) {\n    // [l,r)\n    return l + RNG_64() % (r\
    \ - l);\n}\n"
  code: "#pragma once\n// https://maspypy.github.io/library/random/base.hpp\n#include\
    \ \"template.hpp\"\nunsigned long long RNG_64() {\n    static unsigned long long\
    \ x_ =\n        (unsigned long long)(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                                 chrono::high_resolution_clock::now()\n     \
    \                                .time_since_epoch())\n                      \
    \           .count()) *\n        10150724397891781847ULL;\n    x_ ^= x_ << 7;\n\
    \    return x_ ^= x_ >> 9;\n}\n\nunsigned long long RNG(unsigned long long lim)\
    \ { return RNG_64() % lim; }\n\nll rng(ll l, ll r) {\n    // [l,r)\n    return\
    \ l + RNG_64() % (r - l);\n}"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: rng.hpp
  requiredBy:
  - math/mod-sqrt.hpp
  - string/wildcard-pattern-matching.hpp
  timestamp: '2025-03-16 14:03:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/number_theory/sqrt_mod.test.cpp
  - test/library_checker/string/wildcard_pattern_matching.test.cpp
  - test/my-test/splaytree.test.cpp
documentation_of: rng.hpp
layout: document
redirect_from:
- /library/rng.hpp
- /library/rng.hpp.html
title: rng.hpp
---
