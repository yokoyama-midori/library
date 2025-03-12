---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1040.test.cpp
    title: test/aoj/1040.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/114.test.cpp
    title: test/yukicoder/114.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
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
    #endif\n\nusing ll = long long;\nusing vl = vector<ll>;\nusing vll = vector<vl>;\n\
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
    vl dx = {1, -1, 0, 0};\nvl dy = {0, 0, 1, -1};\n#line 3 \"graph/graph-template.hpp\"\
    \n// https://ei1333.github.io/library/graph/graph-template.hpp\ntemplate <class\
    \ T = ll> struct Edge {\n    int from, to;\n    T cost;\n    int idx;\n    Edge()\
    \ = default;\n    Edge(int from, int to, T cost = 1, int idx = -1)\n        :\
    \ from(from), to(to), cost(cost), idx(idx) {}\n    Edge &operator=(const int &x)\
    \ {\n        to = x;\n        return *this;\n    }\n    operator int() const {\
    \ return to; }\n};\ntemplate <class T = ll> struct Graph {\n    using cost_type\
    \ = T;\n    vector<vector<Edge<T>>> g;\n    int es; // edge_size\n    Graph(int\
    \ n) : g(n), es(0) {};\n    int size() const { return ssize(g); }\n    void add_directed_edge(int\
    \ from, int to, T cost = 1) {\n        g[from].emplace_back(from, to, cost, es++);\n\
    \    }\n    void add_edge(int from, int to, T cost = 1) {\n        g[from].emplace_back(from,\
    \ to, cost, es);\n        g[to].emplace_back(to, from, cost, es++);\n    }\n \
    \   vector<Edge<T>> &operator[](const int &k) { return g[k]; }\n    const vector<Edge<T>>\
    \ &operator[](const int &k) const { return g[k]; }\n    void read(int m, int padding\
    \ = -1, bool weighted = false,\n              bool directed = false) {\n     \
    \   rep(i, m) {\n            int a, b;\n            T c(1);\n            cin >>\
    \ a >> b;\n            a += padding;\n            b += padding;\n            if(weighted)\n\
    \                cin >> c;\n            if(directed)\n                add_directed_edge(a,\
    \ b, c);\n            else\n                add_edge(a, b, c);\n        }\n  \
    \  }\n};\n#line 3 \"graph/minimum-steiner-tree.hpp\"\ntemplate <class T = ll>\
    \ struct MinimumSteinerTree {\n    int n, k;\n    vector<int> terminal;\n    T\
    \ cost;\n    const T infty = numeric_limits<T>::max();\n    vector<vector<T>>\
    \ dp;\n    MinimumSteinerTree(const Graph<T> &g, const vector<int> terminal)\n\
    \        : n(g.size()), k(terminal.size()), terminal(terminal), cost(0),\n   \
    \       dp(1 << k, vector<T>(n, infty)) {\n        assert(!terminal.empty());\n\
    \        rep(i, k) { dp[1 << i][terminal[i]] = 0; }\n        rep(bit, 1, 1 <<\
    \ k) {\n            rep(i, n) {\n                for(int sub = (bit - 1) & bit;\
    \ sub > 0; sub = (sub - 1) & bit) {\n                    if(dp[sub][i] != infty\
    \ and dp[bit ^ sub][i] != infty)\n                        chmin(dp[bit][i], dp[sub][i]\
    \ + dp[bit ^ sub][i]);\n                }\n            }\n            using pti\
    \ = pair<T, int>;\n            priority_queue<pti, vector<pti>, greater<pti>>\
    \ pq;\n            rep(i, n) pq.push(pti(dp[bit][i], i));\n            while(pq.size())\
    \ {\n                auto [c, v] = pq.top();\n                pq.pop();\n    \
    \            if(c != dp[bit][v] or c == infty)\n                    continue;\n\
    \                for(auto &e : g[v]) {\n                    T nc = c + e.cost;\n\
    \                    if(chmin(dp[bit][e.to], nc))\n                        pq.push(pti(nc,\
    \ e.to));\n                }\n            }\n        }\n        cost = dp.back()[terminal.front()];\n\
    \    }\n};\n"
  code: "#pragma once\n#include \"graph/graph-template.hpp\"\ntemplate <class T =\
    \ ll> struct MinimumSteinerTree {\n    int n, k;\n    vector<int> terminal;\n\
    \    T cost;\n    const T infty = numeric_limits<T>::max();\n    vector<vector<T>>\
    \ dp;\n    MinimumSteinerTree(const Graph<T> &g, const vector<int> terminal)\n\
    \        : n(g.size()), k(terminal.size()), terminal(terminal), cost(0),\n   \
    \       dp(1 << k, vector<T>(n, infty)) {\n        assert(!terminal.empty());\n\
    \        rep(i, k) { dp[1 << i][terminal[i]] = 0; }\n        rep(bit, 1, 1 <<\
    \ k) {\n            rep(i, n) {\n                for(int sub = (bit - 1) & bit;\
    \ sub > 0; sub = (sub - 1) & bit) {\n                    if(dp[sub][i] != infty\
    \ and dp[bit ^ sub][i] != infty)\n                        chmin(dp[bit][i], dp[sub][i]\
    \ + dp[bit ^ sub][i]);\n                }\n            }\n            using pti\
    \ = pair<T, int>;\n            priority_queue<pti, vector<pti>, greater<pti>>\
    \ pq;\n            rep(i, n) pq.push(pti(dp[bit][i], i));\n            while(pq.size())\
    \ {\n                auto [c, v] = pq.top();\n                pq.pop();\n    \
    \            if(c != dp[bit][v] or c == infty)\n                    continue;\n\
    \                for(auto &e : g[v]) {\n                    T nc = c + e.cost;\n\
    \                    if(chmin(dp[bit][e.to], nc))\n                        pq.push(pti(nc,\
    \ e.to));\n                }\n            }\n        }\n        cost = dp.back()[terminal.front()];\n\
    \    }\n};"
  dependsOn:
  - graph/graph-template.hpp
  - template.hpp
  isVerificationFile: false
  path: graph/minimum-steiner-tree.hpp
  requiredBy: []
  timestamp: '2025-03-07 18:46:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1040.test.cpp
  - test/yukicoder/114.test.cpp
documentation_of: graph/minimum-steiner-tree.hpp
layout: document
redirect_from:
- /library/graph/minimum-steiner-tree.hpp
- /library/graph/minimum-steiner-tree.hpp.html
title: graph/minimum-steiner-tree.hpp
---
