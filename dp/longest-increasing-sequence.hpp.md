---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/other/longest_increasing_subsequence.test.cpp
    title: test/library_checker/other/longest_increasing_subsequence.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \ dy = {0, 0, 1, -1};\n#line 3 \"dp/longest-increasing-sequence.hpp\"\ntemplate\
    \ <class T>\nvector<int> longest_increasing_sequence(const vector<T> &a,\n   \
    \                                     bool strong = true) {\n    int n = ssize(a);\n\
    \    if(n == 0) {\n        return {};\n    }\n    T infty = numeric_limits<T>::max();\n\
    \    vector<T> dp(n, infty);\n    vector<int> idx(n, -1);\n    vector<int> previous(n,\
    \ -1);\n    rep(i, n) {\n        int j =\n            (strong ? lower_bound(all(dp),\
    \ a[i]) : upper_bound(all(dp), a[i])) -\n            begin(dp);\n        dp[j]\
    \ = a[i];\n        idx[j] = i;\n        if(j)\n            previous[i] = idx[j\
    \ - 1];\n    }\n    vector<int> ans;\n    int now = n - 1;\n    while(dp[now]\
    \ == infty)\n        now--;\n    for(int i = idx[now]; i != -1; i = previous[i])\
    \ {\n        ans.emplace_back(i);\n    }\n    ranges::reverse(ans);\n    return\
    \ ans;\n}\n"
  code: "#pragma once\n#include \"template.hpp\"\ntemplate <class T>\nvector<int>\
    \ longest_increasing_sequence(const vector<T> &a,\n                          \
    \              bool strong = true) {\n    int n = ssize(a);\n    if(n == 0) {\n\
    \        return {};\n    }\n    T infty = numeric_limits<T>::max();\n    vector<T>\
    \ dp(n, infty);\n    vector<int> idx(n, -1);\n    vector<int> previous(n, -1);\n\
    \    rep(i, n) {\n        int j =\n            (strong ? lower_bound(all(dp),\
    \ a[i]) : upper_bound(all(dp), a[i])) -\n            begin(dp);\n        dp[j]\
    \ = a[i];\n        idx[j] = i;\n        if(j)\n            previous[i] = idx[j\
    \ - 1];\n    }\n    vector<int> ans;\n    int now = n - 1;\n    while(dp[now]\
    \ == infty)\n        now--;\n    for(int i = idx[now]; i != -1; i = previous[i])\
    \ {\n        ans.emplace_back(i);\n    }\n    ranges::reverse(ans);\n    return\
    \ ans;\n}"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: dp/longest-increasing-sequence.hpp
  requiredBy: []
  timestamp: '2025-03-17 22:44:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/other/longest_increasing_subsequence.test.cpp
documentation_of: dp/longest-increasing-sequence.hpp
layout: document
redirect_from:
- /library/dp/longest-increasing-sequence.hpp
- /library/dp/longest-increasing-sequence.hpp.html
title: dp/longest-increasing-sequence.hpp
---
