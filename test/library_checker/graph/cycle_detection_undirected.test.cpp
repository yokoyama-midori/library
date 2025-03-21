// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/cycle_detection_undirected
#include "graph/cycle-detection.hpp"
void solve() {
    INT(n, m);
    Graph<bool> g(n);
    g.read(m, 0, 0, 0);
    auto cycle = cycle_detection(g);
    if(cycle.empty()) {
        print(-1);
        return;
    }
    print(cycle.size());
    for(auto i : cycle)
        cout << i.from << " ";
    cout << "\n";
    for(auto i : cycle)
        cout << i.idx << " ";
    cout << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
