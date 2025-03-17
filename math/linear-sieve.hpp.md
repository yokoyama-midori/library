---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
    \ dy = {0, 0, 1, -1};\n#line 3 \"math/linear-sieve.hpp\"\n// https://37zigen.com/linear-sieve/\n\
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
  timestamp: '2025-03-17 22:06:24+09:00'
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
