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
    Matrix &operator^=(int k) {
        assert(height == width and k >= 0);
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
    [[nodiscard]] Matrix pow(int k) const {
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

    /*
    O(N^3 + N^2*log mod)
    modは素数である必要がある
    TODO : https://github.com/yosupo06/library-checker-problems/issues/750
    をチェック
    */
    T determinant() const {
        assert(height == width);
        static_assert(!is_integral_v<T>);
        Matrix B(*this);
        // vector一本にしてしまったため行のswapに一工夫...
        vector<int> ord(height);
        iota(begin(ord), end(ord), 0);
        T res = 1;
        for(int i = 0; i < height; ++i) {
            if(B(ord[i], i) == 0) {
                for(int i2 = i + 1; i2 < height; ++i2) {
                    if(B(ord[i2], i) != 0) {
                        res *= -1;
                        swap(ord[i], ord[i2]);
                        break;
                    }
                }
            }
            if(B(ord[i], i) == 0)
                return 0;
            res *= B(ord[i], i);
            for(int i2 = i + 1; i2 < height; ++i2) {
                T r = B(ord[i2], i) / B(ord[i], i);
                for(int j = 0; j < width; ++j) {
                    B(ord[i2], j) -= r * B(ord[i], j);
                }
            }
        }
        return res;
    }
};
