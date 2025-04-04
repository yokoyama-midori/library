#include "../template.hpp"
#include "formal-power-series.hpp"
/**
 * @brief 列の冪乗和
 * @see https://yukicoder.me/problems/no/1145/editorial
 * 各i(0≦i≦k)についてsum[aj in a]aj^iを求め、長さk+1の列を返す
 * O(n*log(n)^2 + k*log(k))時間
 */
template <class mint> vector<mint> sum_of_powers(const vector<mint> &a, int k) {
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