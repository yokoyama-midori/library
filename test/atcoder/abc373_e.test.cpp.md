---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: dp/cumulative-sum.hpp
    title: dp/cumulative-sum.hpp
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
    PROBLEM: https://atcoder.jp/contests/abc373/tasks/abc373_e
    links:
    - https://atcoder.jp/contests/abc373/tasks/abc373_e
  bundledCode: "#line 1 \"test/atcoder/abc373_e.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc373/tasks/abc373_e\"\
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
    vl dx = {1, -1, 0, 0};\nvl dy = {0, 0, 1, -1};\n#line 3 \"dp/cumulative-sum.hpp\"\
    \n// https://ei1333.github.io/library/dp/cumulative-sum.hpp\ntemplate <class T\
    \ = long long> struct CumulativeSum {\n    bool is_built = false;\n    size_t\
    \ sz;\n    vector<T> data;\n    CumulativeSum(size_t maxi) : sz(maxi + 1), data(maxi\
    \ + 1, 0) {}\n    CumulativeSum(const vector<T> &v) : sz(v.size() + 1) {\n   \
    \     data = {T(0)};\n        data.reserve(sz);\n        for(auto &&x : v) {\n\
    \            data.push_back(data.back() + x);\n        }\n        is_built = true;\n\
    \    }\n    void add(size_t x, T dx) {\n        assert(0 <= x and x < sz);\n \
    \       data[x + 1] += dx;\n        is_built = false;\n    }\n    void build()\
    \ {\n        if(is_built)\n            return;\n        is_built = true;\n   \
    \     rep(i, sz - 1) { data[i + 1] += data[i]; }\n    }\n    T sum(ll r) {\n \
    \       // \u533A\u9593[0,r)\u306E\u548C\n        assert(0 <= r and r < sz);\n\
    \        assert(is_built);\n        return data[r];\n    }\n    T sum(ll l, ll\
    \ r) {\n        // \u533A\u9593[l,r)\u306E\u548C\n        assert(is_built);\n\
    \        assert(0 <= l and l <= r and r < sz);\n        return sum(r) - sum(l);\n\
    \    }\n    T all_sum() {\n        assert(is_built);\n        return data.back();\n\
    \    }\n    const T operator[](size_t t) {\n        // \"\u7D2F\u7A4D\u548C\u3092\
    \u3068\u308B\u524D\u306E\" t \u3067\u306E\u5024\n        assert(0 <= t and t <\
    \ sz);\n        assert(is_built);\n        return data[t + 1] - data[t];\n   \
    \ }\n};\n#line 4 \"test/atcoder/abc373_e.test.cpp\"\nvoid solve() {\n    LL(n,\
    \ m, k);\n    vl a(n), ord(n);\n    iota(all(ord), 0);\n    input(a);\n    sort(all(ord),\
    \ [&a](ll i, ll j) { return a[i] < a[j]; });\n    CumulativeSum<ll> cs(n);\n \
    \   rep(i, n) { cs.add(i, a[ord[i]]); }\n    sort(all(a));\n    cs.build();\n\
    \    auto check = [&](ll i, ll plus) {\n        if(n == m)\n            return\
    \ true;\n        ll x = cs[i] + plus;\n        ll cnt = upper_bound(all(a), x)\
    \ - begin(a);\n        // x+1 \u4EE5\u4E0A\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\
    \u30B9\n        if(n - cnt >= m) {\n            return false;\n        }\n   \
    \     if(i >= n - m) {\n            ll ness = cs.sum(0, n - m - 1) + (x + 1) *\
    \ (cnt - (n - m - 1)) +\n                      cs.sum(cnt, n);\n            ness--;\n\
    \            return ness > k;\n        } else {\n            ll ness = cs.sum(0,\
    \ n - m) + (x + 1) * (cnt - (n - m)) +\n                      cs.sum(cnt, n) +\
    \ plus;\n            return ness > k;\n        }\n    };\n    vl ans(n);\n   \
    \ rep(i, n) {\n        if(!check(i, k - cs.all_sum())) {\n            ans[ord[i]]\
    \ = -1;\n            continue;\n        }\n        ll ok = k - cs.all_sum(), ng\
    \ = -1;\n        while(ok > ng + 1) {\n            ll mid = (ok + ng) / 2;\n \
    \           if(check(i, mid)) {\n                ok = mid;\n            } else\n\
    \                ng = mid;\n        }\n        ans[ord[i]] = ok;\n    }\n    print(ans);\n\
    }\nint main() {\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    solve();\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc373/tasks/abc373_e\"\n#include\
    \ \"dp/cumulative-sum.hpp\"\n#include \"template.hpp\"\nvoid solve() {\n    LL(n,\
    \ m, k);\n    vl a(n), ord(n);\n    iota(all(ord), 0);\n    input(a);\n    sort(all(ord),\
    \ [&a](ll i, ll j) { return a[i] < a[j]; });\n    CumulativeSum<ll> cs(n);\n \
    \   rep(i, n) { cs.add(i, a[ord[i]]); }\n    sort(all(a));\n    cs.build();\n\
    \    auto check = [&](ll i, ll plus) {\n        if(n == m)\n            return\
    \ true;\n        ll x = cs[i] + plus;\n        ll cnt = upper_bound(all(a), x)\
    \ - begin(a);\n        // x+1 \u4EE5\u4E0A\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\
    \u30B9\n        if(n - cnt >= m) {\n            return false;\n        }\n   \
    \     if(i >= n - m) {\n            ll ness = cs.sum(0, n - m - 1) + (x + 1) *\
    \ (cnt - (n - m - 1)) +\n                      cs.sum(cnt, n);\n            ness--;\n\
    \            return ness > k;\n        } else {\n            ll ness = cs.sum(0,\
    \ n - m) + (x + 1) * (cnt - (n - m)) +\n                      cs.sum(cnt, n) +\
    \ plus;\n            return ness > k;\n        }\n    };\n    vl ans(n);\n   \
    \ rep(i, n) {\n        if(!check(i, k - cs.all_sum())) {\n            ans[ord[i]]\
    \ = -1;\n            continue;\n        }\n        ll ok = k - cs.all_sum(), ng\
    \ = -1;\n        while(ok > ng + 1) {\n            ll mid = (ok + ng) / 2;\n \
    \           if(check(i, mid)) {\n                ok = mid;\n            } else\n\
    \                ng = mid;\n        }\n        ans[ord[i]] = ok;\n    }\n    print(ans);\n\
    }\nint main() {\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    solve();\n}"
  dependsOn:
  - dp/cumulative-sum.hpp
  - template.hpp
  isVerificationFile: true
  path: test/atcoder/abc373_e.test.cpp
  requiredBy: []
  timestamp: '2024-12-18 14:40:24+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc373_e.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc373_e.test.cpp
- /verify/test/atcoder/abc373_e.test.cpp.html
title: test/atcoder/abc373_e.test.cpp
---
