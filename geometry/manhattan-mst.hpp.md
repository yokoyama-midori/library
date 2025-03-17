---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/geometry/manhattanmst.test.cpp
    title: test/library_checker/geometry/manhattanmst.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
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
    \ dy = {0, 0, 1, -1};\n#line 2 \"geometry/manhattan-mst.hpp\"\n// Hai Zhou, Narendra\
    \ Shenoy, and William Nicholls. 2001. Efficient minimum\n// spanning tree construction\
    \ without Delaunay triangulation.\ntemplate <class T = long long>\nvector<tuple<T,\
    \ int, int>> manhattan_mst(vector<T> xs, vector<T> ys) {\n    // O(N)\u500B\u306E\
    \u6700\u5C0F\u5168\u57DF\u6728\u306E\u8FBA\u306E\u5019\u88DC{(\u91CD\u307F,i,j)}\n\
    \    assert(ssize(xs) == ssize(ys));\n    vector<tuple<T, int, int>> res;\n  \
    \  int n = ssize(xs);\n    res.reserve(2 * n);\n    vector<int> ord(n);\n    iota(all(ord),\
    \ 0);\n    auto cul = [&]() -> void {\n        map<T, int, greater<T>> mp;\n \
    \       for(auto i : ord) {\n            for(auto itr = mp.lower_bound(xs[i]);\
    \ itr != end(mp);\n                itr = mp.erase(itr)) {\n                int\
    \ j = itr->second;\n                if(xs[j] - ys[j] < xs[i] - ys[i]) {\n    \
    \                break;\n                }\n                T dist = (ys[i] -\
    \ ys[j]) + (xs[i] - xs[j]);\n                res.emplace_back(dist, i, j);\n \
    \           }\n            mp[xs[i]] = i;\n        }\n    };\n    rep(cnt, 4)\
    \ {\n        if(cnt & 1) {\n            swap(xs, ys);\n        } else {\n    \
    \        if(cnt == 2) {\n                for(auto &&x : xs)\n                \
    \    x *= -1;\n            }\n            sort(all(ord),\n                 [&](int\
    \ i, int j) { return xs[i] + ys[i] < xs[j] + ys[j]; });\n        }\n        cul();\n\
    \    }\n    sort(all(res));\n    return res;\n}\n"
  code: "#include \"template.hpp\"\n// Hai Zhou, Narendra Shenoy, and William Nicholls.\
    \ 2001. Efficient minimum\n// spanning tree construction without Delaunay triangulation.\n\
    template <class T = long long>\nvector<tuple<T, int, int>> manhattan_mst(vector<T>\
    \ xs, vector<T> ys) {\n    // O(N)\u500B\u306E\u6700\u5C0F\u5168\u57DF\u6728\u306E\
    \u8FBA\u306E\u5019\u88DC{(\u91CD\u307F,i,j)}\n    assert(ssize(xs) == ssize(ys));\n\
    \    vector<tuple<T, int, int>> res;\n    int n = ssize(xs);\n    res.reserve(2\
    \ * n);\n    vector<int> ord(n);\n    iota(all(ord), 0);\n    auto cul = [&]()\
    \ -> void {\n        map<T, int, greater<T>> mp;\n        for(auto i : ord) {\n\
    \            for(auto itr = mp.lower_bound(xs[i]); itr != end(mp);\n         \
    \       itr = mp.erase(itr)) {\n                int j = itr->second;\n       \
    \         if(xs[j] - ys[j] < xs[i] - ys[i]) {\n                    break;\n  \
    \              }\n                T dist = (ys[i] - ys[j]) + (xs[i] - xs[j]);\n\
    \                res.emplace_back(dist, i, j);\n            }\n            mp[xs[i]]\
    \ = i;\n        }\n    };\n    rep(cnt, 4) {\n        if(cnt & 1) {\n        \
    \    swap(xs, ys);\n        } else {\n            if(cnt == 2) {\n           \
    \     for(auto &&x : xs)\n                    x *= -1;\n            }\n      \
    \      sort(all(ord),\n                 [&](int i, int j) { return xs[i] + ys[i]\
    \ < xs[j] + ys[j]; });\n        }\n        cul();\n    }\n    sort(all(res));\n\
    \    return res;\n}"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: geometry/manhattan-mst.hpp
  requiredBy: []
  timestamp: '2025-03-17 22:06:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/geometry/manhattanmst.test.cpp
documentation_of: geometry/manhattan-mst.hpp
layout: document
redirect_from:
- /library/geometry/manhattan-mst.hpp
- /library/geometry/manhattan-mst.hpp.html
title: geometry/manhattan-mst.hpp
---
