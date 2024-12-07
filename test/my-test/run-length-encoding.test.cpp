#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "string/run-length-encoding.hpp"
#include "template.hpp"
void test() {
    {
        string s = "";
        auto res = RunLengthEncoding(s);
        assert(res.empty());
    }
    {
        string s = "aabbCCabc";
        using p = pair<char, ll>;
        auto res = RunLengthEncoding(s);
        vector<p> ans = {{'a', 2}, {'b', 2}, {'C', 2},
                         {'a', 1}, {'b', 1}, {'c', 1}};
        assert(res == ans);
        s = "ZZZZZZ";
        res = RunLengthEncoding(s);
        ans = {{'Z', 6}};
        assert(res == ans);
    }
    {
        vector<int> v = {1, 2, 3, 3, 4};
        vector<pair<int, ll>> ans = {{1, 1}, {2, 1}, {3, 2}, {4, 1}};
        auto res = RunLengthEncoding(v);
        assert(res == ans);
    }
    {
        vl v = {1, 1, 2, 2, 3, 4, 5, 5, 5};
        vector<pair<ll, ll>> ans = {{1, 2}, {2, 2}, {3, 1}, {4, 1}, {5, 3}};
        auto res = RunLengthEncoding(v);
        assert(res == ans);
    }
}
void solve() {
    LL(a, b);
    print(a + b);
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    test();
    solve();
}
