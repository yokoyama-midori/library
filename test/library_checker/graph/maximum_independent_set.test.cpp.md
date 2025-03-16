---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  - icon: ':heavy_check_mark:'
    path: graph/maximum-independent-set.hpp
    title: "\u6700\u5927\u72EC\u7ACB\u96C6\u5408"
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
    PROBLEM: https://judge.yosupo.jp/problem/maximum_independent_set
    links:
    - https://judge.yosupo.jp/problem/maximum_independent_set
  bundledCode: "#line 1 \"test/library_checker/graph/maximum_independent_set.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/maximum_independent_set\"\n\
    #line 2 \"template.hpp\"\n// #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"\
    O3\")\n// #pragma GCC optimize(\"unroll-loops\")\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n// https://xn--kst.jp/blog/2019/08/29/cpp-comp/\n\ntemplate\
    \ <class Container, typename = void>\nstruct is_container : std::false_type {};\n\
    template <class Container>\nstruct is_container<Container, std::void_t<decltype(std::declval<Container>().begin()),\
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
    vl dx = {1, -1, 0, 0};\nvl dy = {0, 0, 1, -1};\n#line 3 \"graph/graph-template.hpp\"\
    \n// https://ei1333.github.io/library/graph/graph-template.hpp\ntemplate <class\
    \ T = ll> struct Edge {\n    int from, to;\n    T cost;\n    int idx;\n    Edge()\
    \ = default;\n    Edge(int from, int to, T cost = 1, int idx = -1)\n        :\
    \ from(from), to(to), cost(cost), idx(idx) {}\n    Edge &operator=(const int &x)\
    \ {\n        to = x;\n        return *this;\n    }\n    operator int() const {\
    \ return to; }\n};\ntemplate <class T = ll> struct Graph {\n    using cost_type\
    \ = T;\n    vector<vector<Edge<T>>> g;\n    int es; // edge_size\n    Graph(int\
    \ n) : g(n), es(0) {};\n    int size() const { return ssize(g); }\n    void add_directed_edge(int\
    \ from, int to, T cost = 1) {\n        g[from].emplace_back(from, to, cost, es++);\n\
    \    }\n    void add_edge(int from, int to, T cost = 1) {\n        g[from].emplace_back(from,\
    \ to, cost, es);\n        g[to].emplace_back(to, from, cost, es++);\n    }\n \
    \   vector<Edge<T>> &operator[](const int &k) { return g[k]; }\n    const vector<Edge<T>>\
    \ &operator[](const int &k) const { return g[k]; }\n    void read(int m, int padding\
    \ = -1, bool weighted = false,\n              bool directed = false) {\n     \
    \   rep(i, m) {\n            int a, b;\n            T c(1);\n            cin >>\
    \ a >> b;\n            a += padding;\n            b += padding;\n            if(weighted)\n\
    \                cin >> c;\n            if(directed)\n                add_directed_edge(a,\
    \ b, c);\n            else\n                add_edge(a, b, c);\n        }\n  \
    \  }\n};\n#line 3 \"graph/maximum-independent-set.hpp\"\n// https://maspypy.github.io/library/graph/maximum_independent_set.hpp\n\
    // https://yukicoder.me/problems/no/382\n// https://www.slideshare.net/wata_orz/ss-12131479\
    \ \u3088\u308A\u9AD8\u901F\n// n=120 5sec\ntemplate <int n_max, class edge_type>\n\
    vector<int> max_independent_set(int n, const vector<edge_type> &edges) {\n   \
    \ using BS = bitset<n_max>;\n    BS res;\n    auto dfs = [&n, &res](auto &&dfs,\
    \ vector<BS> nbd, BS rem, BS cur) {\n        while(1) {\n            bool upd\
    \ = false;\n            for(int i : views::iota(0, n) | views::filter([&](int\
    \ i) {\n                            return rem[i] and (rem & nbd[i]).count() <=\
    \ 1;\n                        })) {\n                rem[i] = 0;\n           \
    \     cur[i] = 1;\n                upd = true;\n                rem &= ~nbd[i];\n\
    \            }\n            if(!upd)\n                break;\n        }\n    \
    \    if(rem.none()) {\n            if(res.count() < cur.count())\n           \
    \     res = cur;\n            return;\n        }\n        int max_idx = ranges::max(\n\
    \            views::iota(0, n) | views::filter([&](int i) { return rem[i]; }),\n\
    \            {}, [&](int i) { return (rem & nbd[i]).count(); });\n        assert(rem[max_idx]\
    \ and nbd[max_idx].any());\n        rem[max_idx] = 0;\n        // max_idx \u4F7F\
    \u308F\u306A\u3044\n        if(nbd[max_idx].count() > 2) // 2\u4EE5\u4E0B->\u5168\
    \u90E82->\u3069\u308C\u4F7F\u3063\u3066\u3082\u4E00\u7DD2\n            dfs(dfs,\
    \ nbd, rem, cur);\n        // \u4F7F\u3046\n        cur[max_idx] = 1;\n      \
    \  rem &= ~nbd[max_idx];\n        dfs(dfs, nbd, rem, cur);\n    };\n    vector<BS>\
    \ nbd(n);\n    BS rem;\n    for(int i : views::iota(0, n))\n        rem[i] = 1;\n\
    \    for(auto &e : edges) {\n        assert(0 <= min(e, e.from) and max(e, e.from)\
    \ < n);\n        if(e.from == e)\n            rem[e] = 0;\n        nbd[e.from][e]\
    \ = nbd[e][e.from] = 1;\n    }\n    dfs(dfs, nbd, rem, BS(0));\n    vector<int>\
    \ res_v;\n    for(int i :\n        views::iota(0, n) | views::filter([&](int i)\
    \ { return res[i]; }))\n        res_v.emplace_back(i);\n    return res_v;\n}\n\
    #line 3 \"test/library_checker/graph/maximum_independent_set.test.cpp\"\nvoid\
    \ solve() {\n    INT(n, m);\n    using edge_type = Edge<bool>;\n    vector<edge_type>\
    \ edges;\n    rep(i, m) {\n        INT(a, b);\n        edges.emplace_back(a, b);\n\
    \    }\n    auto ans = max_independent_set<40, edge_type>(n, edges);\n    print(ans.size());\n\
    \    print(ans);\n}\nint main() {\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/maximum_independent_set\"\
    \n#include \"graph/maximum-independent-set.hpp\"\nvoid solve() {\n    INT(n, m);\n\
    \    using edge_type = Edge<bool>;\n    vector<edge_type> edges;\n    rep(i, m)\
    \ {\n        INT(a, b);\n        edges.emplace_back(a, b);\n    }\n    auto ans\
    \ = max_independent_set<40, edge_type>(n, edges);\n    print(ans.size());\n  \
    \  print(ans);\n}\nint main() {\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    solve();\n}\n"
  dependsOn:
  - graph/maximum-independent-set.hpp
  - graph/graph-template.hpp
  - template.hpp
  isVerificationFile: true
  path: test/library_checker/graph/maximum_independent_set.test.cpp
  requiredBy: []
  timestamp: '2025-03-16 14:03:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/graph/maximum_independent_set.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/graph/maximum_independent_set.test.cpp
- /verify/test/library_checker/graph/maximum_independent_set.test.cpp.html
title: test/library_checker/graph/maximum_independent_set.test.cpp
---
