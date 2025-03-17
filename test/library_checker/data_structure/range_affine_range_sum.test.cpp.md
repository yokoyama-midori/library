---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/lazy-segtree.hpp
    title: data_structure/lazy-segtree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/library_checker/data_structure/range_affine_range_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\
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
    \ dy = {0, 0, 1, -1};\n#line 3 \"data_structure/lazy-segtree.hpp\"\ntemplate <class\
    \ S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),\n          F (*composition)(F,\
    \ F), F (*id)()>\n//   composition(f,g)(x) = f\u2218g(x) = f(g(x))\n// acl\u3068\
    \u540C\u3058\u3001maspy\u3055\u3093\u8A18\u4E8B\u3068\u9006\nstruct lazy_segtree\
    \ {\n    ll n;\n    vector<S> v;\n    vector<F> vf;\n    lazy_segtree(ll n)\n\
    \        : n(n), v(vector<S>(2 * n, e())), vf(vector<F>(2 * n, id())) {};\n  \
    \  lazy_segtree(vector<S> v_) : n(v_.size()) {\n        vf = vector<F>(2 * n,\
    \ id());\n        v = vector<S>(2 * n, e());\n        rep(i, n) { v[i + n] = v_[i];\
    \ }\n        for(ll i = n - 1; i > 0; i--) {\n            v[i] = op(v[i << 1],\
    \ v[i << 1 | 1]);\n        }\n    }\n    void apply(ll l, ll r, F f) {\n     \
    \   l += n;\n        r += n;\n        ll l0 = l / (l & -l);\n        ll r0 = r\
    \ / (r & -r) - 1;\n        propagate_above(l0);\n        propagate_above(r0);\n\
    \        while(l < r) {\n            if(l & 1) {\n                apply_at(l,\
    \ f);\n                l++;\n            }\n            if(r & 1) {\n        \
    \        r--;\n                apply_at(r, f);\n            }\n            l >>=\
    \ 1;\n            r >>= 1;\n        }\n        recul_above(l0);\n        recul_above(r0);\n\
    \    }\n    S get(ll x) {\n        x += n;\n        ll maxi = bit_length(x) -\
    \ 1;\n        for(ll i = maxi; i > 0; i--) {\n            propagate_at(x >> i);\n\
    \        }\n        return v[x];\n    }\n    void set(ll x, S s) {\n        x\
    \ += n;\n        propagate_above(x);\n        v[x] = s;\n        recul_above(x);\n\
    \    }\n    S prod(ll l, ll r) {\n        l += n;\n        r += n;\n        ll\
    \ l0 = l / (l & -l);\n        ll r0 = r / (r & -r) - 1;\n        propagate_above(l0);\n\
    \        propagate_above(r0);\n        S sl = e(), sr = e();\n        while(l\
    \ < r) {\n            if(l & 1) {\n                sl = op(sl, v[l]);\n      \
    \          l++;\n            }\n            if(r & 1) {\n                r--;\n\
    \                sr = op(v[r], sr);\n            }\n            l >>= 1;\n   \
    \         r >>= 1;\n        }\n        return op(sl, sr);\n    }\n    S all_prod_commute()\
    \ { \n        // \u53EF\u63DB\u306A\u30E2\u30CE\u30A4\u30C9\u5C02\u7528\n    \
    \    // 2\u51AA\u306B\u3059\u308C\u3070\u975E\u53EF\u63DB\u3067\u3082\u826F\u3055\
    \u305D\u3046\n        return v[1]; \n    }\n\n  private:\n    void apply_at(ll\
    \ x, F f) {\n        v[x] = mapping(f, v[x]);\n        if(x < n)\n           \
    \ vf[x] = composition(f, vf[x]);\n    }\n    void propagate_at(ll x) {\n     \
    \   apply_at(x << 1, vf[x]);\n        apply_at(x << 1 | 1, vf[x]);\n        vf[x]\
    \ = id();\n    }\n    ll bit_length(unsigned long long x) const { return 64 -\
    \ countl_zero(x); }\n    void propagate_above(ll x) {\n        ll maxi = bit_length(x)\
    \ - 1;\n        for(ll i = maxi; i > 0; i--) {\n            propagate_at(x >>\
    \ i);\n        }\n        return;\n    }\n    void recul_above(ll x) {\n     \
    \   while(x > 1) {\n            x >>= 1;\n            v[x] = op(v[x << 1], v[x\
    \ << 1 | 1]);\n        }\n    }\n};\n#line 4 \"test/library_checker/data_structure/range_affine_range_sum.test.cpp\"\
    \n#include <atcoder/modint>\nusing mint = atcoder::modint998244353;\nstruct S\
    \ {\n    mint a, sz;\n};\nS e() { return S(0, 0); };\nS op(S a, S b) { return\
    \ S(a.a + b.a, a.sz + b.sz); }\nstruct F {\n    mint b, c;\n};\nS mapping(F f,\
    \ S s) { return S(f.b * s.a + s.sz * f.c, s.sz); }\nF composition(F f, F g) {\
    \ return F(f.b * g.b, f.b * g.c + f.c); }\nF id() { return F(1, 0); }\n\nvoid\
    \ solve() {\n    LL(n, q);\n    lazy_segtree<S, op, e, F, mapping, composition,\
    \ id> seg(n);\n    rep(i, n) {\n        LL(a);\n        seg.set(i, S(a, 1));\n\
    \    }\n    rep(_, q) {\n        LL(flag, l, r);\n        if(flag == 0) {\n  \
    \          LL(b, c);\n            seg.apply(l, r, F(b, c));\n        } else {\n\
    \            print(seg.prod(l, r).a.val());\n        }\n    }\n}\nint main() {\n\
    \    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n    solve();\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#include \"data_structure/lazy-segtree.hpp\"\n#include \"template.hpp\"\n#include\
    \ <atcoder/modint>\nusing mint = atcoder::modint998244353;\nstruct S {\n    mint\
    \ a, sz;\n};\nS e() { return S(0, 0); };\nS op(S a, S b) { return S(a.a + b.a,\
    \ a.sz + b.sz); }\nstruct F {\n    mint b, c;\n};\nS mapping(F f, S s) { return\
    \ S(f.b * s.a + s.sz * f.c, s.sz); }\nF composition(F f, F g) { return F(f.b *\
    \ g.b, f.b * g.c + f.c); }\nF id() { return F(1, 0); }\n\nvoid solve() {\n   \
    \ LL(n, q);\n    lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);\n\
    \    rep(i, n) {\n        LL(a);\n        seg.set(i, S(a, 1));\n    }\n    rep(_,\
    \ q) {\n        LL(flag, l, r);\n        if(flag == 0) {\n            LL(b, c);\n\
    \            seg.apply(l, r, F(b, c));\n        } else {\n            print(seg.prod(l,\
    \ r).a.val());\n        }\n    }\n}\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    solve();\n}\n"
  dependsOn:
  - data_structure/lazy-segtree.hpp
  - template.hpp
  isVerificationFile: true
  path: test/library_checker/data_structure/range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2025-03-17 22:06:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/data_structure/range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/range_affine_range_sum.test.cpp
- /verify/test/library_checker/data_structure/range_affine_range_sum.test.cpp.html
title: test/library_checker/data_structure/range_affine_range_sum.test.cpp
---
