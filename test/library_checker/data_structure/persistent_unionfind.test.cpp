// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/persistent_unionfind
#include "data_structure/union-find-with-undo.hpp"
void solve() {
    INT(n, q);
    UnionFindWithUndo dsu(n);
    vector ch(q + 1, vector<int>());
    vector<pair<int, int>> mg(q + 1, {0, 0});
    vector<vector<tuple<int, int, int>>> query(q + 1);
    vector<int> ans(q + 1, -1);
    rep(i, 1, q + 1) {
        INT(t, k, x, y);
        ++k;
        if(!t) {
            ch[k].push_back(i);
            mg[i] = {x, y};
        } else {
            query[k].emplace_back(i, x, y);
        }
    }
    auto dfs = [&](auto &&dfs, int cur) -> void {
        dsu.merge(mg[cur].first, mg[cur].second);
        for(auto [i, x, y] : query[cur]) {
            ans[i] = dsu.same(x, y);
        }
        for(auto nex : ch[cur])
            dfs(dfs, nex);
        dsu.undo();
        return;
    };
    dfs(dfs, 0);
    for(auto ai : ans)
        if(ai != -1)
            print(ai);
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
