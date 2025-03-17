---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/factorial.hpp
    title: math/factorial.hpp
  - icon: ':heavy_check_mark:'
    path: poly/poly_taylor_shift.hpp
    title: poly taylor shift
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
    PROBLEM: https://judge.yosupo.jp/problem/polynomial_taylor_shift
    links:
    - https://judge.yosupo.jp/problem/polynomial_taylor_shift
  bundledCode: "#line 1 \"test/library_checker/polynomial/polynomial_taylor_shift.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/polynomial_taylor_shift\"\n\
    #include <atcoder/convolution>\n#include <atcoder/modint>\nusing mint = atcoder::modint998244353;\n\
    #line 1 \"poly/poly_taylor_shift.hpp\"\n// https://drken1215.hatenablog.com/entry/2023/09/08/003100\n\
    // https://maspypy.github.io/library/poly/poly_taylor_shift.hpp\n// https://x.com/risujiroh/status/1215710785000751104?s=20\n\
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
    \n  private:\n    vector<T> fac, fac_inv;\n};\n#line 8 \"poly/poly_taylor_shift.hpp\"\
    \ntemplate <class mint> vector<mint> poly_taylor_shift(vector<mint> f, mint c)\
    \ {\n    factorial<mint> fac;\n    ll n = ssize(f);\n    fac.ensure(n);\n    rep(i,\
    \ n) { f[i] *= fac[i]; }\n    vector<mint> d = [&] {\n        vector<mint> d(n);\n\
    \        mint c_pow = 1;\n        rep(i, n) {\n            d[i] = c_pow * fac.inv(i);\n\
    \            c_pow *= c;\n        }\n        return d;\n    }();\n    reverse(all(f));\n\
    \    f = convolution(f, d);\n    f.resize(n);\n    reverse(all(f));\n    rep(i,\
    \ n) f[i] *= fac.inv(i);\n    return f;\n}\n#line 7 \"test/library_checker/polynomial/polynomial_taylor_shift.test.cpp\"\
    \nfactorial<mint> fac;\nvoid solve() {\n    LL(n, c);\n    vector<mint> a(n);\n\
    \    rep(i, n) {\n        LL(ai);\n        a[i] = ai;\n    }\n    auto b = poly_taylor_shift(a,\
    \ mint(c));\n    print(b);\n}\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/polynomial_taylor_shift\"\
    \n#include <atcoder/convolution>\n#include <atcoder/modint>\nusing mint = atcoder::modint998244353;\n\
    #include \"poly/poly_taylor_shift.hpp\"\n#include \"template.hpp\"\nfactorial<mint>\
    \ fac;\nvoid solve() {\n    LL(n, c);\n    vector<mint> a(n);\n    rep(i, n) {\n\
    \        LL(ai);\n        a[i] = ai;\n    }\n    auto b = poly_taylor_shift(a,\
    \ mint(c));\n    print(b);\n}\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    solve();\n}\n"
  dependsOn:
  - poly/poly_taylor_shift.hpp
  - math/factorial.hpp
  - template.hpp
  isVerificationFile: true
  path: test/library_checker/polynomial/polynomial_taylor_shift.test.cpp
  requiredBy: []
  timestamp: '2025-03-17 22:44:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/polynomial/polynomial_taylor_shift.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/polynomial/polynomial_taylor_shift.test.cpp
- /verify/test/library_checker/polynomial/polynomial_taylor_shift.test.cpp.html
title: test/library_checker/polynomial/polynomial_taylor_shift.test.cpp
---
