---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/linear_algebra/matrix_product.test.cpp
    title: test/library_checker/linear_algebra/matrix_product.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/linear_algebra/pow_of_matrix.test.cpp
    title: test/library_checker/linear_algebra/pow_of_matrix.test.cpp
  - icon: ':x:'
    path: test/yukicoder/3006.test.cpp
    title: test/yukicoder/3006.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    \ dy = {0, 0, 1, -1};\n#line 3 \"math/matrix.hpp\"\ntemplate <class T> struct\
    \ Matrix {\n    vector<vector<T>> A;\n    size_t height, width;\n    Matrix()\
    \ {}\n    Matrix(size_t n, size_t m)\n        : A(vector(n, vector<T>(m, 0))),\
    \ height(n), width(m) {}\n    Matrix(size_t n) : Matrix(n, n) {}\n    Matrix(vector<vector<T>>\
    \ A_)\n        : A(A_), height(A_.size()), width(A_[0].size()) {}\n    inline\
    \ const vector<T> &operator[](size_t k) const { return A.at(k); };\n    inline\
    \ vector<T> &operator[](size_t k) { return A.at(k); };\n    void show() {\n  \
    \      rep(i, height) {\n            rep(j, width) {\n                if constexpr(is_arithmetic<T>::value)\
    \ {\n                    cout << A[i][j] << \" \\n\"[j + 1 == width];\n      \
    \          } else {\n                    // atcoder::modint\u7528\n          \
    \          cout << A[i][j].val() << \" \\n\"[j + 1 == width];\n              \
    \  }\n            }\n        }\n    }\n\n    Matrix &operator+=(const Matrix &B)\
    \ {\n        assert(height == B.height && width == B.width);\n        rep(i, height)\
    \ {\n            rep(j, width) { A[i][j] += B[i][j]; }\n        }\n        return\
    \ *this;\n    }\n    Matrix &operator-=(const Matrix &B) {\n        assert(height\
    \ == B.height && width == B.width);\n        rep(i, height) {\n            rep(j,\
    \ width) { A[i][j] -= B[i][j]; }\n        }\n        return *this;\n    }\n  \
    \  Matrix &operator*=(const Matrix &B) {\n        assert(width == B.height);\n\
    \        // (height,width)*(B.height,B.width) -> (height,B.width)\n        Matrix<T>\
    \ res(height, B.width);\n        rep(i, height) {\n            rep(j, width) {\n\
    \                rep(k, B.width) { res[i][k] += A[i][j] * B[j][k]; }\n       \
    \     }\n        }\n        swap(*this, res);\n        return *this;\n    }\n\
    \    Matrix &operator^=(size_t k) {\n        assert(height == width);\n      \
    \  Matrix<T> res(height);\n        rep(i, height) res[i][i] = 1;\n        while(k)\
    \ {\n            if(k & 1) {\n                res *= (*this);\n            }\n\
    \            (*this) *= (*this);\n            k >>= 1;\n        }\n        swap(res,\
    \ *this);\n        return *this;\n    }\n    Matrix pow(size_t k) {\n        auto\
    \ res(*this);\n        res ^= k;\n        return res;\n    }\n    Matrix operator+(const\
    \ Matrix &B) { return Matrix(*this) += B; }\n    Matrix operator-(const Matrix\
    \ &B) { return Matrix(*this) -= B; }\n    Matrix operator*(const Matrix &B) {\
    \ return Matrix(*this) *= B; }\n};\n"
  code: "#pragma once\n#include \"template.hpp\"\ntemplate <class T> struct Matrix\
    \ {\n    vector<vector<T>> A;\n    size_t height, width;\n    Matrix() {}\n  \
    \  Matrix(size_t n, size_t m)\n        : A(vector(n, vector<T>(m, 0))), height(n),\
    \ width(m) {}\n    Matrix(size_t n) : Matrix(n, n) {}\n    Matrix(vector<vector<T>>\
    \ A_)\n        : A(A_), height(A_.size()), width(A_[0].size()) {}\n    inline\
    \ const vector<T> &operator[](size_t k) const { return A.at(k); };\n    inline\
    \ vector<T> &operator[](size_t k) { return A.at(k); };\n    void show() {\n  \
    \      rep(i, height) {\n            rep(j, width) {\n                if constexpr(is_arithmetic<T>::value)\
    \ {\n                    cout << A[i][j] << \" \\n\"[j + 1 == width];\n      \
    \          } else {\n                    // atcoder::modint\u7528\n          \
    \          cout << A[i][j].val() << \" \\n\"[j + 1 == width];\n              \
    \  }\n            }\n        }\n    }\n\n    Matrix &operator+=(const Matrix &B)\
    \ {\n        assert(height == B.height && width == B.width);\n        rep(i, height)\
    \ {\n            rep(j, width) { A[i][j] += B[i][j]; }\n        }\n        return\
    \ *this;\n    }\n    Matrix &operator-=(const Matrix &B) {\n        assert(height\
    \ == B.height && width == B.width);\n        rep(i, height) {\n            rep(j,\
    \ width) { A[i][j] -= B[i][j]; }\n        }\n        return *this;\n    }\n  \
    \  Matrix &operator*=(const Matrix &B) {\n        assert(width == B.height);\n\
    \        // (height,width)*(B.height,B.width) -> (height,B.width)\n        Matrix<T>\
    \ res(height, B.width);\n        rep(i, height) {\n            rep(j, width) {\n\
    \                rep(k, B.width) { res[i][k] += A[i][j] * B[j][k]; }\n       \
    \     }\n        }\n        swap(*this, res);\n        return *this;\n    }\n\
    \    Matrix &operator^=(size_t k) {\n        assert(height == width);\n      \
    \  Matrix<T> res(height);\n        rep(i, height) res[i][i] = 1;\n        while(k)\
    \ {\n            if(k & 1) {\n                res *= (*this);\n            }\n\
    \            (*this) *= (*this);\n            k >>= 1;\n        }\n        swap(res,\
    \ *this);\n        return *this;\n    }\n    Matrix pow(size_t k) {\n        auto\
    \ res(*this);\n        res ^= k;\n        return res;\n    }\n    Matrix operator+(const\
    \ Matrix &B) { return Matrix(*this) += B; }\n    Matrix operator-(const Matrix\
    \ &B) { return Matrix(*this) -= B; }\n    Matrix operator*(const Matrix &B) {\
    \ return Matrix(*this) *= B; }\n};\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: math/matrix.hpp
  requiredBy: []
  timestamp: '2025-03-18 18:04:39+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library_checker/linear_algebra/matrix_product.test.cpp
  - test/library_checker/linear_algebra/pow_of_matrix.test.cpp
  - test/yukicoder/3006.test.cpp
documentation_of: math/matrix.hpp
layout: document
redirect_from:
- /library/math/matrix.hpp
- /library/math/matrix.hpp.html
title: math/matrix.hpp
---
