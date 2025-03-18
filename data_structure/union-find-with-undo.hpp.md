---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/persistent_unionfind.test.cpp
    title: test/library_checker/data_structure/persistent_unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://nyaannyaan.github.io/library/data-structure/rollback-union-find.hpp.html
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
    \ dy = {0, 0, 1, -1};\n#line 3 \"data_structure/union-find-with-undo.hpp\"\n//\
    \ https://nyaannyaan.github.io/library/data-structure/rollback-union-find.hpp.html\n\
    // snapshot/rollback \u3044\u308B\u304B\u306A\uFF1F\nstruct UnionFindWithUndo\
    \ {\n    int n, numComponents;\n    vector<int> p;\n    using T = tuple<int, int,\
    \ int, int>;\n    stack<T> history;\n    UnionFindWithUndo(int n) : n(n), numComponents(n),\
    \ p(n, -1) {}\n    int leader(int x) {\n        while(p[x] >= 0)\n           \
    \ x = p[x];\n        return x;\n    }\n    int merge(int x, int y) {\n       \
    \ x = leader(x), y = leader(y);\n        history.push(T(x, y, p[x], p[y]));\n\
    \        if(x == y)\n            return x;\n        --numComponents;\n       \
    \ if(-p[x] < -p[y])\n            swap(x, y);\n        p[x] += p[y];\n        p[y]\
    \ = x;\n        return x;\n    }\n    void undo(int k = 1) {\n        assert(history.size()\
    \ >= k);\n        while(k--) {\n            auto [x, y, px, py] = history.top();\n\
    \            history.pop();\n            p[x] = px, p[y] = py;\n            if(x\
    \ != y)\n                ++numComponents;\n        }\n    }\n    int size(int\
    \ x) { return -p[leader(x)]; }\n    bool same(int x, int y) { return leader(x)\
    \ == leader(y); }\n};\n"
  code: "#pragma once\n#include \"template.hpp\"\n// https://nyaannyaan.github.io/library/data-structure/rollback-union-find.hpp.html\n\
    // snapshot/rollback \u3044\u308B\u304B\u306A\uFF1F\nstruct UnionFindWithUndo\
    \ {\n    int n, numComponents;\n    vector<int> p;\n    using T = tuple<int, int,\
    \ int, int>;\n    stack<T> history;\n    UnionFindWithUndo(int n) : n(n), numComponents(n),\
    \ p(n, -1) {}\n    int leader(int x) {\n        while(p[x] >= 0)\n           \
    \ x = p[x];\n        return x;\n    }\n    int merge(int x, int y) {\n       \
    \ x = leader(x), y = leader(y);\n        history.push(T(x, y, p[x], p[y]));\n\
    \        if(x == y)\n            return x;\n        --numComponents;\n       \
    \ if(-p[x] < -p[y])\n            swap(x, y);\n        p[x] += p[y];\n        p[y]\
    \ = x;\n        return x;\n    }\n    void undo(int k = 1) {\n        assert(history.size()\
    \ >= k);\n        while(k--) {\n            auto [x, y, px, py] = history.top();\n\
    \            history.pop();\n            p[x] = px, p[y] = py;\n            if(x\
    \ != y)\n                ++numComponents;\n        }\n    }\n    int size(int\
    \ x) { return -p[leader(x)]; }\n    bool same(int x, int y) { return leader(x)\
    \ == leader(y); }\n};"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: data_structure/union-find-with-undo.hpp
  requiredBy: []
  timestamp: '2025-03-18 18:04:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/data_structure/persistent_unionfind.test.cpp
documentation_of: data_structure/union-find-with-undo.hpp
layout: document
title: "Undo\u3064\u304DUnion Find"
---

## 問題例

- [ABC302 Ex - Ball Collector](https://atcoder.jp/contests/abc302/tasks/abc302_h)  
連結成分の辺の数と頂点数を持つ
- [ABC334 G - Christmas Color Grid 2](https://atcoder.jp/contests/abc334/tasks/abc334_g)  
分割統治+undoつきUF
- [JOI 2021/2022 二次予選 E - 交易計画 (Trade Plan)](https://atcoder.jp/contests/joi2022yo2/tasks/joi2022_yo2_e)  
同じ州間の辺のみ予め貼っておく。州$i,j$間のクエリに対してまとめて、辺追加→クエリ回答→辺削除 をおこなう。州はたくさんあるのでクエリとして存在するもののみに対して行う。各辺は高々1回しか追加・削除されない。
