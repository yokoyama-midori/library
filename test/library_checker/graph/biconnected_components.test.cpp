// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/biconnected_components
#include "../../../graph/biconnected-components.hpp"
#include "../../../graph/graph-template.hpp"
#include "../../../template.hpp"
void solve() {
    INT(n, m);
    Graph<bool> g(n);
    g.read(m, 0);
    auto groups = biconnected_components(g);
    print(groups.size());
    for(auto &v : groups) {
        write(ssize(v));
        write(" ");
        print(v);
    }
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
