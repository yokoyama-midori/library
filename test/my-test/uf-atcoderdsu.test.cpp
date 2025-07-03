#define STANDALONE
#include "../../data-structure/union-find.hpp"
#include "../../rng.hpp"
#include "../../template.hpp"
#include <atcoder/dsu>
void test() {
    int maxi = 100'000, check_times = 10;
    int n = rng(1, maxi);
    UnionFind uf(n);
    atcoder::dsu dsu(n);
    int q = rng(1, maxi);
    rep(qi, q) {
        int i = rng(0, n), j = rng(0, n);
        assert(uf.size(i) == dsu.size(i));
        assert(uf.same(i, j) == dsu.same(i, j));
        uf.merge(i, j);
        dsu.merge(i, j);
        if(qi % (maxi / check_times) == 0) {
            auto g = uf.groups();
            auto h = dsu.groups();
            for(auto &&v : g)
                ranges::sort(v);
            for(auto &&v : h)
                ranges::sort(v);
            ranges::sort(g);
            ranges::sort(h);
            assert(g == h);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n = 100;
    rep(i, n) {
        test();
        cerr << "ok: " << i << endl;
    }
}
