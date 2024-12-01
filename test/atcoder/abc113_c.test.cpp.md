---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/compress.hpp
    title: data_structure/compress.hpp
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
    PROBLEM: https://atcoder.jp/contests/abc113/tasks/abc113_c
    links:
    - https://atcoder.jp/contests/abc113/tasks/abc113_c
  bundledCode: "#line 1 \"test/atcoder/abc113_c.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc113/tasks/abc113_c\"\
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
    vl dx = {1, -1, 0, 0};\nvl dy = {0, 0, 1, -1};\n#line 3 \"data_structure/compress.hpp\"\
    \n// https://ei1333.github.io/library/other/compress.hpp\ntemplate <class T> struct\
    \ Compress {\n    bool is_built = false;\n    vector<T> data;\n    Compress()\
    \ = default;\n    Compress(const vector<T> &v) {\n        add(v);\n    }\n   \
    \ void add(const T &x) {\n        is_built = false;\n        data.push_back(x);\n\
    \    }\n    void add(const vector<T> &v) {\n        for(auto x : v)\n        \
    \    add(x);\n    }\n    void build() {\n        is_built = true;\n        sort(data.begin(),\
    \ data.end());\n        data.erase(unique(data.begin(), data.end()), data.end());\n\
    \    }\n    ll get(const T &x) const {\n        assert(is_built);\n        ll\
    \ res = lower_bound(data.begin(), data.end(), x) - data.begin();\n        assert(data[res]\
    \ == x);\n        return res;\n    }\n    const T &operator[](size_t t) {\n  \
    \      assert(is_built);\n        assert(0 <= t and t < ssize(data));\n      \
    \  data[t];\n    }\n    ll size() {\n        return ssize(data);\n    }\n};\n\
    #line 3 \"test/atcoder/abc113_c.test.cpp\"\nstring make_str(ll n) {\n    string\
    \ suf = to_string(n);\n    string res;\n    rep(i, 6 - ssize(suf)) { res += '0';\
    \ }\n    res += suf;\n    return res;\n}\nvoid solve() {\n    LL(n, m);\n    vector<Compress<int>>\
    \ vc(n + 1);\n    vector<int> p(m), y(m);\n    rep(i, m) {\n        cin >> p[i]\
    \ >> y[i];\n        vc[p[i]].add(y[i]);\n    }\n    rep(i, n + 1) { vc[i].build();\
    \ }\n    rep(i, m) {\n        string ans = make_str(p[i]);\n        ans += make_str(vc[p[i]].get(y[i])\
    \ + 1);\n        cout << ans << \"\\n\";\n    }\n}\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    solve();\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc113/tasks/abc113_c\"\n#include\
    \ \"data_structure/compress.hpp\"\nstring make_str(ll n) {\n    string suf = to_string(n);\n\
    \    string res;\n    rep(i, 6 - ssize(suf)) { res += '0'; }\n    res += suf;\n\
    \    return res;\n}\nvoid solve() {\n    LL(n, m);\n    vector<Compress<int>>\
    \ vc(n + 1);\n    vector<int> p(m), y(m);\n    rep(i, m) {\n        cin >> p[i]\
    \ >> y[i];\n        vc[p[i]].add(y[i]);\n    }\n    rep(i, n + 1) { vc[i].build();\
    \ }\n    rep(i, m) {\n        string ans = make_str(p[i]);\n        ans += make_str(vc[p[i]].get(y[i])\
    \ + 1);\n        cout << ans << \"\\n\";\n    }\n}\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    solve();\n}\n"
  dependsOn:
  - data_structure/compress.hpp
  - template.hpp
  isVerificationFile: true
  path: test/atcoder/abc113_c.test.cpp
  requiredBy: []
  timestamp: '2024-12-02 00:25:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc113_c.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc113_c.test.cpp
- /verify/test/atcoder/abc113_c.test.cpp.html
title: test/atcoder/abc113_c.test.cpp
---