// competitive-verifier: PROBLEM https://yukicoder.me/problems/no/654
#include "../../graph/flow/edmonds-karp.hpp"
#include "../../template.hpp"
struct flow_edge {
    int u, v, p, q;
    ll w;
};
int main() {
    INT(n, m, d);
    vector<flow_edge> g(m);
    using pii = pair<int, int>;
    vector<map<int, int>> id(n);
    int sz = 0;
    auto ins = [&](int loc, int time) {
        if(id[loc].contains(time))
            return;
        id[loc][time] = sz++;
    };
    ins(0, 0);
    ins(n - 1, numeric_limits<int>::max());
    rep(i, m) {
        INT(u, v, p, q, w);
        u--, v--, q += d;
        g[i] = flow_edge(u, v, p, q, w);
        ins(u, p);
        ins(v, q);
    }
    vector<unordered_map<int, ll>> graph(sz);
    for(auto [u, v, p, q, w] : g) {
        graph[id[u][p]][id[v][q]] += w;
    }
    rep(i, 0, n) {
        for(auto itr = begin(id[i]); itr != end(id[i]); ++itr) {
            if(itr != begin(id[i])) {
                graph[prev(itr)->second][itr->second] = inf;
            }
        }
    }
    ll ans = edmonds_karp(graph, 0, 1);
    print(ans);
}
