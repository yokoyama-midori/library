---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/splaytree.hpp
    title: "\u30B9\u30D7\u30EC\u30FC\u6728"
  - icon: ':heavy_check_mark:'
    path: rng.hpp
    title: rng.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/my-test/splaytree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n#line 2 \"template.hpp\"\n// #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"\
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
    vl dx = {1, -1, 0, 0};\nvl dy = {0, 0, 1, -1};\n#line 2 \"data_structure/splaytree.hpp\"\
    \ntemplate <class S, auto op = [](S a, S b) { return S(0); },\n          auto\
    \ e = []() { return S(0); }>\nstruct SplayTree {\n  private:\n    struct Node;\n\
    \    using pNode = unique_ptr<Node>;\n    struct Node {\n        Node *left, *right,\
    \ *parent;\n        S a, prod;\n        int size;\n        Node()\n          \
    \  : left(nullptr), right(nullptr), parent(nullptr), size(1), a(e()),\n      \
    \        prod(e()) {}\n        Node(const S &s)\n            : left(nullptr),\
    \ right(nullptr), parent(nullptr), size(1), a(s),\n              prod(s) {}\n\
    \        int state() {\n            if(!this->parent)\n                return\
    \ 0;\n            if(this->parent->left == this)\n                return 1;\n\
    \            if(this->parent->right == this)\n                return 2;\n    \
    \        return 0;\n        }\n        void update() {\n            size = 1;\n\
    \            prod = a;\n            if(left) {\n                size += left->size;\n\
    \                prod = op(left->prod, prod);\n            }\n            if(right)\
    \ {\n                size += right->size;\n                prod = op(prod, right->prod);\n\
    \            }\n        }\n    };\n    void rotate(Node *me) {\n        Node *pp,\
    \ *p, *c;\n        p = me->parent;\n        pp = p->parent;\n        if(p->left\
    \ == me) {\n            c = me->right;\n            me->right = p;\n         \
    \   p->left = c;\n        } else {\n            c = me->left;\n            me->left\
    \ = p;\n            p->right = c;\n        }\n        if(pp) {\n            if(pp->right\
    \ == p) {\n                pp->right = me;\n            } else {\n           \
    \     pp->left = me;\n            }\n        }\n        me->parent = pp;\n   \
    \     p->parent = me;\n        if(c) {\n            c->parent = p;\n        }\n\
    \    }\n    void splay(Node *me) {\n        while(me->parent) {\n            Node\
    \ *p = me->parent, *pp = p->parent;\n            if(me->parent->state() == 0)\
    \ {\n                rotate(me);\n                p->update();\n             \
    \   break;\n            } else if(me->state() == me->parent->state()) {\n    \
    \            rotate(me->parent), rotate(me);\n            } else {\n         \
    \       rotate(me), rotate(me);\n            }\n            pp->update(), p->update();\n\
    \        }\n        me->update();\n    }\n    Node *splay_kth(int k, Node *node)\
    \ {\n        assert(0 <= k and k < node->size);\n        while(1) {\n        \
    \    int l_size = node->left ? node->left->size : 0;\n            if(k < l_size)\
    \ {\n                node = node->left;\n            } else if(k == l_size) {\n\
    \                splay(node);\n                return node;\n            } else\
    \ {\n                k -= l_size + 1;\n                node = node->right;\n \
    \           }\n        }\n    }\n    Node *merge(Node *l_root, Node *r_root) {\n\
    \        if(!l_root)\n            return r_root;\n        if(!r_root)\n      \
    \      return l_root;\n        l_root = splay_kth(l_root->size - 1, l_root);\n\
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
    \ = split(l, c_root);\n        return;\n    }\n    void dfs(Node *node, vector<S>\
    \ &res) {\n        if(node->left)\n            dfs(node->left, res);\n       \
    \ res.push_back(node->a);\n        if(node->right)\n            dfs(node->right,\
    \ res);\n    }\n\n  public:\n    void insert_at(int k, const S &s) {\n       \
    \ pool.push_back(move(make_unique<Node>(s)));\n        // \u2191move\u3044\u308B\
    \uFF1F\n        Node *node = pool.back().get();\n        root = insert(k, node,\
    \ root);\n    }\n    void remove_at(int k) {\n        root = remove(k, root).first;\n\
    \        // .second\u306F\u653E\u7F6E\u3055\u308C\u3066\u307E\u3059\u304C...\n\
    \    }\n    void set(int k, const S &s) {\n        root = splay_kth(k, root);\n\
    \        root->a = s;\n        root->update();\n    }\n    int size() { return\
    \ root ? root->size : 0; }\n    S get(int k) {\n        root = splay_kth(k, root);\n\
    \        return root->a;\n    }\n    S prod(int l, int r) {\n        if(l == r)\n\
    \            return e();\n        Node *l_root, *c_root, *r_root;\n        between(l_root,\
    \ c_root, r_root, l, r);\n        S res = c_root->prod;\n        root = merge(merge(l_root,\
    \ c_root), r_root);\n        return res;\n    }\n    S all_prod() { return root->prod;\
    \ }\n    void shift(int l, int r) {\n        //    ...,a[l]  ,    ... ,a[r-1],a[r],...\n\
    \        // -> ...,a[r-1],a[l],...,a[r-2],a[r],...\n        Node *node;\n    \
    \    tie(root, node) = remove(r - 1, root);\n        root = insert(l, node, root);\n\
    \    }\n    void swap(ll l, ll r) {\n        // swap(a[l],a[r])\n        if(l\
    \ == r)\n            return;\n        if(l > r)\n            std::swap(l, r);\n\
    \        Node *al, *ar;\n        tie(root, ar) = remove(r, root);\n        tie(root,\
    \ al) = remove(l, root);\n        root = insert(l, ar, root);\n        root =\
    \ insert(r, al, root);\n    }\n    vector<S> get_vec() {\n        vector<S> res;\n\
    \        dfs(root, res);\n        return res;\n    }\n    int find(const S &s,\
    \ auto &&comp) {\n        // comp(s,t) <==> s < t\n        // \u6607\u9806\u306B\
    \u30BD\u30FC\u30C8\u3055\u308C\u3066\u3044\u308B\u3053\u3068\u3092\u4EEE\u5B9A\
    \u3059\u308B\n        // comp(a[i],s)\u304C\u6210\u308A\u7ACB\u305F\u306A\u3044\
    \u6700\u5C0F\u306Ei(s\u4EE5\u4E0A\u306E\u6700\u521D\u306Eidx)\u3092\u8FD4\u3059\
    \n        // \u306A\u3051\u308C\u3070size()\u3092\u8FD4\u3059\n        // amortized\
    \ O(log size)\n        Node *cur = root;\n        Node *res = nullptr;\n     \
    \   while(cur) {\n            if(comp(cur->a, s)) {\n                cur = cur->right;\n\
    \            } else {\n                res = cur;\n                cur = cur->left;\n\
    \            }\n        }\n        if(res) {\n            splay(res);\n      \
    \      root = res;\n            return res->left ? res->left->size : 0;\n    \
    \    } else {\n            return size();\n        }\n    }\n\n    SplayTree()\
    \ : root(nullptr) {}\n    SplayTree(const vector<S> &v) : root(nullptr) {\n  \
    \      Node *prev = nullptr;\n        for(const auto &s : v) {\n            pool.push_back(move(make_unique<Node>(s)));\n\
    \            Node *node = pool.back().get();\n            if(prev)\n         \
    \       prev->parent = node;\n            node->left = prev;\n            node->update();\n\
    \            root = prev = node;\n        }\n    }\n};\n#line 2 \"rng.hpp\"\n\
    // https://maspypy.github.io/library/random/base.hpp\n#line 4 \"rng.hpp\"\nunsigned\
    \ long long RNG_64() {\n    static unsigned long long x_ =\n        (unsigned\
    \ long long)(chrono::duration_cast<chrono::nanoseconds>(\n                   \
    \              chrono::high_resolution_clock::now()\n                        \
    \             .time_since_epoch())\n                                 .count())\
    \ *\n        10150724397891781847ULL;\n    x_ ^= x_ << 7;\n    return x_ ^= x_\
    \ >> 9;\n}\n\nunsigned long long RNG(unsigned long long lim) { return RNG_64()\
    \ % lim; }\n\nll rng(ll l, ll r) {\n    // [l,r)\n    return l + RNG_64() % (r\
    \ - l);\n}\n#line 4 \"test/my-test/splaytree.test.cpp\"\nvoid test() {\n    const\
    \ int size_max = 100, value_max = 1000000000, query_max = 1000;\n    int n = rng(1,\
    \ size_max + 1);\n    vl a(n);\n    rep(i, n) a[i] = rng(1, value_max + 1);\n\
    \    SplayTree<ll, [](ll a, ll b) { return a + b; }, []() { return 0LL; }> spt(\n\
    \        a);\n    auto make_val = [&value_max] { return rng(1, value_max + 1);\
    \ };\n    auto make_pos = [&] { return rng(0, n); };\n    auto make_lr = [&]()\
    \ {\n        int l(make_pos()), r(make_pos() + 1);\n        if(l > r)\n      \
    \      swap(l, r);\n        return pair<int, int>(l, r);\n    };\n    auto insert_query\
    \ = [&] {\n        int x = rng(0, n + 1), val = make_val();\n        assert(x\
    \ <= n);\n        a.insert(begin(a) + x, val);\n        ++n;\n        spt.insert_at(x,\
    \ val);\n    };\n    auto erase_query = [&]() {\n        int x = make_pos();\n\
    \        assert(x < n);\n        a.erase(begin(a) + x);\n        --n;\n      \
    \  spt.remove_at(x);\n    };\n    auto set_query = [&]() {\n        int x = make_pos(),\
    \ val = make_val();\n        assert(x < n);\n        a[x] = val;\n        spt.set(x,\
    \ val);\n    };\n    auto size_query = [&] { assert(a.size() == n and n == spt.size());\
    \ };\n    auto get_query = [&] {\n        int x = make_pos();\n        assert(x\
    \ < n);\n        assert(a[x] == spt.get(x));\n    };\n    auto prod_query = [&]\
    \ {\n        auto [l, r] = make_lr();\n        assert(0 <= l and l <= r and r\
    \ <= n);\n        ll sum = accumulate(begin(a) + l, begin(a) + r, 0LL);\n    \
    \    assert(sum == spt.prod(l, r));\n    };\n    auto shift_query = [&] {\n  \
    \      auto [l, r] = make_lr();\n        while(l == r)\n            tie(l, r)\
    \ = make_lr();\n        assert(0 <= l and l < r and r <= n);\n        rotate(begin(a)\
    \ + l, begin(a) + r - 1, begin(a) + r);\n        spt.shift(l, r);\n    };\n  \
    \  auto swap_query = [&] {\n        int l = make_pos(), r = make_pos();\n    \
    \    assert(0 <= min(l, r) and max(l, r) < n);\n        swap(a[l], a[r]);\n  \
    \      spt.swap(l, r);\n    };\n    auto get_vec_query = [&]() { assert(spt.get_vec()\
    \ == a); };\n    int q = rng(1, query_max + 1);\n    while(q--) {\n        if(n\
    \ == 0) {\n            insert_query();\n            continue;\n        }\n   \
    \     ll flag = rng(0, 9);\n        if(flag == 0) {\n            insert_query();\n\
    \        } else if(flag == 1) {\n            erase_query();\n        } else if(flag\
    \ == 2) {\n            set_query();\n        } else if(flag == 3) {\n        \
    \    size_query();\n        } else if(flag == 4) {\n            get_query();\n\
    \        } else if(flag == 5) {\n            prod_query();\n        } else if(flag\
    \ == 6) {\n            shift_query();\n        } else if(flag == 7) {\n      \
    \      swap_query();\n        } else {\n            get_vec_query();\n       \
    \ }\n        debug(q, flag, \"ok\", a);\n    }\n}\nvoid solve() {\n    LL(a, b);\n\
    \    print(a + b);\n}\nint main() {\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    rep(i, 10) test();\n    solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"data_structure/splaytree.hpp\"\
    \n#include \"rng.hpp\"\nvoid test() {\n    const int size_max = 100, value_max\
    \ = 1000000000, query_max = 1000;\n    int n = rng(1, size_max + 1);\n    vl a(n);\n\
    \    rep(i, n) a[i] = rng(1, value_max + 1);\n    SplayTree<ll, [](ll a, ll b)\
    \ { return a + b; }, []() { return 0LL; }> spt(\n        a);\n    auto make_val\
    \ = [&value_max] { return rng(1, value_max + 1); };\n    auto make_pos = [&] {\
    \ return rng(0, n); };\n    auto make_lr = [&]() {\n        int l(make_pos()),\
    \ r(make_pos() + 1);\n        if(l > r)\n            swap(l, r);\n        return\
    \ pair<int, int>(l, r);\n    };\n    auto insert_query = [&] {\n        int x\
    \ = rng(0, n + 1), val = make_val();\n        assert(x <= n);\n        a.insert(begin(a)\
    \ + x, val);\n        ++n;\n        spt.insert_at(x, val);\n    };\n    auto erase_query\
    \ = [&]() {\n        int x = make_pos();\n        assert(x < n);\n        a.erase(begin(a)\
    \ + x);\n        --n;\n        spt.remove_at(x);\n    };\n    auto set_query =\
    \ [&]() {\n        int x = make_pos(), val = make_val();\n        assert(x < n);\n\
    \        a[x] = val;\n        spt.set(x, val);\n    };\n    auto size_query =\
    \ [&] { assert(a.size() == n and n == spt.size()); };\n    auto get_query = [&]\
    \ {\n        int x = make_pos();\n        assert(x < n);\n        assert(a[x]\
    \ == spt.get(x));\n    };\n    auto prod_query = [&] {\n        auto [l, r] =\
    \ make_lr();\n        assert(0 <= l and l <= r and r <= n);\n        ll sum =\
    \ accumulate(begin(a) + l, begin(a) + r, 0LL);\n        assert(sum == spt.prod(l,\
    \ r));\n    };\n    auto shift_query = [&] {\n        auto [l, r] = make_lr();\n\
    \        while(l == r)\n            tie(l, r) = make_lr();\n        assert(0 <=\
    \ l and l < r and r <= n);\n        rotate(begin(a) + l, begin(a) + r - 1, begin(a)\
    \ + r);\n        spt.shift(l, r);\n    };\n    auto swap_query = [&] {\n     \
    \   int l = make_pos(), r = make_pos();\n        assert(0 <= min(l, r) and max(l,\
    \ r) < n);\n        swap(a[l], a[r]);\n        spt.swap(l, r);\n    };\n    auto\
    \ get_vec_query = [&]() { assert(spt.get_vec() == a); };\n    int q = rng(1, query_max\
    \ + 1);\n    while(q--) {\n        if(n == 0) {\n            insert_query();\n\
    \            continue;\n        }\n        ll flag = rng(0, 9);\n        if(flag\
    \ == 0) {\n            insert_query();\n        } else if(flag == 1) {\n     \
    \       erase_query();\n        } else if(flag == 2) {\n            set_query();\n\
    \        } else if(flag == 3) {\n            size_query();\n        } else if(flag\
    \ == 4) {\n            get_query();\n        } else if(flag == 5) {\n        \
    \    prod_query();\n        } else if(flag == 6) {\n            shift_query();\n\
    \        } else if(flag == 7) {\n            swap_query();\n        } else {\n\
    \            get_vec_query();\n        }\n        debug(q, flag, \"ok\", a);\n\
    \    }\n}\nvoid solve() {\n    LL(a, b);\n    print(a + b);\n}\nint main() {\n\
    \    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n    rep(i, 10)\
    \ test();\n    solve();\n}\n"
  dependsOn:
  - data_structure/splaytree.hpp
  - template.hpp
  - rng.hpp
  isVerificationFile: true
  path: test/my-test/splaytree.test.cpp
  requiredBy: []
  timestamp: '2025-03-16 14:03:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/my-test/splaytree.test.cpp
layout: document
redirect_from:
- /verify/test/my-test/splaytree.test.cpp
- /verify/test/my-test/splaytree.test.cpp.html
title: test/my-test/splaytree.test.cpp
---
