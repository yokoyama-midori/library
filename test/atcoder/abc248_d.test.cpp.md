---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/hash-map-variable-length.hpp
    title: data_structure/hash-map-variable-length.hpp
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
    PROBLEM: https://atcoder.jp/contests/abc248/tasks/abc248_d
    links:
    - https://atcoder.jp/contests/abc248/editorial/3819
    - https://atcoder.jp/contests/abc248/tasks/abc248_d
  bundledCode: "#line 1 \"test/atcoder/abc248_d.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc248/tasks/abc248_d\"\
    \n#line 2 \"template.hpp\"\n// #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"\
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
    vl dx = {1, -1, 0, 0};\nvl dy = {0, 0, 1, -1};\n#line 3 \"data_structure/hash-map-variable-length.hpp\"\
    \ntemplate <class Val> struct HashMap {\n    int sz, mask, cnt;\n    vector<bool>\
    \ used;\n    vector<ll> keys;\n    vector<Val> vals;\n    HashMap(int n = 1) {\n\
    \        sz = 1;\n        while(sz < 2 * n) {\n            sz <<= 1;\n       \
    \ }\n        mask = sz - 1;\n        cnt = 0;\n        keys.resize(sz);\n    \
    \    vals.resize(sz);\n        used.resize(sz);\n    }\n\n    Val &operator[](const\
    \ ll &key) {\n        if(cnt * 2 >= sz) {\n            reallocate();\n       \
    \ }\n        ll i = index(key);\n        if(!used[i]) {\n            used[i] =\
    \ true;\n            keys[i] = key;\n            cnt++;\n        }\n        return\
    \ vals[i];\n    }\n    bool contains(const ll &key) {\n        ll i = index(key);\n\
    \        return used[i];\n    }\n    // for(auto [key,val]:mp.enumerate()){}\n\
    \    // \u307F\u305F\u3044\u306B\u66F8\u3044\u305F\u3068\u304D\u306Bval\u3092\u5909\
    \u66F4\u3057\u305F\u3044\u304C\u3053\u306E\u66F8\u304D\u65B9\u3067\u3044\u3044\
    ?\n    vector<pair<ll, Val &>> enumerate() {\n        vector<pair<ll, Val &>>\
    \ res;\n        rep(i, sz) {\n            if(used[i]) {\n                res.push_back({keys[i],\
    \ vals[i]});\n            }\n        }\n        return res;\n    }\n  private:\n\
    \    int hash(ll x) {\n        // https://judge.yosupo.jp/submission/186759\n\
    \        static const ll r =\n            std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \        x += r;\n        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n        x\
    \ = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n        return (x ^ (x >> 31)) & mask;\n\
    \    }\n    int index(const ll &key) {\n        ll i = hash(key);\n        while(used[i]\
    \ and keys[i] != key) {\n            i = (i + 1) & mask;\n        }\n        return\
    \ i;\n    }\n    void reallocate() {\n        ll old_sz = sz;\n        sz <<=\
    \ 1;\n        mask = sz - 1;\n        cnt = 0;\n\n        vector<ll> old_keys;\n\
    \        vector<Val> old_vals;\n        vector<bool> old_used;\n        keys.swap(old_keys);\n\
    \        vals.swap(old_vals);\n        used.swap(old_used);\n        keys.resize(sz);\n\
    \        vals.resize(sz);\n        used.resize(sz);\n\n        rep(i, old_sz)\
    \ {\n            if(old_used[i]) {\n                ll key = old_keys[i];\n  \
    \              Val val = old_vals[i];\n                (*this)[key] = val;\n \
    \           }\n        }\n        return;\n    }\n};\n#line 3 \"test/atcoder/abc248_d.test.cpp\"\
    \n// segtree \u6539\u9020\n// https://atcoder.jp/contests/abc248/editorial/3819\n\
    template <class S, S (*op)(S, S), S (*e)()> struct segtree {\n    ll n;\n    vector<S>\
    \ v;\n    segtree(ll n_) : segtree(vector<S>(n_, e())) {}\n    segtree(const vector<S>\
    \ &v_) : n(v_.size()) {\n        v = vector<S>(2 * n, e());\n        rep(i, n)\
    \ v[n + i] = v_[i];\n        for(ll i = n - 1; i >= 0; i--) {\n            v[i]\
    \ = op(v[i << 1], v[i << 1 | 1]);\n        }\n    }\n    void set(ll x, S p) {\n\
    \        assert(0 <= x && x < n);\n        x += n;\n        v[x] = p;\n      \
    \  while(x > 1) {\n            x >>= 1;\n            v[x] = op(v[x << 1], v[x\
    \ << 1 | 1]);\n        }\n    }\n    ll prod(ll l, ll r, ll x) {\n        assert(0\
    \ <= l && l <= r && r <= n);\n        ll pl(0), pr(0);\n        l += n, r += n;\n\
    \        while(l < r) {\n            if(l & 1) {\n                if(v[l].contains(x))\n\
    \                    pl += v[l][x];\n            }\n            if(r & 1) {\n\
    \                if(v[r - 1].contains(x))\n                    pr += v[r - 1][x];\n\
    \            }\n            l = (l + 1) >> 1;\n            r >>= 1;\n        }\n\
    \        return pl + pr;\n    }\n    S get(ll x) { return v[n + x]; }\n};\nusing\
    \ S = HashMap<ll>;\nS op(S s, S t) {\n    if(t.sz > s.sz)\n        swap(s, t);\n\
    \    for(auto [key, val] : t.enumerate()) {\n        s[key] += val;\n    }\n \
    \   return s;\n};\nS e() { return S(); }\n\nvoid solve() {\n    LL(n);\n    Graph\
    \ g(n);\n    vector<S> mp(n);\n    rep(i, n) {\n        LL(a);\n        mp[i][--a]\
    \ = 1;\n    }\n    segtree<S, op, e> seg(mp);\n    LL(q);\n    rep(_, q) {\n \
    \       LL(l, r, x);\n        l--, x--;\n        ll ans = seg.prod(l, r, x);\n\
    \        print(ans);\n    }\n}\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    solve();\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc248/tasks/abc248_d\"\n#include\
    \ \"data_structure/hash-map-variable-length.hpp\"\n// segtree \u6539\u9020\n//\
    \ https://atcoder.jp/contests/abc248/editorial/3819\ntemplate <class S, S (*op)(S,\
    \ S), S (*e)()> struct segtree {\n    ll n;\n    vector<S> v;\n    segtree(ll\
    \ n_) : segtree(vector<S>(n_, e())) {}\n    segtree(const vector<S> &v_) : n(v_.size())\
    \ {\n        v = vector<S>(2 * n, e());\n        rep(i, n) v[n + i] = v_[i];\n\
    \        for(ll i = n - 1; i >= 0; i--) {\n            v[i] = op(v[i << 1], v[i\
    \ << 1 | 1]);\n        }\n    }\n    void set(ll x, S p) {\n        assert(0 <=\
    \ x && x < n);\n        x += n;\n        v[x] = p;\n        while(x > 1) {\n \
    \           x >>= 1;\n            v[x] = op(v[x << 1], v[x << 1 | 1]);\n     \
    \   }\n    }\n    ll prod(ll l, ll r, ll x) {\n        assert(0 <= l && l <= r\
    \ && r <= n);\n        ll pl(0), pr(0);\n        l += n, r += n;\n        while(l\
    \ < r) {\n            if(l & 1) {\n                if(v[l].contains(x))\n    \
    \                pl += v[l][x];\n            }\n            if(r & 1) {\n    \
    \            if(v[r - 1].contains(x))\n                    pr += v[r - 1][x];\n\
    \            }\n            l = (l + 1) >> 1;\n            r >>= 1;\n        }\n\
    \        return pl + pr;\n    }\n    S get(ll x) { return v[n + x]; }\n};\nusing\
    \ S = HashMap<ll>;\nS op(S s, S t) {\n    if(t.sz > s.sz)\n        swap(s, t);\n\
    \    for(auto [key, val] : t.enumerate()) {\n        s[key] += val;\n    }\n \
    \   return s;\n};\nS e() { return S(); }\n\nvoid solve() {\n    LL(n);\n    Graph\
    \ g(n);\n    vector<S> mp(n);\n    rep(i, n) {\n        LL(a);\n        mp[i][--a]\
    \ = 1;\n    }\n    segtree<S, op, e> seg(mp);\n    LL(q);\n    rep(_, q) {\n \
    \       LL(l, r, x);\n        l--, x--;\n        ll ans = seg.prod(l, r, x);\n\
    \        print(ans);\n    }\n}\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    solve();\n}"
  dependsOn:
  - data_structure/hash-map-variable-length.hpp
  - template.hpp
  isVerificationFile: true
  path: test/atcoder/abc248_d.test.cpp
  requiredBy: []
  timestamp: '2024-11-14 16:49:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc248_d.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc248_d.test.cpp
- /verify/test/atcoder/abc248_d.test.cpp.html
title: test/atcoder/abc248_d.test.cpp
---
