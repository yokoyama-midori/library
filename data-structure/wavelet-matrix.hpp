#pragma once
#include "../template.hpp"
#include "./bit-vector.hpp"
/**
 * @brief ウェーブレット行列
 * ref: https://judge.yosupo.jp/submission/208512
 * COMPRESSがfalseの場合は非負しか扱えない
 */
template <class T, bool COMPRESS = true> struct WaveletMatrix {
    int n, lg{};
    vector<BitVector> b{};
    vector<T> memo{};
    WaveletMatrix() = default;
    explicit WaveletMatrix(const vector<T> &a) : n(a.size()) { build(a); }

  private:
    void build0(vector<T> a) {
        vector<T> lv(n), rv(n);
        for(int i = 0; i < lg; ++i) {
            int l{}, r{};
            for(int j = 0; j < n; ++j) {
                if(kth_bit(a[j], lg - 1 - i)) {
                    b[i].set(j);
                    rv[r++] = a[j];
                } else
                    lv[l++] = a[j];
            }
            b[i].build();
            swap(a, lv);
            copy(begin(rv), begin(rv) + r, begin(a) + l);
        }
    }
    void build(const vector<T> &a) {
        if constexpr(COMPRESS) {
            memo.reserve(n);
            vector<int> ord(n), _a(n);
            iota(all(ord), 0);
            ranges::stable_sort(ord, {}, [&](int i) { return a[i]; });
            int val = -1;
            for(auto i : ord) {
                if(memo.empty() or memo.back() != a[i]) {
                    memo.emplace_back(a[i]);
                    val++;
                }
                _a[i] = val;
            }
            lg = bit_width(val + 1);
            b = vector(lg, BitVector(n));
            build0(std::move(_a));
        } else {
            if(a.empty())
                return;
            auto [mini, maxi] = ranges::minmax(a);
            assert(0 <= mini);
            lg = bit_width(maxi + 1);
            b = vector(lg, BitVector(n));
            build0(a);
        }
    }

  public:
    T kth_smallest(int l, int r, int k) const {
        T res{};
        for(int i = 0; i < lg; ++i) {
            bool f = b[i].rank0(l, r) <= (u32)k;
            if(f) {
                k -= b[i].rank0(l, r);
                res |= T(1) << (lg - 1 - i);
            }
            tie(l, r) = b[i].succ(f, l, r);
        }
        if constexpr(COMPRESS)
            return memo[res];
        else
            return res;
    }
    // #{i : l<=i<r and a[i]<upper}
    T count(int l, int r, T upper) const {
        if constexpr(COMPRESS) {
            upper = ranges::lower_bound(memo, upper) - begin(memo);
        }
        if(upper >> lg) {
            return r - l;
        }
        T res{};
        for(int i = 0; i < lg; ++i) {
            bool f = kth_bit(upper, lg - 1 - i);
            if(f)
                res += b[i].rank0(l, r);
            tie(l, r) = b[i].succ(f, l, r);
        }
        return res;
    }
    // #{i : l<=i<r and lower<=a[i]<upper}
    T count(int l, int r, T lower, T upper) const {
        return count(l, r, upper) - count(l, r, lower);
    }
    // #{i : l<=i<r and a[i]==x}
    T freq(int l, int r, T x) const { return count(l, r, x, x + 1); }
};
