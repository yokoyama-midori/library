---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/lazy-splaytree.hpp
    title: data_structure/lazy-splaytree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
  bundledCode: "#line 1 \"test/library_checker/data_structure/dynamic_sequence_range_affine_range_sum.test.cpp\"\
    \n#define PROBLEM                                                            \
    \    \\\n    \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n#line 2 \"template.hpp\"\n// #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"\
    O3\")\n// #pragma GCC optimize(\"unroll-loops\")\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\ntemplate <class T>\nconcept Streamable = requires(ostream os,\
    \ T &x) { os << x; };\ntemplate <class mint>\nconcept is_modint = requires(mint\
    \ &x) {\n    { x.val() } -> std::convertible_to<int>;\n};\n#ifdef LOCAL\n#include\
    \ <debug.hpp>\n#else\n#define debug(...) 42\n#endif\n\ntemplate <Streamable T>\
    \ void print_one(const T &value) { cout << value; }\ntemplate <is_modint T> void\
    \ print_one(const T &value) { cout << value.val(); }\nvoid print() { cout << '\\\
    n'; }\ntemplate <class T, class... Ts> void print(const T &a, const Ts &...b)\
    \ {\n    print_one(a);\n    ((cout << ' ', print_one(b)), ...);\n    cout << '\\\
    n';\n}\ntemplate <ranges::range Iterable>\n    requires(!Streamable<Iterable>)\n\
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
    \ dy = {0, 0, 1, -1};\n#line 3 \"data_structure/lazy-splaytree.hpp\"\ntemplate\
    \ <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),\n          F\
    \ (*composition)(F, F), F (*id)()>\n//   composition(f,g)(x) = f\u2218g(x) = f(g(x))\n\
    struct SplayTree {\n  private:\n    struct Node;\n    using pNode = unique_ptr<Node>;\n\
    \    struct Node {\n        Node *left, *right, *parent;\n        S a, prod;\n\
    \        F lazy;\n        int size;\n        bool rev;\n        Node()\n     \
    \       : left(nullptr), right(nullptr), parent(nullptr), size(1), a(e()),\n \
    \             prod(e()), lazy(id()), rev(false) {}\n        Node(const S &s)\n\
    \            : left(nullptr), right(nullptr), parent(nullptr), size(1), a(s),\n\
    \              prod(s), lazy(id()), rev(false) {}\n        int state() {\n   \
    \         if(!this->parent)\n                return 0;\n            if(this->parent->left\
    \ == this)\n                return 1;\n            if(this->parent->right == this)\n\
    \                return 2;\n            return 0;\n        }\n        void apply(const\
    \ F &f) {\n            a = mapping(f, a);\n            prod = mapping(f, prod);\n\
    \            lazy = composition(f, lazy);\n        }\n        void reverse() {\n\
    \            swap(left, right);\n            rev = !rev;\n        }\n        void\
    \ push() {\n            if(lazy != id()) {\n                if(left)\n       \
    \             left->apply(lazy);\n                if(right)\n                \
    \    right->apply(lazy);\n                lazy = id();\n            }\n      \
    \      if(rev) {\n                if(left)\n                    left->reverse();\n\
    \                if(right)\n                    right->reverse();\n          \
    \      rev = false;\n            }\n        }\n        void update() {\n     \
    \       size = 1;\n            prod = a;\n            if(left) {\n           \
    \     size += left->size;\n                prod = op(left->prod, prod);\n    \
    \        }\n            if(right) {\n                size += right->size;\n  \
    \              prod = op(prod, right->prod);\n            }\n        }\n    };\n\
    \    void rotate(Node *me) {\n        Node *pp, *p, *c;\n        p = me->parent;\n\
    \        pp = p->parent;\n        if(p->left == me) {\n            c = me->right;\n\
    \            me->right = p;\n            p->left = c;\n        } else {\n    \
    \        c = me->left;\n            me->left = p;\n            p->right = c;\n\
    \        }\n        if(pp) {\n            if(pp->right == p) {\n             \
    \   pp->right = me;\n            } else {\n                pp->left = me;\n  \
    \          }\n        }\n        me->parent = pp;\n        p->parent = me;\n \
    \       if(c) {\n            c->parent = p;\n        }\n    }\n    void push_from_root(Node\
    \ *node) {\n        // \u6839\u304B\u3089\u30C8\u30C3\u30D7\u30C0\u30A6\u30F3\u306B\
    push\n        // https://qiita.com/ngtkana/items/4d0b84d45210771aa074#32-%E3%81%99%E3%81%B9%E3%81%A6%E3%83%88%E3%83%83%E3%83%97%E3%83%80%E3%82%A6%E3%83%B3%E3%83%95%E3%82%A7%E3%83%BC%E3%82%BA%E3%81%AB-push\n\
    \        if(!node)\n            return;\n        if(node->parent)\n          \
    \  push_from_root(node->parent);\n        node->push();\n    }\n    void splay(Node\
    \ *me, bool push_from_root_done = false) {\n        if(push_from_root_done)\n\
    \            me->push();\n        else\n            push_from_root(me);\n    \
    \    while(me->parent) {\n            Node *p = me->parent, *pp = p->parent;\n\
    \            if(me->parent->state() == 0) {\n                rotate(me);\n   \
    \             p->update();\n                break;\n            } else if(me->state()\
    \ == me->parent->state()) {\n                rotate(me->parent), rotate(me);\n\
    \            } else {\n                rotate(me), rotate(me);\n            }\n\
    \            pp->update(), p->update();\n        }\n        me->update();\n  \
    \  }\n    Node *splay_kth(int k, Node *node) {\n        assert(0 <= k and k <\
    \ node->size);\n        while(1) {\n            node->push();\n            int\
    \ l_size = node->left ? node->left->size : 0;\n            if(k < l_size) {\n\
    \                node = node->left;\n            } else if(k == l_size) {\n  \
    \              splay(node, true);\n                return node;\n            }\
    \ else {\n                k -= l_size + 1;\n                node = node->right;\n\
    \            }\n        }\n    }\n    Node *merge(Node *l_root, Node *r_root)\
    \ {\n        if(!l_root)\n            return r_root;\n        if(!r_root)\n  \
    \          return l_root;\n        l_root = splay_kth(l_root->size - 1, l_root);\n\
    \        l_root->update();\n        l_root->right = r_root;\n        r_root->parent\
    \ = l_root;\n        l_root->update();\n        return l_root;\n    }\n    pair<Node\
    \ *, Node *> split(int l_size, Node *node) {\n        if(l_size == 0)\n      \
    \      return {nullptr, node};\n        if(l_size == node->size)\n           \
    \ return {node, nullptr};\n        node = splay_kth(l_size, node);\n        Node\
    \ *l, *r;\n        l = node->left, r = node;\n        r->left = l->parent = nullptr;\n\
    \        r->update();\n        return {l, r};\n    }\n    Node *insert(int k,\
    \ Node *node, Node *root) {\n        Node *l, *r;\n        tie(l, r) = split(k,\
    \ root);\n        return merge(merge(l, node), r);\n    }\n    pair<Node *, Node\
    \ *> remove(int k, Node *node) {\n        node = splay_kth(k, node);\n       \
    \ Node *l = node->left, *r = node->right;\n        if(l)\n            l->parent\
    \ = nullptr;\n        if(r)\n            r->parent = nullptr;\n        node->left\
    \ = node->right = nullptr;\n        node->update();\n        return {merge(l,\
    \ r), node};\n    }\n    vector<pNode> pool;\n    Node *root;\n    void between(Node\
    \ *&l_root, Node *&c_root, Node *&r_root, int l, int r) {\n        // c_root\u3092\
    [l,r)\u306E\u90E8\u5206\u6728\u306E\u6839\u3068\u3057\u3066split\u3001l,r_root\u306F\
    \u5DE6\u53F3\u306E\u6728\u306E\u6839\n        // \u547C\u3073\u51FA\u3057\u305F\
    \u3042\u3068merge\u3057\u3066root\u3092\u304D\u3061\u3093\u3068\u66F4\u65B0\u3059\
    \u308B\n        tie(c_root, r_root) = split(r, root);\n        tie(l_root, c_root)\
    \ = split(l, c_root);\n        return;\n    }\n\n  public:\n    void insert_at(int\
    \ k, const S &s) {\n        pool.push_back(move(make_unique<Node>(s)));\n    \
    \    // \u2191move\u3044\u308B\uFF1F\n        Node *node = pool.back().get();\n\
    \        root = insert(k, node, root);\n    }\n    void remove_at(int k) {\n \
    \       root = remove(k, root).first;\n        // .second\u306F\u653E\u7F6E\u3055\
    \u308C\u3066\u307E\u3059\u304C...\n    }\n    void set(int k, const S &s) {\n\
    \        root = splay_kth(k, root);\n        root->a = s;\n        root->update();\n\
    \    }\n    int size() { return root ? root->size : 0; }\n    S get(int k) {\n\
    \        root = splay_kth(k, root);\n        return root->a;\n    }\n    S prod(int\
    \ l, int r) {\n        if(l == r)\n            return e();\n        Node *l_root,\
    \ *c_root, *r_root;\n        between(l_root, c_root, r_root, l, r);\n        S\
    \ res = c_root->prod;\n        root = merge(merge(l_root, c_root), r_root);\n\
    \        return res;\n    }\n    void reverse(int l, int r) {\n        if(l ==\
    \ r)\n            return;\n        Node *l_root, *c_root, *r_root;\n        between(l_root,\
    \ c_root, r_root, l, r);\n        c_root->reverse();\n        root = merge(merge(l_root,\
    \ c_root), r_root);\n    }\n    void apply(int l, int r, F f) {\n        if(l\
    \ == r)\n            return;\n        Node *l_root, *c_root, *r_root;\n      \
    \  between(l_root, c_root, r_root, l, r);\n        c_root->apply(f);\n       \
    \ root = merge(merge(l_root, c_root), r_root);\n    }\n\n    SplayTree() : root(nullptr)\
    \ {}\n    SplayTree(const vector<S> &v) : root(nullptr) {\n        Node *prev\
    \ = nullptr;\n        for(const auto &s : v) {\n            pool.push_back(move(make_unique<Node>(s)));\n\
    \            Node *node = pool.back().get();\n            if(prev)\n         \
    \       prev->parent = node;\n            node->left = prev;\n            node->update();\n\
    \            root = prev = node;\n        }\n    }\n};\n#line 4 \"test/library_checker/data_structure/dynamic_sequence_range_affine_range_sum.test.cpp\"\
    \n#include <atcoder/modint>\nusing mint = atcoder::modint998244353;\nstruct S\
    \ {\n    mint a, sz;\n};\nstatic S op(S s, S t) { return S(s.a + t.a, s.sz + t.sz);\
    \ }\nstatic S e() { return S(0, 0); }\nstruct F {\n    mint b, c;\n    bool operator==(const\
    \ F &other) const {\n        return b == other.b && c == other.c;\n    }\n};\n\
    static S mapping(F f, S s) { return S(f.b * s.a + f.c * s.sz, s.sz); }\nstatic\
    \ F composition(F f, F g) {\n    // composition(f,g)(s) = f(g(s))\n    return\
    \ F(f.b * g.b, f.b * g.c + f.c);\n}\nstatic F id() { return F(1, 0); }\n\nvoid\
    \ solve() {\n    LL(n, q);\n    vector<S> v(n);\n    rep(i, n) {\n        LL(val);\n\
    \        v[i] = S(val, 1);\n    }\n    SplayTree<S, op, e, F, mapping, composition,\
    \ id> st(v);\n    rep(t, q) {\n        LL(flag);\n        if(flag == 0) {\n  \
    \          LL(i, x);\n            st.insert_at(i, S(x, 1));\n        } else if(flag\
    \ == 1) {\n            LL(i);\n            st.remove_at(i);\n        } else if(flag\
    \ == 2) {\n            LL(l, r);\n            st.reverse(l, r);\n        } else\
    \ if(flag == 3) {\n            LL(l, r, b, c);\n            st.apply(l, r, F(b,\
    \ c));\n        } else {\n            LL(l, r);\n            print(st.prod(l,\
    \ r).a.val());\n        }\n    }\n}\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    solve();\n}\n"
  code: "#define PROBLEM                                                         \
    \       \\\n    \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n#include \"data_structure/lazy-splaytree.hpp\"\n#include <atcoder/modint>\n\
    using mint = atcoder::modint998244353;\nstruct S {\n    mint a, sz;\n};\nstatic\
    \ S op(S s, S t) { return S(s.a + t.a, s.sz + t.sz); }\nstatic S e() { return\
    \ S(0, 0); }\nstruct F {\n    mint b, c;\n    bool operator==(const F &other)\
    \ const {\n        return b == other.b && c == other.c;\n    }\n};\nstatic S mapping(F\
    \ f, S s) { return S(f.b * s.a + f.c * s.sz, s.sz); }\nstatic F composition(F\
    \ f, F g) {\n    // composition(f,g)(s) = f(g(s))\n    return F(f.b * g.b, f.b\
    \ * g.c + f.c);\n}\nstatic F id() { return F(1, 0); }\n\nvoid solve() {\n    LL(n,\
    \ q);\n    vector<S> v(n);\n    rep(i, n) {\n        LL(val);\n        v[i] =\
    \ S(val, 1);\n    }\n    SplayTree<S, op, e, F, mapping, composition, id> st(v);\n\
    \    rep(t, q) {\n        LL(flag);\n        if(flag == 0) {\n            LL(i,\
    \ x);\n            st.insert_at(i, S(x, 1));\n        } else if(flag == 1) {\n\
    \            LL(i);\n            st.remove_at(i);\n        } else if(flag == 2)\
    \ {\n            LL(l, r);\n            st.reverse(l, r);\n        } else if(flag\
    \ == 3) {\n            LL(l, r, b, c);\n            st.apply(l, r, F(b, c));\n\
    \        } else {\n            LL(l, r);\n            print(st.prod(l, r).a.val());\n\
    \        }\n    }\n}\n\nint main() {\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    solve();\n}\n"
  dependsOn:
  - data_structure/lazy-splaytree.hpp
  - template.hpp
  isVerificationFile: true
  path: test/library_checker/data_structure/dynamic_sequence_range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2025-03-18 18:04:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/data_structure/dynamic_sequence_range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/dynamic_sequence_range_affine_range_sum.test.cpp
- /verify/test/library_checker/data_structure/dynamic_sequence_range_affine_range_sum.test.cpp.html
title: test/library_checker/data_structure/dynamic_sequence_range_affine_range_sum.test.cpp
---
