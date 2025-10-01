#pragma once
#include "../template.hpp"
/**
 * @brief ビットベクトル
 * ref: https://judge.yosupo.jp/submission/208512
 */
struct BitVector {
    int n;
    vector<u32> bit, sum;
    BitVector() = default;
    explicit BitVector(int n)
        : n(n), bit((n + 31) >> 5, 0), sum(bit.size() + 1, 0) {}
    void set(int i) { bit[i >> 5] |= 1U << (i & 31); }
    void reset(int i) { bit[i >> 5] &= ~(1U << (i & 31)); }
    void build() {
        for(int i = 0; i < ssize(bit); ++i) {
            sum[i + 1] = sum[i] + popcount(bit[i]);
        }
    }
    u32 rank1(int r) const {
        return sum[r >> 5] + popcount(bit[r >> 5] & ((1U << (r & 31)) - 1));
    }
    u32 rank1(int l, int r) const { return rank1(r) - rank1(l); }
    u32 rank0(int r) const { return r - rank1(r); }
    u32 rank0(int l, int r) const { return rank0(r) - rank0(l); }
    u32 rank(bool f, int r) const { return f ? rank1(r) : rank0(r); }
    u32 rank(bool f, int l, int r) const {
        return f ? rank1(l, r) : rank0(l, r);
    }
    pair<u32, u32> succ(bool f, int l, int r) const {
        return f ? make_pair(n - sum.back() + rank1(l),
                             n - sum.back() + rank1(r))
                 : make_pair(rank0(l), rank0(r));
    }
};
