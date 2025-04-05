#include "../template.hpp"
#include "formal-power-series.hpp"
/**
 * @brief 冪乗和の列挙
 * @see https://yukicoder.me/problems/no/1145/editorial
 * @see https://maspypy.com/多項式・形式的べき級数-高速に計算できるもの#toc19
 * @see https://maspypy.com/多項式・形式的べき級数-高速に計算できるもの#toc34
 */
/// 各i(0≦i≦k)についてsum[j]a_j^iを求め、長さk+1の列を返す
/// O(n*log(n)^2 + k*log(k))時間
template <class mint> vector<mint> sum_of_powers(const vector<mint> &a, int k) {
    if(a.empty())
        return vector<mint>(k + 1, 0);
    queue<FormalPowerSeries<mint>> que;
    for(auto &ai : a)
        que.push({1, -ai});
    while(que.size() > 1) {
        auto f = que.front();
        que.pop();
        auto g = que.front();
        que.pop();
        que.push(f * g);
    }
    auto &f = que.front();
    f = f.log(k + 1);
    for(int i = 1; i <= k; ++i)
        f[i] = -f[i] * mint(i);
    f[0] = ssize(a);
    return f;
}
/// 各i(0≦i≦k)についてsum[j in (0,n]]j^iを求め、長さk+1の列を返す
/// O(k*log(k))時間
template <class mint> vector<mint> sum_of_powers_iota(int n, int k) {
    using FPS = FormalPowerSeries<mint>;
    FPS num(k + 1, 1), den(k + 1, 1);
    mint fac = 1, npow = n;
    for(int i = 0; i <= k; ++i, npow *= n) {
        num[i] *= npow;
        fac *= i + 1;
    }
    fac = mint(1) / fac;
    for(int i = k; i >= 0; --i) {
        num[i] *= fac;
        den[i] *= fac;
        fac *= i + 1;
    }
    FPS res = num * den.inv(k + 1);
    res.resize(k + 1);
    fac = 1;
    for(int i = 0; i <= k; ++i) {
        res[i] *= fac;
        fac *= i + 1;
    }
    return res;
}