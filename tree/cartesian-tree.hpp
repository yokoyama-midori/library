#include "template.hpp"
// a : distinct
// p[root] = -1
template <class T> vector<int> cartesian_tree(const vector<T> &a) {
    int n = a.size();
    vector<int> p(n);
    stack<T> s;
    rep(i, n) {
        int prev = -1;
        while(s.size() and a[s.top()] > a[i]) {
            prev = s.top();
            s.pop();
        }
        p[i] = s.size() ? s.top() : -1;
        if(prev != -1)
            p[prev] = i;
        s.push(i);
    }
    return p;
}