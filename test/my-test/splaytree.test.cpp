#define STANDALONE
#include "../../data-structure/splaytree.hpp"
#include "../../rng.hpp"
void test() {
    const int size_max = 100, value_max = 1000000000, query_max = 1000;
    int n = rng(1, size_max + 1);
    vl a(n);
    rep(i, n) a[i] = rng(1, value_max + 1);
    SplayTree<ll, [](ll a, ll b) { return a + b; }, []() { return 0LL; }> spt(
        a);
    auto make_val = [&value_max] { return rng(1, value_max + 1); };
    auto make_pos = [&] { return rng(0, n); };
    auto make_lr = [&]() {
        int l(make_pos()), r(make_pos() + 1);
        if(l > r)
            swap(l, r);
        return pair<int, int>(l, r);
    };
    auto insert_query = [&] {
        int x = rng(0, n + 1), val = make_val();
        assert(x <= n);
        a.insert(begin(a) + x, val);
        ++n;
        spt.insert_at(x, val);
    };
    auto erase_query = [&]() {
        int x = make_pos();
        assert(x < n);
        a.erase(begin(a) + x);
        --n;
        spt.remove_at(x);
    };
    auto set_query = [&]() {
        int x = make_pos(), val = make_val();
        assert(x < n);
        a[x] = val;
        spt.set(x, val);
    };
    auto size_query = [&] { assert(a.size() == n and n == spt.size()); };
    auto get_query = [&] {
        int x = make_pos();
        assert(x < n);
        assert(a[x] == spt.get(x));
    };
    auto prod_query = [&] {
        auto [l, r] = make_lr();
        assert(0 <= l and l <= r and r <= n);
        ll sum = accumulate(begin(a) + l, begin(a) + r, 0LL);
        assert(sum == spt.prod(l, r));
    };
    auto shift_query = [&] {
        auto [l, r] = make_lr();
        while(l == r)
            tie(l, r) = make_lr();
        assert(0 <= l and l < r and r <= n);
        rotate(begin(a) + l, begin(a) + r - 1, begin(a) + r);
        spt.shift(l, r);
    };
    auto swap_query = [&] {
        int l = make_pos(), r = make_pos();
        assert(0 <= min(l, r) and max(l, r) < n);
        swap(a[l], a[r]);
        spt.swap(l, r);
    };
    auto get_vec_query = [&]() { assert(spt.get_vec() == a); };
    int q = rng(1, query_max + 1);
    while(q--) {
        if(n == 0) {
            insert_query();
            continue;
        }
        ll flag = rng(0, 9);
        if(flag == 0) {
            insert_query();
        } else if(flag == 1) {
            erase_query();
        } else if(flag == 2) {
            set_query();
        } else if(flag == 3) {
            size_query();
        } else if(flag == 4) {
            get_query();
        } else if(flag == 5) {
            prod_query();
        } else if(flag == 6) {
            shift_query();
        } else if(flag == 7) {
            swap_query();
        } else {
            get_vec_query();
        }
        debug(q, flag, "ok", a);
    }
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    rep(i, 10) test();
}
