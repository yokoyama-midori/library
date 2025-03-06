---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  - icon: ':heavy_check_mark:'
    path: tree/tree-diameter.hpp
    title: tree/tree-diameter.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_diameter
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
  bundledCode: "#line 1 \"test/library_checker/tree/tree_diameter.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n#line 2 \"template.hpp\"\
    \n// #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"O3\")\n// #pragma\
    \ GCC optimize(\"unroll-loops\")\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n// https://xn--kst.jp/blog/2019/08/29/cpp-comp/\n// debug methods\n//\
    \ usage: debug(x,y);\n// vector \u51FA\u529B\u3067\u304D\u308B\u3088\u3046\u306B\
    \u4FEE\u6B63\ntemplate <typename T>\nostream& debug_print(ostream& os, const vector<T>&\
    \ v) {\n    os << \"[\";\n    for (size_t i = 0; i < v.size(); ++i) {\n      \
    \  os << v[i];\n        if (i < v.size() - 1) os << \", \";\n    }\n    os <<\
    \ \"]\";\n    return os;\n}\ntemplate <typename T>\nostream& debug_print(ostream&\
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
    \ from(from), to(to), cost(cost), idx(idx) {}\n};\ntemplate <class T = ll> struct\
    \ Graph {\n    using cost_type = T;\n    vector<vector<Edge<T>>> g;\n    int es;\
    \ // edge_size\n    Graph(int n) : g(n), es(0) {};\n    int size() const { return\
    \ ssize(g); }\n    void add_directed_edge(int from, int to, T cost = 1) {\n  \
    \      g[from].emplace_back(from, to, cost, es++);\n    }\n    void add_edge(int\
    \ from, int to, T cost = 1) {\n        g[from].emplace_back(from, to, cost, es);\n\
    \        g[to].emplace_back(to, from, cost, es++);\n    }\n    vector<Edge<T>>\
    \ &operator[](const int &k) { return g[k]; }\n    const vector<Edge<T>> &operator[](const\
    \ int &k) const { return g[k]; }\n    void read(int m, int padding = -1, bool\
    \ weighted = false,\n              bool directed = false) {\n        rep(i, m)\
    \ {\n            int a, b;\n            T c(1);\n            cin >> a >> b;\n\
    \            a += padding;\n            b += padding;\n            if(weighted)\n\
    \                cin >> c;\n            if(directed)\n                add_directed_edge(a,\
    \ b, c);\n            else\n                add_edge(a, b, c);\n        }\n  \
    \  }\n};\n#line 3 \"tree/tree-diameter.hpp\"\n// dist : distance from d1\ntemplate\
    \ <class TREE> struct TreeDiamter {\n    TREE &g;\n    using T = typename TREE::cost_type;\n\
    \    vector<T> dist;\n    int d1, d2;\n    TreeDiamter(TREE &g) : g(g), dist(g.size(),\
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
    \   return ranges::max_element(dist) - begin(dist);\n    }\n};\n#line 4 \"test/library_checker/tree/tree_diameter.test.cpp\"\
    \nvoid solve() {\n    INT(n);\n    Graph<ll> g(n);\n    g.read(n - 1, 0, true);\n\
    \    TreeDiamter<decltype(g)> td(g);\n    auto path = td.get_path();\n    print(td.dist[td.d2],\
    \ path.size());\n    print(path);\n}\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    cout << setprecision(16);\n    solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n#include\
    \ \"graph/graph-template.hpp\"\n#include \"tree/tree-diameter.hpp\"\nvoid solve()\
    \ {\n    INT(n);\n    Graph<ll> g(n);\n    g.read(n - 1, 0, true);\n    TreeDiamter<decltype(g)>\
    \ td(g);\n    auto path = td.get_path();\n    print(td.dist[td.d2], path.size());\n\
    \    print(path);\n}\n\nint main() {\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    cout << setprecision(16);\n    solve();\n}\n"
  dependsOn:
  - graph/graph-template.hpp
  - template.hpp
  - tree/tree-diameter.hpp
  isVerificationFile: true
  path: test/library_checker/tree/tree_diameter.test.cpp
  requiredBy: []
  timestamp: '2025-03-06 09:55:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/tree/tree_diameter.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/tree/tree_diameter.test.cpp
- /verify/test/library_checker/tree/tree_diameter.test.cpp.html
title: test/library_checker/tree/tree_diameter.test.cpp
---
