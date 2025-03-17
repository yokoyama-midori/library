---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: string/run-length-encoding.hpp
    title: string/run-length-encoding.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/my-test/run-length-encoding.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 2 \"template.hpp\"\n// #pragma\
    \ GCC target(\"avx2\")\n// #pragma GCC optimize(\"O3\")\n// #pragma GCC optimize(\"\
    unroll-loops\")\n#include <bits/stdc++.h>\nusing namespace std;\ntemplate <class\
    \ T>\nconcept Streamable = requires(ostream os, T &x) { os << x; };\ntemplate\
    \ <class mint>\nconcept is_modint = requires(mint &x) {\n    { x.val() } -> std::convertible_to<int>;\n\
    };\n#ifdef LOCAL\n#include <debug.hpp>\n#else\n#define debug(...) 42\n#endif\n\
    \ntemplate <Streamable T> void print_one(const T &value) { cout << value; }\n\
    template <is_modint T> void print_one(const T &value) { cout << value.val(); }\n\
    void print() { cout << '\\n'; }\ntemplate <class T, class... Ts> void print(const\
    \ T &a, const Ts &...b) {\n    print_one(a);\n    ((cout << ' ', print_one(b)),\
    \ ...);\n    cout << '\\n';\n}\nvoid print(const string &s) { cout << s << '\\\
    n'; }\ntemplate <ranges::range Iterable>\n    requires(!Streamable<Iterable>)\n\
    void print(const Iterable &v) {\n    for(auto it = v.begin(); it != v.end(); ++it)\
    \ {\n        if(it != v.begin())\n            cout << \" \";\n        print_one(*it);\n\
    \    }\n    cout << '\\n';\n}\nusing ll = long long;\nusing vl = vector<ll>;\n\
    using vll = vector<vl>;\nusing P = pair<ll, ll>;\n#define all(v) v.begin(), v.end()\n\
    template <typename T> inline bool chmax(T &a, T b) {\n    return ((a < b) ? (a\
    \ = b, true) : (false));\n}\ntemplate <typename T> inline bool chmin(T &a, T b)\
    \ {\n    return ((a > b) ? (a = b, true) : (false));\n}\n#define rep1(i, n) for(ll\
    \ i = 1; i <= ((ll)n); ++i)\n// https://trap.jp/post/1224/\ntemplate <class...\
    \ T> constexpr auto min(T... a) {\n    return min(initializer_list<common_type_t<T...>>{a...});\n\
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
    \ dy = {0, 0, 1, -1};\n#line 3 \"string/run-length-encoding.hpp\"\ntemplate <class\
    \ S>\nvector<pair<typename S::value_type, ll>> RunLengthEncoding(S &s) {\n   \
    \ using C = S::value_type;\n    vector<pair<C, ll>> res;\n    for(auto &&c : s)\
    \ {\n        if(res.empty() or res.back().first != c) {\n            res.emplace_back(c,\
    \ 0);\n        }\n        res.back().second++;\n    }\n    return res;\n}\n#line\
    \ 4 \"test/my-test/run-length-encoding.test.cpp\"\nvoid test() {\n    {\n    \
    \    string s = \"\";\n        auto res = RunLengthEncoding(s);\n        assert(res.empty());\n\
    \    }\n    {\n        string s = \"aabbCCabc\";\n        using p = pair<char,\
    \ ll>;\n        auto res = RunLengthEncoding(s);\n        vector<p> ans = {{'a',\
    \ 2}, {'b', 2}, {'C', 2},\n                         {'a', 1}, {'b', 1}, {'c',\
    \ 1}};\n        assert(res == ans);\n        s = \"ZZZZZZ\";\n        res = RunLengthEncoding(s);\n\
    \        ans = {{'Z', 6}};\n        assert(res == ans);\n    }\n    {\n      \
    \  vector<int> v = {1, 2, 3, 3, 4};\n        vector<pair<int, ll>> ans = {{1,\
    \ 1}, {2, 1}, {3, 2}, {4, 1}};\n        auto res = RunLengthEncoding(v);\n   \
    \     assert(res == ans);\n    }\n    {\n        vl v = {1, 1, 2, 2, 3, 4, 5,\
    \ 5, 5};\n        vector<pair<ll, ll>> ans = {{1, 2}, {2, 2}, {3, 1}, {4, 1},\
    \ {5, 3}};\n        auto res = RunLengthEncoding(v);\n        assert(res == ans);\n\
    \    }\n}\nvoid solve() {\n    LL(a, b);\n    print(a + b);\n}\nint main() {\n\
    \    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n    test();\n \
    \   solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"string/run-length-encoding.hpp\"\
    \n#include \"template.hpp\"\nvoid test() {\n    {\n        string s = \"\";\n\
    \        auto res = RunLengthEncoding(s);\n        assert(res.empty());\n    }\n\
    \    {\n        string s = \"aabbCCabc\";\n        using p = pair<char, ll>;\n\
    \        auto res = RunLengthEncoding(s);\n        vector<p> ans = {{'a', 2},\
    \ {'b', 2}, {'C', 2},\n                         {'a', 1}, {'b', 1}, {'c', 1}};\n\
    \        assert(res == ans);\n        s = \"ZZZZZZ\";\n        res = RunLengthEncoding(s);\n\
    \        ans = {{'Z', 6}};\n        assert(res == ans);\n    }\n    {\n      \
    \  vector<int> v = {1, 2, 3, 3, 4};\n        vector<pair<int, ll>> ans = {{1,\
    \ 1}, {2, 1}, {3, 2}, {4, 1}};\n        auto res = RunLengthEncoding(v);\n   \
    \     assert(res == ans);\n    }\n    {\n        vl v = {1, 1, 2, 2, 3, 4, 5,\
    \ 5, 5};\n        vector<pair<ll, ll>> ans = {{1, 2}, {2, 2}, {3, 1}, {4, 1},\
    \ {5, 3}};\n        auto res = RunLengthEncoding(v);\n        assert(res == ans);\n\
    \    }\n}\nvoid solve() {\n    LL(a, b);\n    print(a + b);\n}\nint main() {\n\
    \    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n    test();\n \
    \   solve();\n}\n"
  dependsOn:
  - string/run-length-encoding.hpp
  - template.hpp
  isVerificationFile: true
  path: test/my-test/run-length-encoding.test.cpp
  requiredBy: []
  timestamp: '2025-03-17 22:44:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/my-test/run-length-encoding.test.cpp
layout: document
redirect_from:
- /verify/test/my-test/run-length-encoding.test.cpp
- /verify/test/my-test/run-length-encoding.test.cpp.html
title: test/my-test/run-length-encoding.test.cpp
---
