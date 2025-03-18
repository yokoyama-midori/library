---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  - icon: ':x:'
    path: tree/tree-query.hpp
    title: tree/tree-query.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/library_checker/tree/lca_doubling.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#line 2 \"template.hpp\"\n\
    // #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"O3\")\n// #pragma GCC\
    \ optimize(\"unroll-loops\")\n#include <bits/stdc++.h>\nusing namespace std;\n\
    template <class T>\nconcept Streamable = requires(ostream os, T &x) { os << x;\
    \ };\ntemplate <class mint>\nconcept is_modint = requires(mint &x) {\n    { x.val()\
    \ } -> std::convertible_to<int>;\n};\n#ifdef LOCAL\n#include <debug.hpp>\n#else\n\
    #define debug(...) 42\n#endif\n\ntemplate <Streamable T> void print_one(const\
    \ T &value) { cout << value; }\ntemplate <is_modint T> void print_one(const T\
    \ &value) { cout << value.val(); }\nvoid print() { cout << '\\n'; }\ntemplate\
    \ <class T, class... Ts> void print(const T &a, const Ts &...b) {\n    print_one(a);\n\
    \    ((cout << ' ', print_one(b)), ...);\n    cout << '\\n';\n}\ntemplate <ranges::range\
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
    \ 3 \"tree/tree-query.hpp\"\n// https://nyaannyaan.github.io/library/tree/tree-query.hpp\n\
    template <class T> struct Tree {\n    int n, root, lg;\n    Graph<T> &g;\n   \
    \ vector<int> depth;\n    vector<vector<int>> table;\n    Tree(Graph<T> &g, int\
    \ root = 0)\n        : n(g.size()), root(root), lg(bit_width((unsigned)n)), g(g),\n\
    \          depth(n, 0), table(lg, vector<int>(n, -1)) {\n        dfs(root, -1);\n\
    \    }\n    // root -> -1\n    int par(int u) const { return table[0][u]; }\n\
    \    int kth_ancestor(int u, int k) const {\n        if(depth[u] < k)\n      \
    \      return -1;\n        while(k) {\n            int t = countr_zero((unsigned)k);\n\
    \            u = table[t][u], k ^= 1 << t;\n        }\n        return u;\n   \
    \ }\n    int lca(int s, int t) const {\n        if(depth[s] > depth[t])\n    \
    \        swap(s, t);\n        t = kth_ancestor(t, depth[t] - depth[s]);\n    \
    \    if(s == t)\n            return s;\n        for(int i = lg - 1; i >= 0; i--)\
    \ {\n            if(table[i][s] != table[i][t])\n                s = table[i][s],\
    \ t = table[i][t];\n        }\n        return table[0][s];\n    }\n    // s\u304B\
    \u3089t\u65B9\u5411\u306Bk\u9032\u3080\n    // dist(s,t) < k \u306A\u3089 -1\n\
    \    int jump(int s, int t, int k) const {\n        int lc = lca(s, t);\n    \
    \    if(depth[s] - depth[lc] >= k)\n            return kth_ancestor(s, k);\n \
    \       k = depth[s] + depth[t] - 2 * depth[lc] - k;\n        if(k >= 0 and depth[t]\
    \ - depth[lc] >= k)\n            return kth_ancestor(t, k);\n        return -1;\n\
    \    }\n\n  private:\n    void dfs(int cur, int par) {\n        for(int i = 0;\
    \ i + 1 < lg and table[i][cur] != -1; i++)\n            table[i + 1][cur] = table[i][table[i][cur]];\n\
    \        for(auto &to : g[cur]) {\n            if(to == par)\n               \
    \ continue;\n            depth[to] = depth[cur] + 1;\n            table[0][to]\
    \ = cur;\n            dfs(to, cur);\n        }\n    }\n};\n#line 3 \"test/library_checker/tree/lca_doubling.test.cpp\"\
    \nint main() {\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    INT(n, q);\n    Graph<bool> g(n);\n    vector<int> p(n, -1);\n    rep(i,\
    \ 1, n) {\n        input(p[i]);\n        g.add_edge(i, p[i]);\n    }\n    Tree<bool>\
    \ tree(g);\n    while(q--) {\n        INT(s, t);\n        print(tree.lca(s, t));\n\
    \    }\n    rep(i, n) assert(p[i] == tree.par(i));\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#include \"tree/tree-query.hpp\"\
    \nint main() {\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    INT(n, q);\n    Graph<bool> g(n);\n    vector<int> p(n, -1);\n    rep(i,\
    \ 1, n) {\n        input(p[i]);\n        g.add_edge(i, p[i]);\n    }\n    Tree<bool>\
    \ tree(g);\n    while(q--) {\n        INT(s, t);\n        print(tree.lca(s, t));\n\
    \    }\n    rep(i, n) assert(p[i] == tree.par(i));\n}\n"
  dependsOn:
  - tree/tree-query.hpp
  - graph/graph-template.hpp
  - template.hpp
  isVerificationFile: true
  path: test/library_checker/tree/lca_doubling.test.cpp
  requiredBy: []
  timestamp: '2025-03-18 18:04:39+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/tree/lca_doubling.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/tree/lca_doubling.test.cpp
- /verify/test/library_checker/tree/lca_doubling.test.cpp.html
title: test/library_checker/tree/lca_doubling.test.cpp
---
