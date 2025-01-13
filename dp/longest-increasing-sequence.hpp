#pragma once
#include "template.hpp"
template <class T>
vector<int> longest_increasing_sequence(const vector<T> &a,
                                        bool strong = true) {
    int n = ssize(a);
    if(n == 0) {
        return {};
    }
    T infty = numeric_limits<T>::max();
    vector<T> dp(n, infty);
    vector<int> idx(n, -1);
    vector<int> previous(n, -1);
    rep(i, n) {
        int j =
            (strong ? lower_bound(all(dp), a[i]) : upper_bound(all(dp), a[i])) -
            begin(dp);
        dp[j] = a[i];
        idx[j] = i;
        if(j)
            previous[i] = idx[j - 1];
    }
    vector<int> ans;
    int now = n - 1;
    while(dp[now] == infty)
        now--;
    for(int i = idx[now]; i != -1; i = previous[i]) {
        ans.push_back(i);
    }
    reverse(all(ans));
    return ans;
}