---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/factorial.hpp
    title: math/factorial.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy:
  - icon: ':question:'
    path: math/factorial_large.hpp
    title: math/factorial_large.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/enumerative_combinatorics/many_factorials.test.cpp
    title: test/library_checker/enumerative_combinatorics/many_factorials.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/shift_of_sampling_points_of_polynomial.test.cpp
    title: test/library_checker/polynomial/shift_of_sampling_points_of_polynomial.test.cpp
  - icon: ':x:'
    path: test/yukicoder/3004.test.cpp
    title: test/yukicoder/3004.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://suisen-cp.github.io/cp-library-cpp/library/polynomial/shift_of_sampling_points.hpp
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
    \ dy = {0, 0, 1, -1};\n#line 3 \"math/factorial.hpp\"\n// https://suisen-cp.github.io/cp-library-cpp/library/math/factorial.hpp\n\
    template <class T> struct factorial {\n    factorial() {};\n    void ensure(const\
    \ int n) {\n        int sz = size(fac);\n        if(sz > n) {\n            return;\n\
    \        }\n        int new_sz = max(2 * sz, n + 1);\n        fac.resize(new_sz),\
    \ fac_inv.resize(new_sz);\n        for(int i = sz; i < new_sz; i++) {\n      \
    \      if(i == 0) {\n                fac[i] = 1;\n                continue;\n\
    \            }\n            fac[i] = fac[i - 1] * i;\n        }\n        fac_inv[new_sz\
    \ - 1] = T(1) / fac[new_sz - 1];\n        for(int i = new_sz - 2; i >= sz; i--)\
    \ {\n            fac_inv[i] = fac_inv[i + 1] * (i + 1);\n        }\n        return;\n\
    \    }\n    T get(int i) {\n        ensure(i);\n        return fac[i];\n    }\n\
    \    T operator[](int i) { return get(i); }\n    T inv(int i) {\n        ensure(i);\n\
    \        return fac_inv[i];\n    }\n    T binom(int n, int i) {\n        if(n\
    \ < 0 || i < 0 || n < i) {\n            return T(0);\n        }\n        ensure(n);\n\
    \        return fac[n] * fac_inv[i] * fac_inv[n - i];\n    }\n    T perm(int n,\
    \ int i) {\n        if(n < 0 || i < 0 || n < i) {\n            return T(0);\n\
    \        }\n        ensure(n);\n        return fac[n] * fac_inv[n - i];\n    }\n\
    \n  private:\n    vector<T> fac, fac_inv;\n};\n#line 3 \"poly/shift_of_sampling_points.hpp\"\
    \n#include <atcoder/convolution>\n// https://suisen-cp.github.io/cp-library-cpp/library/polynomial/shift_of_sampling_points.hpp\n\
    template <class Mint>\nvector<Mint> shift_of_sampling_points(const vector<Mint>\
    \ &f, const int m,\n                                      const int c) {\n   \
    \ // n\u6B21\u672A\u6E80\u306E\u591A\u9805\u5F0Ff\u306En\u500B\u306E\u70B9f(0),...,f(n-1)\u306B\
    \u5BFE\u3057\u3066\n    // f(c),...,f(c+m-1)\u3092\u8A08\u7B97\n    factorial<Mint>\
    \ fac;\n    const int n = f.size();\n    auto a = [&] {\n        vector<Mint>\
    \ a1(n), a2(n);\n        rep(i, n) {\n            a1[i] = f[i] * fac.inv(i);\n\
    \            a2[i] = ((i & 1) ? -1 : 1) * fac.inv(i);\n        }\n        auto\
    \ a = convolution(a1, a2);\n        a.resize(n);\n        return a;\n    }();\n\
    \    vector<Mint> a_(n);\n    rep(i, n) { a_[i] = a[n - 1 - i] * fac[n - 1 - i];\
    \ }\n    vector<Mint> b2 = [&] {\n        // b2[i] = c*(c-1)*...*(c-i+1)/i!\n\
    \        vector<Mint> b2(n);\n        Mint ci = 1;\n        b2[0] = ci;\n    \
    \    for(int i = 1; i < n; i++) {\n            ci *= c - i + 1;\n            b2[i]\
    \ = ci * fac.inv(i);\n        }\n        return b2;\n    }();\n    auto b = convolution(a_,\
    \ b2);\n    vector<Mint> fc = [&] {\n        vector<Mint> f1(n);\n        vector<Mint>\
    \ f2(m);\n        rep(i, n) { f1[i] = b[n - 1 - i] * fac.inv(i); }\n        rep(i,\
    \ m) { f2[i] = fac.inv(i); }\n        return convolution(f1, f2);\n    }();\n\
    \    vector<Mint> res(m);\n    rep(i, m) { res[i] = fac[i] * fc[i]; }\n    return\
    \ res;\n}\n"
  code: "#pragma once\n#include \"math/factorial.hpp\"\n#include <atcoder/convolution>\n\
    // https://suisen-cp.github.io/cp-library-cpp/library/polynomial/shift_of_sampling_points.hpp\n\
    template <class Mint>\nvector<Mint> shift_of_sampling_points(const vector<Mint>\
    \ &f, const int m,\n                                      const int c) {\n   \
    \ // n\u6B21\u672A\u6E80\u306E\u591A\u9805\u5F0Ff\u306En\u500B\u306E\u70B9f(0),...,f(n-1)\u306B\
    \u5BFE\u3057\u3066\n    // f(c),...,f(c+m-1)\u3092\u8A08\u7B97\n    factorial<Mint>\
    \ fac;\n    const int n = f.size();\n    auto a = [&] {\n        vector<Mint>\
    \ a1(n), a2(n);\n        rep(i, n) {\n            a1[i] = f[i] * fac.inv(i);\n\
    \            a2[i] = ((i & 1) ? -1 : 1) * fac.inv(i);\n        }\n        auto\
    \ a = convolution(a1, a2);\n        a.resize(n);\n        return a;\n    }();\n\
    \    vector<Mint> a_(n);\n    rep(i, n) { a_[i] = a[n - 1 - i] * fac[n - 1 - i];\
    \ }\n    vector<Mint> b2 = [&] {\n        // b2[i] = c*(c-1)*...*(c-i+1)/i!\n\
    \        vector<Mint> b2(n);\n        Mint ci = 1;\n        b2[0] = ci;\n    \
    \    for(int i = 1; i < n; i++) {\n            ci *= c - i + 1;\n            b2[i]\
    \ = ci * fac.inv(i);\n        }\n        return b2;\n    }();\n    auto b = convolution(a_,\
    \ b2);\n    vector<Mint> fc = [&] {\n        vector<Mint> f1(n);\n        vector<Mint>\
    \ f2(m);\n        rep(i, n) { f1[i] = b[n - 1 - i] * fac.inv(i); }\n        rep(i,\
    \ m) { f2[i] = fac.inv(i); }\n        return convolution(f1, f2);\n    }();\n\
    \    vector<Mint> res(m);\n    rep(i, m) { res[i] = fac[i] * fc[i]; }\n    return\
    \ res;\n}\n"
  dependsOn:
  - math/factorial.hpp
  - template.hpp
  isVerificationFile: false
  path: poly/shift_of_sampling_points.hpp
  requiredBy:
  - math/factorial_large.hpp
  timestamp: '2025-03-17 22:06:24+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library_checker/enumerative_combinatorics/many_factorials.test.cpp
  - test/library_checker/polynomial/shift_of_sampling_points_of_polynomial.test.cpp
  - test/yukicoder/3004.test.cpp
documentation_of: poly/shift_of_sampling_points.hpp
layout: document
redirect_from:
- /library/poly/shift_of_sampling_points.hpp
- /library/poly/shift_of_sampling_points.hpp.html
title: poly/shift_of_sampling_points.hpp
---
