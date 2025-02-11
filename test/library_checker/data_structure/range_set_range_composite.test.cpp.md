---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: data_structure/lazy_segtree.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_set_range_composite\"\
    \n#include \"data_structure/lazy_segtree.hpp\"\n#include \"template.hpp\"\n#include\
    \ <atcoder/modint>\nusing mint = atcoder::modint998244353;\nstruct S {\n    mint\
    \ b, c;\n    ll sz;\n};\nS e() { return S(1, 0, 0); };\nS op(S g, S f) { return\
    \ S(f.b * g.b, f.b * g.c + f.c, g.sz + f.sz); }\nstruct F {\n    bool used;\n\
    \    mint b, c;\n};\nS mapping(F f, S s) {\n    if(!f.used)\n        return s;\n\
    \    S res(e());\n    S ff(f.b, f.c);\n    ll sz = s.sz;\n    while(sz) {\n  \
    \      if(sz & 1) {\n            res = op(res, ff);\n        }\n        ff = op(ff,\
    \ ff);\n        sz >>= 1;\n    }\n    res.sz = s.sz;\n    return S(res);\n}\n\
    F composition(F f, F g) {\n    if(!f.used)\n        return g;\n    return f;\n\
    }\nF id() { return F(false, 0, 0); }\n\nvoid solve() {\n    LL(n, q);\n    lazy_segtree<S,\
    \ op, e, F, mapping, composition, id> seg(n);\n    rep(i, n) {\n        LL(b,\
    \ c);\n        seg.set(i, S(b, c, 1));\n    }\n    rep(_, q) {\n        LL(flag,\
    \ l, r);\n        if(flag == 0) {\n            LL(b, c);\n            seg.apply(l,\
    \ r, F(true, b, c));\n        } else {\n            LL(x);\n            S p =\
    \ seg.prod(l, r);\n            mint ans = p.b * x + p.c;\n            print(ans.val());\n\
    \        }\n    }\n}\nint main() {\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    solve();\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/data_structure/range_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/data_structure/range_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/range_set_range_composite.test.cpp
- /verify/test/library_checker/data_structure/range_set_range_composite.test.cpp.html
title: test/library_checker/data_structure/range_set_range_composite.test.cpp
---
