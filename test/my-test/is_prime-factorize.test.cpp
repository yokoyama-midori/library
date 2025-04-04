#define STANDALONE
#include "../../math/linear-sieve.hpp"
#include "../../math/pollard-rho.hpp"
#include "../../template.hpp"
void test() {
    const int n = 1000000;
    LinearSieve ls(n);
    for(int i = 1; i <= n; i++) {
        assert(ls.is_prime(i) == is_prime(i));
        auto lsf = ls.factorize(n);
        auto f = factorize(n);
        assert(ranges::equal(lsf, f));
        auto lsf_c = ls.factor_count(n);
        auto f_c = factor_count(n);
        assert(lsf_c.size() == f_c.size());
        int j = 0;
        for(auto pe : f_c) {
            assert(pe == (pair<const ll, ll>)lsf_c[j++]);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    test();
}
