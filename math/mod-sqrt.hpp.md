---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/mod-pow.hpp
    title: math/mod-pow.hpp
  - icon: ':x:'
    path: rng.hpp
    title: rng.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/number_theory/sqrt_mod.test.cpp
    title: test/library_checker/number_theory/sqrt_mod.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://37zigen.com/cipolla-algorithm/
    - https://maspypy.github.io/library/mod/mod_sqrt.hpp
    - https://suu-0313.hatenablog.com/entry/2021/10/01/024229
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
    \ Iterable> void print(const Iterable &v) {\n    auto it = v.begin();\n    for(;\
    \ it != v.end(); ++it) {\n        if(it != v.begin())\n            cout << \"\
    \ \";\n        print_one(*it);\n    }\n    cout << '\\n';\n}\nusing ll = long\
    \ long;\nusing vl = vector<ll>;\nusing vll = vector<vl>;\nusing P = pair<ll, ll>;\n\
    #define all(v) v.begin(), v.end()\ntemplate <typename T> inline bool chmax(T &a,\
    \ T b) {\n    return ((a < b) ? (a = b, true) : (false));\n}\ntemplate <typename\
    \ T> inline bool chmin(T &a, T b) {\n    return ((a > b) ? (a = b, true) : (false));\n\
    }\n#define rep1(i, n) for(ll i = 1; i <= ((ll)n); ++i)\n// https://trap.jp/post/1224/\n\
    template <class... T> constexpr auto min(T... a) {\n    return min(initializer_list<common_type_t<T...>>{a...});\n\
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
    \ dy = {0, 0, 1, -1};\n#line 3 \"math/mod-pow.hpp\"\nint mod_pow(int x, ll n,\
    \ int mod) {\n    assert(n >= 0);\n    ll res = 1, xpow = x;\n    while(n) {\n\
    \        if(n & 1) {\n            res = res * xpow % mod;\n        }\n       \
    \ xpow = xpow * xpow % mod;\n        n >>= 1;\n    }\n    return res;\n}\nll mod_pow_ll(ll\
    \ x, ll n, ll mod) {\n    assert(n >= 0);\n    __int128 res = 1, xpow = x;\n \
    \   while(n) {\n        if(n & 1) {\n            res = res * xpow % mod;\n   \
    \     }\n        xpow = xpow * xpow % mod;\n        n >>= 1;\n    }\n    return\
    \ res;\n}\n#line 2 \"rng.hpp\"\n// https://maspypy.github.io/library/random/base.hpp\n\
    #line 4 \"rng.hpp\"\nunsigned long long RNG_64() {\n    static unsigned long long\
    \ x_ =\n        (unsigned long long)(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                                 chrono::high_resolution_clock::now()\n     \
    \                                .time_since_epoch())\n                      \
    \           .count()) *\n        10150724397891781847ULL;\n    x_ ^= x_ << 7;\n\
    \    return x_ ^= x_ >> 9;\n}\n\nunsigned long long RNG(unsigned long long lim)\
    \ { return RNG_64() % lim; }\n\nll rng(ll l, ll r) {\n    // [l,r)\n    return\
    \ l + RNG_64() % (r - l);\n}\n#line 5 \"math/mod-sqrt.hpp\"\n// Cipolla \u306E\
    \u30A2\u30EB\u30B4\u30EA\u30BA\u30E0 O(log p)\n// https://suu-0313.hatenablog.com/entry/2021/10/01/024229\n\
    // https://37zigen.com/cipolla-algorithm/\n// https://maspypy.github.io/library/mod/mod_sqrt.hpp\n\
    int mod_sqrt(int y, int p) {\n    // return x (x^2 = y mod p)\n    // \u306A\u3051\
    \u308C\u3070 -1 \u3092\u8FD4\u3059\n    assert(0 <= y and y < p);\n    if(p ==\
    \ 2 or y <= 1) {\n        return y;\n    }\n    if(mod_pow(y, (p - 1) / 2, p)\
    \ != 1) {\n        return -1;\n    }\n    int b, x2;\n    while(1) {\n       \
    \ b = rng(1, p);\n        x2 = ((ll)b * b - y) % p;\n        if(x2 < 0)\n    \
    \        x2 += p;\n        if(mod_pow(x2, (p - 1) / 2, p) != 1)\n            break;\n\
    \    }\n    if(x2 == 0)\n        return b;\n    int k = (p + 1) / 2;\n    ll f1\
    \ = 1, f2 = 0;\n    // (b + \u221Ax2)^k\n    ll pow1 = b, pow2 = 1;\n    while(k)\
    \ {\n        // 2*int_max*int_max < ll_max\n        if(k & 1) {\n            tie(f1,\
    \ f2) =\n                P{f1 * pow1 + f2 * pow2 % p * x2, f1 * pow2 + f2 * pow1};\n\
    \            f1 %= p, f2 %= p;\n        }\n        tie(pow1, pow2) =\n       \
    \     P{pow1 * pow1 + pow2 * pow2 % p * x2, 2 * pow1 % p * pow2};\n        pow1\
    \ %= p, pow2 %= p;\n        k >>= 1;\n    }\n    // assert(f2 == 0);\n    return\
    \ f1;\n}\n"
  code: "#pragma once\n#include \"math/mod-pow.hpp\"\n#include \"rng.hpp\"\n#include\
    \ \"template.hpp\"\n// Cipolla \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0 O(log\
    \ p)\n// https://suu-0313.hatenablog.com/entry/2021/10/01/024229\n// https://37zigen.com/cipolla-algorithm/\n\
    // https://maspypy.github.io/library/mod/mod_sqrt.hpp\nint mod_sqrt(int y, int\
    \ p) {\n    // return x (x^2 = y mod p)\n    // \u306A\u3051\u308C\u3070 -1 \u3092\
    \u8FD4\u3059\n    assert(0 <= y and y < p);\n    if(p == 2 or y <= 1) {\n    \
    \    return y;\n    }\n    if(mod_pow(y, (p - 1) / 2, p) != 1) {\n        return\
    \ -1;\n    }\n    int b, x2;\n    while(1) {\n        b = rng(1, p);\n       \
    \ x2 = ((ll)b * b - y) % p;\n        if(x2 < 0)\n            x2 += p;\n      \
    \  if(mod_pow(x2, (p - 1) / 2, p) != 1)\n            break;\n    }\n    if(x2\
    \ == 0)\n        return b;\n    int k = (p + 1) / 2;\n    ll f1 = 1, f2 = 0;\n\
    \    // (b + \u221Ax2)^k\n    ll pow1 = b, pow2 = 1;\n    while(k) {\n       \
    \ // 2*int_max*int_max < ll_max\n        if(k & 1) {\n            tie(f1, f2)\
    \ =\n                P{f1 * pow1 + f2 * pow2 % p * x2, f1 * pow2 + f2 * pow1};\n\
    \            f1 %= p, f2 %= p;\n        }\n        tie(pow1, pow2) =\n       \
    \     P{pow1 * pow1 + pow2 * pow2 % p * x2, 2 * pow1 % p * pow2};\n        pow1\
    \ %= p, pow2 %= p;\n        k >>= 1;\n    }\n    // assert(f2 == 0);\n    return\
    \ f1;\n}"
  dependsOn:
  - math/mod-pow.hpp
  - template.hpp
  - rng.hpp
  isVerificationFile: false
  path: math/mod-sqrt.hpp
  requiredBy: []
  timestamp: '2025-03-17 22:06:24+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/number_theory/sqrt_mod.test.cpp
documentation_of: math/mod-sqrt.hpp
layout: document
redirect_from:
- /library/math/mod-sqrt.hpp
- /library/math/mod-sqrt.hpp.html
title: math/mod-sqrt.hpp
---
