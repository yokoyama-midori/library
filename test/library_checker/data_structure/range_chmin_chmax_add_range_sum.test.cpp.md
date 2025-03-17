---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/range-chminmaxaddsum-segtree-beats.hpp
    title: data_structure/range-chminmaxaddsum-segtree-beats.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/segtree-beats.hpp
    title: data_structure/segtree-beats.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
  bundledCode: "#line 1 \"test/library_checker/data_structure/range_chmin_chmax_add_range_sum.test.cpp\"\
    \n#define PROBLEM                                                            \
    \    \\\n    \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
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
    \ v[x << 1 | 1]);\n        }\n    }\n};\n#line 3 \"data_structure/range-chminmaxaddsum-segtree-beats.hpp\"\
    \nnamespace RangeChMinMaxAddSum {\nstruct S {\n    ll min, min2, max, max2;\n\
    \    // min2,max2\u306F2\u756A\u76EE\u306E\u6700\u5C0F\u6700\u5927,\u4F46\u3057\
    \u5024\u304C1\u7A2E\u985E\u306E\u3068\u304D\u306F\u5168\u90E8\u4E00\u81F4\u3055\
    \u305B\u308B\n    // \u5024\u304C2\u7A2E\u985E\u306E\u3068\u304Dmin == max2 and\
    \ max == min2\u3067\u3042\u308Amapping\u306E\u969B\u306F\u6CE8\u610F\u304C\u5FC5\
    \u8981\n    ll sz, szmin, szmax, sum;\n    bool fail;\n    S(ll x, ll sz = 1)\n\
    \        : min(x), min2(x), max(x), max2(x), sum(x * sz), sz(sz), fail(false),\n\
    \          szmin(sz), szmax(sz) {};\n    S()\n        : min(inf), min2(inf), max(-inf),\
    \ max2(-inf), sz(0), szmin(0), szmax(0),\n          sum(0), fail(false) {}\n\n\
    \    bool operator==(const S &other) const {\n        return min == other.min\
    \ and min2 == other.min2 and max == other.max and\n               max2 == other.max2\
    \ and sz == other.sz and\n               szmin == other.szmin and szmax == other.szmax\
    \ and\n               sum == other.sum;\n    }\n};\nS e() {\n    S res(0, 0);\n\
    \    res.min = res.min2 = inf, res.max = res.max2 = -inf;\n    res.fail = false;\n\
    \    return res;\n};\nvoid chmin2(ll &m, ll &m2, ll val) {\n    if(val < m) {\n\
    \        m2 = m, m = val;\n    } else if(m < val and val < m2) {\n        m2 =\
    \ val;\n    }\n}\nll second_lowest(S &a, S &b) {\n    ll m = inf, m2 = inf;\n\
    \    chmin2(m, m2, a.min), chmin2(m, m2, a.min2), chmin2(m, m2, b.min),\n    \
    \    chmin2(m, m2, b.min2);\n    return (m2 == inf ? m : m2);\n}\nll second_heighest(S\
    \ &a, S &b) {\n    ll m = inf, m2 = inf;\n    chmin2(m, m2, -a.max), chmin2(m,\
    \ m2, -a.max2), chmin2(m, m2, -b.max),\n        chmin2(m, m2, -b.max2);\n    return\
    \ (m2 == inf ? -m : -m2);\n}\nS op(S a, S b) {\n    if(a.fail)\n        return\
    \ a;\n    if(b.fail)\n        return b;\n    S res;\n    res.min = min(a.min,\
    \ b.min);\n    res.max = max(a.max, b.max);\n    res.min2 = second_lowest(a, b);\n\
    \    res.max2 = second_heighest(a, b);\n    res.sum = a.sum + b.sum;\n    res.sz\
    \ = a.sz + b.sz;\n    res.szmin = a.szmin * (a.min == res.min) + b.szmin * (b.min\
    \ == res.min);\n    res.szmax = a.szmax * (a.max == res.max) + b.szmax * (b.max\
    \ == res.max);\n    return res;\n}\nstruct F {\n    // min -> max -> add \u306E\
    \u9806\n    ll min, max, add;\n    bool operator==(const F &other) const {\n \
    \       return min == other.min && max == other.max && add == other.add;\n   \
    \ }\n};\nF id() { return F(inf, -inf, 0); }\nS mapping(F f, S s) {\n    if(s.fail\
    \ or f == id())\n        return s;\n    if(s.sz == 1) {\n        ll x = s.min;\n\
    \        chmin(x, f.min);\n        chmax(x, f.max);\n        x += f.add;\n   \
    \     return S(x, s.sz);\n    }\n    // f.min\n    if(f.min > s.max2) {\n    \
    \    // f.min\u3092\u51E6\u7406\u3067\u304D\u308B\n        ll dif = min(0LL, f.min\
    \ - s.max);\n        s.sum += dif * s.szmax;\n        s.max += dif;\n        if(s.min2\
    \ + dif == s.max) {\n            s.min2 = s.max;\n        }\n    } else if(f.min\
    \ <= s.min) {\n        // \u5168\u90E8x\n        ll x = max(f.max, f.min) + f.add;\n\
    \        return S(x, s.sz);\n    } else {\n        s.fail = true;\n        return\
    \ s;\n    }\n    // f.max\n    if(f.max < s.min2) {\n        ll dif = max(0LL,\
    \ f.max - s.min);\n        s.sum += dif * s.szmin;\n        s.min += dif;\n  \
    \      if(s.max2 + dif == s.min) {\n            s.max2 = s.min;\n        }\n \
    \   } else if(f.max >= s.max) {\n        return S(f.max + f.add, s.sz);\n    }\
    \ else {\n        s.fail = true;\n        return s;\n    }\n    s.min += f.add,\
    \ s.min2 += f.add, s.max += f.add, s.max2 += f.add;\n    s.sum += f.add * s.sz;\n\
    \    return s;\n}\nF composition(F f, F g) {\n    F res;\n    if(f == id())\n\
    \        return g;\n    if(g == id())\n        return f;\n    res.min = min(g.min,\
    \ f.min - g.add);\n    res.max = max(g.max, f.max - g.add);\n    if(g.max >= f.min\
    \ - g.add) {\n        res.min = res.max = f.min - g.add;\n    }\n    if(f.max\
    \ - g.add >= g.min) {\n        res.min = res.max = f.max - g.add;\n    }\n   \
    \ res.add = f.add + g.add;\n    return res;\n}\nusing segtree = segtree_beats<S,\
    \ op, e, F, mapping, composition, id>;\n} // namespace RangeChMinMaxAddSum\nusing\
    \ RangeChMinMaxAddSum::F;\nusing RangeChMinMaxAddSum::S;\nusing RangeChMinMaxAddSum::segtree;\n\
    #line 4 \"test/library_checker/data_structure/range_chmin_chmax_add_range_sum.test.cpp\"\
    \nvoid solve() {\n    LL(n, q);\n    vector<S> a(n);\n    rep(i, n) {\n      \
    \  LL(ai);\n        a[i] = S(ai, 1);\n    }\n    segtree seg(a);\n    rep(_, q)\
    \ {\n        LL(flag, l, r);\n        if(flag == 0) {\n            LL(b);\n  \
    \          seg.apply(l, r, F(b, -inf, 0));\n        } else if(flag == 1) {\n \
    \           LL(b);\n            seg.apply(l, r, F(inf, b, 0));\n        } else\
    \ if(flag == 2) {\n            LL(b);\n            seg.apply(l, r, F(inf, -inf,\
    \ b));\n        } else {\n            print(seg.prod(l, r).sum);\n        }\n\
    \    }\n}\nint main() {\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    solve();\n}\n"
  code: "#define PROBLEM                                                         \
    \       \\\n    \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n#include \"data_structure/range-chminmaxaddsum-segtree-beats.hpp\"\nvoid solve()\
    \ {\n    LL(n, q);\n    vector<S> a(n);\n    rep(i, n) {\n        LL(ai);\n  \
    \      a[i] = S(ai, 1);\n    }\n    segtree seg(a);\n    rep(_, q) {\n       \
    \ LL(flag, l, r);\n        if(flag == 0) {\n            LL(b);\n            seg.apply(l,\
    \ r, F(b, -inf, 0));\n        } else if(flag == 1) {\n            LL(b);\n   \
    \         seg.apply(l, r, F(inf, b, 0));\n        } else if(flag == 2) {\n   \
    \         LL(b);\n            seg.apply(l, r, F(inf, -inf, b));\n        } else\
    \ {\n            print(seg.prod(l, r).sum);\n        }\n    }\n}\nint main() {\n\
    \    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n    solve();\n\
    }\n"
  dependsOn:
  - data_structure/range-chminmaxaddsum-segtree-beats.hpp
  - data_structure/segtree-beats.hpp
  - template.hpp
  isVerificationFile: true
  path: test/library_checker/data_structure/range_chmin_chmax_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2025-03-17 22:44:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/data_structure/range_chmin_chmax_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/range_chmin_chmax_add_range_sum.test.cpp
- /verify/test/library_checker/data_structure/range_chmin_chmax_add_range_sum.test.cpp.html
title: test/library_checker/data_structure/range_chmin_chmax_add_range_sum.test.cpp
---
