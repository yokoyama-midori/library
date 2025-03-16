---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/segtree.hpp
    title: data_structure/segtree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"test/library_checker/data_structure/point_set_range_composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#line 2 \"template.hpp\"\n// #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"\
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
    vl dx = {1, -1, 0, 0};\nvl dy = {0, 0, 1, -1};\n#line 3 \"data_structure/segtree.hpp\"\
    \n\ntemplate <class S, auto op, auto e> struct segtree {\n    ll n;\n    vector<S>\
    \ v;\n    segtree(ll n_) : segtree(vector<S>(n_, e())) {}\n    segtree(const vector<S>\
    \ &v_) : n(v_.size()) {\n        v = vector<S>(2 * n, e());\n        rep(i, n)\
    \ v[n + i] = v_[i];\n        for(ll i = n - 1; i >= 0; i--) {\n            v[i]\
    \ = op(v[i << 1], v[i << 1 | 1]);\n        }\n    }\n    void set(ll x, S p) {\n\
    \        assert(0 <= x && x < n);\n        x += n;\n        v[x] = p;\n      \
    \  while(x > 1) {\n            x >>= 1;\n            v[x] = op(v[x << 1], v[x\
    \ << 1 | 1]);\n        }\n    }\n    S prod(ll l, ll r) const {\n        assert(0\
    \ <= l && l <= r && r <= n);\n        S pl(e()), pr(e());\n        l += n, r +=\
    \ n;\n        while(l < r) {\n            if(l & 1) {\n                pl = op(pl,\
    \ v[l]);\n            }\n            if(r & 1) {\n                pr = op(v[r\
    \ - 1], pr);\n            }\n            l = (l + 1) >> 1;\n            r >>=\
    \ 1;\n        }\n        return op(pl, pr);\n    }\n    S get(ll x) const { return\
    \ v[n + x]; }\n};\n#line 4 \"test/library_checker/data_structure/point_set_range_composite.test.cpp\"\
    \n#include <atcoder/modint>\nusing namespace atcoder;\nusing mint = modint998244353;\n\
    \nstruct S {\n    mint a, b;\n};\nS op(S fl,S fr){\n    S res;\n    res.a = fr.a\
    \ * fl.a;\n    res.b = fr.a * fl.b + fr.b;\n    return res;\n}\nS e() { return\
    \ S{1, 0}; }\nvoid solve() {\n    LL(n, q);\n    segtree<S, op, e> seg(n);\n \
    \   rep(i, n) {\n        LL(a, b);\n        seg.set(i, S{a, b});\n    }\n    rep(_,\
    \ q) {\n        LL(flag);\n        if(flag == 0) {\n            LL(p, c, d);\n\
    \            seg.set(p, S{c, d});\n        } else {\n            LL(l, r, x);\n\
    \            S p = seg.prod(l, r);\n            mint ans = p.a * x + p.b;\n  \
    \          print(ans.val());\n        }\n    }\n}\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include \"data_structure/segtree.hpp\"\n#include \"template.hpp\"\n#include\
    \ <atcoder/modint>\nusing namespace atcoder;\nusing mint = modint998244353;\n\n\
    struct S {\n    mint a, b;\n};\nS op(S fl,S fr){\n    S res;\n    res.a = fr.a\
    \ * fl.a;\n    res.b = fr.a * fl.b + fr.b;\n    return res;\n}\nS e() { return\
    \ S{1, 0}; }\nvoid solve() {\n    LL(n, q);\n    segtree<S, op, e> seg(n);\n \
    \   rep(i, n) {\n        LL(a, b);\n        seg.set(i, S{a, b});\n    }\n    rep(_,\
    \ q) {\n        LL(flag);\n        if(flag == 0) {\n            LL(p, c, d);\n\
    \            seg.set(p, S{c, d});\n        } else {\n            LL(l, r, x);\n\
    \            S p = seg.prod(l, r);\n            mint ans = p.a * x + p.b;\n  \
    \          print(ans.val());\n        }\n    }\n}\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    solve();\n}\n"
  dependsOn:
  - data_structure/segtree.hpp
  - template.hpp
  isVerificationFile: true
  path: test/library_checker/data_structure/point_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '2025-03-16 14:03:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/data_structure/point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/point_set_range_composite.test.cpp
- /verify/test/library_checker/data_structure/point_set_range_composite.test.cpp.html
title: test/library_checker/data_structure/point_set_range_composite.test.cpp
---
