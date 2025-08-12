// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/aho_corasick
#include "../../../string/aho-corasick.hpp"
#include "../../../template.hpp"
// こういう問題ならポインタで管理しないほうがいいな...
void solve() {
    INT(n);
    AhoCorasick<> aho;
    using pNode = decltype(aho)::pNode;
    vector<int> v(n);
    rep(i, n) {
        STR(s);
        v[i] = aho.add(s)->id;
    }
    aho.build();
    vector<int> p(aho.cur_id), s(aho.cur_id);
    queue<pNode> que;
    que.push(aho.root);
    while(!que.empty()) {
        auto cur = que.front();
        que.pop();
        rep(i, 26) {
            if(cur->ch[i]) {
                p[cur->ch[i]->id] = cur->id;
                s[cur->ch[i]->id] = cur->ch[i]->fail->id;
                que.push(cur->ch[i]);
            }
        }
    }
    print(p.size());
    rep(i, 1, p.size()) { print(p[i], s[i]); }
    print(v);
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    solve();
}