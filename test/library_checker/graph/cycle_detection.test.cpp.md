---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/cycle-detection.hpp
    title: graph/cycle-detection.hpp
  - icon: ':question:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/cycle_detection
    links:
    - https://judge.yosupo.jp/problem/cycle_detection
  bundledCode: "#line 1 \"test/library_checker/graph/cycle_detection.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/cycle_detection\"\n#line 2 \"\
    template.hpp\"\n// #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"O3\"\
    )\n// #pragma GCC optimize(\"unroll-loops\")\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\ntemplate <class T>\nconcept Streamable = requires(ostream os,\
    \ T &x) { os << x; };\ntemplate <class mint>\nconcept is_modint = requires(mint\
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
    \ 4 \"graph/cycle-detection.hpp\"\n// https://ei1333.github.io/library/graph/others/cycle-detection.hpp\n\
    // \u8FBA\u7D20\u306A\u30B5\u30A4\u30AF\u30EB\u30921\u3064\u8FD4\u3059 \u306A\u3051\
    \u308C\u3070\u7A7A\n// Edge\u306Eidx\u304C\u5FC5\u8981\n// \u6709\u5411/\u7121\
    \u52B9 \u3069\u3061\u3089\u3067\u3082ok\ntemplate <class T> vector<Edge<T>> cycle_detection(Graph<T>\
    \ &g) {\n    int n = g.size();\n    using edge_type = Edge<T>;\n    vector<char>\
    \ used(n, 0);\n    vector<edge_type> prev(n, edge_type(-1, -1)), cycle;\n    auto\
    \ dfs = [&](auto &&dfs, edge_type cur) -> bool {\n        used[cur] = 1;\n   \
    \     for(edge_type e : g[cur]) {\n            if(e.idx == cur.idx)\n        \
    \        continue;\n            prev[e] = e;\n            if(used[e] == 0) {\n\
    \                if(dfs(dfs, e)) {\n                    return true;\n       \
    \         }\n            } else if(used[e] == 1) {\n                int s = e.to;\n\
    \                while(cycle.empty() or e.to != s) {\n                    cycle.emplace_back(e);\n\
    \                    e = prev[e.from];\n                }\n                return\
    \ true;\n            }\n        }\n        used[cur] = 2;\n        return false;\n\
    \    };\n    rep(i, n) {\n        if(cycle.empty() and used[i] == 0)\n       \
    \     dfs(dfs, edge_type(-1, i));\n    }\n    ranges::reverse(cycle);\n    return\
    \ cycle;\n}\n#line 3 \"test/library_checker/graph/cycle_detection.test.cpp\"\n\
    void solve() {\n    INT(n, m);\n    Graph<bool> g(n);\n    g.read(m, 0, 0, 1);\n\
    \    auto cycle = cycle_detection(g);\n    if(cycle.empty()) {\n        print(-1);\n\
    \        return;\n    }\n    print(cycle.size());\n    for(auto i : cycle)\n \
    \       print(i.idx);\n}\nint main() {\n    ios::sync_with_stdio(false);\n   \
    \ std::cin.tie(nullptr);\n    solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cycle_detection\"\n#include\
    \ \"graph/cycle-detection.hpp\"\nvoid solve() {\n    INT(n, m);\n    Graph<bool>\
    \ g(n);\n    g.read(m, 0, 0, 1);\n    auto cycle = cycle_detection(g);\n    if(cycle.empty())\
    \ {\n        print(-1);\n        return;\n    }\n    print(cycle.size());\n  \
    \  for(auto i : cycle)\n        print(i.idx);\n}\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    solve();\n}\n"
  dependsOn:
  - graph/cycle-detection.hpp
  - graph/graph-template.hpp
  - template.hpp
  isVerificationFile: true
  path: test/library_checker/graph/cycle_detection.test.cpp
  requiredBy: []
  timestamp: '2025-03-17 22:44:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/graph/cycle_detection.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/graph/cycle_detection.test.cpp
- /verify/test/library_checker/graph/cycle_detection.test.cpp.html
title: test/library_checker/graph/cycle_detection.test.cpp
---
