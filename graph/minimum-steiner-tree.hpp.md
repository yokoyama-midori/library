---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  - icon: ':heavy_check_mark:'
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
    \ dy = {0, 0, 1, -1};\n#line 3 \"graph/graph-template.hpp\"\n// https://ei1333.github.io/library/graph/graph-template.hpp\n\
    template <class T = ll> struct Edge {\n    int from, to;\n    T cost;\n    int\
    \ idx;\n    Edge() = default;\n    Edge(int from, int to, T cost = 1, int idx\
    \ = -1)\n        : from(from), to(to), cost(cost), idx(idx) {}\n    Edge &operator=(const\
    \ int &x) {\n        to = x;\n        return *this;\n    }\n    operator int()\
    \ const { return to; }\n};\ntemplate <class T = ll> struct Graph {\n    using\
    \ cost_type = T;\n    vector<vector<Edge<T>>> g;\n    int es; // edge_size\n \
    \   Graph(int n) : g(n), es(0) {};\n    int size() const { return ssize(g); }\n\
    \    void add_directed_edge(int from, int to, T cost = 1) {\n        g[from].emplace_back(from,\
    \ to, cost, es++);\n    }\n    void add_edge(int from, int to, T cost = 1) {\n\
    \        g[from].emplace_back(from, to, cost, es);\n        g[to].emplace_back(to,\
    \ from, cost, es++);\n    }\n    vector<Edge<T>> &operator[](const int &k) { return\
    \ g[k]; }\n    const vector<Edge<T>> &operator[](const int &k) const { return\
    \ g[k]; }\n    void read(int m, int padding = -1, bool weighted = false,\n   \
    \           bool directed = false) {\n        rep(i, m) {\n            int a,\
    \ b;\n            T c(1);\n            cin >> a >> b;\n            a += padding;\n\
    \            b += padding;\n            if(weighted)\n                cin >> c;\n\
    \            if(directed)\n                add_directed_edge(a, b, c);\n     \
    \       else\n                add_edge(a, b, c);\n        }\n    }\n};\n#line\
    \ 3 \"graph/minimum-steiner-tree.hpp\"\ntemplate <class T = ll> struct MinimumSteinerTree\
    \ {\n    int n, k;\n    vector<int> terminal;\n    T cost;\n    const T infty\
    \ = numeric_limits<T>::max();\n    vector<vector<T>> dp;\n    MinimumSteinerTree(const\
    \ Graph<T> &g, const vector<int> terminal)\n        : n(g.size()), k(terminal.size()),\
    \ terminal(terminal), cost(0),\n          dp(1 << k, vector<T>(n, infty)) {\n\
    \        assert(!terminal.empty());\n        rep(i, k) { dp[1 << i][terminal[i]]\
    \ = 0; }\n        rep(bit, 1, 1 << k) {\n            rep(i, n) {\n           \
    \     for(int sub = (bit - 1) & bit; sub > 0; sub = (sub - 1) & bit) {\n     \
    \               if(dp[sub][i] != infty and dp[bit ^ sub][i] != infty)\n      \
    \                  chmin(dp[bit][i], dp[sub][i] + dp[bit ^ sub][i]);\n       \
    \         }\n            }\n            using pti = pair<T, int>;\n          \
    \  priority_queue<pti, vector<pti>, greater<pti>> pq;\n            rep(i, n) pq.push(pti(dp[bit][i],\
    \ i));\n            while(pq.size()) {\n                auto [c, v] = pq.top();\n\
    \                pq.pop();\n                if(c != dp[bit][v] or c == infty)\n\
    \                    continue;\n                for(auto &e : g[v]) {\n      \
    \              T nc = c + e.cost;\n                    if(chmin(dp[bit][e.to],\
    \ nc))\n                        pq.push(pti(nc, e.to));\n                }\n \
    \           }\n        }\n        cost = dp.back()[terminal.front()];\n    }\n\
    };\n"
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
  timestamp: '2025-03-17 22:44:15+09:00'
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
