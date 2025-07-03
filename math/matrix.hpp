#pragma once
#include "../template.hpp"
template <class T> struct Matrix {
    int height, width;
    vector<T> A;
    Matrix() = default;
    Matrix(int n, int m) : height(n), width(m), A(n * m, T(0)) {}
    Matrix(int n) : Matrix(n, n) {}
    Matrix(vector<vector<T>> A_) : height(A_.size()), width(A_[0].size()) {
        A.reserve(height * width);
        for(auto &&row : A_ | views::join)
            A.emplace_back(row);
    }
    inline const T &operator()(int i, int j) const { return A[i * width + j]; }
    inline T &operator()(int i, int j) { return A[i * width + j]; }
    void show() const {
        for(int i = 0; i < height; ++i) {
            for(int j = 0; j < width; ++j) {
                if constexpr(is_arithmetic_v<T>) {
                    cout << (*this)(i, j) << " \n"[j + 1 == width];
                } else {
                    // atcoder::modint用
                    cout << (*this)(i, j).val() << " \n"[j + 1 == width];
                }
            }
        }
    }

    Matrix &operator+=(const Matrix &B) {
        assert(height == B.height && width == B.width);
        for(int i = 0; i < height * width; ++i)
            A[i] += B.A[i];
        return *this;
    }
    Matrix &operator-=(const Matrix &B) {
        assert(height == B.height && width == B.width);
        for(int i = 0; i < height * width; ++i)
            A[i] -= B.A[i];
        return *this;
    }
    Matrix &operator*=(const Matrix &B) {
        assert(width == B.height);
        // (height,width)*(B.height,B.width) -> (height,B.width)
        Matrix<T> res(height, B.width);
        for(int i = 0; i < height; ++i) {
            for(int k = 0; k < width; ++k) {
                for(int j = 0; j < B.width; ++j) {
                    res(i, j) += (*this)(i, k) * B(k, j);
                }
            }
        }
        swap(*this, res);
        return *this;
    }
    Matrix &operator^=(size_t k) {
        assert(height == width);
        Matrix<T> res(height);
        for(int i = 0; i < height; ++i)
            res(i, i) = T(1);
        while(k) {
            if(k & 1) {
                res *= (*this);
            }
            (*this) *= (*this);
            k >>= 1;
        }
        swap(res, *this);
        return *this;
    }
    [[nodiscard]] Matrix pow(size_t k) const {
        auto res(*this);
        res ^= k;
        return res;
    }
    [[nodiscard]] Matrix operator+(const Matrix &B) const {
        return Matrix(*this) += B;
    }
    [[nodiscard]] Matrix operator-(const Matrix &B) const {
        return Matrix(*this) -= B;
    }
    [[nodiscard]] Matrix operator*(const Matrix &B) const {
        return Matrix(*this) *= B;
    }
};
