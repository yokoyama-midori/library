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
    vl dx = {1, -1, 0, 0};\nvl dy = {0, 0, 1, -1};\n#line 3 \"tree/rerooting.hpp\"\
    \n// https://atcoder.jp/contests/abc222/editorial/2749\n// https://nyaannyaan.github.io/library/tree/rerooting.hpp\n\
    // TreeType : Graph<Cost>\n// MergeFunc : Data(Data,Data)\n// ApplyFunc : Data(Data,int\
    \ from,int to,Cost)\n/*\nusing Data = ;\nusing Cost = ;\nGraph<Cost> g;\nData\
    \ leaf = ;\nauto merge = [](Data a, Data b) {};\nauto apply = [](Data data, int\
    \ from, int to, Cost cost) {};\nRerooting<Data, decltype(g), decltype(merge),\
    \ decltype(apply)> dp(\n    g, merge, apply, leaf);\n*/\ntemplate <class Data,\
    \ class TreeType, class MergeFunc, class ApplyFunc>\nstruct Rerooting {\n    const\
    \ TreeType &g;\n    const MergeFunc merge;\n    const ApplyFunc apply;\n    const\
    \ Data leaf;\n    vector<Data> dp, memo;\n    Rerooting(const TreeType &g, MergeFunc\
    \ merge, ApplyFunc apply, Data leaf)\n        : g(g), merge(merge), apply(apply),\
    \ leaf(leaf), dp(g.size(), leaf),\n          memo(g.size(), leaf) {\n        dfs1(0,\
    \ -1);\n        dfs2(0, -1, leaf);\n    }\n    const Data &operator[](int i) const\
    \ { return dp[i]; }\n\n    void dfs1(int cur, int p) {\n        for(auto &d :\
    \ g[cur]) {\n            if(d.to == p)\n                continue;\n          \
    \  dfs1(d.to, cur);\n            memo[cur] = merge(memo[cur], apply(memo[d.to],\
    \ d.to, cur, d.cost));\n        }\n    }\n    void dfs2(int cur, int p, const\
    \ Data &val) {\n        vector<Data> ds{val};\n        for(auto &d : g[cur]) {\n\
    \            if(d.to == p)\n                continue;\n            ds.emplace_back(apply(memo[d.to],\
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
  timestamp: '2025-03-16 14:03:42+09:00'
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
