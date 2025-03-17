---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2896.test.cpp
    title: test/yukicoder/2896.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://37zigen.com/linear-sieve/
  bundledCode: "#line 2 \"template.hpp\"\n// #pragma GCC target(\"avx2\")\n// #pragma\
    \ GCC optimize(\"O3\")\n// #pragma GCC optimize(\"unroll-loops\")\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n// https://xn--kst.jp/blog/2019/08/29/cpp-comp/\n\
    \ntemplate <class Container, typename = void>\nstruct is_container : std::false_type\
    \ {};\ntemplate <class Container>\nstruct is_container<Container, std::void_t<decltype(std::declval<Container>().begin()),\
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
    vl dx = {1, -1, 0, 0};\nvl dy = {0, 0, 1, -1};\n#line 3 \"math/linear-sieve.hpp\"\
    \n// https://37zigen.com/linear-sieve/\n// AtCoder codetest\n// 1e6   7ms 7.5MB\n\
    // 1e7  53ms  46MB\n// 1e8 650ms 426MB\nstruct LinearSieve {\n    int max_value;\n\
    \    // lpf[i] = i\u306E\u6700\u5C0F\u7D20\u56E0\u6570(least prime factor)\n \
    \   vector<int> lpf, primes;\n    LinearSieve(int max_value) : max_value(max_value),\
    \ lpf(max_value + 1, 1) {\n        for(int i = 2; i <= max_value; ++i) {\n   \
    \         if(lpf[i] == 1) {\n                lpf[i] = i;\n                primes.emplace_back(i);\n\
    \            }\n            for(auto p : primes) {\n                if(p * i >\
    \ max_value or p > lpf[i])\n                    break;\n                lpf[p\
    \ * i] = p;\n            }\n        }\n    }\n    vector<int> factorize(int n)\
    \ {\n        vector<int> res;\n        while(n > 1) {\n            res.emplace_back(lpf[n]);\n\
    \            n /= lpf[n];\n        }\n        return res;\n    }\n    vector<pair<int,\
    \ int>> factor_count(int n) {\n        vector<pair<int, int>> res;\n        while(n\
    \ > 1) {\n            if(res.empty() or res.back().first != lpf[n])\n        \
    \        res.emplace_back(lpf[n], 0);\n            ++res.back().second;\n    \
    \        n /= lpf[n];\n        }\n        return res;\n    }\n};\n"
  code: "#pragma once\n#include \"template.hpp\"\n// https://37zigen.com/linear-sieve/\n\
    // AtCoder codetest\n// 1e6   7ms 7.5MB\n// 1e7  53ms  46MB\n// 1e8 650ms 426MB\n\
    struct LinearSieve {\n    int max_value;\n    // lpf[i] = i\u306E\u6700\u5C0F\u7D20\
    \u56E0\u6570(least prime factor)\n    vector<int> lpf, primes;\n    LinearSieve(int\
    \ max_value) : max_value(max_value), lpf(max_value + 1, 1) {\n        for(int\
    \ i = 2; i <= max_value; ++i) {\n            if(lpf[i] == 1) {\n             \
    \   lpf[i] = i;\n                primes.emplace_back(i);\n            }\n    \
    \        for(auto p : primes) {\n                if(p * i > max_value or p > lpf[i])\n\
    \                    break;\n                lpf[p * i] = p;\n            }\n\
    \        }\n    }\n    vector<int> factorize(int n) {\n        vector<int> res;\n\
    \        while(n > 1) {\n            res.emplace_back(lpf[n]);\n            n\
    \ /= lpf[n];\n        }\n        return res;\n    }\n    vector<pair<int, int>>\
    \ factor_count(int n) {\n        vector<pair<int, int>> res;\n        while(n\
    \ > 1) {\n            if(res.empty() or res.back().first != lpf[n])\n        \
    \        res.emplace_back(lpf[n], 0);\n            ++res.back().second;\n    \
    \        n /= lpf[n];\n        }\n        return res;\n    }\n};"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: math/linear-sieve.hpp
  requiredBy: []
  timestamp: '2025-03-17 11:03:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/2896.test.cpp
documentation_of: math/linear-sieve.hpp
layout: document
redirect_from:
- /library/math/linear-sieve.hpp
- /library/math/linear-sieve.hpp.html
title: math/linear-sieve.hpp
---
