#pragma once
#include "../template.hpp"
/**
 * @brief グリッドの回転・転置・拡大
 */
template <class T>
vector<T> grid_rotate(const vector<T> &a, int clockwize_cnt = 1) {
    if(a.empty())
        return vector<T>();
    clockwize_cnt = bmod(clockwize_cnt, 4);
    if(clockwize_cnt == 0) {
        return a;
    }
    using U = typename T::value_type;
    int h = ssize(a), w = ssize(a[0]);
    vector res =
        (clockwize_cnt & 1 ? vector(w, T(h, U())) : vector(h, T(w, U())));
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            if(clockwize_cnt == 1) {
                res[j][h - 1 - i] = a[i][j];
            } else if(clockwize_cnt == 3) {
                res[w - 1 - j][i] = a[i][j];
            } else {
                res[h - 1 - i][w - 1 - j] = a[i][j];
            }
        }
    }
    return res;
}
template <class T> vector<T> grid_transpose(const vector<T> &a) {
    if(a.empty())
        return {};
    using U = typename T::value_type;
    int h = ssize(a), w = ssize(a[0]);
    vector res(w, T(h, U()));
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            res[j][i] = a[i][j];
        }
    }
    return res;
}
template <class T> vector<T> grid_expansion(const vector<T> &a, int k) {
    if(a.empty()) {
        return vector<T>();
    }
    int h = ssize(a), w = ssize(a[0]);
    using U = typename T::value_type;
    vector<T> res(k * h, T(k * w, U()));
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            for(int s = 0; s < k; ++s) {
                for(int t = 0; t < k; ++t) {
                    res[k * i + s][k * j + t] = a[i][j];
                }
            }
        }
    }
    return res;
}
