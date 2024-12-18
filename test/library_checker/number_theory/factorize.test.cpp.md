---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/miller_rabin.hpp
    title: math/miller_rabin.hpp
  - icon: ':heavy_check_mark:'
    path: math/pollard_rho.hpp
    title: math/pollard_rho.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/factorize
    links:
    - https://judge.yosupo.jp/problem/factorize
  bundledCode: "#line 1 \"test/library_checker/number_theory/factorize.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\n#line 2 \"template.hpp\"\
    \n// #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"O3\")\n// #pragma\
    \ GCC optimize(\"unroll-loops\")\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n// https://xn--kst.jp/blog/2019/08/29/cpp-comp/\n// debug methods\n//\
    \ usage: debug(x,y);\n// vector \u51FA\u529B\u3067\u304D\u308B\u3088\u3046\u306B\
    \u4FEE\u6B63\ntemplate <typename T>\nostream& debug_print(ostream& os, const vector<T>&\
    \ v) {\n    os << \"[\";\n    for (size_t i = 0; i < v.size(); ++i) {\n      \
    \  os << v[i];\n        if (i < v.size() - 1) os << \", \";\n    }\n    os <<\
    \ \"]\";\n    return os;\n}\ntemplate <typename T>\nostream& debug_print(ostream&\
    \ os, const T& var) {\n    os << var;\n    return os;\n}\n#define CHOOSE(a) CHOOSE2\
    \ a\n#define CHOOSE2(a0, a1, a2, a3, a4, x, ...) x\n#define debug_1(x1) { cout\
    \ << #x1 << \": \"; debug_print(cout, x1) << endl; }\n#define debug_2(x1, x2)\
    \ { cout << #x1 << \": \"; debug_print(cout, x1) << \", \" << #x2 << \": \"; debug_print(cout,\
    \ x2) << endl; }\n#define debug_3(x1, x2, x3) { cout << #x1 << \": \"; debug_print(cout,\
    \ x1) << \", \" << #x2 << \": \"; debug_print(cout, x2) << \", \" << #x3 << \"\
    : \"; debug_print(cout, x3) << endl; }\n#define debug_4(x1, x2, x3, x4) { cout\
    \ << #x1 << \": \"; debug_print(cout, x1) << \", \" << #x2 << \": \"; debug_print(cout,\
    \ x2) << \", \" << #x3 << \": \"; debug_print(cout, x3) << \", \" << #x4 << \"\
    : \"; debug_print(cout, x4) << endl; }\n#define debug_5(x1, x2, x3, x4, x5) {\
    \ cout << #x1 << \": \"; debug_print(cout, x1) << \", \" << #x2 << \": \"; debug_print(cout,\
    \ x2) << \", \" << #x3 << \": \"; debug_print(cout, x3) << \", \" << #x4 << \"\
    : \"; debug_print(cout, x4) << \", \" << #x5 << \": \"; debug_print(cout, x5)\
    \ << endl; }\n\n#ifdef LOCAL\n#define debug(...) CHOOSE((__VA_ARGS__, debug_5,\
    \ debug_4, debug_3, debug_2, debug_1, ~))(__VA_ARGS__)\n#else\n#define debug(...)\n\
    #endif\n\nusing ll = long long;\nusing vl = vector<ll>;\nusing Graph = vector<vector<ll>>;\n\
    using P = pair<ll, ll>;\n#define all(v) v.begin(), v.end()\ntemplate <typename\
    \ T> inline bool chmax(T &a, T b) {\n    return ((a < b) ? (a = b, true) : (false));\n\
    }\ntemplate <typename T> inline bool chmin(T &a, T b) {\n    return ((a > b) ?\
    \ (a = b, true) : (false));\n}\n#define rep1(i, n) for(ll i = 1; i <= ((ll)n);\
    \ ++i)\n// https://trap.jp/post/1224/\ntemplate <class... T> constexpr auto min(T...\
    \ a) {\n    return min(initializer_list<common_type_t<T...>>{a...});\n}\ntemplate\
    \ <class... T> constexpr auto max(T... a) {\n    return max(initializer_list<common_type_t<T...>>{a...});\n\
    }\ntemplate <class... T> void input(T &...a) { (cin >> ... >> a); }\ntemplate\
    \ <class T> void input(vector<T> &a) {\n    for(T &x : a)\n        cin >> x;\n\
    }\nvoid print() { cout << '\\n'; }\ntemplate <class T, class... Ts> void print(const\
    \ T &a, const Ts &...b) {\n    cout << a;\n    (cout << ... << (cout << ' ', b));\n\
    \    cout << '\\n';\n}\nvoid print(const string &s) {\n    cout << s << '\\n';\n\
    }\ntemplate <class Container, typename = void>\nstruct is_container : std::false_type\
    \ {};\ntemplate <class Container>\nstruct is_container<Container, std::void_t<decltype(std::declval<Container>().begin()),\
    \ decltype(std::declval<Container>().end())>> : std::true_type {};\ntemplate <class\
    \ Container>\ntypename enable_if<is_container<Container>::value>::type print(const\
    \ Container& x) {\n    if (!x.empty()) {\n        auto it = x.begin();\n     \
    \   for (; it != prev(x.end()); ++it) {\n            cout << *it << \" \";\n \
    \       }\n        cout << *it << \"\\n\";  // \u6700\u5F8C\u306E\u8981\u7D20\u3092\
    \u51FA\u529B\u3057\u3066\u6539\u884C\n    }\n}\n#define INT(...)             \
    \                                                  \\\n    int __VA_ARGS__;  \
    \                                                         \\\n    input(__VA_ARGS__)\n\
    #define LL(...)                                                              \
    \  \\\n    long long __VA_ARGS__;                                            \
    \         \\\n    input(__VA_ARGS__)\n#define STR(...)                       \
    \                                        \\\n    string __VA_ARGS__;         \
    \                                               \\\n    input(__VA_ARGS__)\n#define\
    \ REP1(a) for(ll i = 0; i < a; i++)\n#define REP2(i, a) for(ll i = 0; i < a; i++)\n\
    #define REP3(i, a, b) for(ll i = a; i < b; i++)\n#define REP4(i, a, b, c) for(ll\
    \ i = a; i < b; i += c)\n#define overload4(a, b, c, d, e, ...) e\n#define rep(...)\
    \ overload4(__VA_ARGS__, REP4, REP3, REP2, REP1)(__VA_ARGS__)\n\nll inf = 3e18;\n\
    vl dx = {1, -1, 0, 0};\nvl dy = {0, 0, 1, -1};\n#line 3 \"math/miller_rabin.hpp\"\
    \n// https://drken1215.hatenablog.com/entry/2023/05/23/233000\n// todo \u30E2\u30F3\
    \u30B4\u30E1\u30EA\u4E57\u7B97\nbool is_prime(ll n) {\n    auto pow_mod = [&n](__int128\
    \ a, ll d) {\n        __int128 res = 1;\n        while(d) {\n            if(d\
    \ & 1) {\n                res *= a;\n                if(res >= n)\n          \
    \          res %= n;\n            }\n            a *= a;\n            if(a >=\
    \ n)\n                a %= n;\n            d >>= 1;\n        }\n        return\
    \ res;\n    };\n    if(n == 2 or n == 7 or n == 61) {\n        return true;\n\
    \    }\n    if(n % 2 == 0 or n == 1) {\n        return false;\n    }\n    ll d\
    \ = n - 1;\n    ll s = 0;\n    while(d % 2 == 0) {\n        d >>= 1;\n       \
    \ s++;\n    }\n    auto check = [&](ll a) {\n        ll ad = pow_mod(a, d);\n\
    \        if(ad == 1) {\n            return true;\n        }\n        rep(i, s)\
    \ {\n            if(ad == n - 1) {\n                return true;\n           \
    \ }\n            if(i < s - 1)\n                ad = pow_mod(ad, 2);\n       \
    \ }\n        return false;\n    };\n    if(n < 4759123141) {\n        for(auto\
    \ a : vl{2, 7, 61}) {\n            if(!check(a)) {\n                return false;\n\
    \            }\n        }\n        return true;\n    } else {\n        for(auto\
    \ a : vl{2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {\n            if(n\
    \ == a) {\n                return true;\n            }\n            if(!check(a))\
    \ {\n                return false;\n            }\n        }\n        return true;\n\
    \    }\n}\n#line 3 \"math/pollard_rho.hpp\"\n// https://manabitimes.jp/math/1192\n\
    // https://wacchoz.hatenablog.com/entry/2019/01/05/230128\n// https://nyaannyaan.github.io/library/prime/fast-factorize.hpp\n\
    namespace fast_factorize {\nll pollard_rho(ll n) {\n    // n\u306E\u7D20\u56E0\
    \u6570\u3092\uFF11\u3064\u8FD4\u3059\n    // 1\u306B\u306F1\u3092\u8FD4\u3059\n\
    \    if(n == 1) {\n        return 1;\n    }\n    if(~n & 1) {\n        return\
    \ 2;\n    }\n    if(is_prime(n)) {\n        return n;\n    }\n    ll r = 1;\n\
    \    auto f = [&n, &r](ll m) { return ((__int128)m * m + r) % n; };\n    ll x\
    \ = 1, y = f(x);\n    while(1) {\n        ll g = gcd(n, abs(x - y));\n       \
    \ if(1 < g and g < n) {\n            return pollard_rho(g);\n        } else if(g\
    \ == 1) {\n            x = f(x);\n            y = f(f(y));\n        } else {\n\
    \            r = rand() % (n - 2) + 2;\n            x = 1;\n            y = f(x);\n\
    \        }\n    }\n}\nvl inner_factorize(ll n) {\n    vl res;\n    if(n == 1)\
    \ {\n        return res;\n    }\n    while(n > 1 and !is_prime(n)) {\n       \
    \ ll p = pollard_rho(n);\n        while(n % p == 0) {\n            res.push_back(p);\n\
    \            n /= p;\n        }\n    }\n    if(n > 1) {\n        res.push_back(n);\n\
    \    }\n    return res;\n}\nvl factorize(ll n) {\n    auto res = inner_factorize(n);\n\
    \    sort(all(res));\n    return res;\n}\nmap<ll, ll> factor_count(ll n) {\n \
    \   auto res = inner_factorize(n);\n    map<ll, ll> mp;\n    for(auto &x : res)\
    \ {\n        mp[x]++;\n    }\n    return mp;\n}\nvl divisors(ll n) {\n    vl res\
    \ = {1};\n    auto mp = factor_count(n);\n    for(auto [p, cnt] : mp) {\n    \
    \    ll sz = ssize(res);\n        rep(i, sz) {\n            ll pi = p;\n     \
    \       rep(_, cnt) {\n                res.push_back(res[i] * pi);\n         \
    \       pi *= p;\n            }\n        }\n    }\n    sort(all(res));\n    return\
    \ res;\n}\n} // namespace fast_factorize\nusing fast_factorize::divisors;\nusing\
    \ fast_factorize::factor_count;\nusing fast_factorize::factorize;\n#line 4 \"\
    test/library_checker/number_theory/factorize.test.cpp\"\nvoid solve() {\n    LL(n);\n\
    \    if(n == 1) {\n        print(0);\n        return;\n    }\n    auto ans = factorize(n);\n\
    \    cout << ssize(ans) << \" \";\n    print(ans);\n}\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    LL(t);\n    rep(_, t) solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\n#include \"\
    math/pollard_rho.hpp\"\n#include \"template.hpp\"\nvoid solve() {\n    LL(n);\n\
    \    if(n == 1) {\n        print(0);\n        return;\n    }\n    auto ans = factorize(n);\n\
    \    cout << ssize(ans) << \" \";\n    print(ans);\n}\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    LL(t);\n    rep(_, t) solve();\n}\n"
  dependsOn:
  - math/pollard_rho.hpp
  - math/miller_rabin.hpp
  - template.hpp
  isVerificationFile: true
  path: test/library_checker/number_theory/factorize.test.cpp
  requiredBy: []
  timestamp: '2024-12-08 11:15:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/number_theory/factorize.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/number_theory/factorize.test.cpp
- /verify/test/library_checker/number_theory/factorize.test.cpp.html
title: test/library_checker/number_theory/factorize.test.cpp
---