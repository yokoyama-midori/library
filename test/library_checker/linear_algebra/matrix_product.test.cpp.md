---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/matrix.hpp
    title: math/matrix.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/matrix_product
    links:
    - https://judge.yosupo.jp/problem/matrix_product
  bundledCode: "#line 1 \"test/library_checker/linear_algebra/matrix_product.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n#line 2\
    \ \"template.hpp\"\n// #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"\
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
    vl dx = {1, -1, 0, 0};\nvl dy = {0, 0, 1, -1};\n#line 3 \"math/matrix.hpp\"\n\
    template <class T> struct Matrix {\n    vector<vector<T>> A;\n    size_t height,\
    \ width;\n    Matrix() {}\n    Matrix(size_t n, size_t m)\n        : A(vector(n,\
    \ vector<T>(m, 0))), height(n), width(m) {}\n    Matrix(size_t n) : Matrix(n,\
    \ n) {}\n    Matrix(vector<vector<T>> A_)\n        : A(A_), height(A_.size()),\
    \ width(A_[0].size()) {}\n    inline const vector<T> &operator[](size_t k) const\
    \ { return A.at(k); };\n    inline vector<T> &operator[](size_t k) { return A.at(k);\
    \ };\n    void show() {\n        rep(i, height) {\n            rep(j, width) {\n\
    \                if constexpr(is_arithmetic<T>::value) {\n                   \
    \ cout << A[i][j] << \" \\n\"[j + 1 == width];\n                } else {\n   \
    \                 // atcoder::modint\u7528\n                    cout << A[i][j].val()\
    \ << \" \\n\"[j + 1 == width];\n                }\n            }\n        }\n\
    \    }\n\n    Matrix &operator+=(const Matrix &B) {\n        assert(height ==\
    \ B.height && width == B.width);\n        rep(i, height) {\n            rep(j,\
    \ width) { A[i][j] += B[i][j]; }\n        }\n        return *this;\n    }\n  \
    \  Matrix &operator-=(const Matrix &B) {\n        assert(height == B.height &&\
    \ width == B.width);\n        rep(i, height) {\n            rep(j, width) { A[i][j]\
    \ -= B[i][j]; }\n        }\n        return *this;\n    }\n    Matrix &operator*=(const\
    \ Matrix &B) {\n        assert(width == B.height);\n        // (height,width)*(B.height,B.width)\
    \ -> (height,B.width)\n        Matrix<T> res(height, B.width);\n        rep(i,\
    \ height) {\n            rep(j, width) {\n                rep(k, B.width) { res[i][k]\
    \ += A[i][j] * B[j][k]; }\n            }\n        }\n        swap(*this, res);\n\
    \        return *this;\n    }\n    Matrix &operator^=(size_t k) {\n        assert(height\
    \ == width);\n        Matrix<T> res(height);\n        rep(i, height) res[i][i]\
    \ = 1;\n        while(k) {\n            if(k & 1) {\n                res *= (*this);\n\
    \            }\n            (*this) *= (*this);\n            k >>= 1;\n      \
    \  }\n        swap(res, *this);\n        return *this;\n    }\n    Matrix pow(size_t\
    \ k) {\n        auto res(*this);\n        res ^= k;\n        return res;\n   \
    \ }\n    Matrix operator+(const Matrix &B) { return Matrix(*this) += B; }\n  \
    \  Matrix operator-(const Matrix &B) { return Matrix(*this) -= B; }\n    Matrix\
    \ operator*(const Matrix &B) { return Matrix(*this) *= B; }\n};\n#line 4 \"test/library_checker/linear_algebra/matrix_product.test.cpp\"\
    \n#include <atcoder/modint>\nusing namespace atcoder;\nusing mint = modint998244353;\n\
    \nvoid solve() {\n    LL(n, m, k);\n    Matrix<mint> a(n, m), b(m, k);\n    rep(i,\
    \ n) rep(j, m) {\n        LL(p);\n        a[i][j] = p;\n    }\n    rep(i, m) rep(j,\
    \ k) {\n        LL(p);\n        b[i][j] = p;\n    }\n    auto c = a * b;\n   \
    \ c.show();\n}\nint main() {\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n#include\
    \ \"math/matrix.hpp\"\n#include \"template.hpp\"\n#include <atcoder/modint>\n\
    using namespace atcoder;\nusing mint = modint998244353;\n\nvoid solve() {\n  \
    \  LL(n, m, k);\n    Matrix<mint> a(n, m), b(m, k);\n    rep(i, n) rep(j, m) {\n\
    \        LL(p);\n        a[i][j] = p;\n    }\n    rep(i, m) rep(j, k) {\n    \
    \    LL(p);\n        b[i][j] = p;\n    }\n    auto c = a * b;\n    c.show();\n\
    }\nint main() {\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    solve();\n}\n"
  dependsOn:
  - math/matrix.hpp
  - template.hpp
  isVerificationFile: true
  path: test/library_checker/linear_algebra/matrix_product.test.cpp
  requiredBy: []
  timestamp: '2025-03-16 14:03:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/linear_algebra/matrix_product.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/linear_algebra/matrix_product.test.cpp
- /verify/test/library_checker/linear_algebra/matrix_product.test.cpp.html
title: test/library_checker/linear_algebra/matrix_product.test.cpp
---
