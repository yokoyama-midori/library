---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/rectangle-union-area.hpp
    title: data_structure/rectangle-union-area.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/area_of_union_of_rectangles.test.cpp
    title: test/library_checker/data_structure/area_of_union_of_rectangles.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://ei1333.github.io/library/other/compress.hpp
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
    \ dy = {0, 0, 1, -1};\n#line 3 \"data_structure/compress.hpp\"\n// https://ei1333.github.io/library/other/compress.hpp\n\
    template <class T> struct Compress {\n    bool is_built = false;\n    vector<T>\
    \ data;\n    Compress() = default;\n    Compress(const vector<T> &v) {\n     \
    \   add(v);\n    }\n    void add(const T &x) {\n        is_built = false;\n  \
    \      data.emplace_back(x);\n    }\n    void add(const vector<T> &v) {\n    \
    \    for(auto x : v)\n            add(x);\n    }\n    void build() {\n       \
    \ is_built = true;\n        sort(data.begin(), data.end());\n        data.erase(unique(data.begin(),\
    \ data.end()), data.end());\n    }\n    ll get(const T &x) const {\n        //\
    \ x \u4EE5\u4E0A\u3068\u306A\u308B\u6700\u5C0F\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\
    \u30B9\u3092\u8FD4\u3059\n        assert(is_built);\n        ll res = lower_bound(data.begin(),\
    \ data.end(), x) - data.begin();\n        return res;\n    }\n    const T &operator[](size_t\
    \ t) {\n        assert(is_built);\n        assert(0 <= t and t < data.size());\n\
    \        return data[t];\n    }\n    ll size() {\n        return ssize(data);\n\
    \    }\n};\n"
  code: "#pragma once\n#include \"template.hpp\"\n// https://ei1333.github.io/library/other/compress.hpp\n\
    template <class T> struct Compress {\n    bool is_built = false;\n    vector<T>\
    \ data;\n    Compress() = default;\n    Compress(const vector<T> &v) {\n     \
    \   add(v);\n    }\n    void add(const T &x) {\n        is_built = false;\n  \
    \      data.emplace_back(x);\n    }\n    void add(const vector<T> &v) {\n    \
    \    for(auto x : v)\n            add(x);\n    }\n    void build() {\n       \
    \ is_built = true;\n        sort(data.begin(), data.end());\n        data.erase(unique(data.begin(),\
    \ data.end()), data.end());\n    }\n    ll get(const T &x) const {\n        //\
    \ x \u4EE5\u4E0A\u3068\u306A\u308B\u6700\u5C0F\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\
    \u30B9\u3092\u8FD4\u3059\n        assert(is_built);\n        ll res = lower_bound(data.begin(),\
    \ data.end(), x) - data.begin();\n        return res;\n    }\n    const T &operator[](size_t\
    \ t) {\n        assert(is_built);\n        assert(0 <= t and t < data.size());\n\
    \        return data[t];\n    }\n    ll size() {\n        return ssize(data);\n\
    \    }\n};"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: data_structure/compress.hpp
  requiredBy:
  - data_structure/rectangle-union-area.hpp
  timestamp: '2025-03-17 22:44:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/data_structure/area_of_union_of_rectangles.test.cpp
documentation_of: data_structure/compress.hpp
layout: document
redirect_from:
- /library/data_structure/compress.hpp
- /library/data_structure/compress.hpp.html
title: data_structure/compress.hpp
---
