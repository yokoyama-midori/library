---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: poly/bostan_mori.hpp
    title: poly/bostan_mori.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
    links:
    - https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
  bundledCode: "#line 1 \"test/library_checker/other/kth_term_of_linearly_recurrent_sequence.test.cpp\"\
    \n#define PROBLEM                                                            \
    \    \\\n    \"https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence\"\
    \n#line 2 \"template.hpp\"\n// #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"\
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
    \ dy = {0, 0, 1, -1};\n#line 3 \"poly/bostan_mori.hpp\"\n#include <atcoder/convolution>\n\
    #include <atcoder/modint>\ntemplate <class T> T bostanMori(vector<T> p, vector<T>\
    \ q, ll n) {\n    // return [x^n]P(x)/Q(x)\n    using namespace atcoder;\n   \
    \ assert(p.size() < q.size());\n    int k = ssize(q) - 1;\n    if(p.size() < k\
    \ - 1)\n        p.resize(k);\n    while(n) {\n        auto q_minus(q);\n     \
    \   for(int i = 1; i < k + 1; i += 2) {\n            q_minus[i] *= -1;\n     \
    \   }\n        if(T::mod() == 998244353) {\n            p = convolution(p, q_minus);\n\
    \            q = convolution(q, q_minus);\n        } else {\n            p = convolution_naive(p,\
    \ q_minus);\n            q = convolution_naive(q, q_minus);\n        }\n     \
    \   int n1 = n & 1;\n        rep(i, k) p[i] = p[2 * i + n1];\n        rep(i, k\
    \ + 1) q[i] = q[2 * i];\n        p.resize(k);\n        q.resize(k + 1);\n    \
    \    n >>= 1;\n    }\n    return p[0] / q[0];\n}\n#line 4 \"test/library_checker/other/kth_term_of_linearly_recurrent_sequence.test.cpp\"\
    \nusing namespace atcoder;\nusing mint = modint998244353;\nvoid solve() {\n  \
    \  LL(d, k);\n    vector<mint> a(d);\n    vector<mint> q(d + 1);\n    rep(i, d)\
    \ {\n        LL(ai);\n        a[i] = ai;\n    }\n    q[0] = 1;\n    rep1(i, d)\
    \ {\n        LL(qi);\n        q[i] = -qi;\n    }\n    auto p = convolution(a,\
    \ q);\n    p.resize(d);\n    print(bostanMori(p, q, k).val());\n}\nint main()\
    \ {\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n    solve();\n\
    }\n"
  code: "#define PROBLEM                                                         \
    \       \\\n    \"https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence\"\
    \n#include \"poly/bostan_mori.hpp\"\nusing namespace atcoder;\nusing mint = modint998244353;\n\
    void solve() {\n    LL(d, k);\n    vector<mint> a(d);\n    vector<mint> q(d +\
    \ 1);\n    rep(i, d) {\n        LL(ai);\n        a[i] = ai;\n    }\n    q[0] =\
    \ 1;\n    rep1(i, d) {\n        LL(qi);\n        q[i] = -qi;\n    }\n    auto\
    \ p = convolution(a, q);\n    p.resize(d);\n    print(bostanMori(p, q, k).val());\n\
    }\nint main() {\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    solve();\n}\n"
  dependsOn:
  - poly/bostan_mori.hpp
  - template.hpp
  isVerificationFile: true
  path: test/library_checker/other/kth_term_of_linearly_recurrent_sequence.test.cpp
  requiredBy: []
  timestamp: '2025-03-17 22:06:24+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/other/kth_term_of_linearly_recurrent_sequence.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/other/kth_term_of_linearly_recurrent_sequence.test.cpp
- /verify/test/library_checker/other/kth_term_of_linearly_recurrent_sequence.test.cpp.html
title: test/library_checker/other/kth_term_of_linearly_recurrent_sequence.test.cpp
---
