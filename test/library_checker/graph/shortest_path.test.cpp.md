---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  - icon: ':heavy_check_mark:'
    path: graph/shortest-path.hpp
    title: graph/shortest-path.hpp
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"test/library_checker/graph/shortest_path.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#line 2 \"template.hpp\"\
    \n// #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"O3\")\n// #pragma\
    \ GCC optimize(\"unroll-loops\")\n#include <bits/stdc++.h>\nusing namespace std;\n\
    template <class T>\nconcept Streamable = requires(ostream os, T &x) { os << x;\
    \ };\ntemplate <class mint>\nconcept is_modint = requires(mint &x) {\n    { x.val()\
    \ } -> std::convertible_to<int>;\n};\n#ifdef LOCAL\n#include <debug.hpp>\n#else\n\
    #define debug(...) 42\n#endif\n\ntemplate <Streamable T> void print_one(const\
    \ T &value) { cout << value; }\ntemplate <is_modint T> void print_one(const T\
    \ &value) { cout << value.val(); }\nvoid print() { cout << '\\n'; }\ntemplate\
    \ <class T, class... Ts> void print(const T &a, const Ts &...b) {\n    print_one(a);\n\
    \    ((cout << ' ', print_one(b)), ...);\n    cout << '\\n';\n}\nvoid print(const\
    \ string &s) { cout << s << '\\n'; }\ntemplate <ranges::range Iterable>\n    requires(!Streamable<Iterable>)\n\
    void print(const Iterable &v) {\n    for(auto it = v.begin(); it != v.end(); ++it)\
    \ {\n        if(it != v.begin())\n            cout << \" \";\n        print_one(*it);\n\
    \    }\n    cout << '\\n';\n}\nusing ll = long long;\nusing vl = vector<ll>;\n\
    using vll = vector<vl>;\nusing P = pair<ll, ll>;\n#define all(v) v.begin(), v.end()\n\
    template <typename T> inline bool chmax(T &a, T b) {\n    return ((a < b) ? (a\
    \ = b, true) : (false));\n}\ntemplate <typename T> inline bool chmin(T &a, T b)\
    \ {\n    return ((a > b) ? (a = b, true) : (false));\n}\n#define rep1(i, n) for(ll\
    \ i = 1; i <= ((ll)n); ++i)\n// https://trap.jp/post/1224/\ntemplate <class...\
    \ T> constexpr auto min(T... a) {\n    return min(initializer_list<common_type_t<T...>>{a...});\n\
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
    \ 3 \"graph/shortest-path.hpp\"\ntemplate <class T> struct ShortestPath {\n  \
    \  int n;\n    Graph<T> &g;\n    vector<int> from;\n    vector<T> dist;\n    ShortestPath(Graph<T>\
    \ &g, int s)\n        : n(g.size()), g(g), from(n, -1), dist(n, -1) {\n      \
    \  using Pti = pair<T, int>;\n        priority_queue<Pti, vector<Pti>, greater<Pti>>\
    \ que;\n        que.push(Pti(0, s));\n        dist[s] = 0;\n        while(que.size())\
    \ {\n            auto [cost, idx] = que.top();\n            que.pop();\n     \
    \       if(dist[idx] < cost)\n                continue;\n            for(auto\
    \ to : g[idx]) {\n                if(dist[to] == -1 or cost + to.cost < dist[to])\
    \ {\n                    dist[to] = cost + to.cost;\n                    que.push(Pti(dist[to],\
    \ to));\n                    from[to] = idx;\n                }\n            }\n\
    \        }\n    }\n    const T &operator[](int i) const { return dist[i]; }\n\
    \    vector<int> restore(int t) const {\n        assert(t != -1);\n        vector<int>\
    \ res = {t};\n        while(from[t] != -1) {\n            t = from[t];\n     \
    \       res.emplace_back(t);\n        }\n        ranges::reverse(res);\n     \
    \   return res;\n    }\n};\n#line 5 \"test/library_checker/graph/shortest_path.test.cpp\"\
    \nvoid solve() {\n    INT(n, m, s, t);\n    Graph<ll> g(n);\n    g.read(m, 0,\
    \ 1, 1);\n    ShortestPath<ll> dijkstra(g, s);\n    if(dijkstra[t] == -1)\n  \
    \      print(-1);\n    else {\n        auto path = dijkstra.restore(t);\n    \
    \    print(dijkstra[t], ssize(path) - 1);\n        rep(i, ssize(path) - 1) { print(path[i],\
    \ path[i + 1]); }\n    }\n}\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#include\
    \ \"graph/graph-template.hpp\"\n#include \"graph/shortest-path.hpp\"\n#include\
    \ \"template.hpp\"\nvoid solve() {\n    INT(n, m, s, t);\n    Graph<ll> g(n);\n\
    \    g.read(m, 0, 1, 1);\n    ShortestPath<ll> dijkstra(g, s);\n    if(dijkstra[t]\
    \ == -1)\n        print(-1);\n    else {\n        auto path = dijkstra.restore(t);\n\
    \        print(dijkstra[t], ssize(path) - 1);\n        rep(i, ssize(path) - 1)\
    \ { print(path[i], path[i + 1]); }\n    }\n}\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    solve();\n}\n"
  dependsOn:
  - graph/graph-template.hpp
  - template.hpp
  - graph/shortest-path.hpp
  isVerificationFile: true
  path: test/library_checker/graph/shortest_path.test.cpp
  requiredBy: []
  timestamp: '2025-03-17 22:44:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/graph/shortest_path.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/graph/shortest_path.test.cpp
- /verify/test/library_checker/graph/shortest_path.test.cpp.html
title: test/library_checker/graph/shortest_path.test.cpp
---
