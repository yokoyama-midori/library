#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"
#include "graph/cycle-detection.hpp"
void solve() {
    INT(n, m);
    Graph<bool> g(n);
    g.read(m, 0, 0, 1);
    auto cycle = cycle_detection(g);
    if(cycle.empty()) {
        print(-1);
        return;
    }
    print(cycle.size());
    for(auto i : cycle)
        print(i.idx);
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
