---
data:
  _extendedDependsOn:
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"aplusb.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n#include <template.hpp>\nvoid solve() {\n    LL(a, b);\n    print(a + b);\n\
    }\nint main() {\n    ll t = 1;\n    rep(_, t) solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include <template.hpp>\n\
    void solve() {\n    LL(a, b);\n    print(a + b);\n}\nint main() {\n    ll t =\
    \ 1;\n    rep(_, t) solve();\n}\n"
  dependsOn:
  - template.hpp
  isVerificationFile: true
  path: aplusb.test.cpp
  requiredBy: []
  timestamp: '2025-03-17 11:03:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: aplusb.test.cpp
layout: document
redirect_from:
- /verify/aplusb.test.cpp
- /verify/aplusb.test.cpp.html
title: aplusb.test.cpp
---
