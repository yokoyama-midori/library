---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/sparse-table.hpp
    title: data_structure/sparse-table.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: tree/auxiliary-tree.hpp
    title: "\u6307\u5B9A\u3055\u308C\u305F\u9802\u70B9\u305F\u3061\u306E\u6700\u5C0F\
      \u5171\u901A\u7956\u5148\u95A2\u4FC2\u3092\u4FDD\u3063\u3066\u6728\u3092\u5727\
      \u7E2E\u3057\u3066\u3067\u304D\u308B\u88DC\u52A9\u7684\u306A\u6728"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/tree/lca.test.cpp
    title: test/library_checker/tree/lca.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://maspypy.com/euler-tour-%E3%81%AE%E3%81%8A%E5%8B%89%E5%BC%B7
    - https://nyaannyaan.github.io/library/tree/euler-tour.hpp
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
    n';\n}\ntemplate <ranges::range Iterable>\n    requires(!Streamable<Iterable>)\n\
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
    \ dy = {0, 0, 1, -1};\n#line 3 \"data_structure/sparse-table.hpp\"\n/*\n    auto\
    \ op\u306B\u306F\n    [](int i,int j){return min(i,j);}\u3084(int(*)(int,int))min\n\
    \    \u3092\u6E21\u3059\n    prod \u5358\u4F4D\u5143\u3092\u6E21\u3057\u3066\u3044\
    \u306A\u3044\u306E\u3067 l==r\u306F\u4E0D\u53EF\n*/\ntemplate <class T, auto op>\
    \ struct SparseTable {\n    SparseTable(const vector<T> &vec) {\n        int n\
    \ = vec.size();\n        int b = bit_width(unsigned(n));\n        v.resize(b);\n\
    \        v[0] = vec;\n        rep(i, b - 1) {\n            v[i + 1].resize(n -\
    \ (1 << i));\n            rep(j, ssize(v[i]) - (1 << i)) {\n                v[i\
    \ + 1][j] = op(v[i][j], v[i][j + (1 << i)]);\n            }\n        }\n    }\n\
    \    T prod(int l, int r) const {\n        if(l + 1 == r)\n            return\
    \ v[0][l];\n        int b = bit_width(unsigned(r - l - 1)) - 1;\n        return\
    \ op(v[b][l], v[b][r - (1 << b)]);\n    }\n\n  private:\n    vector<vector<T>>\
    \ v;\n};\n#line 4 \"tree/euler-tour.hpp\"\n// https://maspypy.com/euler-tour-%E3%81%AE%E3%81%8A%E5%8B%89%E5%BC%B7\n\
    // https://nyaannyaan.github.io/library/tree/euler-tour.hpp\n\ntemplate <class\
    \ G> struct EulerTour {\n    int root, id;\n    vector<int> in, out, dep;\n  \
    \  using pii = pair<int, int>; // depth,vartex\n    SparseTable<pii, [](pii a,\
    \ pii b) { return a.first < b.first ? a : b; }>\n        rmq;\n    EulerTour(G\
    \ &g, int root = 0)\n        : root(root), id(0), in(g.size(), -1), out(g.size(),\
    \ -1),\n          dep(g.size(), 0), rmq([&] {\n              vector<pii> vec;\n\
    \              vec.reserve(2 * g.size());\n              dfs(g, root, -1, vec);\n\
    \              return vec;\n          }()) {}\n    int lca(int x, int y) const\
    \ {\n        int ix = in[x], iy = in[y];\n        if(ix > iy)\n            swap(ix,\
    \ iy);\n        return rmq.prod(ix, iy + 1).second;\n    }\n    int dist(int x,\
    \ int y) const {\n        int l = lca(x, y);\n        return dep[x] + dep[y] -\
    \ 2 * dep[l];\n    }\n\n  private:\n    void dfs(G &g, int now, int prev, vector<pii>\
    \ &vec) {\n        vec.push_back({dep[now], now});\n        in[now] = id++;\n\
    \        for(auto nex : g[now]) {\n            if(nex == prev)\n             \
    \   continue;\n            dep[nex] = dep[now] + 1;\n            dfs(g, nex, now,\
    \ vec);\n        }\n        vec.push_back({dep[now] - 1, prev});\n        out[now]\
    \ = id++;\n    }\n};\n"
  code: "#pragma once\n#include \"data_structure/sparse-table.hpp\"\n#include \"template.hpp\"\
    \n// https://maspypy.com/euler-tour-%E3%81%AE%E3%81%8A%E5%8B%89%E5%BC%B7\n// https://nyaannyaan.github.io/library/tree/euler-tour.hpp\n\
    \ntemplate <class G> struct EulerTour {\n    int root, id;\n    vector<int> in,\
    \ out, dep;\n    using pii = pair<int, int>; // depth,vartex\n    SparseTable<pii,\
    \ [](pii a, pii b) { return a.first < b.first ? a : b; }>\n        rmq;\n    EulerTour(G\
    \ &g, int root = 0)\n        : root(root), id(0), in(g.size(), -1), out(g.size(),\
    \ -1),\n          dep(g.size(), 0), rmq([&] {\n              vector<pii> vec;\n\
    \              vec.reserve(2 * g.size());\n              dfs(g, root, -1, vec);\n\
    \              return vec;\n          }()) {}\n    int lca(int x, int y) const\
    \ {\n        int ix = in[x], iy = in[y];\n        if(ix > iy)\n            swap(ix,\
    \ iy);\n        return rmq.prod(ix, iy + 1).second;\n    }\n    int dist(int x,\
    \ int y) const {\n        int l = lca(x, y);\n        return dep[x] + dep[y] -\
    \ 2 * dep[l];\n    }\n\n  private:\n    void dfs(G &g, int now, int prev, vector<pii>\
    \ &vec) {\n        vec.push_back({dep[now], now});\n        in[now] = id++;\n\
    \        for(auto nex : g[now]) {\n            if(nex == prev)\n             \
    \   continue;\n            dep[nex] = dep[now] + 1;\n            dfs(g, nex, now,\
    \ vec);\n        }\n        vec.push_back({dep[now] - 1, prev});\n        out[now]\
    \ = id++;\n    }\n};"
  dependsOn:
  - data_structure/sparse-table.hpp
  - template.hpp
  isVerificationFile: false
  path: tree/euler-tour.hpp
  requiredBy:
  - tree/auxiliary-tree.hpp
  timestamp: '2025-03-18 18:04:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/tree/lca.test.cpp
documentation_of: tree/euler-tour.hpp
layout: document
redirect_from:
- /library/tree/euler-tour.hpp
- /library/tree/euler-tour.hpp.html
title: tree/euler-tour.hpp
---
