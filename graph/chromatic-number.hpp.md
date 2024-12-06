---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://ei1333.github.io/library/graph/others/chromatic-number.hpp
    - https://kokiymgch.hatenablog.com/entry/2018/01/27/235959
    - https://nyaannyaan.github.io/library/graph/chromatic-number.hpp
    - https://www.slideshare.net/wata_orz/ss-12131479
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: /home/y_midori/cp/library/template.hpp:\
    \ line -1: no such header\n"
  code: "#include \"/home/y_midori/cp/library/template.hpp\"\n// https://kokiymgch.hatenablog.com/entry/2018/01/27/235959\n\
    // https://www.slideshare.net/wata_orz/ss-12131479\n// TODO \u2193\u3000hist\u8FBA\
    \u308A\u3067\u4F55\u3084\u3063\u3066\u308B\u304B\u7406\u89E3\u3059\u308B\n// https://nyaannyaan.github.io/library/graph/chromatic-number.hpp\n\
    // https://ei1333.github.io/library/graph/others/chromatic-number.hpp\n#include\
    \ <atcoder/modint>\ntemplate <class T> int ChromaticNumber(vector<vector<T>> &g)\
    \ {\n    using mint = atcoder::modint;\n    // g \u96A3\u63A5\u884C\u5217\n  \
    \  ll n = g.size();\n    vl adj(n, 0);\n    rep(i, n) {\n        adj[i] |= 1LL\
    \ << i;\n        for(ll j = i + 1; j < n; j++)\n            if(g[i][j]) {\n  \
    \              adj[j] |= 1LL << i;\n                adj[i] |= 1LL << j;\n    \
    \        }\n    }\n    vl ind_cnt(1LL << n, 0);\n    // ind_cnt[s] = s\u306E\u90E8\
    \u5206\u96C6\u5408\u3067\u3042\u3063\u3066\u3001\u72EC\u7ACB\u306A\u3082\u306E\
    \u306E\u6570\n    ind_cnt[0] = 1;\n    for(ll s = 1; s < (1LL << n); s++) {\n\
    \        ll i = __builtin_ctz(s);\n        // s\u306E\u4E0B\u304B\u3089i\u6841\
    \u76EE\u304C(\u521D\u3081\u3066)1\n        ll j = s & (s - 1);\n        // j =\
    \ s ^ (1LL << i)\n        ind_cnt[s] = ind_cnt[j] + ind_cnt[j & (~adj[i])];\n\
    \        // ind_cnt[s] = ind_cnt[j](i\u3092\u4F7F\u308F\u306A\u3044) + ind_cnt[..](i\u3092\
    \u4F7F\u3046)\n        // i\u3092\u4F7F\u3046\u5834\u5408i\u3068\u96A3\u63A5\u3057\
    \u305F\u9802\u70B9\u306F\u4F7F\u3048\u306A\u3044\u306E\u3067 .. = j & (~adj[i])\n\
    \    }\n    ll res = n;\n    vector<int> ps = {1000000007, 1000000009};\n    for(auto\
    \ &p : ps) {\n        mint::set_mod(p);\n        rep(k, n) {\n            mint\
    \ cc = 0;\n            ll s = (1LL << n) - 1;\n            for(ll t = s;; t =\
    \ (t - 1) & s) {\n                ll sign = n - __popcount(t);\n             \
    \   cc += ((sign & 1) ? -1 : 1) * mint(ind_cnt[t]).pow(k);\n                if(t\
    \ == 0)\n                    break;\n            }\n            if(cc.val()) {\n\
    \                chmin(res, k);\n                break;\n            }\n     \
    \   }\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/chromatic-number.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/chromatic-number.hpp
layout: document
redirect_from:
- /library/graph/chromatic-number.hpp
- /library/graph/chromatic-number.hpp.html
title: graph/chromatic-number.hpp
---
