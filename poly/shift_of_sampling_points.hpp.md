---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/factorial.hpp
    title: math/factorial.hpp
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/factorial_large.hpp
    title: math/factorial_large.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/enumerative_combinatorics/many_factorials.test.cpp
    title: test/library_checker/enumerative_combinatorics/many_factorials.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/shift_of_sampling_points_of_polynomial.test.cpp
    title: test/library_checker/polynomial/shift_of_sampling_points_of_polynomial.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://suisen-cp.github.io/cp-library-cpp/library/polynomial/shift_of_sampling_points.hpp
  bundledCode: "#line 2 \"template.hpp\"\n// #pragma GCC target(\"avx2\")\n// #pragma\
    \ GCC optimize(\"O3\")\n// #pragma GCC optimize(\"unroll-loops\")\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n// https://xn--kst.jp/blog/2019/08/29/cpp-comp/\n\
    // debug methods\n// usage: debug(x,y);\n// vector \u51FA\u529B\u3067\u304D\u308B\
    \u3088\u3046\u306B\u4FEE\u6B63\ntemplate <typename T>\nostream& debug_print(ostream&\
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
    #endif\n\nusing ll = long long;\nusing vl = vector<ll>;\nusing Graph = vector<vector<ll>>;\n\
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
    vl dx = {1, -1, 0, 0};\nvl dy = {0, 0, 1, -1};\n#line 3 \"math/factorial.hpp\"\
    \n// https://suisen-cp.github.io/cp-library-cpp/library/math/factorial.hpp\ntemplate\
    \ <class T> struct factorial {\n    factorial() {};\n    void ensure(const int\
    \ n) {\n        int sz = size(fac);\n        if(sz > n) {\n            return;\n\
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
  timestamp: '2024-12-02 02:31:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/enumerative_combinatorics/many_factorials.test.cpp
  - test/library_checker/polynomial/shift_of_sampling_points_of_polynomial.test.cpp
documentation_of: poly/shift_of_sampling_points.hpp
layout: document
redirect_from:
- /library/poly/shift_of_sampling_points.hpp
- /library/poly/shift_of_sampling_points.hpp.html
title: poly/shift_of_sampling_points.hpp
---
