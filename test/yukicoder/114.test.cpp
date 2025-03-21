// competitive-verifier: PROBLEM https://yukicoder.me/problems/114
#include "../../data_structure/union-find.hpp"
#include "../../graph/graph-template.hpp"
#include "../../graph/minimum-steiner-tree.hpp"
void solve() {
    INT(n, m, t);
    if(t <= 15) {
        Graph<int> g(n);
        g.read(m, -1, true);
        vector<int> term(t);
        for(auto &ti : term) {
            cin >> ti;
            --ti;
        }
        MinimumSteinerTree<int> mst(g, term);
        print(mst.cost);
    } else {
        using T = tuple<int, int, int>;
        vector<T> edge(m);
        rep(i, m) {
            INT(a, b, c);
            edge[i] = T(c, --a, --b);
        }
        ranges::sort(edge);
        vector<int> oth(n, -2);
        vector<int> term(t);
        {
            rep(i, t) {
                INT(ti);
                oth[--ti] = -1;
                term[i] = ti;
            }
            int sz = 0;
            rep(i, n) {
                if(oth[i] == -2)
                    oth[i] = sz++;
            }
        }
        int ans = numeric_limits<int>::max();
        rep(bit, 1 << (n - t)) {
            UnionFind uf(n);
            int cost = 0;
            for(auto [c, a, b] : edge) {
                if(uf.same(a, b) or (oth[a] >= 0 and (~bit >> (oth[a])) & 1) or
                   (oth[b] >= 0 and (~bit >> (oth[b])) & 1))
                    continue;
                cost += c;
                uf.merge(a, b);
            }
            bool flag = true;
            rep(i, 1, t) {
                if(!uf.same(term[0], term[i])) {
                    flag = false;
                    break;
                }
            }
            if(flag)
                chmin(ans, cost);
        }
        print(ans);
    }
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
