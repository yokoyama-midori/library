---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/tree/tree_diameter.test.cpp
    title: test/library_checker/tree/tree_diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
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
    vl dx = {1, -1, 0, 0};\nvl dy = {0, 0, 1, -1};\n#line 3 \"tree/tree-diameter.hpp\"\
    \n// dist : distance from d1\ntemplate <class TreeType> struct TreeDiamter {\n\
    \    TreeType &g;\n    using T = typename TreeType::cost_type;\n    vector<T>\
    \ dist;\n    int d1, d2;\n    TreeDiamter(TreeType &g) : g(g), dist(g.size(),\
    \ -1) {\n        d1 = bfs(0);\n        dist = vector<T>(g.size(), -1);\n     \
    \   d2 = bfs(d1);\n    }\n    vector<int> get_path() const {\n        vector<int>\
    \ res = {d2};\n        int cur = d2;\n        while(cur != d1) {\n           \
    \ for(auto &e : g[cur]) {\n                if(dist[e.to] + e.cost == dist[cur])\
    \ {\n                    cur = e.to;\n                    res.emplace_back(cur);\n\
    \                    break;\n                }\n            }\n        }\n   \
    \     ranges::reverse(res);\n        return res;\n    }\n\n  private:\n    int\
    \ bfs(int root) {\n        queue<int> que;\n        que.push(root);\n        dist[root]\
    \ = 0;\n        while(que.size()) {\n            int cur = que.front();\n    \
    \        que.pop();\n            for(auto &e : g[cur]) {\n                if(dist[e.to]\
    \ != -1)\n                    continue;\n                dist[e.to] = dist[cur]\
    \ + e.cost;\n                que.push(e.to);\n            }\n        }\n     \
    \   return ranges::max_element(dist) - begin(dist);\n    }\n};\n"
  code: "#pragma once\n#include \"template.hpp\"\n// dist : distance from d1\ntemplate\
    \ <class TreeType> struct TreeDiamter {\n    TreeType &g;\n    using T = typename\
    \ TreeType::cost_type;\n    vector<T> dist;\n    int d1, d2;\n    TreeDiamter(TreeType\
    \ &g) : g(g), dist(g.size(), -1) {\n        d1 = bfs(0);\n        dist = vector<T>(g.size(),\
    \ -1);\n        d2 = bfs(d1);\n    }\n    vector<int> get_path() const {\n   \
    \     vector<int> res = {d2};\n        int cur = d2;\n        while(cur != d1)\
    \ {\n            for(auto &e : g[cur]) {\n                if(dist[e.to] + e.cost\
    \ == dist[cur]) {\n                    cur = e.to;\n                    res.emplace_back(cur);\n\
    \                    break;\n                }\n            }\n        }\n   \
    \     ranges::reverse(res);\n        return res;\n    }\n\n  private:\n    int\
    \ bfs(int root) {\n        queue<int> que;\n        que.push(root);\n        dist[root]\
    \ = 0;\n        while(que.size()) {\n            int cur = que.front();\n    \
    \        que.pop();\n            for(auto &e : g[cur]) {\n                if(dist[e.to]\
    \ != -1)\n                    continue;\n                dist[e.to] = dist[cur]\
    \ + e.cost;\n                que.push(e.to);\n            }\n        }\n     \
    \   return ranges::max_element(dist) - begin(dist);\n    }\n};\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: tree/tree-diameter.hpp
  requiredBy: []
  timestamp: '2025-03-16 14:03:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/tree/tree_diameter.test.cpp
documentation_of: tree/tree-diameter.hpp
layout: document
redirect_from:
- /library/tree/tree-diameter.hpp
- /library/tree/tree-diameter.hpp.html
title: tree/tree-diameter.hpp
---
