---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/tree/tree_path_composite_sum.test.cpp
    title: test/library_checker/tree/tree_path_composite_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1718.test.cpp
    title: test/yukicoder/1718.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2677.test.cpp
    title: test/yukicoder/2677.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc222/editorial/2749
    - https://nyaannyaan.github.io/library/tree/rerooting.hpp
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
    \ dy = {0, 0, 1, -1};\n#line 3 \"tree/rerooting.hpp\"\n// https://atcoder.jp/contests/abc222/editorial/2749\n\
    // https://nyaannyaan.github.io/library/tree/rerooting.hpp\n// TreeType : Graph<Cost>\n\
    // MergeFunc : Data(Data,Data)\n// ApplyFunc : Data(Data,int from,int to,Cost)\n\
    /*\nusing Data = ;\nusing Cost = ;\nGraph<Cost> g;\nData leaf = ;\nauto merge\
    \ = [](Data a, Data b) {};\nauto apply = [](Data data, int from, int to, Cost\
    \ cost) {};\nRerooting<Data, decltype(g), decltype(merge), decltype(apply)> dp(\n\
    \    g, merge, apply, leaf);\n*/\ntemplate <class Data, class TreeType, class\
    \ MergeFunc, class ApplyFunc>\nstruct Rerooting {\n    const TreeType &g;\n  \
    \  const MergeFunc merge;\n    const ApplyFunc apply;\n    const Data leaf;\n\
    \    vector<Data> dp, memo;\n    Rerooting(const TreeType &g, MergeFunc merge,\
    \ ApplyFunc apply, Data leaf)\n        : g(g), merge(merge), apply(apply), leaf(leaf),\
    \ dp(g.size(), leaf),\n          memo(g.size(), leaf) {\n        dfs1(0, -1);\n\
    \        dfs2(0, -1, leaf);\n    }\n    const Data &operator[](int i) const {\
    \ return dp[i]; }\n\n    void dfs1(int cur, int p) {\n        for(auto &d : g[cur])\
    \ {\n            if(d.to == p)\n                continue;\n            dfs1(d.to,\
    \ cur);\n            memo[cur] = merge(memo[cur], apply(memo[d.to], d.to, cur,\
    \ d.cost));\n        }\n    }\n    void dfs2(int cur, int p, const Data &val)\
    \ {\n        vector<Data> ds{val};\n        for(auto &d : g[cur]) {\n        \
    \    if(d.to == p)\n                continue;\n            ds.emplace_back(apply(memo[d.to],\
    \ d.to, cur, d.cost));\n        }\n        vector<Data> left(ds.size() + 1, leaf),\
    \ right(ds.size() + 1, leaf);\n        for(int i = 0; i + 1 < left.size(); i++)\n\
    \            left[i + 1] = merge(left[i], ds[i]);\n        for(int i = ssize(right)\
    \ - 2; 0 < i; i--)\n            right[i] = merge(right[i + 1], ds[i]);\n     \
    \   dp[cur] = left.back();\n        int idx = 1;\n        for(auto &d : g[cur])\
    \ {\n            if(d.to == p)\n                continue;\n            Data tmp\
    \ = merge(left[idx], right[idx + 1]);\n            tmp = apply(tmp, cur, d.to,\
    \ d.cost);\n            dfs2(d.to, cur, tmp);\n            idx++;\n        }\n\
    \    }\n};\n"
  code: "#pragma once\n#include \"template.hpp\"\n// https://atcoder.jp/contests/abc222/editorial/2749\n\
    // https://nyaannyaan.github.io/library/tree/rerooting.hpp\n// TreeType : Graph<Cost>\n\
    // MergeFunc : Data(Data,Data)\n// ApplyFunc : Data(Data,int from,int to,Cost)\n\
    /*\nusing Data = ;\nusing Cost = ;\nGraph<Cost> g;\nData leaf = ;\nauto merge\
    \ = [](Data a, Data b) {};\nauto apply = [](Data data, int from, int to, Cost\
    \ cost) {};\nRerooting<Data, decltype(g), decltype(merge), decltype(apply)> dp(\n\
    \    g, merge, apply, leaf);\n*/\ntemplate <class Data, class TreeType, class\
    \ MergeFunc, class ApplyFunc>\nstruct Rerooting {\n    const TreeType &g;\n  \
    \  const MergeFunc merge;\n    const ApplyFunc apply;\n    const Data leaf;\n\
    \    vector<Data> dp, memo;\n    Rerooting(const TreeType &g, MergeFunc merge,\
    \ ApplyFunc apply, Data leaf)\n        : g(g), merge(merge), apply(apply), leaf(leaf),\
    \ dp(g.size(), leaf),\n          memo(g.size(), leaf) {\n        dfs1(0, -1);\n\
    \        dfs2(0, -1, leaf);\n    }\n    const Data &operator[](int i) const {\
    \ return dp[i]; }\n\n    void dfs1(int cur, int p) {\n        for(auto &d : g[cur])\
    \ {\n            if(d.to == p)\n                continue;\n            dfs1(d.to,\
    \ cur);\n            memo[cur] = merge(memo[cur], apply(memo[d.to], d.to, cur,\
    \ d.cost));\n        }\n    }\n    void dfs2(int cur, int p, const Data &val)\
    \ {\n        vector<Data> ds{val};\n        for(auto &d : g[cur]) {\n        \
    \    if(d.to == p)\n                continue;\n            ds.emplace_back(apply(memo[d.to],\
    \ d.to, cur, d.cost));\n        }\n        vector<Data> left(ds.size() + 1, leaf),\
    \ right(ds.size() + 1, leaf);\n        for(int i = 0; i + 1 < left.size(); i++)\n\
    \            left[i + 1] = merge(left[i], ds[i]);\n        for(int i = ssize(right)\
    \ - 2; 0 < i; i--)\n            right[i] = merge(right[i + 1], ds[i]);\n     \
    \   dp[cur] = left.back();\n        int idx = 1;\n        for(auto &d : g[cur])\
    \ {\n            if(d.to == p)\n                continue;\n            Data tmp\
    \ = merge(left[idx], right[idx + 1]);\n            tmp = apply(tmp, cur, d.to,\
    \ d.cost);\n            dfs2(d.to, cur, tmp);\n            idx++;\n        }\n\
    \    }\n};"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: tree/rerooting.hpp
  requiredBy: []
  timestamp: '2025-03-17 22:44:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/tree/tree_path_composite_sum.test.cpp
  - test/yukicoder/1718.test.cpp
  - test/yukicoder/2677.test.cpp
documentation_of: tree/rerooting.hpp
layout: document
redirect_from:
- /library/tree/rerooting.hpp
- /library/tree/rerooting.hpp.html
title: tree/rerooting.hpp
---
