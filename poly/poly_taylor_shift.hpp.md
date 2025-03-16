---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/factorial.hpp
    title: math/factorial.hpp
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/polynomial_taylor_shift.test.cpp
    title: test/library_checker/polynomial/polynomial_taylor_shift.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://drken1215.hatenablog.com/entry/2023/09/08/003100
    - https://maspypy.github.io/library/poly/poly_taylor_shift.hpp
    - https://x.com/risujiroh/status/1215710785000751104?s=20
  bundledCode: "#line 1 \"poly/poly_taylor_shift.hpp\"\n// https://drken1215.hatenablog.com/entry/2023/09/08/003100\n\
    // https://maspypy.github.io/library/poly/poly_taylor_shift.hpp\n// https://x.com/risujiroh/status/1215710785000751104?s=20\n\
    #line 2 \"template.hpp\"\n// #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"\
    O3\")\n// #pragma GCC optimize(\"unroll-loops\")\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n// https://xn--kst.jp/blog/2019/08/29/cpp-comp/\n\ntemplate\
    \ <class Container, typename = void>\nstruct is_container : std::false_type {};\n\
    template <class Container>\nstruct is_container<Container, std::void_t<decltype(std::declval<Container>().begin()),\
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
    \n  private:\n    vector<T> fac, fac_inv;\n};\n#line 6 \"poly/poly_taylor_shift.hpp\"\
    \n#include <atcoder/convolution>\n#include <atcoder/modint>\ntemplate <class mint>\
    \ vector<mint> poly_taylor_shift(vector<mint> f, mint c) {\n    factorial<mint>\
    \ fac;\n    ll n = ssize(f);\n    fac.ensure(n);\n    rep(i, n) { f[i] *= fac[i];\
    \ }\n    vector<mint> d = [&] {\n        vector<mint> d(n);\n        mint c_pow\
    \ = 1;\n        rep(i, n) {\n            d[i] = c_pow * fac.inv(i);\n        \
    \    c_pow *= c;\n        }\n        return d;\n    }();\n    reverse(all(f));\n\
    \    f = convolution(f, d);\n    f.resize(n);\n    reverse(all(f));\n    rep(i,\
    \ n) f[i] *= fac.inv(i);\n    return f;\n}\n"
  code: "// https://drken1215.hatenablog.com/entry/2023/09/08/003100\n// https://maspypy.github.io/library/poly/poly_taylor_shift.hpp\n\
    // https://x.com/risujiroh/status/1215710785000751104?s=20\n#include \"math/factorial.hpp\"\
    \n#include \"template.hpp\"\n#include <atcoder/convolution>\n#include <atcoder/modint>\n\
    template <class mint> vector<mint> poly_taylor_shift(vector<mint> f, mint c) {\n\
    \    factorial<mint> fac;\n    ll n = ssize(f);\n    fac.ensure(n);\n    rep(i,\
    \ n) { f[i] *= fac[i]; }\n    vector<mint> d = [&] {\n        vector<mint> d(n);\n\
    \        mint c_pow = 1;\n        rep(i, n) {\n            d[i] = c_pow * fac.inv(i);\n\
    \            c_pow *= c;\n        }\n        return d;\n    }();\n    reverse(all(f));\n\
    \    f = convolution(f, d);\n    f.resize(n);\n    reverse(all(f));\n    rep(i,\
    \ n) f[i] *= fac.inv(i);\n    return f;\n}"
  dependsOn:
  - math/factorial.hpp
  - template.hpp
  isVerificationFile: false
  path: poly/poly_taylor_shift.hpp
  requiredBy: []
  timestamp: '2025-03-16 14:03:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/polynomial/polynomial_taylor_shift.test.cpp
documentation_of: poly/poly_taylor_shift.hpp
layout: document
title: poly taylor shift
---
テスト