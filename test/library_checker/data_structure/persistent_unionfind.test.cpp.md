---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/union-find-with-undo.hpp
    title: "Undo\u3064\u304DUnion Find"
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
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "#line 1 \"test/library_checker/data_structure/persistent_unionfind.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n#line\
    \ 2 \"template.hpp\"\n// #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"\
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
    vl dx = {1, -1, 0, 0};\nvl dy = {0, 0, 1, -1};\n#line 3 \"data_structure/union-find-with-undo.hpp\"\
    \n// https://nyaannyaan.github.io/library/data-structure/rollback-union-find.hpp.html\n\
    // snapshot/rollback \u3044\u308B\u304B\u306A\uFF1F\nstruct UnionFindWithUndo\
    \ {\n    int n, numComponents;\n    vector<int> p;\n    using T = tuple<int, int,\
    \ int, int>;\n    stack<T> history;\n    UnionFindWithUndo(int n) : n(n), numComponents(n),\
    \ p(n, -1) {}\n    int leader(int x) {\n        while(p[x] >= 0)\n           \
    \ x = p[x];\n        return x;\n    }\n    int merge(int x, int y) {\n       \
    \ x = leader(x), y = leader(y);\n        history.push(T(x, y, p[x], p[y]));\n\
    \        if(x == y)\n            return x;\n        --numComponents;\n       \
    \ if(-p[x] < -p[y])\n            swap(x, y);\n        p[x] += p[y];\n        p[y]\
    \ = x;\n        return x;\n    }\n    void undo(int k = 1) {\n        assert(history.size()\
    \ >= k);\n        while(k--) {\n            auto [x, y, px, py] = history.top();\n\
    \            history.pop();\n            p[x] = px, p[y] = py;\n            if(x\
    \ != y)\n                ++numComponents;\n        }\n    }\n    int size(int\
    \ x) { return -p[leader(x)]; }\n    bool same(int x, int y) { return leader(x)\
    \ == leader(y); }\n};\n#line 3 \"test/library_checker/data_structure/persistent_unionfind.test.cpp\"\
    \nvoid solve() {\n    INT(n, q);\n    UnionFindWithUndo dsu(n);\n    vector ch(q\
    \ + 1, vector<int>());\n    vector<pair<int, int>> mg(q + 1, {0, 0});\n    vector<vector<tuple<int,\
    \ int, int>>> query(q + 1);\n    vector<int> ans(q + 1, -1);\n    rep(i, 1, q\
    \ + 1) {\n        INT(t, k, x, y);\n        ++k;\n        if(!t) {\n         \
    \   ch[k].push_back(i);\n            mg[i] = {x, y};\n        } else {\n     \
    \       query[k].emplace_back(i, x, y);\n        }\n    }\n    auto dfs = [&](auto\
    \ &&dfs, int cur) -> void {\n        dsu.merge(mg[cur].first, mg[cur].second);\n\
    \        for(auto [i, x, y] : query[cur]) {\n            ans[i] = dsu.same(x,\
    \ y);\n        }\n        for(auto nex : ch[cur])\n            dfs(dfs, nex);\n\
    \        dsu.undo();\n        return;\n    };\n    dfs(dfs, 0);\n    for(auto\
    \ ai : ans)\n        if(ai != -1)\n            print(ai);\n}\nint main() {\n \
    \   ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n    solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\
    #include \"data_structure/union-find-with-undo.hpp\"\nvoid solve() {\n    INT(n,\
    \ q);\n    UnionFindWithUndo dsu(n);\n    vector ch(q + 1, vector<int>());\n \
    \   vector<pair<int, int>> mg(q + 1, {0, 0});\n    vector<vector<tuple<int, int,\
    \ int>>> query(q + 1);\n    vector<int> ans(q + 1, -1);\n    rep(i, 1, q + 1)\
    \ {\n        INT(t, k, x, y);\n        ++k;\n        if(!t) {\n            ch[k].push_back(i);\n\
    \            mg[i] = {x, y};\n        } else {\n            query[k].emplace_back(i,\
    \ x, y);\n        }\n    }\n    auto dfs = [&](auto &&dfs, int cur) -> void {\n\
    \        dsu.merge(mg[cur].first, mg[cur].second);\n        for(auto [i, x, y]\
    \ : query[cur]) {\n            ans[i] = dsu.same(x, y);\n        }\n        for(auto\
    \ nex : ch[cur])\n            dfs(dfs, nex);\n        dsu.undo();\n        return;\n\
    \    };\n    dfs(dfs, 0);\n    for(auto ai : ans)\n        if(ai != -1)\n    \
    \        print(ai);\n}\nint main() {\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    solve();\n}\n"
  dependsOn:
  - data_structure/union-find-with-undo.hpp
  - template.hpp
  isVerificationFile: true
  path: test/library_checker/data_structure/persistent_unionfind.test.cpp
  requiredBy: []
  timestamp: '2025-03-16 14:03:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/data_structure/persistent_unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/persistent_unionfind.test.cpp
- /verify/test/library_checker/data_structure/persistent_unionfind.test.cpp.html
title: test/library_checker/data_structure/persistent_unionfind.test.cpp
---
