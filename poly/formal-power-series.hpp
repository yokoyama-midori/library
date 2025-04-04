#pragma once
#include "../template.hpp"
#include <atcoder/convolution>
// 10^9+7みたいなときconvolutionどうする？
template <class mint> struct FormalPowerSeries : vector<mint> {
    using vector<mint>::vector;
    using FPS = FormalPowerSeries;
    FormalPowerSeries(const vector<mint> &v) : vector<mint>(v) {}
    FPS &operator+=(const FPS &f) {
        if(this->size() < f.size())
            this->resize(f.size());
        for(int i = 0; i < ssize(f); ++i)
            (*this)[i] += f[i];
        return *this;
    }
    FPS &operator-=(const FPS &f) {
        if(this->size() < f.size())
            this->resize(f.size());
        for(int i = 0; i < ssize(f); ++i)
            (*this)[i] -= f[i];
        return *this;
    }
    FPS &operator*=(const FPS &f) {
        return (*this) = atcoder::convolution(*this, f);
    }
    FPS &operator*=(const mint &x) {
        for(mint &vi : *this)
            vi *= x;
        return *this;
    }
    FPS operator+(const FPS &f) const { return FPS(*this) += f; }
    FPS operator-(const FPS &f) const { return FPS(*this) -= f; }
    FPS operator*(const FPS &f) const { return FPS(*this) *= f; }
    FPS operator*(const mint &x) const { return FPS(*this) *= x; }
    FPS operator>>(const int sz) const {
        if(sz >= ssize(*this))
            return {};
        FPS res(begin(*this) + sz, end(*this));
        return res;
    }
    FPS operator<<(const int sz) const {
        FPS res(sz, 0);
        res.insert(end(res), begin(*this), end(*this));
        return res;
    }
    FPS inv(int deg = -1) const {
        assert(!this->empty() and (*this)[0] != mint(0));
        if(deg == -1)
            deg = this->size();
        FPS res = {(*this)[0].inv()};
        FPS f;
        f.reserve(this->size());
        for(int d = 1; d < deg << 1; d <<= 1) {
            while(ssize(f) < min(ssize(*this), d))
                f.emplace_back((*this)[f.size()]);
            res *= (FPS({2}) - f * res);
            while(ssize(res) > min(d, deg))
                res.pop_back();
        }
        return res;
    }
    // なければ空を返す
    // 定数項が1でないときget_sqrtを渡す。解が複数ありうることに注意
    FPS sqrt(
        int deg = -1,
        function<mint(mint)> get_sqrt = [](mint) { return mint(1); }) const {
        if(this->empty())
            return {};
        if(deg == -1)
            deg = this->size();
        if((*this)[0] == mint(0)) {
            for(int i = 1; i < ssize(*this); ++i) {
                if((*this)[i] == mint(0))
                    continue;
                if(i & 1)
                    return {};
                if(i / 2 >= deg)
                    break;
                FPS res = (*this >> i).sqrt(deg - i / 2, get_sqrt);
                if(res.empty())
                    return {};
                res = res << (i / 2);
                return res;
            }
            return FPS(deg, 0);
        }
        FPS res{get_sqrt((*this)[0])};
        if(res[0] * res[0] != (*this)[0])
            return {};
        FPS f;
        f.reserve(this->size());
        mint inv2 = mint(1) / mint(2);
        for(int d = 1; d < deg << 1; d <<= 1) {
            while(ssize(f) < min(ssize(*this), d))
                f.emplace_back((*this)[f.size()]);
            res = (res + f * res.inv(d)) * inv2;
            while(ssize(res) > min(d, deg))
                res.pop_back();
        }
        return res;
    }
    FPS diff() const {
        FPS res(max<int>(0, ssize(*this) - 1));
        for(int i = 1; i < ssize(*this); ++i)
            res[i - 1] = (mint)i * (*this)[i];
        return res;
    }
    FPS integral() const {
        FPS res(ssize(*this) + 1);
        for(int i = 0; i < ssize(*this); ++i)
            res[i + 1] = (*this)[i] / mint(i + 1);
        return res;
    }
    FPS log(int deg = -1) const {
        assert(!this->empty() and (*this)[0] == (mint)1);
        if(deg == -1)
            deg = this->size();
        if(deg == 0)
            return {};
        FPS t(begin(*this), begin(*this) + min<int>(deg, ssize(*this)));
        FPS res = t.diff() * t.inv(deg - 1);
        res.resize(deg - 1);
        return res.integral();
    }
    FPS exp(int deg = -1) {
        assert(!this->empty() and (*this)[0] == (mint)0);
        if(deg == -1)
            deg = this->size();
        if(deg == 0)
            return {};
        FPS res = {1};
        FPS f;
        f.reserve(this->size());
        for(int d = 1; d < deg << 1; d <<= 1) {
            while(ssize(f) < min(ssize(*this), d))
                f.emplace_back((*this)[f.size()]);
            res *= (FPS({1}) + f - res.log(d));
            while(ssize(res) > min(d, deg))
                res.pop_back();
        }
        return res;
    }
};
