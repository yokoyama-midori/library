---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/lazy_segtree.hpp
    title: data_structure/lazy_segtree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_point_get
    links:
    - https://github.com/yosupo06/library-checker-problems/issues/778
    - https://judge.yosupo.jp/problem/range_affine_point_get
  bundledCode: "#line 1 \"test/library_checker/data_structure/range_affine_point_get.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\n\
    // \u53CC\u5BFE\u30BB\u30B0\u6728\u3067\u53EF\u80FD\u3001\u3001\u3060\u304C\u3068\
    \u308A\u3042\u3048\u305A\u9045\u5EF6\u30BB\u30B0\u6728\u3067\n// https://github.com/yosupo06/library-checker-problems/issues/778\n\
    #line 2 \"template.hpp\"\n// #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"\
    O3\")\n// #pragma GCC optimize(\"unroll-loops\")\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n// https://xn--kst.jp/blog/2019/08/29/cpp-comp/\n// debug\
    \ methods\n// usage: debug(x,y);\n// vector \u51FA\u529B\u3067\u304D\u308B\u3088\
    \u3046\u306B\u4FEE\u6B63\ntemplate <typename T>\nostream& debug_print(ostream&\
    \ os, const vector<T>& v) {\n    os << \"[\";\n    for (size_t i = 0; i < v.size();\
    \ ++i) {\n        os << v[i];\n        if (i < v.size() - 1) os << \", \";\n \
    \   }\n    os << \"]\";\n    return os;\n}\ntemplate <typename T>\nostream& debug_print(ostream&\
    \ os, const T& var) {\n    os << var;\n    return os;\n}\n#define CHOOSE(a) CHOOSE2\
    \ a\n#define CHOOSE2(a0, a1, a2, a3, a4, x, ...) x\n#define debug_1(x1) { cout\
    \ << #x1 << \": \"; debug_print(cout, x1) << endl; }\n#define debug_2(x1, x2)\
    \ { cout << #x1 << \": \"; debug_print(cout, x1) << \", \" << #x2 << \": \"; debug_print(cout,\
    \ x2) << endl; }\n#define debug_3(x1, x2, x3) { cout << #x1 << \": \"; debug_print(cout,\
    \ x1) << \", \" << #x2 << \": \"; debug_print(cout, x2) << \", \" << #x3 << \"\
    : \"; debug_print(cout, x3) << endl; }\n#define debug_4(x1, x2, x3, x4) { cout\
    \ << #x1 << \": \"; debug_print(cout, x1) << \", \" << #x2 << \": \"; debug_print(cout,\
    \ x2) << \", \" << #x3 << \": \"; debug_print(cout, x3) << \", \" << #x4 << \"\
    : \"; debug_print(cout, x4) << endl; }\n#define debug_5(x1, x2, x3, x4, x5) {\
    \ cout << #x1 << \": \"; debug_print(cout, x1) << \", \" << #x2 << \": \"; debug_print(cout,\
    \ x2) << \", \" << #x3 << \": \"; debug_print(cout, x3) << \", \" << #x4 << \"\
    : \"; debug_print(cout, x4) << \", \" << #x5 << \": \"; debug_print(cout, x5)\
    \ << endl; }\n\n#ifdef LOCAL\n#define debug(...) CHOOSE((__VA_ARGS__, debug_5,\
    \ debug_4, debug_3, debug_2, debug_1, ~))(__VA_ARGS__)\n#else\n#define debug(...)\n\
    #endif\n\nusing ll = long long;\nusing vl = vector<ll>;\nusing Graph = vector<vector<ll>>;\n\
    using P = pair<ll, ll>;\n#define all(v) v.begin(), v.end()\ntemplate <typename\
    \ T> inline bool chmax(T &a, T b) {\n    return ((a < b) ? (a = b, true) : (false));\n\
    }\ntemplate <typename T> inline bool chmin(T &a, T b) {\n    return ((a > b) ?\
    \ (a = b, true) : (false));\n}\n#define rep1(i, n) for(ll i = 1; i <= ((ll)n);\
    \ ++i)\n// https://trap.jp/post/1224/\ntemplate <class... T> constexpr auto min(T...\
    \ a) {\n    return min(initializer_list<common_type_t<T...>>{a...});\n}\ntemplate\
    \ <class... T> constexpr auto max(T... a) {\n    return max(initializer_list<common_type_t<T...>>{a...});\n\
    }\ntemplate <class... T> void input(T &...a) { (cin >> ... >> a); }\ntemplate\
    \ <class T> void input(vector<T> &a) {\n    for(T &x : a)\n        cin >> x;\n\
    }\nvoid print() { cout << '\\n'; }\ntemplate <class T, class... Ts> void print(const\
    \ T &a, const Ts &...b) {\n    cout << a;\n    (cout << ... << (cout << ' ', b));\n\
    \    cout << '\\n';\n}\ntemplate <class Container, typename = void>\nstruct is_container\
    \ : std::false_type {};\ntemplate <class Container>\nstruct is_container<Container,\
    \ std::void_t<decltype(std::declval<Container>().begin()), decltype(std::declval<Container>().end())>>\
    \ : std::true_type {};\ntemplate <class Container>\ntypename enable_if<is_container<Container>::value>::type\
    \ print(const Container& x) {\n    if (!x.empty()) {\n        auto it = x.begin();\n\
    \        for (; it != prev(x.end()); ++it) {\n            cout << *it << \" \"\
    ;\n        }\n        cout << *it << \"\\n\";  // \u6700\u5F8C\u306E\u8981\u7D20\
    \u3092\u51FA\u529B\u3057\u3066\u6539\u884C\n    }\n}\n#define INT(...)       \
    \                                                        \\\n    int __VA_ARGS__;\
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
    vl dx = {1, -1, 0, 0};\nvl dy = {0, 0, 1, -1};\n#line 2 \"data_structure/lazy_segtree.hpp\"\
    \n\ntemplate <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),\n\
    \          F (*composition)(F, F), F (*id)()>\n        //   composition(f,g)(x)\
    \ = f\u2218g(x) = f(g(x))\n        // acl\u3068\u540C\u3058\u3001maspy\u3055\u3093\
    \u8A18\u4E8B\u3068\u9006\nstruct lazy_segtree {\n    vector<S> v;\n    vector<F>\
    \ vf;\n    ll n;\n    lazy_segtree(ll n)\n        : n(n), v(vector<S>(2 * n, e())),\
    \ vf(vector<F>(2 * n, id())) {};\n    lazy_segtree(vector<S> v_) : n(v_.size())\
    \ {\n        vf = vector<F>(2 * n, id());\n        v = vector<S>(2 * n, e());\n\
    \        rep(i, n) { v[i + n] = v_[i]; }\n        for(ll i = n - 1; i > 0; i--)\
    \ {\n            v[i] = op(v[i << 1], v[i << 1 | 1]);\n        }\n    }\n    void\
    \ apply(ll l, ll r, F f) {\n        l += n;\n        r += n;\n        ll l0 =\
    \ l / (l & -l);\n        ll r0 = r / (r & -r) - 1;\n        propagate_above(l0);\n\
    \        propagate_above(r0);\n        while(l < r) {\n            if(l & 1) {\n\
    \                vf[l] = composition(f, vf[l]);\n                l++;\n      \
    \      }\n            if(r & 1) {\n                r--;\n                vf[r]\
    \ = composition(f, vf[r]);\n            }\n            l >>= 1;\n            r\
    \ >>= 1;\n        }\n        recul_above(l0);\n        recul_above(r0);\n    }\n\
    \    S get(ll x) {\n        x += n;\n        ll maxi = bit_length(x) - 1;\n  \
    \      for(ll i = maxi; i > 0; i--) {\n            propagate_at(x >> i);\n   \
    \     }\n        return mapping(vf[x], v[x]);\n    }\n    void set(ll x, S s)\
    \ {\n        x += n;\n        propagate_above(x);\n        v[x] = s;\n       \
    \ vf[x] = id();\n        recul_above(x);\n    }\n    S prod(ll l, ll r) {\n  \
    \      l += n;\n        r += n;\n        ll l0 = l / (l & -l);\n        ll r0\
    \ = r / (r & -r) - 1;\n        propagate_above(l0);\n        propagate_above(r0);\n\
    \        S sl = e(), sr = e();\n        while(l < r) {\n            if(l & 1)\
    \ {\n                sl = op(sl, mapping(vf[l], v[l]));\n                l++;\n\
    \            }\n            if(r & 1) {\n                r--;\n              \
    \  sr = op(mapping(vf[r], v[r]), sr);\n            }\n            l >>= 1;\n \
    \           r >>= 1;\n        }\n        return op(sl, sr);\n    }\n\n  private:\n\
    \    S eval_at(ll x) { return mapping(vf[x], v[x]); }\n    void propagate_at(ll\
    \ x) {\n        v[x] = mapping(vf[x], v[x]);\n        vf[x << 1] = composition(vf[x],\
    \ vf[x << 1]);\n        vf[x << 1 | 1] = composition(vf[x], vf[x << 1 | 1]);\n\
    \        vf[x] = id();\n    }\n    ll bit_length(unsigned long long x) { return\
    \ 64 - countl_zero(x); }\n    void propagate_above(ll x) {\n        ll maxi =\
    \ bit_length(x) - 1;\n        for(ll i = maxi; i > 0; i--) {\n            propagate_at(x\
    \ >> i);\n        }\n        return;\n    }\n    void recul_above(ll x) {\n  \
    \      while(x > 1) {\n            x >>= 1;\n            v[x] = op(eval_at(x <<\
    \ 1), eval_at(x << 1 | 1));\n        }\n    }\n};\n#line 6 \"test/library_checker/data_structure/range_affine_point_get.test.cpp\"\
    \n#include <atcoder/modint>\nusing mint = atcoder::modint998244353;\nstruct S\
    \ {\n    mint a, sz;\n};\nS e() { return S(0, 0); };\nS op(S a, S b) { return\
    \ S(a.a + b.a, a.sz + b.sz); }\nstruct F {\n    mint b, c;\n};\nS mapping(F f,\
    \ S s) { return S(f.b * s.a + s.sz * f.c, s.sz); }\nF composition(F f, F g) {\
    \ return F(f.b * g.b, f.b * g.c + f.c); }\nF id() { return F(1, 0); }\n\nvoid\
    \ solve() {\n    LL(n, q);\n    lazy_segtree<S, op, e, F, mapping, composition,\
    \ id> seg(n);\n    rep(i, n) {\n        LL(a);\n        seg.set(i, S(a, 1));\n\
    \    }\n    rep(_, q) {\n        LL(flag);\n        if(flag == 0) {\n        \
    \    LL(l, r, b, c);\n            seg.apply(l, r, F(b, c));\n        } else {\n\
    \            LL(i);\n            print(seg.get(i).a.val());\n        }\n    }\n\
    }\nint main() {\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\
    \n// \u53CC\u5BFE\u30BB\u30B0\u6728\u3067\u53EF\u80FD\u3001\u3001\u3060\u304C\u3068\
    \u308A\u3042\u3048\u305A\u9045\u5EF6\u30BB\u30B0\u6728\u3067\n// https://github.com/yosupo06/library-checker-problems/issues/778\n\
    #include \"data_structure/lazy_segtree.hpp\"\n#include \"template.hpp\"\n#include\
    \ <atcoder/modint>\nusing mint = atcoder::modint998244353;\nstruct S {\n    mint\
    \ a, sz;\n};\nS e() { return S(0, 0); };\nS op(S a, S b) { return S(a.a + b.a,\
    \ a.sz + b.sz); }\nstruct F {\n    mint b, c;\n};\nS mapping(F f, S s) { return\
    \ S(f.b * s.a + s.sz * f.c, s.sz); }\nF composition(F f, F g) { return F(f.b *\
    \ g.b, f.b * g.c + f.c); }\nF id() { return F(1, 0); }\n\nvoid solve() {\n   \
    \ LL(n, q);\n    lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);\n\
    \    rep(i, n) {\n        LL(a);\n        seg.set(i, S(a, 1));\n    }\n    rep(_,\
    \ q) {\n        LL(flag);\n        if(flag == 0) {\n            LL(l, r, b, c);\n\
    \            seg.apply(l, r, F(b, c));\n        } else {\n            LL(i);\n\
    \            print(seg.get(i).a.val());\n        }\n    }\n}\nint main() {\n \
    \   ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n    solve();\n}\n"
  dependsOn:
  - data_structure/lazy_segtree.hpp
  - template.hpp
  isVerificationFile: true
  path: test/library_checker/data_structure/range_affine_point_get.test.cpp
  requiredBy: []
  timestamp: '2024-10-24 17:39:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/data_structure/range_affine_point_get.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/range_affine_point_get.test.cpp
- /verify/test/library_checker/data_structure/range_affine_point_get.test.cpp.html
title: test/library_checker/data_structure/range_affine_point_get.test.cpp
---
