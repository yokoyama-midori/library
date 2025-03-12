---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/chromatic-number.hpp
    title: graph/chromatic-number.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/chromatic_number
    links:
    - https://judge.yosupo.jp/problem/chromatic_number
  bundledCode: "#line 1 \"test/library_checker/graph/chromatic_number.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/chromatic_number\"\n#line 2\
    \ \"template.hpp\"\n// #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"\
    O3\")\n// #pragma GCC optimize(\"unroll-loops\")\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n// https://xn--kst.jp/blog/2019/08/29/cpp-comp/\n// debug\
    \ methods\n// usage: debug(x,y);\n// vector \u51FA\u529B\u3067\u304D\u308B\u3088\
    \u3046\u306B\u4FEE\u6B63\ntemplate <typename T>\nostream& debug_print(ostream&\
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
    vl dx = {1, -1, 0, 0};\nvl dy = {0, 0, 1, -1};\n#line 2 \"graph/chromatic-number.hpp\"\
    \n// https://kokiymgch.hatenablog.com/entry/2018/01/27/235959\n// https://www.slideshare.net/wata_orz/ss-12131479\n\
    // TODO \u2193\u3000hist\u8FBA\u308A\u3067\u4F55\u3084\u3063\u3066\u308B\u304B\
    \u7406\u89E3\u3059\u308B\n// https://nyaannyaan.github.io/library/graph/chromatic-number.hpp\n\
    // https://ei1333.github.io/library/graph/others/chromatic-number.hpp\n#include\
    \ <atcoder/modint>\ntemplate <class T> int ChromaticNumber(vector<vector<T>> &g)\
    \ {\n    using mint = atcoder::modint;\n    // g \u96A3\u63A5\u884C\u5217\n  \
    \  ll n = g.size();\n    vl adj(n, 0);\n    rep(i, n) {\n        adj[i] |= 1LL\
    \ << i;\n        for(ll j = i + 1; j < n; j++)\n            if(g[i][j]) {\n  \
    \              adj[j] |= 1LL << i;\n                adj[i] |= 1LL << j;\n    \
    \        }\n    }\n    vl ind_cnt(1LL << n, 0);\n    // ind_cnt[s] = s\u306E\u90E8\
    \u5206\u96C6\u5408\u3067\u3042\u3063\u3066\u3001\u72EC\u7ACB\u306A\u3082\u306E\
    \u306E\u6570\n    ind_cnt[0] = 1;\n    for(ll s = 1; s < (1LL << n); s++) {\n\
    \        ll i = __builtin_ctz(s);\n        // s\u306E\u4E0B\u304B\u3089i\u6841\
    \u76EE\u304C(\u521D\u3081\u3066)1\n        ll j = s & (s - 1);\n        // j =\
    \ s ^ (1LL << i)\n        ind_cnt[s] = ind_cnt[j] + ind_cnt[j & (~adj[i])];\n\
    \        // ind_cnt[s] = ind_cnt[j](i\u3092\u4F7F\u308F\u306A\u3044) + ind_cnt[..](i\u3092\
    \u4F7F\u3046)\n        // i\u3092\u4F7F\u3046\u5834\u5408i\u3068\u96A3\u63A5\u3057\
    \u305F\u9802\u70B9\u306F\u4F7F\u3048\u306A\u3044\u306E\u3067 .. = j & (~adj[i])\n\
    \    }\n    ll res = n;\n    vector<int> ps = {1000000007, 1000000009};\n    for(auto\
    \ &p : ps) {\n        mint::set_mod(p);\n        rep(k, n) {\n            mint\
    \ cc = 0;\n            ll s = (1LL << n) - 1;\n            for(ll t = s;; t =\
    \ (t - 1) & s) {\n                ll sign = n - __popcount(t);\n             \
    \   cc += ((sign & 1) ? -1 : 1) * mint(ind_cnt[t]).pow(k);\n                if(t\
    \ == 0)\n                    break;\n            }\n            if(cc.val()) {\n\
    \                chmin(res, k);\n                break;\n            }\n     \
    \   }\n    }\n    return res;\n}\n#line 3 \"test/library_checker/graph/chromatic_number.test.cpp\"\
    \nvoid solve() {\n    LL(n, m);\n    vector g(n, vector<bool>(n, false));\n  \
    \  rep(i, m) {\n        LL(a, b);\n        g[a][b] = g[b][a] = true;\n    }\n\
    \    print(ChromaticNumber(g));\n}\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/chromatic_number\"\n#include\
    \ \"graph/chromatic-number.hpp\"\nvoid solve() {\n    LL(n, m);\n    vector g(n,\
    \ vector<bool>(n, false));\n    rep(i, m) {\n        LL(a, b);\n        g[a][b]\
    \ = g[b][a] = true;\n    }\n    print(ChromaticNumber(g));\n}\nint main() {\n\
    \    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n    solve();\n\
    }\n"
  dependsOn:
  - graph/chromatic-number.hpp
  - template.hpp
  isVerificationFile: true
  path: test/library_checker/graph/chromatic_number.test.cpp
  requiredBy: []
  timestamp: '2025-03-02 18:30:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/graph/chromatic_number.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/graph/chromatic_number.test.cpp
- /verify/test/library_checker/graph/chromatic_number.test.cpp.html
title: test/library_checker/graph/chromatic_number.test.cpp
---
