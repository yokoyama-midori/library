---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"debug.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    string trim_whitespace(const string &str) {\n    string result = str;\n    erase_if(result,\
    \ [](char c) { return isspace(c); });\n    return result;\n}\n/*\n    Streamable(string\u542B\
    \u3080) -> \u305D\u306E\u307E\u307E\u51FA\u529B\n    - is_modint(.val()->int)\
    \ -> .val()\u3057\u3066\u51FA\u529B\n    \u4EE5\u4E0B\u306E\u3082\u306E\u306F\u9806\
    \u306B\u518D\u5E30\u7684\u306B\u51FA\u529B\u3059\u308B\n    - pair,tuple\n   \
    \ - ranges::begin(),ranges::end()\u304C\u4F7F\u3048\u308B\u578B(vector,deque,set,map,....)\n\
    */\ntemplate <class... Args> void debug_print(const tuple<Args...> &);\ntemplate\
    \ <ranges::range Iterable>\n    requires(!Streamable<Iterable>)\nvoid debug_print(const\
    \ Iterable &);\n\ntemplate <Streamable T> void debug_print(const T &value) { cout\
    \ << value; }\ntemplate <is_modint mint>\n    requires(!Streamable<mint>)\nvoid\
    \ debug_print(const mint &value) {\n    cout << value.val();\n}\ntemplate <class\
    \ F, class S> void debug_print(const pair<F, S> &value) {\n    cout << \"[\";\n\
    \    debug_print(value.first);\n    cout << \", \";\n    debug_print(value.second);\n\
    \    cout << \"]\";\n}\ntemplate <size_t N = 0, class T> void enum_tuple(const\
    \ T &value) {\n    if constexpr(N < tuple_size<T>::value) {\n        const auto\
    \ &x = get<N>(value);\n        debug_print(x);\n        if(N + 1 < tuple_size<T>::value)\
    \ {\n            cout << \", \";\n            enum_tuple<N + 1, T>(value);\n \
    \       }\n    }\n}\ntemplate <class... Args> void debug_print(const tuple<Args...>\
    \ &value) {\n    cout << \"[\";\n    enum_tuple(value);\n    cout << \"]\";\n\
    }\ntemplate <ranges::range Iterable>\n    requires(!Streamable<Iterable>)\nvoid\
    \ debug_print(const Iterable &v) {\n    cout << \"[\";\n    for(auto itr = v.begin();\
    \ itr != v.end(); itr++) {\n        if(itr != v.begin())\n            cout <<\
    \ \", \";\n        debug_print(*itr);\n    }\n    cout << \"]\";\n}\n\ntemplate\
    \ <typename T> void debug_impl(const string &names, const T &value) {\n    string\
    \ name = trim_whitespace(names);\n    cout << name << \": \";\n    debug_print(value);\n\
    \    cout << endl;\n}\n\ntemplate <typename T, typename... Args>\nvoid debug_impl(const\
    \ string &names, const T &head, const Args &...rest) {\n    size_t pos = names.find(',');\n\
    \    string name = trim_whitespace(names.substr(0, pos));\n    cout << name <<\
    \ \": \";\n    debug_print(head);\n    cout << \", \";\n    debug_impl(names.substr(pos\
    \ + 1), rest...);\n}\n#define debug(...) debug_impl(#__VA_ARGS__, __VA_ARGS__)\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\nstring trim_whitespace(const\
    \ string &str) {\n    string result = str;\n    erase_if(result, [](char c) {\
    \ return isspace(c); });\n    return result;\n}\n/*\n    Streamable(string\u542B\
    \u3080) -> \u305D\u306E\u307E\u307E\u51FA\u529B\n    - is_modint(.val()->int)\
    \ -> .val()\u3057\u3066\u51FA\u529B\n    \u4EE5\u4E0B\u306E\u3082\u306E\u306F\u9806\
    \u306B\u518D\u5E30\u7684\u306B\u51FA\u529B\u3059\u308B\n    - pair,tuple\n   \
    \ - ranges::begin(),ranges::end()\u304C\u4F7F\u3048\u308B\u578B(vector,deque,set,map,....)\n\
    */\ntemplate <class... Args> void debug_print(const tuple<Args...> &);\ntemplate\
    \ <ranges::range Iterable>\n    requires(!Streamable<Iterable>)\nvoid debug_print(const\
    \ Iterable &);\n\ntemplate <Streamable T> void debug_print(const T &value) { cout\
    \ << value; }\ntemplate <is_modint mint>\n    requires(!Streamable<mint>)\nvoid\
    \ debug_print(const mint &value) {\n    cout << value.val();\n}\ntemplate <class\
    \ F, class S> void debug_print(const pair<F, S> &value) {\n    cout << \"[\";\n\
    \    debug_print(value.first);\n    cout << \", \";\n    debug_print(value.second);\n\
    \    cout << \"]\";\n}\ntemplate <size_t N = 0, class T> void enum_tuple(const\
    \ T &value) {\n    if constexpr(N < tuple_size<T>::value) {\n        const auto\
    \ &x = get<N>(value);\n        debug_print(x);\n        if(N + 1 < tuple_size<T>::value)\
    \ {\n            cout << \", \";\n            enum_tuple<N + 1, T>(value);\n \
    \       }\n    }\n}\ntemplate <class... Args> void debug_print(const tuple<Args...>\
    \ &value) {\n    cout << \"[\";\n    enum_tuple(value);\n    cout << \"]\";\n\
    }\ntemplate <ranges::range Iterable>\n    requires(!Streamable<Iterable>)\nvoid\
    \ debug_print(const Iterable &v) {\n    cout << \"[\";\n    for(auto itr = v.begin();\
    \ itr != v.end(); itr++) {\n        if(itr != v.begin())\n            cout <<\
    \ \", \";\n        debug_print(*itr);\n    }\n    cout << \"]\";\n}\n\ntemplate\
    \ <typename T> void debug_impl(const string &names, const T &value) {\n    string\
    \ name = trim_whitespace(names);\n    cout << name << \": \";\n    debug_print(value);\n\
    \    cout << endl;\n}\n\ntemplate <typename T, typename... Args>\nvoid debug_impl(const\
    \ string &names, const T &head, const Args &...rest) {\n    size_t pos = names.find(',');\n\
    \    string name = trim_whitespace(names.substr(0, pos));\n    cout << name <<\
    \ \": \";\n    debug_print(head);\n    cout << \", \";\n    debug_impl(names.substr(pos\
    \ + 1), rest...);\n}\n#define debug(...) debug_impl(#__VA_ARGS__, __VA_ARGS__)"
  dependsOn: []
  isVerificationFile: false
  path: debug.hpp
  requiredBy: []
  timestamp: '2025-03-17 22:36:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: debug.hpp
layout: document
redirect_from:
- /library/debug.hpp
- /library/debug.hpp.html
title: debug.hpp
---
