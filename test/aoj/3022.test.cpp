// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/3022
#include "../../graph/block-cut-tree.hpp"
#include "../../graph/graph-template.hpp"
#include "../../template.hpp"
void solve() {
    INT(n, m);
    vector<ll> v(n);
    input(v);
    Graph<bool> g(n);
    g.read(m);
    auto bct = block_cut_tree(g);
    int N = bct.size();
    vector<ll> sub = v;
    sub.resize(N, 0);
    vector<int> par(N, -1);
    auto dfs = [&](auto &dfs, int cur, int p) -> ll {
        par[cur] = p;
        for(auto &to : bct[cur]) {
            if(to != p) {
                sub[cur] += dfs(dfs, to, cur);
            }
        }
        return sub[cur];
    };
    ll sum = dfs(dfs, 0, -1);
    for(int i = 0; i < n; ++i) {
        ll ans = 0;
        ll tmp = 0;
        for(auto &to : bct[i]) {
            if(to != par[i]) {
                chmax(ans, sub[to]);
                tmp += sub[to];
            }
        }
        if(par[i] != -1) {
            chmax(ans, sum - tmp - v[i]);
        }
        print(ans);
    }
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    solve();
}