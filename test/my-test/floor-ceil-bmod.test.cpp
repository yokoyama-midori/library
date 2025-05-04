#define STANDALONE
#include "../../rng.hpp"
#include "../../template.hpp"
const int testcnt = 1e6;
template <class T> void test(T l, T r) {
    rep(_, testcnt) {
        T x = rng(l, r), y = rng(l, r);
        if(y == 0)
            continue;
        T f = floor(x, y), c = ceil(x, y), b = bmod(x, y);
        assert(0 <= b and ((y > 0 and b < y) or b < -y));
        assert((x - b) % y == 0);
        assert(std::floor((long double)x / y) == (long double)f);
        assert(std::ceil((long double)x / y) == (long double)c);
    }
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    test<int>(-5e8, 5e8);
    test<unsigned>(0, 1e9);
    test<ll>(-3e18, 3e18);
    test<unsigned long long>(0, 3e18);
}