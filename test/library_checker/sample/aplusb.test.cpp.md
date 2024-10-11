---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/library_checker/sample/aplusb.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"template.hpp\"\n#pragma\
    \ GCC target(\"avx2\")\n#pragma GCC optimize(\"O3\")\n#pragma GCC optimize(\"\
    unroll-loops\")\n\n#include <bits/stdc++.h>\nusing namespace std;\n// https://xn--kst.jp/blog/2019/08/29/cpp-comp/\n\
    // debug methods\n// usage: debug(x,y);\n#define CHOOSE(a) CHOOSE2 a\n#define\
    \ CHOOSE2(a0, a1, a2, a3, a4, x, ...) x\n#define debug_1(x1) cout << #x1 << \"\
    : \" << x1 << endl\n#define debug_2(x1, x2)                                  \
    \                      \\\n    cout << #x1 << \": \" << x1 << \", \" #x2 << \"\
    : \" << x2 << endl\n#define debug_3(x1, x2, x3)                              \
    \                      \\\n    cout << #x1 << \": \" << x1 << \", \" #x2 << \"\
    : \" << x2 << \", \" #x3 << \": \"    \\\n         << x3 << endl\n#define debug_4(x1,\
    \ x2, x3, x4)                                                \\\n    cout << #x1\
    \ << \": \" << x1 << \", \" #x2 << \": \" << x2 << \", \" #x3 << \": \"    \\\n\
    \         << x3 << \", \" #x4 << \": \" << x4 << endl\n#define debug_5(x1, x2,\
    \ x3, x4, x5)                                            \\\n    cout << #x1 <<\
    \ \": \" << x1 << \", \" #x2 << \": \" << x2 << \", \" #x3 << \": \"    \\\n \
    \        << x3 << \", \" #x4 << \": \" << x4 << \", \" #x5 << \": \" << x5 <<\
    \ endl\n#ifdef LOCAL\n#define debug(...)                                     \
    \                        \\\n    CHOOSE((__VA_ARGS__, debug_5, debug_4, debug_3,\
    \ debug_2, debug_1, ~))      \\\n    (__VA_ARGS__)\n#else\n#define debug(...)\n\
    #endif\n\nusing ll = long long;\nusing vl = vector<ll>;\nusing Graph = vector<vector<ll>>;\n\
    using P = pair<ll, ll>;\n#define all(v) v.begin(), v.end()\ntemplate <typename\
    \ T> inline bool chmax(T &a, T b) {\n    return ((a < b) ? (a = b, true) : (false));\n\
    }\ntemplate <typename T> inline bool chmin(T &a, T b) {\n    return ((a > b) ?\
    \ (a = b, true) : (false));\n}\n#define rep1(i, n) for(ll i = 1; i <= ((ll)n);\
    \ ++i)\n// https://trap.jp/post/1224/\ntemplate <class... T> constexpr auto min(T...\
    \ a) {\n    return min(initializer_list<common_type_t<T...>>{a...});\n}\ntemplate\
    \ <class... T> constexpr auto max(T... a) {\n    return max(initializer_list<common_type_t<T...>>{a...});\n\
    }\ntemplate <class... T> void input(T &...a) {\n    (cin >> ... >> a);\n}\nvoid\
    \ print() {\n    cout << '\\n';\n}\ntemplate <class T, class... Ts> void print(const\
    \ T &a, const Ts &...b) {\n    cout << a;\n    (cout << ... << (cout << ' ', b));\n\
    \    cout << '\\n';\n}\ntemplate <class T> void print(vector<T> x) {\n    if(x.size())\
    \ {\n        for(ll i = 0; i < x.size(); i++) {\n            cout << x[i] << \"\
    \ \\n\"[i + 1 == x.size()];\n        }\n    }\n}\n#define INT(...)           \
    \                                                    \\\n    int __VA_ARGS__;\
    \                                                           \\\n    input(__VA_ARGS__)\n\
    #define LL(...)                                                              \
    \  \\\n    long long __VA_ARGS__;                                            \
    \         \\\n    input(__VA_ARGS__)\n#define STRING(...)                    \
    \                                        \\\n    string __VA_ARGS__;         \
    \                                               \\\n    input(__VA_ARGS__)\n#define\
    \ REP1(a) for(int i = 0; i < a; i++)\n#define REP2(i, a) for(int i = 0; i < a;\
    \ i++)\n#define REP3(i, a, b) for(int i = a; i < b; i++)\n#define REP4(i, a, b,\
    \ c) for(int i = a; i < b; i += c)\n#define overload4(a, b, c, d, e, ...) e\n\
    #define rep(...) overload4(__VA_ARGS__, REP4, REP3, REP2, REP1)(__VA_ARGS__)\n\
    \nll inf = 3e18;\nvl dx = {1, -1, 0, 0};\nvl dy = {0, 0, 1, -1};\n#line 3 \"test/library_checker/sample/aplusb.test.cpp\"\
    \nvoid solve() {\n    LL(a, b);\n    print(a + b);\n}\nint main() {\n    ll t\
    \ = 1;\n    rep(_, t) solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"template.hpp\"\
    \nvoid solve() {\n    LL(a, b);\n    print(a + b);\n}\nint main() {\n    ll t\
    \ = 1;\n    rep(_, t) solve();\n}\n"
  dependsOn:
  - template.hpp
  isVerificationFile: true
  path: test/library_checker/sample/aplusb.test.cpp
  requiredBy: []
  timestamp: '2024-10-11 15:04:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/sample/aplusb.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/sample/aplusb.test.cpp
- /verify/test/library_checker/sample/aplusb.test.cpp.html
title: test/library_checker/sample/aplusb.test.cpp
---
