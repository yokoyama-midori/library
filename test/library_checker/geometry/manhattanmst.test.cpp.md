---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/manhattan-mst.hpp
    title: geometry/manhattan-mst.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/manhattanmst
    links:
    - https://judge.yosupo.jp/problem/manhattanmst
  bundledCode: "#line 1 \"test/library_checker/geometry/manhattanmst.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/manhattanmst\"\n#line 2 \"template.hpp\"\
    \n// #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"O3\")\n// #pragma\
    \ GCC optimize(\"unroll-loops\")\n#include <bits/stdc++.h>\nusing namespace std;\n\
    template <class T>\nconcept Streamable = requires(ostream os, T &x) { os << x;\
    \ };\ntemplate <class mint>\nconcept is_modint = requires(mint &x) {\n    { x.val()\
    \ } -> std::convertible_to<int>;\n};\n#ifdef LOCAL\n#include <debug.hpp>\n#else\n\
    #define debug(...) 42\n#endif\n\ntemplate <Streamable T> void print_one(const\
    \ T &value) { cout << value; }\ntemplate <is_modint T> void print_one(const T\
    \ &value) { cout << value.val(); }\nvoid print() { cout << '\\n'; }\ntemplate\
    \ <class T, class... Ts> void print(const T &a, const Ts &...b) {\n    print_one(a);\n\
    \    ((cout << ' ', print_one(b)), ...);\n    cout << '\\n';\n}\ntemplate <ranges::range\
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
    \    }\n    sort(all(res));\n    return res;\n}\n#line 3 \"test/library_checker/geometry/manhattanmst.test.cpp\"\
    \n#include <atcoder/dsu>\nvoid solve() {\n    LL(n);\n    vl xs(n), ys(n);\n \
    \   rep(i, n) cin >> xs[i] >> ys[i];\n    const auto &dxy = manhattan_mst(xs,\
    \ ys);\n    atcoder::dsu g(n);\n    ll w = 0;\n    vector<P> edge;\n    edge.reserve(n\
    \ - 1);\n    for(auto &[d, i, j] : dxy) {\n        if(!g.same(i, j)) {\n     \
    \       g.merge(i, j);\n            w += d;\n            edge.emplace_back(i,\
    \ j);\n        }\n    }\n    print(w);\n    for(auto [i, j] : edge) {\n      \
    \  print(i, j);\n    }\n}\nint main() {\n    ios::sync_with_stdio(false);\n  \
    \  std::cin.tie(nullptr);\n    solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/manhattanmst\"\n#include\
    \ \"geometry/manhattan-mst.hpp\"\n#include <atcoder/dsu>\nvoid solve() {\n   \
    \ LL(n);\n    vl xs(n), ys(n);\n    rep(i, n) cin >> xs[i] >> ys[i];\n    const\
    \ auto &dxy = manhattan_mst(xs, ys);\n    atcoder::dsu g(n);\n    ll w = 0;\n\
    \    vector<P> edge;\n    edge.reserve(n - 1);\n    for(auto &[d, i, j] : dxy)\
    \ {\n        if(!g.same(i, j)) {\n            g.merge(i, j);\n            w +=\
    \ d;\n            edge.emplace_back(i, j);\n        }\n    }\n    print(w);\n\
    \    for(auto [i, j] : edge) {\n        print(i, j);\n    }\n}\nint main() {\n\
    \    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n    solve();\n\
    }\n"
  dependsOn:
  - geometry/manhattan-mst.hpp
  - template.hpp
  isVerificationFile: true
  path: test/library_checker/geometry/manhattanmst.test.cpp
  requiredBy: []
  timestamp: '2025-03-18 18:04:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/geometry/manhattanmst.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/geometry/manhattanmst.test.cpp
- /verify/test/library_checker/geometry/manhattanmst.test.cpp.html
title: test/library_checker/geometry/manhattanmst.test.cpp
---
