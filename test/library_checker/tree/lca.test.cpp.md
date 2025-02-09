---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/sparse-table.hpp
    title: data_structure/sparse-table.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  - icon: ':heavy_check_mark:'
    path: tree/euler-tour.hpp
    title: tree/euler-tour.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/library_checker/tree/lca.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/lca\"\n#line 2 \"template.hpp\"\n// #pragma\
    \ GCC target(\"avx2\")\n// #pragma GCC optimize(\"O3\")\n// #pragma GCC optimize(\"\
    unroll-loops\")\n\n#include <bits/stdc++.h>\nusing namespace std;\n// https://xn--kst.jp/blog/2019/08/29/cpp-comp/\n\
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
    #endif\n\nusing ll = long long;\nusing vl = vector<ll>;\nusing Graph = vector<vector<ll>>;\n\
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
    vl dx = {1, -1, 0, 0};\nvl dy = {0, 0, 1, -1};\n#line 3 \"data_structure/sparse-table.hpp\"\
    \ntemplate <class T, auto op> struct SparseTable {\n    SparseTable(const vector<T>\
    \ &vec) {\n        int n = vec.size();\n        int b = 32 - countl_zero(unsigned(n\
    \ > 1 ? n - 1 : n));\n        v = vector(b, vector<T>(n));\n        v[0] = vec;\n\
    \        rep(i, b - 1) {\n            for(int j = 0; j + (1 << i) < n; j++) {\n\
    \                v[i + 1][j] = op(v[i][j], v[i][j + (1 << i)]);\n            }\n\
    \        }\n    }\n    T prod(int l, int r) const {\n        if(l + 1 == r)\n\
    \            return v[0][l];\n        int b = 31 - countl_zero(unsigned(r - l\
    \ - 1));\n        return op(v[b][l], v[b][r - (1 << b)]);\n    }\n\n  private:\n\
    \    vector<vector<T>> v;\n};\n#line 4 \"tree/euler-tour.hpp\"\n// https://maspypy.com/euler-tour-%E3%81%AE%E3%81%8A%E5%8B%89%E5%BC%B7\n\
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
    \ = id++;\n    }\n};\n#line 3 \"test/library_checker/tree/lca.test.cpp\"\nvoid\
    \ solve() {\n    INT(n, q);\n    vector<vector<int>> g(n);\n    rep(i, 1, n) {\n\
    \        INT(p);\n        g[p].push_back(i), g[i].push_back(p);\n    }\n    EulerTour\
    \ et(g);\n    while(q--) {\n        INT(x, y);\n        print(et.lca(x, y));\n\
    \    }\n}\nint main() {\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#include \"tree/euler-tour.hpp\"\
    \nvoid solve() {\n    INT(n, q);\n    vector<vector<int>> g(n);\n    rep(i, 1,\
    \ n) {\n        INT(p);\n        g[p].push_back(i), g[i].push_back(p);\n    }\n\
    \    EulerTour et(g);\n    while(q--) {\n        INT(x, y);\n        print(et.lca(x,\
    \ y));\n    }\n}\nint main() {\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    solve();\n}"
  dependsOn:
  - tree/euler-tour.hpp
  - data_structure/sparse-table.hpp
  - template.hpp
  isVerificationFile: true
  path: test/library_checker/tree/lca.test.cpp
  requiredBy: []
  timestamp: '2025-02-09 18:10:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/tree/lca.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/tree/lca.test.cpp
- /verify/test/library_checker/tree/lca.test.cpp.html
title: test/library_checker/tree/lca.test.cpp
---
