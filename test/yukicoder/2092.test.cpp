#define PROBLEM "https://yukicoder.me/problems/no/2092"
#include "dp/cumulative-sum.hpp"
#include "template.hpp"
void solve() {
    LL(n);
    CumulativeSum cs(1e5 + 1);
    cs.add(0, n);
    while(n--) {
        LL(a);
        cs.add(a, -1);
    }
    cs.build();
    vl ans;
    rep1(i, 1e5) {
        if(cs.sum(i) == 0)
            break;
        ans.push_back(cs.sum(i));
    }
    print(ans);
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}