---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/number_theory/discrete_logarithm_mod.test.cpp
    title: test/library_checker/number_theory/discrete_logarithm_mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
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
    \ dy = {0, 0, 1, -1};\n#line 3 \"math/mod-log.hpp\"\n#include <atcoder/math>\n\
    // https : // qiita.com/suisen_cp/items/d597c8ec576ae32ee2d7\nll mod_log_coprime(ll\
    \ x, ll y, ll mod) {\n    // gcd(x,mod) == 1\n    assert(0 <= x and x < mod and\
    \ 0 <= y and y < mod);\n    if(x == 0) {\n        if(y == 0)\n            return\
    \ 1;\n        else if(y == 1)\n            return 0;\n        else\n         \
    \   return -1;\n    }\n    ll p = 0, xp = 1, ixp = 1;\n    unordered_map<ll, ll>\
    \ mp;\n    for(; p * p < mod; p++) {\n        if(!mp.contains(xp))\n         \
    \   mp[xp] = p;\n        xp = ll(xp) * x % mod;\n    }\n    ll ix = atcoder::inv_mod(x,\
    \ mod);\n    ix = atcoder::pow_mod(ix, p, mod);\n    for(ll i = 0; i < p; i++)\
    \ {\n        if(mp.contains(y * ixp % mod)) {\n            return i * p + mp[y\
    \ * ixp % mod];\n        }\n        ixp = ixp * ix % mod;\n    }\n    return -1;\n\
    }\n// min k s.t. x^k==y mod mod\n// \u306A\u3051\u308C\u3070 -1\nll mod_log(ll\
    \ x, ll y, ll mod) {\n    assert(0 < mod and mod < numeric_limits<int>::max());\n\
    \    // mod \u3067\u304B\u3059\u304E\u308B\u3068128bit\u5FC5\u8981\n    if(x <\
    \ 0 or mod <= x) {\n        x %= mod;\n        if(x < 0)\n            x += mod;\n\
    \    }\n    if(y < 0 or mod <= y) {\n        y %= mod;\n        if(y < 0)\n  \
    \          y += mod;\n    }\n    if(mod == 1 or y == 1)\n        return 0;\n \
    \   ll g = gcd(x, mod);\n    if(g == 1)\n        return mod_log_coprime(x, y,\
    \ mod);\n    if(y % g)\n        return -1;\n    y /= g, mod /= g;\n    ll ix =\
    \ atcoder::inv_mod(x / g, mod);\n    ll z = y * ix % mod;\n    ll l = mod_log(x\
    \ % mod, z, mod);\n    return l == -1 ? l : l + 1;\n}\n"
  code: "#pragma once\n#include \"template.hpp\"\n#include <atcoder/math>\n// https\
    \ : // qiita.com/suisen_cp/items/d597c8ec576ae32ee2d7\nll mod_log_coprime(ll x,\
    \ ll y, ll mod) {\n    // gcd(x,mod) == 1\n    assert(0 <= x and x < mod and 0\
    \ <= y and y < mod);\n    if(x == 0) {\n        if(y == 0)\n            return\
    \ 1;\n        else if(y == 1)\n            return 0;\n        else\n         \
    \   return -1;\n    }\n    ll p = 0, xp = 1, ixp = 1;\n    unordered_map<ll, ll>\
    \ mp;\n    for(; p * p < mod; p++) {\n        if(!mp.contains(xp))\n         \
    \   mp[xp] = p;\n        xp = ll(xp) * x % mod;\n    }\n    ll ix = atcoder::inv_mod(x,\
    \ mod);\n    ix = atcoder::pow_mod(ix, p, mod);\n    for(ll i = 0; i < p; i++)\
    \ {\n        if(mp.contains(y * ixp % mod)) {\n            return i * p + mp[y\
    \ * ixp % mod];\n        }\n        ixp = ixp * ix % mod;\n    }\n    return -1;\n\
    }\n// min k s.t. x^k==y mod mod\n// \u306A\u3051\u308C\u3070 -1\nll mod_log(ll\
    \ x, ll y, ll mod) {\n    assert(0 < mod and mod < numeric_limits<int>::max());\n\
    \    // mod \u3067\u304B\u3059\u304E\u308B\u3068128bit\u5FC5\u8981\n    if(x <\
    \ 0 or mod <= x) {\n        x %= mod;\n        if(x < 0)\n            x += mod;\n\
    \    }\n    if(y < 0 or mod <= y) {\n        y %= mod;\n        if(y < 0)\n  \
    \          y += mod;\n    }\n    if(mod == 1 or y == 1)\n        return 0;\n \
    \   ll g = gcd(x, mod);\n    if(g == 1)\n        return mod_log_coprime(x, y,\
    \ mod);\n    if(y % g)\n        return -1;\n    y /= g, mod /= g;\n    ll ix =\
    \ atcoder::inv_mod(x / g, mod);\n    ll z = y * ix % mod;\n    ll l = mod_log(x\
    \ % mod, z, mod);\n    return l == -1 ? l : l + 1;\n}"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: math/mod-log.hpp
  requiredBy: []
  timestamp: '2025-03-17 22:44:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/number_theory/discrete_logarithm_mod.test.cpp
documentation_of: math/mod-log.hpp
layout: document
redirect_from:
- /library/math/mod-log.hpp
- /library/math/mod-log.hpp.html
title: math/mod-log.hpp
---
