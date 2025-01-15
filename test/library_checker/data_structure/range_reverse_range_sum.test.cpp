#define PROBLEM "https://judge.yosupo.jp/problem/range_reverse_range_sum"
#include "data_structure/splaytree.hpp"
using S = ll;
static S op(S s, S t) { return s + t; }
static S e() { return 0; }
// 作用は不要だが...
struct F {
    bool operator==(const F &other) const { return true; }
};
static S mapping(F f, S s) { return s; }
static F id() { return F(); }
static F composition(F f, F g) {
    // composition(f,g)(s) = f(g(s))
    return id();
}
void solve() {
    LL(n, q);
    vector<S> v(n);
    rep(i, n) {
        LL(val);
        v[i] = val;
    }
    SplayTree<S, op, e, F, mapping, composition, id> st(v);
    rep(t, q) {
        LL(flag);
        LL(l, r);
        if(flag == 0) {
            st.reverse(l, r);
        } else {
            print(st.prod(l, r));
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
