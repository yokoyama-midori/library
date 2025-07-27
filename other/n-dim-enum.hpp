#pragma once
#include "../template.hpp"

/*
 * @brief n次元のインデックスを列挙するためのイテレータ
 *
 * 使い方:
 * for (const auto& v : n_dim_enum(n, k)) {
 *   // v は n 次元のインデックス (vector<T>)
 * }
 *
 * n: 次元の数
 * k: 各次元の大きさ (0 から k-1 まで)
 * T: インデックスの型。n_dim_enum(n, 5LL) のように k の型から推論される。
 *
 * 例: n=2, k=3 の場合
 * v は {0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2} のように変化する
 */

template <class T = int> struct NDimEnum {
    int n;
    T k;

    struct iterator {
        vector<T> a;
        bool end = false;
        T k;

        iterator(int n, T k, bool is_end = false) : a(n, 0), end(is_end), k(k) {
            if(is_end)
                a.clear();
        }

        vector<T> operator*() const { return a; }

        iterator &operator++() {
            for(int i = ssize(a) - 1; i >= 0; --i) {
                if(++a[i] < k)
                    return *this;
                a[i] = 0;
            }
            end = true;
            return *this;
        }

        bool operator!=(const iterator &other) const {
            return end != other.end;
        }
    };

    iterator begin() const { return iterator(n, k); }
    iterator end() const { return iterator(n, k, true); }
};

template <class T> NDimEnum<T> n_dim_enum(int n, T k) {
    return NDimEnum<T>{n, k};
}