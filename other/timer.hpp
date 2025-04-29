#pragma once
#include "../template.hpp"
/**
 * @brief タイマー
 * @see https://ei1333.github.io/library/other/chrono-timer.hpp
 * @see https://qiita.com/hurou927/items/a2d63837e731713c7a22
 */
struct Timer {
    chrono::high_resolution_clock::time_point start;
    Timer() { reset(); }
    void reset() { start = chrono::high_resolution_clock::now(); }
    // ミリ秒 型はint64_t?
    chrono::milliseconds::rep operator()() const {
        auto cur = chrono::high_resolution_clock::now();
        return chrono::duration_cast<chrono::milliseconds>(cur - start).count();
    }
};