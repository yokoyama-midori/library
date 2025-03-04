---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/compress.hpp
    title: data_structure/compress.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/lazy-segtree.hpp
    title: data_structure/lazy-segtree.hpp
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/area_of_union_of_rectangles.test.cpp
    title: test/library_checker/data_structure/area_of_union_of_rectangles.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template.hpp\"\n// #pragma GCC target(\"avx2\")\n// #pragma\
    \ GCC optimize(\"O3\")\n// #pragma GCC optimize(\"unroll-loops\")\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n// https://xn--kst.jp/blog/2019/08/29/cpp-comp/\n\
    // debug methods\n// usage: debug(x,y);\n// vector \u51FA\u529B\u3067\u304D\u308B\
    \u3088\u3046\u306B\u4FEE\u6B63\ntemplate <typename T>\nostream& debug_print(ostream&\
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
    #endif\n\nusing ll = long long;\nusing vl = vector<ll>;\nusing vll = vector<vl>;\n\
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
    \    cout << '\\n';\n}\nvoid print(const string &s) {\n    cout << s << '\\n';\n\
    }\ntemplate <class Container, typename = void>\nstruct is_container : std::false_type\
    \ {};\ntemplate <class Container>\nstruct is_container<Container, std::void_t<decltype(std::declval<Container>().begin()),\
    \ decltype(std::declval<Container>().end())>> : std::true_type {};\ntemplate <class\
    \ Container>\ntypename enable_if<is_container<Container>::value>::type print(const\
    \ Container& x) {\n    if (!x.empty()) {\n        auto it = x.begin();\n     \
    \   for (; it != prev(x.end()); ++it) {\n            cout << *it << \" \";\n \
    \       }\n        cout << *it << \"\\n\";  // \u6700\u5F8C\u306E\u8981\u7D20\u3092\
    \u51FA\u529B\u3057\u3066\u6539\u884C\n    }\n}\n#define INT(...)             \
    \                                                  \\\n    int __VA_ARGS__;  \
    \                                                         \\\n    input(__VA_ARGS__)\n\
    #define LL(...)                                                              \
    \  \\\n    long long __VA_ARGS__;                                            \
    \         \\\n    input(__VA_ARGS__)\n#define STR(...)                       \
    \                                        \\\n    string __VA_ARGS__;         \
    \                                               \\\n    input(__VA_ARGS__)\n#define\
    \ REP1(a) for(ll i = 0; i < a; i++)\n#define REP2(i, a) for(ll i = 0; i < a; i++)\n\
    #define REP3(i, a, b) for(ll i = a; i < b; i++)\n#define REP4(i, a, b, c) for(ll\
    \ i = a; i < b; i += c)\n#define overload4(a, b, c, d, e, ...) e\n#define rep(...)\
    \ overload4(__VA_ARGS__, REP4, REP3, REP2, REP1)(__VA_ARGS__)\n\nll inf = 3e18;\n\
    vl dx = {1, -1, 0, 0};\nvl dy = {0, 0, 1, -1};\n#line 3 \"data_structure/compress.hpp\"\
    \n// https://ei1333.github.io/library/other/compress.hpp\ntemplate <class T> struct\
    \ Compress {\n    bool is_built = false;\n    vector<T> data;\n    Compress()\
    \ = default;\n    Compress(const vector<T> &v) {\n        add(v);\n    }\n   \
    \ void add(const T &x) {\n        is_built = false;\n        data.push_back(x);\n\
    \    }\n    void add(const vector<T> &v) {\n        for(auto x : v)\n        \
    \    add(x);\n    }\n    void build() {\n        is_built = true;\n        sort(data.begin(),\
    \ data.end());\n        data.erase(unique(data.begin(), data.end()), data.end());\n\
    \    }\n    ll get(const T &x) const {\n        // x \u4EE5\u4E0A\u3068\u306A\u308B\
    \u6700\u5C0F\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u3092\u8FD4\u3059\n   \
    \     assert(is_built);\n        ll res = lower_bound(data.begin(), data.end(),\
    \ x) - data.begin();\n        return res;\n    }\n    const T &operator[](size_t\
    \ t) {\n        assert(is_built);\n        assert(0 <= t and t < data.size());\n\
    \        return data[t];\n    }\n    ll size() {\n        return ssize(data);\n\
    \    }\n};\n#line 3 \"data_structure/lazy-segtree.hpp\"\ntemplate <class S, S\
    \ (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),\n          F (*composition)(F,\
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
    \ << 1 | 1]);\n        }\n    }\n};\n#line 4 \"data_structure/rectangle-union-area.hpp\"\
    \ntemplate <class T = int, class ans_type = ll> struct RectangleUnionArea {\n\
    \  private:\n    using S = pair<T, T>;\n    static S op(S s, S t) {\n        if(s.first\
    \ == t.first)\n            return S(s.first, s.second + t.second);\n        return\
    \ s.first < t.first ? s : t;\n    }\n    static S e() {\n        return S(numeric_limits<T>::max(),\
    \ 0);\n    }\n    using F = T;\n    static F comp(F f, F g) {\n        return\
    \ f + g;\n    }\n    static S mapping(F f, S s) {\n        s.first += f;\n   \
    \     return s;\n    }\n    static F id() {\n        return 0;\n    }\n    struct\
    \ Rectangle {\n        T l, d, r, u;\n    };\n    vector<Rectangle> rectangles;\n\
    \n  public:\n    void add_rect(T l, T d, T r, T u) {\n        assert(l < r and\
    \ d < u);\n        rectangles.emplace_back(l, d, r, u);\n    }\n    ans_type cul()\
    \ {\n        int n = rectangles.size();\n        if(n == 0)\n            return\
    \ 0;\n        Compress<T> cp;\n        vector<int> ord(2 * n);\n        iota(begin(ord),\
    \ end(ord), -n);\n        // \u4E0B\u304B\u3089\u5E73\u9762\u8D70\u67FB i : d[i]\u3067\
    in, -i-1 : u[i]\u3067out\n        for(auto [l, d, r, u] : rectangles)\n      \
    \      cp.add(l), cp.add(r);\n        cp.build();\n        ranges::sort(ord, [&](int\
    \ i, int j) {\n            T x = i < 0 ? rectangles[-i - 1].u : rectangles[i].d;\n\
    \            T y = j < 0 ? rectangles[-j - 1].u : rectangles[j].d;\n         \
    \   return x < y;\n        });\n        lazy_segtree<S, op, e, F, mapping, comp,\
    \ id> seg(cp.size());\n        ans_type ans = 0;\n        for(int i = 0; i + 1\
    \ < cp.size(); i++) {\n            seg.set(i, S(0, cp[i + 1] - cp[i]));\n    \
    \    }\n        seg.set(cp.size() - 1, S(0, 0));\n        ans_type width = cp[cp.size()\
    \ - 1] - cp[0];\n        for(int i = 0; i < 2 * n - 1; i++) {\n            T x\
    \ = ord[i] < 0 ? rectangles[-ord[i] - 1].u : rectangles[ord[i]].d;\n         \
    \   T y = ord[i + 1] < 0 ? rectangles[-ord[i + 1] - 1].u\n                   \
    \              : rectangles[ord[i + 1]].d;\n            if(ord[i] < 0) {\n   \
    \             auto &rec = rectangles[-ord[i] - 1];\n                seg.apply(cp.get(rec.l),\
    \ cp.get(rec.r), -1);\n            } else {\n                auto &rec = rectangles[ord[i]];\n\
    \                seg.apply(cp.get(rec.l), cp.get(rec.r), 1);\n            }\n\
    \            ans += (y - x) * (width - (seg.all_prod_commute().first == 0\n  \
    \                                         ? seg.all_prod_commute().second\n  \
    \                                         : 0));\n        }\n        return ans;\n\
    \    }\n};\n"
  code: "#pragma once\n#include \"data_structure/compress.hpp\"\n#include \"data_structure/lazy-segtree.hpp\"\
    \ntemplate <class T = int, class ans_type = ll> struct RectangleUnionArea {\n\
    \  private:\n    using S = pair<T, T>;\n    static S op(S s, S t) {\n        if(s.first\
    \ == t.first)\n            return S(s.first, s.second + t.second);\n        return\
    \ s.first < t.first ? s : t;\n    }\n    static S e() {\n        return S(numeric_limits<T>::max(),\
    \ 0);\n    }\n    using F = T;\n    static F comp(F f, F g) {\n        return\
    \ f + g;\n    }\n    static S mapping(F f, S s) {\n        s.first += f;\n   \
    \     return s;\n    }\n    static F id() {\n        return 0;\n    }\n    struct\
    \ Rectangle {\n        T l, d, r, u;\n    };\n    vector<Rectangle> rectangles;\n\
    \n  public:\n    void add_rect(T l, T d, T r, T u) {\n        assert(l < r and\
    \ d < u);\n        rectangles.emplace_back(l, d, r, u);\n    }\n    ans_type cul()\
    \ {\n        int n = rectangles.size();\n        if(n == 0)\n            return\
    \ 0;\n        Compress<T> cp;\n        vector<int> ord(2 * n);\n        iota(begin(ord),\
    \ end(ord), -n);\n        // \u4E0B\u304B\u3089\u5E73\u9762\u8D70\u67FB i : d[i]\u3067\
    in, -i-1 : u[i]\u3067out\n        for(auto [l, d, r, u] : rectangles)\n      \
    \      cp.add(l), cp.add(r);\n        cp.build();\n        ranges::sort(ord, [&](int\
    \ i, int j) {\n            T x = i < 0 ? rectangles[-i - 1].u : rectangles[i].d;\n\
    \            T y = j < 0 ? rectangles[-j - 1].u : rectangles[j].d;\n         \
    \   return x < y;\n        });\n        lazy_segtree<S, op, e, F, mapping, comp,\
    \ id> seg(cp.size());\n        ans_type ans = 0;\n        for(int i = 0; i + 1\
    \ < cp.size(); i++) {\n            seg.set(i, S(0, cp[i + 1] - cp[i]));\n    \
    \    }\n        seg.set(cp.size() - 1, S(0, 0));\n        ans_type width = cp[cp.size()\
    \ - 1] - cp[0];\n        for(int i = 0; i < 2 * n - 1; i++) {\n            T x\
    \ = ord[i] < 0 ? rectangles[-ord[i] - 1].u : rectangles[ord[i]].d;\n         \
    \   T y = ord[i + 1] < 0 ? rectangles[-ord[i + 1] - 1].u\n                   \
    \              : rectangles[ord[i + 1]].d;\n            if(ord[i] < 0) {\n   \
    \             auto &rec = rectangles[-ord[i] - 1];\n                seg.apply(cp.get(rec.l),\
    \ cp.get(rec.r), -1);\n            } else {\n                auto &rec = rectangles[ord[i]];\n\
    \                seg.apply(cp.get(rec.l), cp.get(rec.r), 1);\n            }\n\
    \            ans += (y - x) * (width - (seg.all_prod_commute().first == 0\n  \
    \                                         ? seg.all_prod_commute().second\n  \
    \                                         : 0));\n        }\n        return ans;\n\
    \    }\n};"
  dependsOn:
  - data_structure/compress.hpp
  - template.hpp
  - data_structure/lazy-segtree.hpp
  isVerificationFile: false
  path: data_structure/rectangle-union-area.hpp
  requiredBy: []
  timestamp: '2025-03-02 18:30:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/data_structure/area_of_union_of_rectangles.test.cpp
documentation_of: data_structure/rectangle-union-area.hpp
layout: document
redirect_from:
- /library/data_structure/rectangle-union-area.hpp
- /library/data_structure/rectangle-union-area.hpp.html
title: data_structure/rectangle-union-area.hpp
---
