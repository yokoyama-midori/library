---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: tree/auxiliary-tree.hpp
    title: "\u6307\u5B9A\u3055\u308C\u305F\u9802\u70B9\u305F\u3061\u306E\u6700\u5C0F\
      \u5171\u901A\u7956\u5148\u95A2\u4FC2\u3092\u4FDD\u3063\u3066\u6728\u3092\u5727\
      \u7E2E\u3057\u3066\u3067\u304D\u308B\u88DC\u52A9\u7684\u306A\u6728"
  - icon: ':heavy_check_mark:'
    path: tree/euler-tour.hpp
    title: tree/euler-tour.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/atcoder/practice2_j.test.cpp
    title: test/atcoder/practice2_j.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/point_add_range_sum.test.cpp
    title: test/library_checker/data_structure/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/point_set_range_composite.test.cpp
    title: test/library_checker/data_structure/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/static_range_sum_segtree.test.cpp
    title: test/library_checker/data_structure/static_range_sum_segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/staticrmq.test.cpp
    title: test/library_checker/data_structure/staticrmq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/tree/lca.test.cpp
    title: test/library_checker/tree/lca.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    vl dx = {1, -1, 0, 0};\nvl dy = {0, 0, 1, -1};\n#line 3 \"data_structure/segtree.hpp\"\
    \n\ntemplate <class S, S (*op)(S, S), S (*e)()> struct segtree {\n    ll n;\n\
    \    vector<S> v;\n    segtree(ll n_) : segtree(vector<S>(n_, e())) {}\n    segtree(const\
    \ vector<S> &v_) : n(v_.size()) {\n        v = vector<S>(2 * n, e());\n      \
    \  rep(i, n) v[n + i] = v_[i];\n        for(ll i = n - 1; i >= 0; i--) {\n   \
    \         v[i] = op(v[i << 1], v[i << 1 | 1]);\n        }\n    }\n    void set(ll\
    \ x, S p) {\n        assert(0 <= x && x < n);\n        x += n;\n        v[x] =\
    \ p;\n        while(x > 1) {\n            x >>= 1;\n            v[x] = op(v[x\
    \ << 1], v[x << 1 | 1]);\n        }\n    }\n    S prod(ll l, ll r) const {\n \
    \       assert(0 <= l && l <= r && r <= n);\n        S pl(e()), pr(e());\n   \
    \     l += n, r += n;\n        while(l < r) {\n            if(l & 1) {\n     \
    \           pl = op(pl, v[l]);\n            }\n            if(r & 1) {\n     \
    \           pr = op(v[r - 1], pr);\n            }\n            l = (l + 1) >>\
    \ 1;\n            r >>= 1;\n        }\n        return op(pl, pr);\n    }\n   \
    \ S get(ll x) const { return v[n + x]; }\n};\n"
  code: "#pragma once\n#include \"template.hpp\"\n\ntemplate <class S, S (*op)(S,\
    \ S), S (*e)()> struct segtree {\n    ll n;\n    vector<S> v;\n    segtree(ll\
    \ n_) : segtree(vector<S>(n_, e())) {}\n    segtree(const vector<S> &v_) : n(v_.size())\
    \ {\n        v = vector<S>(2 * n, e());\n        rep(i, n) v[n + i] = v_[i];\n\
    \        for(ll i = n - 1; i >= 0; i--) {\n            v[i] = op(v[i << 1], v[i\
    \ << 1 | 1]);\n        }\n    }\n    void set(ll x, S p) {\n        assert(0 <=\
    \ x && x < n);\n        x += n;\n        v[x] = p;\n        while(x > 1) {\n \
    \           x >>= 1;\n            v[x] = op(v[x << 1], v[x << 1 | 1]);\n     \
    \   }\n    }\n    S prod(ll l, ll r) const {\n        assert(0 <= l && l <= r\
    \ && r <= n);\n        S pl(e()), pr(e());\n        l += n, r += n;\n        while(l\
    \ < r) {\n            if(l & 1) {\n                pl = op(pl, v[l]);\n      \
    \      }\n            if(r & 1) {\n                pr = op(v[r - 1], pr);\n  \
    \          }\n            l = (l + 1) >> 1;\n            r >>= 1;\n        }\n\
    \        return op(pl, pr);\n    }\n    S get(ll x) const { return v[n + x]; }\n\
    };"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: data_structure/segtree.hpp
  requiredBy:
  - tree/auxiliary-tree.hpp
  - tree/euler-tour.hpp
  timestamp: '2025-02-07 15:18:13+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library_checker/data_structure/staticrmq.test.cpp
  - test/library_checker/data_structure/point_set_range_composite.test.cpp
  - test/library_checker/data_structure/point_add_range_sum.test.cpp
  - test/library_checker/data_structure/static_range_sum_segtree.test.cpp
  - test/library_checker/tree/lca.test.cpp
  - test/atcoder/practice2_j.test.cpp
documentation_of: data_structure/segtree.hpp
layout: document
redirect_from:
- /library/data_structure/segtree.hpp
- /library/data_structure/segtree.hpp.html
title: data_structure/segtree.hpp
---
