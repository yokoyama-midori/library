// competitive-verifier: PROBLEM https://yukicoder.me/problems/no/3206
#include "../../graph/graph-template.hpp"
#include "../../template.hpp"
#include "../../tree/rerooting.hpp"
int main() {
    using Data = vi;
    using Cost = int;
    INT(n);
    Graph<Cost> g(n);
    g.read(n - 1);
    Data leaf = {0};
    auto merge = [](Data a, Data b) {
        if(b.size() > a.size())
            swap(a, b);
        a.insert(end(a), begin(b), end(b));
        return a;
    };
    auto apply = [](Data data, int /*from*/, int /*to*/, Cost /*cost*/) {
        return Data({ranges::max(data) + 1});
    };
    Rerooting<Data, decltype(g), decltype(merge), decltype(apply)> dp(
        g, merge, apply, leaf);
    int ans = 0;
    for(auto &vi : dp.dp) {
        ranges::sort(vi, greater());
        rep(i, ssize(vi)) { chmax<int>(ans, 1 + (i + 1) * vi[i]); }
    }
    print(ans);
}