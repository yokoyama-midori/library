---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: poly/bostan_mori.hpp
    title: poly/bostan_mori.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_GCC: ''
    links:
    - https://atcoder.jp/contests/tdpc/tasks/tdpc_fibonacci
  bundledCode: "#line 1 \"test/atcoder/tdpc_fibonacci.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/tdpc/tasks/tdpc_fibonacci\"\n#define IGNORE\n\
    // \u884C\u5217\u7D2F\u4E57\u3067\u306F\u7121\u7406 (\u9AD8\u901F)\u304D\u305F\
    \u307E\u3055\u6CD5,Bostan-Mori\u304C\u5FC5\u8981\n#line 2 \"template.hpp\"\n//\
    \ #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"O3\")\n// #pragma GCC\
    \ optimize(\"unroll-loops\")\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    // https://xn--kst.jp/blog/2019/08/29/cpp-comp/\n// debug methods\n// usage: debug(x,y);\n\
    #define CHOOSE(a) CHOOSE2 a\n#define CHOOSE2(a0, a1, a2, a3, a4, x, ...) x\n#define\
    \ debug_1(x1) cout << #x1 << \": \" << x1 << endl\n#define debug_2(x1, x2)   \
    \                                                     \\\n    cout << #x1 << \"\
    : \" << x1 << \", \" #x2 << \": \" << x2 << endl\n#define debug_3(x1, x2, x3)\
    \                                                    \\\n    cout << #x1 << \"\
    : \" << x1 << \", \" #x2 << \": \" << x2 << \", \" #x3 << \": \"    \\\n     \
    \    << x3 << endl\n#define debug_4(x1, x2, x3, x4)                          \
    \                      \\\n    cout << #x1 << \": \" << x1 << \", \" #x2 << \"\
    : \" << x2 << \", \" #x3 << \": \"    \\\n         << x3 << \", \" #x4 << \":\
    \ \" << x4 << endl\n#define debug_5(x1, x2, x3, x4, x5)                      \
    \                      \\\n    cout << #x1 << \": \" << x1 << \", \" #x2 << \"\
    : \" << x2 << \", \" #x3 << \": \"    \\\n         << x3 << \", \" #x4 << \":\
    \ \" << x4 << \", \" #x5 << \": \" << x5 << endl\n#ifdef LOCAL\n#define debug(...)\
    \                                                             \\\n    CHOOSE((__VA_ARGS__,\
    \ debug_5, debug_4, debug_3, debug_2, debug_1, ~))      \\\n    (__VA_ARGS__)\n\
    #else\n#define debug(...)\n#endif\n\nusing ll = long long;\nusing vl = vector<ll>;\n\
    using Graph = vector<vector<ll>>;\nusing P = pair<ll, ll>;\n#define all(v) v.begin(),\
    \ v.end()\ntemplate <typename T> inline bool chmax(T &a, T b) {\n    return ((a\
    \ < b) ? (a = b, true) : (false));\n}\ntemplate <typename T> inline bool chmin(T\
    \ &a, T b) {\n    return ((a > b) ? (a = b, true) : (false));\n}\n#define rep1(i,\
    \ n) for(ll i = 1; i <= ((ll)n); ++i)\n// https://trap.jp/post/1224/\ntemplate\
    \ <class... T> constexpr auto min(T... a) {\n    return min(initializer_list<common_type_t<T...>>{a...});\n\
    }\ntemplate <class... T> constexpr auto max(T... a) {\n    return max(initializer_list<common_type_t<T...>>{a...});\n\
    }\ntemplate <class... T> void input(T &...a) { (cin >> ... >> a); }\ntemplate\
    \ <class T> void input(vector<T> &a) {\n    for(T &x : a)\n        cin >> x;\n\
    }\nvoid print() { cout << '\\n'; }\ntemplate <class T, class... Ts> void print(const\
    \ T &a, const Ts &...b) {\n    cout << a;\n    (cout << ... << (cout << ' ', b));\n\
    \    cout << '\\n';\n}\ntemplate <class T> void print(vector<T> &x) {\n    if(x.size())\
    \ {\n        for(ll i = 0; i < x.size(); i++) {\n            cout << x[i] << \"\
    \ \\n\"[i + 1 == x.size()];\n        }\n    }\n}\n#define INT(...)           \
    \                                                    \\\n    int __VA_ARGS__;\
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
    vl dx = {1, -1, 0, 0};\nvl dy = {0, 0, 1, -1};\n#line 3 \"poly/bostan_mori.hpp\"\
    \n#include <atcoder/modint>\n#include <atcoder/convolution>\nusing namespace atcoder;\n\
    template <class T> T bostanMori(vector<T> p, vector<T> q, ll n) {\n    // return\
    \ [x^n]P(x)/Q(x)\n    ll k = p.size();\n    while(n) {\n        auto q_minus(q);\n\
    \        rep(i, k + 1) {\n            if(i & 1)\n                q_minus[i] *=\
    \ -1;\n        }\n        if(T::mod() == 998244353) {\n            p = convolution(p,\
    \ q_minus);\n            q = convolution(q, q_minus);\n        } else {\n    \
    \        p = convolution_naive(p, q_minus);\n            q = convolution_naive(q,\
    \ q_minus);\n        }\n        vector<T> q_nex(k + 1), p_nex(k);\n        rep(i,\
    \ k + 1) { q_nex[i] = q[2 * i]; }\n        ll n1 = n & 1;\n        rep(i, k) {\
    \ p_nex[i] = p[2 * i + n1]; }\n        swap(p, p_nex);\n        swap(q, q_nex);\n\
    \        n >>= 1;\n    }\n    return p[0] / q[0];\n}\n#line 6 \"test/atcoder/tdpc_fibonacci.test.cpp\"\
    \nusing mint = modint1000000007;\nvoid solve() {\n    LL(k, n);\n    vector<mint>\
    \ f(k), q(k + 1);\n    rep(i, k) f[i] = 1;\n    q[0] = 1;\n    rep1(i, k) q[i]\
    \ = -1;\n    auto p = convolution_naive(f,q);\n    p.resize(k);\n    print(bostanMori(p,q,n-1).val());\n\
    }\nint main() {\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    cout << std::setprecision(16);\n    int t = 1;\n    rep(_, t) { solve();\
    \ }\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/tdpc/tasks/tdpc_fibonacci\"\
    \n#define IGNORE\n// \u884C\u5217\u7D2F\u4E57\u3067\u306F\u7121\u7406 (\u9AD8\u901F\
    )\u304D\u305F\u307E\u3055\u6CD5,Bostan-Mori\u304C\u5FC5\u8981\n#include \"template.hpp\"\
    \n#include \"poly/bostan_mori.hpp\"\nusing mint = modint1000000007;\nvoid solve()\
    \ {\n    LL(k, n);\n    vector<mint> f(k), q(k + 1);\n    rep(i, k) f[i] = 1;\n\
    \    q[0] = 1;\n    rep1(i, k) q[i] = -1;\n    auto p = convolution_naive(f,q);\n\
    \    p.resize(k);\n    print(bostanMori(p,q,n-1).val());\n}\nint main() {\n  \
    \  ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n    cout << std::setprecision(16);\n\
    \    int t = 1;\n    rep(_, t) { solve(); }\n}\n"
  dependsOn:
  - template.hpp
  - poly/bostan_mori.hpp
  isVerificationFile: true
  path: test/atcoder/tdpc_fibonacci.test.cpp
  requiredBy: []
  timestamp: '2024-10-19 02:23:40+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/tdpc_fibonacci.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/tdpc_fibonacci.test.cpp
- /verify/test/atcoder/tdpc_fibonacci.test.cpp.html
title: test/atcoder/tdpc_fibonacci.test.cpp
---
