---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
    vl dx = {1, -1, 0, 0};\nvl dy = {0, 0, 1, -1};\n#line 3 \"data_structure/union-find-with-undo.hpp\"\
    \n// https://nyaannyaan.github.io/library/data-structure/rollback-union-find.hpp.html\n\
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
  timestamp: '2025-03-02 18:30:18+09:00'
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
