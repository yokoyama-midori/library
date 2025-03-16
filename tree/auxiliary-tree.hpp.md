---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/sparse-table.hpp
    title: data_structure/sparse-table.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  - icon: ':x:'
    path: tree/euler-tour.hpp
    title: tree/euler-tour.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://nyaannyaan.github.io/library/tree/auxiliary-tree.hpp
    - https://smijake3.hatenablog.com/entry/2019/09/15/200200#%E3%82%BD%E3%83%BC%E3%83%882%E5%9B%9E%E3%81%AE%E6%96%B9%E6%B3%95
  bundledCode: "#line 2 \"template.hpp\"\n// #pragma GCC target(\"avx2\")\n// #pragma\
    \ GCC optimize(\"O3\")\n// #pragma GCC optimize(\"unroll-loops\")\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n// https://xn--kst.jp/blog/2019/08/29/cpp-comp/\n\
    \ntemplate <class Container, typename = void>\nstruct is_container : std::false_type\
    \ {};\ntemplate <class Container>\nstruct is_container<Container, std::void_t<decltype(std::declval<Container>().begin()),\
    \ decltype(std::declval<Container>().end())>> : std::true_type {};\n\ntemplate\
    \ <typename Container>\nenable_if_t<is_container<Container>::value, ostream&>\
    \ \ndebug_print(ostream& os, const Container& container) {\n    os << \"[\";\n\
    \    auto it = container.begin();\n    for (; it != container.end(); ++it) {\n\
    \        if (it != container.begin()) os << \", \";\n        os << *it;\n    }\n\
    \    os << \"]\";\n    return os;\n}\ntemplate <typename T>\nenable_if_t<!is_container<T>::value,\
    \ ostream&> \ndebug_print(ostream& os, const T& var) {\n    os << var;\n    return\
    \ os;\n}\n#define CHOOSE(a) CHOOSE2 a\n#define CHOOSE2(a0, a1, a2, a3, a4, x,\
    \ ...) x\n#define debug_1(x1) { cout << #x1 << \": \"; debug_print(cout, x1) <<\
    \ endl; }\n#define debug_2(x1, x2) { cout << #x1 << \": \"; debug_print(cout,\
    \ x1) << \", \" << #x2 << \": \"; debug_print(cout, x2) << endl; }\n#define debug_3(x1,\
    \ x2, x3) { cout << #x1 << \": \"; debug_print(cout, x1) << \", \" << #x2 << \"\
    : \"; debug_print(cout, x2) << \", \" << #x3 << \": \"; debug_print(cout, x3)\
    \ << endl; }\n#define debug_4(x1, x2, x3, x4) { cout << #x1 << \": \"; debug_print(cout,\
    \ x1) << \", \" << #x2 << \": \"; debug_print(cout, x2) << \", \" << #x3 << \"\
    : \"; debug_print(cout, x3) << \", \" << #x4 << \": \"; debug_print(cout, x4)\
    \ << endl; }\n#define debug_5(x1, x2, x3, x4, x5) { cout << #x1 << \": \"; debug_print(cout,\
    \ x1) << \", \" << #x2 << \": \"; debug_print(cout, x2) << \", \" << #x3 << \"\
    : \"; debug_print(cout, x3) << \", \" << #x4 << \": \"; debug_print(cout, x4)\
    \ << \", \" << #x5 << \": \"; debug_print(cout, x5) << endl; }\n\n#ifdef LOCAL\n\
    #define debug(...) CHOOSE((__VA_ARGS__, debug_5, debug_4, debug_3, debug_2, debug_1,\
    \ ~))(__VA_ARGS__)\n#else\n#define debug(...)\n#endif\n\nusing ll = long long;\n\
    using vl = vector<ll>;\nusing vll = vector<vl>;\nusing P = pair<ll, ll>;\n#define\
    \ all(v) v.begin(), v.end()\ntemplate <typename T> inline bool chmax(T &a, T b)\
    \ {\n    return ((a < b) ? (a = b, true) : (false));\n}\ntemplate <typename T>\
    \ inline bool chmin(T &a, T b) {\n    return ((a > b) ? (a = b, true) : (false));\n\
    }\n#define rep1(i, n) for(ll i = 1; i <= ((ll)n); ++i)\n// https://trap.jp/post/1224/\n\
    template <class... T> constexpr auto min(T... a) {\n    return min(initializer_list<common_type_t<T...>>{a...});\n\
    }\ntemplate <class... T> constexpr auto max(T... a) {\n    return max(initializer_list<common_type_t<T...>>{a...});\n\
    }\ntemplate <class... T> void input(T &...a) { (cin >> ... >> a); }\ntemplate\
    \ <class T> void input(vector<T> &a) {\n    for(T &x : a)\n        cin >> x;\n\
    }\nvoid print() { cout << '\\n'; }\ntemplate <class T, class... Ts> void print(const\
    \ T &a, const Ts &...b) {\n    cout << a;\n    (cout << ... << (cout << ' ', b));\n\
    \    cout << '\\n';\n}\nvoid print(const string &s) {\n    cout << s << '\\n';\n\
    }\ntemplate <class Container>\nenable_if_t<is_container<Container>::value> print(const\
    \ Container& container) {\n    auto it = container.begin();\n    for(;it != container.end();\
    \ ++it){\n        if(it != container.begin())\n            cout << \" \";\n  \
    \      cout << *it;\n    }\n    cout << '\\n';\n}\n#define INT(...)          \
    \                                                     \\\n    int __VA_ARGS__;\
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
    vl dx = {1, -1, 0, 0};\nvl dy = {0, 0, 1, -1};\n#line 3 \"data_structure/sparse-table.hpp\"\
    \n/*\n    auto op\u306B\u306F\n    [](int i,int j){return min(i,j);}\u3084(int(*)(int,int))min\n\
    \    \u3092\u6E21\u3059\n    prod \u5358\u4F4D\u5143\u3092\u6E21\u3057\u3066\u3044\
    \u306A\u3044\u306E\u3067 l==r\u306F\u4E0D\u53EF\n*/\ntemplate <class T, auto op>\
    \ struct SparseTable {\n    SparseTable(const vector<T> &vec) {\n        int n\
    \ = vec.size();\n        int b = bit_width(unsigned(n));\n        v.resize(b);\n\
    \        v[0] = vec;\n        rep(i, b - 1) {\n            v[i + 1].resize(n -\
    \ (1 << i));\n            rep(j, ssize(v[i]) - (1 << i)) {\n                v[i\
    \ + 1][j] = op(v[i][j], v[i][j + (1 << i)]);\n            }\n        }\n    }\n\
    \    T prod(int l, int r) const {\n        if(l + 1 == r)\n            return\
    \ v[0][l];\n        int b = bit_width(unsigned(r - l - 1)) - 1;\n        return\
    \ op(v[b][l], v[b][r - (1 << b)]);\n    }\n\n  private:\n    vector<vector<T>>\
    \ v;\n};\n#line 4 \"tree/euler-tour.hpp\"\n// https://maspypy.com/euler-tour-%E3%81%AE%E3%81%8A%E5%8B%89%E5%BC%B7\n\
    // https://nyaannyaan.github.io/library/tree/euler-tour.hpp\n\ntemplate <class\
    \ G> struct EulerTour {\n    int root, id;\n    vector<int> in, out, dep;\n  \
    \  using pii = pair<int, int>; // depth,vartex\n    SparseTable<pii, [](pii a,\
    \ pii b) { return a.first < b.first ? a : b; }>\n        rmq;\n    EulerTour(G\
    \ &g, int root = 0)\n        : root(root), id(0), in(g.size(), -1), out(g.size(),\
    \ -1),\n          dep(g.size(), 0), rmq([&] {\n              vector<pii> vec;\n\
    \              vec.reserve(2 * g.size());\n              dfs(g, root, -1, vec);\n\
    \              return vec;\n          }()) {}\n    int lca(int x, int y) const\
    \ {\n        int ix = in[x], iy = in[y];\n        if(ix > iy)\n            swap(ix,\
    \ iy);\n        return rmq.prod(ix, iy + 1).second;\n    }\n    int dist(int x,\
    \ int y) const {\n        int l = lca(x, y);\n        return dep[x] + dep[y] -\
    \ 2 * dep[l];\n    }\n\n  private:\n    void dfs(G &g, int now, int prev, vector<pii>\
    \ &vec) {\n        vec.push_back({dep[now], now});\n        in[now] = id++;\n\
    \        for(auto nex : g[now]) {\n            if(nex == prev)\n             \
    \   continue;\n            dep[nex] = dep[now] + 1;\n            dfs(g, nex, now,\
    \ vec);\n        }\n        vec.push_back({dep[now] - 1, prev});\n        out[now]\
    \ = id++;\n    }\n};\n#line 3 \"tree/auxiliary-tree.hpp\"\n// https://smijake3.hatenablog.com/entry/2019/09/15/200200#%E3%82%BD%E3%83%BC%E3%83%882%E5%9B%9E%E3%81%AE%E6%96%B9%E6%B3%95\n\
    // https://nyaannyaan.github.io/library/tree/auxiliary-tree.hpp\ntemplate <class\
    \ G> struct AuxiliaryTree {\n    G g;\n    EulerTour<G> et;\n    AuxiliaryTree(G\
    \ &g) : g(g), et(g) {}\n    AuxiliaryTree(G &g, EulerTour<G> &et) : g(g), et(et)\
    \ {}\n\n    // \u9802\u70B9\u96C6\u5408vs\u3092\u53D7\u3051\u53D6\u308A\n    //\
    \ {aux tree,vs:aux tree\u306E\u9802\u70B9\u756A\u53F7->g\u3067\u306E\u9802\u70B9\
    \u756A\u53F7}\u3092\u8FD4\u3059\n    // aux tree : \u89AA->\u5B50\u306E\u307F\u542B\
    \u307E\u308C\u308B\n    // N = size(g),M=size(vs)\u3068\u3057\u3066\n    // \u69CB\
    \u7BC9 O(N log N)\n    // \u30AF\u30A8\u30EA O(M log M)\n    template <class T>\
    \ pair<vector<vector<T>>, vector<T>> get(vector<T> vs) {\n        if(vs.empty())\n\
    \            return {};\n        auto comp = [&](T i, T j) { return et.in[i] <\
    \ et.in[j]; };\n        sort(all(vs), comp);\n        for(int i = 1, sz = vs.size();\
    \ i < sz; i++) {\n            vs.push_back(et.lca(vs[i - 1], vs[i]));\n      \
    \  }\n        sort(all(vs), comp);\n        vs.erase(unique(all(vs)), end(vs));\n\
    \        vector<vector<T>> aux(vs.size());\n        stack<T> st;\n        st.push(0);\n\
    \        rep(i, 1, vs.size()) {\n            while(et.out[vs[st.top()]] < et.in[vs[i]])\
    \ {\n                st.pop();\n            }\n            aux[st.top()].push_back(i);\n\
    \            st.push(i);\n        }\n        return {aux, vs};\n    }\n};\n"
  code: "#pragma once\n#include \"tree/euler-tour.hpp\"\n// https://smijake3.hatenablog.com/entry/2019/09/15/200200#%E3%82%BD%E3%83%BC%E3%83%882%E5%9B%9E%E3%81%AE%E6%96%B9%E6%B3%95\n\
    // https://nyaannyaan.github.io/library/tree/auxiliary-tree.hpp\ntemplate <class\
    \ G> struct AuxiliaryTree {\n    G g;\n    EulerTour<G> et;\n    AuxiliaryTree(G\
    \ &g) : g(g), et(g) {}\n    AuxiliaryTree(G &g, EulerTour<G> &et) : g(g), et(et)\
    \ {}\n\n    // \u9802\u70B9\u96C6\u5408vs\u3092\u53D7\u3051\u53D6\u308A\n    //\
    \ {aux tree,vs:aux tree\u306E\u9802\u70B9\u756A\u53F7->g\u3067\u306E\u9802\u70B9\
    \u756A\u53F7}\u3092\u8FD4\u3059\n    // aux tree : \u89AA->\u5B50\u306E\u307F\u542B\
    \u307E\u308C\u308B\n    // N = size(g),M=size(vs)\u3068\u3057\u3066\n    // \u69CB\
    \u7BC9 O(N log N)\n    // \u30AF\u30A8\u30EA O(M log M)\n    template <class T>\
    \ pair<vector<vector<T>>, vector<T>> get(vector<T> vs) {\n        if(vs.empty())\n\
    \            return {};\n        auto comp = [&](T i, T j) { return et.in[i] <\
    \ et.in[j]; };\n        sort(all(vs), comp);\n        for(int i = 1, sz = vs.size();\
    \ i < sz; i++) {\n            vs.push_back(et.lca(vs[i - 1], vs[i]));\n      \
    \  }\n        sort(all(vs), comp);\n        vs.erase(unique(all(vs)), end(vs));\n\
    \        vector<vector<T>> aux(vs.size());\n        stack<T> st;\n        st.push(0);\n\
    \        rep(i, 1, vs.size()) {\n            while(et.out[vs[st.top()]] < et.in[vs[i]])\
    \ {\n                st.pop();\n            }\n            aux[st.top()].push_back(i);\n\
    \            st.push(i);\n        }\n        return {aux, vs};\n    }\n};\n"
  dependsOn:
  - tree/euler-tour.hpp
  - data_structure/sparse-table.hpp
  - template.hpp
  isVerificationFile: false
  path: tree/auxiliary-tree.hpp
  requiredBy: []
  timestamp: '2025-03-16 14:03:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/auxiliary-tree.hpp
layout: document
title: "\u6307\u5B9A\u3055\u308C\u305F\u9802\u70B9\u305F\u3061\u306E\u6700\u5C0F\u5171\
  \u901A\u7956\u5148\u95A2\u4FC2\u3092\u4FDD\u3063\u3066\u6728\u3092\u5727\u7E2E\u3057\
  \u3066\u3067\u304D\u308B\u88DC\u52A9\u7684\u306A\u6728"
---
## 問題例

- [ABC359 G - Sum of Tree Distance](https://atcoder.jp/contests/abc359/editorial/10259)
- [Preserve Connectivity 競プロ典型 90 問](https://atcoder.jp/contests/typical90/tasks/typical90_ai)

## LINK
- <https://smijake3.hatenablog.com/entry/2019/09/15/200200#%E3%82%BD%E3%83%BC%E3%83%882%E5%9B%9E%E3%81%AE%E6%96%B9%E6%B3%95>
- <https://nyaannyaan.github.io/library/tree/auxiliary-tree.hpp>
- <https://noshi91.github.io/algorithm-encyclopedia/auxiliary-tree>
