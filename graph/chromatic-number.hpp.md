---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/chromatic_number.test.cpp
    title: test/library_checker/graph/chromatic_number.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://ei1333.github.io/library/graph/others/chromatic-number.hpp
    - https://kokiymgch.hatenablog.com/entry/2018/01/27/235959
    - https://nyaannyaan.github.io/library/graph/chromatic-number.hpp
    - https://www.slideshare.net/wata_orz/ss-12131479
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
    \ dy = {0, 0, 1, -1};\n#line 2 \"graph/chromatic-number.hpp\"\n// https://kokiymgch.hatenablog.com/entry/2018/01/27/235959\n\
    // https://www.slideshare.net/wata_orz/ss-12131479\n// TODO \u2193\u3000hist\u8FBA\
    \u308A\u3067\u4F55\u3084\u3063\u3066\u308B\u304B\u7406\u89E3\u3059\u308B\n// https://nyaannyaan.github.io/library/graph/chromatic-number.hpp\n\
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
    \   }\n    }\n    return res;\n}\n"
  code: "#include \"template.hpp\"\n// https://kokiymgch.hatenablog.com/entry/2018/01/27/235959\n\
    // https://www.slideshare.net/wata_orz/ss-12131479\n// TODO \u2193\u3000hist\u8FBA\
    \u308A\u3067\u4F55\u3084\u3063\u3066\u308B\u304B\u7406\u89E3\u3059\u308B\n// https://nyaannyaan.github.io/library/graph/chromatic-number.hpp\n\
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
    \   }\n    }\n    return res;\n}"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: graph/chromatic-number.hpp
  requiredBy: []
  timestamp: '2025-03-18 18:04:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/graph/chromatic_number.test.cpp
documentation_of: graph/chromatic-number.hpp
layout: document
redirect_from:
- /library/graph/chromatic-number.hpp
- /library/graph/chromatic-number.hpp.html
title: graph/chromatic-number.hpp
---
