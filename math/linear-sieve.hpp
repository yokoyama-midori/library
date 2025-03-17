#pragma once
#include "template.hpp"
// https://37zigen.com/linear-sieve/
// AtCoder codetest
// 1e6   7ms 7.5MB
// 1e7  53ms  46MB
// 1e8 650ms 426MB
struct LinearSieve {
    int max_value;
    // lpf[i] = iの最小素因数(least prime factor)
    vector<int> lpf, primes;
    LinearSieve(int max_value) : max_value(max_value), lpf(max_value + 1, 1) {
        for(int i = 2; i <= max_value; ++i) {
            if(lpf[i] == 1) {
                lpf[i] = i;
                primes.emplace_back(i);
            }
            for(auto p : primes) {
                if(p * i > max_value or p > lpf[i])
                    break;
                lpf[p * i] = p;
            }
        }
    }
    vector<int> factorize(int n) {
        vector<int> res;
        while(n > 1) {
            res.emplace_back(lpf[n]);
            n /= lpf[n];
        }
        return res;
    }
    vector<pair<int, int>> factor_count(int n) {
        vector<pair<int, int>> res;
        while(n > 1) {
            if(res.empty() or res.back().first != lpf[n])
                res.emplace_back(lpf[n], 0);
            ++res.back().second;
            n /= lpf[n];
        }
        return res;
    }
};