#define STANDALONE
#include "../../data-structure/union-find-with-undo.hpp"
#include "../../data-structure/union-find.hpp"
#include "../../rng.hpp"
#include "../../template.hpp"
void test() {
    int maxi = 100'000;
    int n = rng(1, maxi);
    UnionFind uf(n);
    UnionFindWithUndo ufwu(n);
    assert(uf.num_groups == ufwu.num_groups and uf.num_groups == n);
    int q = rng(1, maxi);
    rep(q) {
        assert(uf.num_groups == ufwu.num_groups);
        int i = rng(0, n), j = rng(0, n);
        assert(uf.size(i) == ufwu.size(i));
        assert(uf.same(i, j) == ufwu.same(i, j));
        uf.merge(i, j);
        ufwu.merge(i, j);
    }
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n = 100;
    rep(n) test();
}
