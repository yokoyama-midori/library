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
    \ dy = {0, 0, 1, -1};\n#line 3 \"data_structure/segtree.hpp\"\n\ntemplate <class\
    \ S, auto op, auto e> struct segtree {\n    int n;\n    vector<S> v;\n    segtree(int\
    \ n_) : segtree(vector<S>(n_, e())) {}\n    segtree(const vector<S> &v_) : n(v_.size())\
    \ {\n        v = vector<S>(2 * n, e());\n        rep(i, n) v[n + i] = v_[i];\n\
    \        for(int i = n - 1; i >= 0; i--) {\n            v[i] = op(v[i << 1], v[i\
    \ << 1 | 1]);\n        }\n    }\n    void set(int x, S p) {\n        assert(0\
    \ <= x && x < n);\n        x += n;\n        v[x] = p;\n        while(x > 1) {\n\
    \            x >>= 1;\n            v[x] = op(v[x << 1], v[x << 1 | 1]);\n    \
    \    }\n    }\n    S prod(int l, int r) const {\n        assert(0 <= l && l <=\
    \ r && r <= n);\n        S pl(e()), pr(e());\n        l += n, r += n;\n      \
    \  while(l < r) {\n            if(l & 1) {\n                pl = op(pl, v[l]);\n\
    \            }\n            if(r & 1) {\n                pr = op(v[r - 1], pr);\n\
    \            }\n            l = (l + 1) >> 1;\n            r >>= 1;\n        }\n\
    \        return op(pl, pr);\n    }\n    S get(int x) const { return v[n + x];\
    \ }\n};\n#line 4 \"test/library_checker/data_structure/point_set_range_composite.test.cpp\"\
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
  timestamp: '2025-03-17 22:44:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/data_structure/point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/point_set_range_composite.test.cpp
- /verify/test/library_checker/data_structure/point_set_range_composite.test.cpp.html
title: test/library_checker/data_structure/point_set_range_composite.test.cpp
---
