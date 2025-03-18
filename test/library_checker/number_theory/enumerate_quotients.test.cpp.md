---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: number-theory/enumerate-quotients.hpp
    title: number-theory/enumerate-quotients.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_quotients
    links:
    - https://judge.yosupo.jp/problem/enumerate_quotients
  bundledCode: "#line 1 \"test/library_checker/number_theory/enumerate_quotients.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_quotients\"\n#line\
    \ 2 \"template.hpp\"\n// #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"\
    O3\")\n// #pragma GCC optimize(\"unroll-loops\")\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\ntemplate <class T>\nconcept Streamable = requires(ostream os,\
    \ T &x) { os << x; };\ntemplate <class mint>\nconcept is_modint = requires(mint\
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
    \ dy = {0, 0, 1, -1};\n#line 3 \"number-theory/enumerate-quotients.hpp\"\n// \u5546\
    \u304Cq\u306E\u7BC4\u56F2[l,r)\u3092q\u306E\u6607\u9806\u306B\u8FD4\u3059\ntemplate\
    \ <class T> vector<tuple<T, T, T>> enumerate_quotients(T n) {\n    vector<tuple<T,\
    \ T, T>> res;\n    T q = n;\n    while(q > 0) {\n        T l = n / (q + 1) + 1,\
    \ r = n / q + 1;\n        res.emplace_back(q, l, r);\n        q = n / r;\n   \
    \ }\n    ranges::reverse(res);\n    return res;\n}\n#line 3 \"test/library_checker/number_theory/enumerate_quotients.test.cpp\"\
    \nvoid solve() {\n    LL(n);\n    auto ans = enumerate_quotients<ll>(n);\n   \
    \ print(ans.size());\n    for(int i : views::iota(0, ssize(ans))) {\n        auto\
    \ [q, l, r] = ans[i];\n        cout << q << \" \\n\"[i + 1 == ssize(ans)];\n \
    \       assert(1 <= l and l < r and r <= n + 1);\n        assert(q == (n / l)\
    \ and q == (n / (r - 1)));\n        assert(q != n / r);\n        assert(i + 1\
    \ == ssize(ans) or l == get<2>(ans[i + 1]));\n    }\n}\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    cout << std::setprecision(16);\n    solve();\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_quotients\"\n\
    #include \"number-theory/enumerate-quotients.hpp\"\nvoid solve() {\n    LL(n);\n\
    \    auto ans = enumerate_quotients<ll>(n);\n    print(ans.size());\n    for(int\
    \ i : views::iota(0, ssize(ans))) {\n        auto [q, l, r] = ans[i];\n      \
    \  cout << q << \" \\n\"[i + 1 == ssize(ans)];\n        assert(1 <= l and l <\
    \ r and r <= n + 1);\n        assert(q == (n / l) and q == (n / (r - 1)));\n \
    \       assert(q != n / r);\n        assert(i + 1 == ssize(ans) or l == get<2>(ans[i\
    \ + 1]));\n    }\n}\nint main() {\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    cout << std::setprecision(16);\n    solve();\n}\n"
  dependsOn:
  - number-theory/enumerate-quotients.hpp
  - template.hpp
  isVerificationFile: true
  path: test/library_checker/number_theory/enumerate_quotients.test.cpp
  requiredBy: []
  timestamp: '2025-03-18 18:04:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/number_theory/enumerate_quotients.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/number_theory/enumerate_quotients.test.cpp
- /verify/test/library_checker/number_theory/enumerate_quotients.test.cpp.html
title: test/library_checker/number_theory/enumerate_quotients.test.cpp
---
