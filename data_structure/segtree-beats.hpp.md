---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/range-chminmaxaddsum-segtree-beats.hpp
    title: data_structure/range-chminmaxaddsum-segtree-beats.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/range_chmin_chmax_add_range_sum.test.cpp
    title: test/library_checker/data_structure/range_chmin_chmax_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/880.test.cpp
    title: test/yukicoder/880.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://rsm9.hatenablog.com/entry/2021/02/01/220408
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
    \ dy = {0, 0, 1, -1};\n#line 3 \"data_structure/segtree-beats.hpp\"\n// https://rsm9.hatenablog.com/entry/2021/02/01/220408\n\
    \ntemplate <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),\n \
    \         F (*composition)(F, F), F (*id)()>\n//   composition(f,g)(x) = f\u2218\
    g(x) = f(g(x))\n// acl\u3068\u540C\u3058\u3001maspy\u3055\u3093\u8A18\u4E8B\u3068\
    \u9006\nstruct segtree_beats {\n    vector<S> v;\n    vector<F> vf;\n    ll n;\n\
    \    segtree_beats(ll n)\n        : n(n), v(vector<S>(2 * n, e())), vf(vector<F>(2\
    \ * n, id())) {};\n    segtree_beats(vector<S> v_) : n(v_.size()) {\n        vf\
    \ = vector<F>(2 * n, id());\n        v = vector<S>(2 * n, e());\n        rep(i,\
    \ n) { v[i + n] = v_[i]; }\n        for(ll i = n - 1; i > 0; i--) {\n        \
    \    v[i] = op(v[i << 1], v[i << 1 | 1]);\n        }\n    }\n    void apply(ll\
    \ l, ll r, F f) {\n        l += n;\n        r += n;\n        ll l0 = l / (l &\
    \ -l);\n        ll r0 = r / (r & -r) - 1;\n        propagate_above(l0);\n    \
    \    propagate_above(r0);\n        while(l < r) {\n            if(l & 1) {\n \
    \               apply_at(l, f);\n                l++;\n            }\n       \
    \     if(r & 1) {\n                r--;\n                apply_at(r, f);\n   \
    \         }\n            l >>= 1;\n            r >>= 1;\n        }\n        recul_above(l0);\n\
    \        recul_above(r0);\n    }\n    S get(ll x) {\n        x += n;\n       \
    \ ll maxi = bit_length(x) - 1;\n        for(ll i = maxi; i > 0; i--) {\n     \
    \       propagate_at(x >> i);\n        }\n        return v[x];\n    }\n    void\
    \ set(ll x, S s) {\n        x += n;\n        propagate_above(x);\n        v[x]\
    \ = s;\n        recul_above(x);\n    }\n    S prod(ll l, ll r) {\n        l +=\
    \ n;\n        r += n;\n        ll l0 = l / (l & -l);\n        ll r0 = r / (r &\
    \ -r) - 1;\n        propagate_above(l0);\n        propagate_above(r0);\n     \
    \   S sl = e(), sr = e();\n        while(l < r) {\n            if(l & 1) {\n \
    \               sl = op(sl, v[l]);\n                l++;\n            }\n    \
    \        if(r & 1) {\n                r--;\n                sr = op(v[r], sr);\n\
    \            }\n            l >>= 1;\n            r >>= 1;\n        }\n      \
    \  return op(sl, sr);\n    }\n\n  private:\n    void apply_at(ll x, F f) {\n \
    \       v[x] = mapping(f, v[x]);\n        if(x < n) {\n            vf[x] = composition(f,\
    \ vf[x]);\n            // Added for Segment Tree Beats implementation.\n     \
    \       if(v[x].fail) {\n                propagate_at(x);\n                v[x]\
    \ = op(v[x << 1], v[x << 1 | 1]);\n            }\n        }\n    }\n    void propagate_at(ll\
    \ x) {\n        apply_at(x << 1, vf[x]);\n        apply_at(x << 1 | 1, vf[x]);\n\
    \        vf[x] = id();\n    }\n    ll bit_length(unsigned long long x) { return\
    \ 64 - countl_zero(x); }\n    void propagate_above(ll x) {\n        ll maxi =\
    \ bit_length(x) - 1;\n        for(ll i = maxi; i > 0; i--) {\n            propagate_at(x\
    \ >> i);\n        }\n        return;\n    }\n    void recul_above(ll x) {\n  \
    \      while(x > 1) {\n            x >>= 1;\n            v[x] = op(v[x << 1],\
    \ v[x << 1 | 1]);\n        }\n    }\n};\n"
  code: "#pragma once\n#include \"template.hpp\"\n// https://rsm9.hatenablog.com/entry/2021/02/01/220408\n\
    \ntemplate <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),\n \
    \         F (*composition)(F, F), F (*id)()>\n//   composition(f,g)(x) = f\u2218\
    g(x) = f(g(x))\n// acl\u3068\u540C\u3058\u3001maspy\u3055\u3093\u8A18\u4E8B\u3068\
    \u9006\nstruct segtree_beats {\n    vector<S> v;\n    vector<F> vf;\n    ll n;\n\
    \    segtree_beats(ll n)\n        : n(n), v(vector<S>(2 * n, e())), vf(vector<F>(2\
    \ * n, id())) {};\n    segtree_beats(vector<S> v_) : n(v_.size()) {\n        vf\
    \ = vector<F>(2 * n, id());\n        v = vector<S>(2 * n, e());\n        rep(i,\
    \ n) { v[i + n] = v_[i]; }\n        for(ll i = n - 1; i > 0; i--) {\n        \
    \    v[i] = op(v[i << 1], v[i << 1 | 1]);\n        }\n    }\n    void apply(ll\
    \ l, ll r, F f) {\n        l += n;\n        r += n;\n        ll l0 = l / (l &\
    \ -l);\n        ll r0 = r / (r & -r) - 1;\n        propagate_above(l0);\n    \
    \    propagate_above(r0);\n        while(l < r) {\n            if(l & 1) {\n \
    \               apply_at(l, f);\n                l++;\n            }\n       \
    \     if(r & 1) {\n                r--;\n                apply_at(r, f);\n   \
    \         }\n            l >>= 1;\n            r >>= 1;\n        }\n        recul_above(l0);\n\
    \        recul_above(r0);\n    }\n    S get(ll x) {\n        x += n;\n       \
    \ ll maxi = bit_length(x) - 1;\n        for(ll i = maxi; i > 0; i--) {\n     \
    \       propagate_at(x >> i);\n        }\n        return v[x];\n    }\n    void\
    \ set(ll x, S s) {\n        x += n;\n        propagate_above(x);\n        v[x]\
    \ = s;\n        recul_above(x);\n    }\n    S prod(ll l, ll r) {\n        l +=\
    \ n;\n        r += n;\n        ll l0 = l / (l & -l);\n        ll r0 = r / (r &\
    \ -r) - 1;\n        propagate_above(l0);\n        propagate_above(r0);\n     \
    \   S sl = e(), sr = e();\n        while(l < r) {\n            if(l & 1) {\n \
    \               sl = op(sl, v[l]);\n                l++;\n            }\n    \
    \        if(r & 1) {\n                r--;\n                sr = op(v[r], sr);\n\
    \            }\n            l >>= 1;\n            r >>= 1;\n        }\n      \
    \  return op(sl, sr);\n    }\n\n  private:\n    void apply_at(ll x, F f) {\n \
    \       v[x] = mapping(f, v[x]);\n        if(x < n) {\n            vf[x] = composition(f,\
    \ vf[x]);\n            // Added for Segment Tree Beats implementation.\n     \
    \       if(v[x].fail) {\n                propagate_at(x);\n                v[x]\
    \ = op(v[x << 1], v[x << 1 | 1]);\n            }\n        }\n    }\n    void propagate_at(ll\
    \ x) {\n        apply_at(x << 1, vf[x]);\n        apply_at(x << 1 | 1, vf[x]);\n\
    \        vf[x] = id();\n    }\n    ll bit_length(unsigned long long x) { return\
    \ 64 - countl_zero(x); }\n    void propagate_above(ll x) {\n        ll maxi =\
    \ bit_length(x) - 1;\n        for(ll i = maxi; i > 0; i--) {\n            propagate_at(x\
    \ >> i);\n        }\n        return;\n    }\n    void recul_above(ll x) {\n  \
    \      while(x > 1) {\n            x >>= 1;\n            v[x] = op(v[x << 1],\
    \ v[x << 1 | 1]);\n        }\n    }\n};"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: data_structure/segtree-beats.hpp
  requiredBy:
  - data_structure/range-chminmaxaddsum-segtree-beats.hpp
  timestamp: '2025-03-17 22:06:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/data_structure/range_chmin_chmax_add_range_sum.test.cpp
  - test/yukicoder/880.test.cpp
documentation_of: data_structure/segtree-beats.hpp
layout: document
redirect_from:
- /library/data_structure/segtree-beats.hpp
- /library/data_structure/segtree-beats.hpp.html
title: data_structure/segtree-beats.hpp
---
