#pragma once
#include "../template.hpp"
template <class T> struct Matrix {
    vector<vector<T>> A;
    size_t height, width;
    Matrix() {}
    Matrix(size_t n, size_t m)
        : A(vector(n, vector<T>(m, 0))), height(n), width(m) {}
    Matrix(size_t n) : Matrix(n, n) {}
    Matrix(vector<vector<T>> A_)
        : A(A_), height(A_.size()), width(A_[0].size()) {}
    inline const vector<T> &operator[](size_t k) const { return A.at(k); };
    inline vector<T> &operator[](size_t k) { return A.at(k); };
    void show() {
        rep(i, height) {
            rep(j, width) {
                if constexpr(is_arithmetic<T>::value) {
                    cout << A[i][j] << " \n"[j + 1 == width];
                } else {
                    // atcoder::modint用
                    cout << A[i][j].val() << " \n"[j + 1 == width];
                }
            }
        }
    }

    Matrix &operator+=(const Matrix &B) {
        assert(height == B.height && width == B.width);
        rep(i, height) {
            rep(j, width) { A[i][j] += B[i][j]; }
        }
        return *this;
    }
    Matrix &operator-=(const Matrix &B) {
        assert(height == B.height && width == B.width);
        rep(i, height) {
            rep(j, width) { A[i][j] -= B[i][j]; }
        }
        return *this;
    }
    Matrix &operator*=(const Matrix &B) {
        assert(width == B.height);
        // (height,width)*(B.height,B.width) -> (height,B.width)
        Matrix<T> res(height, B.width);
        rep(i, height) {
            rep(j, width) {
                rep(k, B.width) { res[i][k] += A[i][j] * B[j][k]; }
            }
        }
        swap(*this, res);
        return *this;
    }
    Matrix &operator^=(size_t k) {
        assert(height == width);
        Matrix<T> res(height);
        rep(i, height) res[i][i] = 1;
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
    Matrix pow(size_t k) {
        auto res(*this);
        res ^= k;
        return res;
    }
    Matrix operator+(const Matrix &B) { return Matrix(*this) += B; }
    Matrix operator-(const Matrix &B) { return Matrix(*this) -= B; }
    Matrix operator*(const Matrix &B) { return Matrix(*this) *= B; }
};
