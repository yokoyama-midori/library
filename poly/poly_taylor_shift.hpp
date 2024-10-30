// https://drken1215.hatenablog.com/entry/2023/09/08/003100
// https://maspypy.github.io/library/poly/poly_taylor_shift.hpp
// https://x.com/risujiroh/status/1215710785000751104?s=20
#include "math/factorial.hpp"
#include "template.hpp"
#include <atcoder/convolution>
#include <atcoder/modint>
template <class mint> vector<mint> poly_taylor_shift(vector<mint> f, mint c) {
    factorial<mint> fac;
    ll n = ssize(f);
    fac.ensure(n);
    rep(i, n) { f[i] *= fac[i]; }
    vector<mint> d = [&] {
        vector<mint> d(n);
        mint c_pow = 1;
        rep(i, n) {
            d[i] = c_pow * fac.inv(i);
            c_pow *= c;
        }
        return d;
    }();
    reverse(all(f));
    f = convolution(f, d);
    f.resize(n);
    reverse(all(f));
    rep(i, n) f[i] *= fac.inv(i);
    return f;
}