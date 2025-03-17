---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: set-function/fast-hadamard-transform.hpp
    title: set-function/fast-hadamard-transform.hpp
  - icon: ':heavy_check_mark:'
    path: set-function/xor-convolution.hpp
    title: set-function/xor-convolution.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_xor_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_xor_convolution
  bundledCode: "#line 1 \"test/library_checker/convolution/bitwise_xor_convolution.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\n\
    #line 2 \"template.hpp\"\n// #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"\
    O3\")\n// #pragma GCC optimize(\"unroll-loops\")\n#include <bits/stdc++.h>\nusing\
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
    \ dy = {0, 0, 1, -1};\n#line 3 \"set-function/fast-hadamard-transform.hpp\"\n\
    // https://sapphire15.hatenablog.com/entry/2021/09/13/114900\ntemplate <class\
    \ T> void fast_hadamard_transform(vector<T> &a, bool inv = false) {\n    if(a.empty())\n\
    \        return;\n    int n = a.size();\n    assert((n & (n - 1)) == 0);\n   \
    \ for(int i = 1; i < n; i <<= 1) {\n        for(int j = 0; j < n; j++) {\n   \
    \         if((i & j) == 0) {\n                tie(a[j], a[i | j]) =\n        \
    \            make_pair(a[j] + a[i | j], a[j] - a[i | j]);\n            }\n   \
    \     }\n    }\n    if(inv) {\n        T invn = T(1) / T(n);\n        for(auto\
    \ &ai : a)\n            ai *= invn;\n    }\n}\n#line 3 \"set-function/xor-convolution.hpp\"\
    \ntemplate <class T> vector<T> xor_convolution(vector<T> a, vector<T> b) {\n \
    \   assert(a.size() == b.size());\n    fast_hadamard_transform(a);\n    fast_hadamard_transform(b);\n\
    \    for(int i = 0; i < a.size(); i++)\n        a[i] *= b[i];\n    fast_hadamard_transform(a,\
    \ true);\n    return a;\n}\n#line 3 \"test/library_checker/convolution/bitwise_xor_convolution.test.cpp\"\
    \n#include <atcoder/modint>\nusing mint = atcoder::modint998244353;\nvoid solve()\
    \ {\n    INT(n);\n    vector<mint> a(1 << n), b(1 << n);\n    rep(i, 1 << n) {\n\
    \        INT(ai);\n        a[i] = ai;\n    }\n    rep(i, 1 << n) {\n        INT(bi);\n\
    \        b[i] = bi;\n    }\n    auto c = xor_convolution(a, b);\n    for(auto\
    \ ci : c)\n        cout << ci.val() << \" \";\n    cout << \"\\n\";\n}\nint main()\
    \ {\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n    solve();\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\
    \n#include \"set-function/xor-convolution.hpp\"\n#include <atcoder/modint>\nusing\
    \ mint = atcoder::modint998244353;\nvoid solve() {\n    INT(n);\n    vector<mint>\
    \ a(1 << n), b(1 << n);\n    rep(i, 1 << n) {\n        INT(ai);\n        a[i]\
    \ = ai;\n    }\n    rep(i, 1 << n) {\n        INT(bi);\n        b[i] = bi;\n \
    \   }\n    auto c = xor_convolution(a, b);\n    for(auto ci : c)\n        cout\
    \ << ci.val() << \" \";\n    cout << \"\\n\";\n}\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    solve();\n}\n"
  dependsOn:
  - set-function/xor-convolution.hpp
  - set-function/fast-hadamard-transform.hpp
  - template.hpp
  isVerificationFile: true
  path: test/library_checker/convolution/bitwise_xor_convolution.test.cpp
  requiredBy: []
  timestamp: '2025-03-17 22:44:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/convolution/bitwise_xor_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/convolution/bitwise_xor_convolution.test.cpp
- /verify/test/library_checker/convolution/bitwise_xor_convolution.test.cpp.html
title: test/library_checker/convolution/bitwise_xor_convolution.test.cpp
---
