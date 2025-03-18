---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/sparse-table.hpp
    title: data_structure/sparse-table.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/library_checker/data_structure/staticrmq_sparse_table.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#line 2 \"template.hpp\"\
    \n// #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"O3\")\n// #pragma\
    \ GCC optimize(\"unroll-loops\")\n#include <bits/stdc++.h>\nusing namespace std;\n\
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
    \ v;\n};\n#line 4 \"test/library_checker/data_structure/staticrmq_sparse_table.test.cpp\"\
    \n\nvoid solve() {\n    INT(n, q);\n    vector<int> a(n);\n    input(a);\n   \
    \ SparseTable<int, [](int a, int b) { return min(a, b); }> seg(a);\n    rep(_,\
    \ q) {\n        INT(l, r);\n        print(seg.prod(l, r));\n    }\n}\nint main()\
    \ {\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n    solve();\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include \"\
    data_structure/sparse-table.hpp\"\n#include \"template.hpp\"\n\nvoid solve() {\n\
    \    INT(n, q);\n    vector<int> a(n);\n    input(a);\n    SparseTable<int, [](int\
    \ a, int b) { return min(a, b); }> seg(a);\n    rep(_, q) {\n        INT(l, r);\n\
    \        print(seg.prod(l, r));\n    }\n}\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    solve();\n}\n"
  dependsOn:
  - data_structure/sparse-table.hpp
  - template.hpp
  isVerificationFile: true
  path: test/library_checker/data_structure/staticrmq_sparse_table.test.cpp
  requiredBy: []
  timestamp: '2025-03-18 18:04:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/data_structure/staticrmq_sparse_table.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/staticrmq_sparse_table.test.cpp
- /verify/test/library_checker/data_structure/staticrmq_sparse_table.test.cpp.html
title: test/library_checker/data_structure/staticrmq_sparse_table.test.cpp
---
