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
    \ GCC optimize(\"unroll-loops\")\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n// https://xn--kst.jp/blog/2019/08/29/cpp-comp/\n\ntemplate <class Container,\
    \ typename = void>\nstruct is_container : std::false_type {};\ntemplate <class\
    \ Container>\nstruct is_container<Container, std::void_t<decltype(std::declval<Container>().begin()),\
    \ decltype(std::declval<Container>().end())>> : std::true_type {};\n\ntemplate\
    \ <typename Container>\nenable_if_t<is_container<Container>::value, ostream&>\
    \ \ndebug_print(ostream& os, const Container& container) {\n    os << \"[\";\n\
    \    auto it = container.begin();\n    for (; it != container.end(); ++it) {\n\
    \        if (it != container.begin()) os << \", \";\n        os << *it;\n    }\n\
    \    os << \"]\";\n    return os;\n}\ntemplate <typename T>\nenable_if_t<!is_container<T>::value,\
    \ ostream&> \ndebug_print(ostream& os, const T& var) {\n    os << var;\n    return\
    \ os;\n}\n#define CHOOSE(a) CHOOSE2 a\n#define CHOOSE2(a0, a1, a2, a3, a4, x,\
    \ ...) x\n#define debug_1(x1) { cout << #x1 << \": \"; debug_print(cout, x1) <<\
    \ endl; }\n#define debug_2(x1, x2) { cout << #x1 << \": \"; debug_print(cout,\
    \ x1) << \", \" << #x2 << \": \"; debug_print(cout, x2) << endl; }\n#define debug_3(x1,\
    \ x2, x3) { cout << #x1 << \": \"; debug_print(cout, x1) << \", \" << #x2 << \"\
    : \"; debug_print(cout, x2) << \", \" << #x3 << \": \"; debug_print(cout, x3)\
    \ << endl; }\n#define debug_4(x1, x2, x3, x4) { cout << #x1 << \": \"; debug_print(cout,\
    \ x1) << \", \" << #x2 << \": \"; debug_print(cout, x2) << \", \" << #x3 << \"\
    : \"; debug_print(cout, x3) << \", \" << #x4 << \": \"; debug_print(cout, x4)\
    \ << endl; }\n#define debug_5(x1, x2, x3, x4, x5) { cout << #x1 << \": \"; debug_print(cout,\
    \ x1) << \", \" << #x2 << \": \"; debug_print(cout, x2) << \", \" << #x3 << \"\
    : \"; debug_print(cout, x3) << \", \" << #x4 << \": \"; debug_print(cout, x4)\
    \ << \", \" << #x5 << \": \"; debug_print(cout, x5) << endl; }\n\n#ifdef LOCAL\n\
    #define debug(...) CHOOSE((__VA_ARGS__, debug_5, debug_4, debug_3, debug_2, debug_1,\
    \ ~))(__VA_ARGS__)\n#else\n#define debug(...)\n#endif\n\nusing ll = long long;\n\
    using vl = vector<ll>;\nusing vll = vector<vl>;\nusing P = pair<ll, ll>;\n#define\
    \ all(v) v.begin(), v.end()\ntemplate <typename T> inline bool chmax(T &a, T b)\
    \ {\n    return ((a < b) ? (a = b, true) : (false));\n}\ntemplate <typename T>\
    \ inline bool chmin(T &a, T b) {\n    return ((a > b) ? (a = b, true) : (false));\n\
    }\n#define rep1(i, n) for(ll i = 1; i <= ((ll)n); ++i)\n// https://trap.jp/post/1224/\n\
    template <class... T> constexpr auto min(T... a) {\n    return min(initializer_list<common_type_t<T...>>{a...});\n\
    }\ntemplate <class... T> constexpr auto max(T... a) {\n    return max(initializer_list<common_type_t<T...>>{a...});\n\
    }\ntemplate <class... T> void input(T &...a) { (cin >> ... >> a); }\ntemplate\
    \ <class T> void input(vector<T> &a) {\n    for(T &x : a)\n        cin >> x;\n\
    }\nvoid print() { cout << '\\n'; }\ntemplate <class T, class... Ts> void print(const\
    \ T &a, const Ts &...b) {\n    cout << a;\n    (cout << ... << (cout << ' ', b));\n\
    \    cout << '\\n';\n}\nvoid print(const string &s) {\n    cout << s << '\\n';\n\
    }\ntemplate <class Container>\nenable_if_t<is_container<Container>::value> print(const\
    \ Container& container) {\n    auto it = container.begin();\n    for(;it != container.end();\
    \ ++it){\n        if(it != container.begin())\n            cout << \" \";\n  \
    \      cout << *it;\n    }\n    cout << '\\n';\n}\n#define INT(...)          \
    \                                                     \\\n    int __VA_ARGS__;\
    \                                                           \\\n    input(__VA_ARGS__)\n\
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
    \n/*\n    auto op\u306B\u306F\n    [](int i,int j){return min(i,j);}\u3084(int(*)(int,int))min\n\
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
  timestamp: '2025-03-16 14:03:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/data_structure/staticrmq_sparse_table.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/staticrmq_sparse_table.test.cpp
- /verify/test/library_checker/data_structure/staticrmq_sparse_table.test.cpp.html
title: test/library_checker/data_structure/staticrmq_sparse_table.test.cpp
---
