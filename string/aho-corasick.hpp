#include "template.hpp"
/**
 * @brief Aho-Corasick
 * @see https://atcoder.jp/contests/abc268/submissions/34765119 解説放送も
 * buildを呼ぶ
 * failuere/suffix linkを作るのが本質
 * buildする際のlinkをたどる回数はaddした文字列の長さの総和で抑えられるっぽい？
 * 任意のオートマトン与えたときに頂点数では抑えられなさそう？
 * いろんな文字出てくるときはハッシュマップを使う
 */
template <int char_size = 26, char base = 'a'> struct AhoCorasick {
    struct Node;
    using pNode = Node *;
    struct Node {
        ll cnt = 0;
        pNode fail;
        array<pNode, char_size> ch{};
    };
    pNode root;
    AhoCorasick() { root = new_node(); }
    pNode add(const string &s) {
        pNode cur = root;
        for(auto &cc : s) {
            int c = cc - base;
            assert(0 <= c and c < char_size);
            if(!cur->ch[c]) {
                cur->ch[c] = new_node();
            }
            cur = cur->ch[c];
        }
        cur->cnt += 1;
        return cur;
    }
    // vの末尾にcを追加したときのsuffix最長のノードに遷移
    pNode operator()(pNode v, int c) const {
        while(v) {
            if(v->ch[c]) {
                return v->ch[c];
            }
            v = v->fail;
        }
        return root;
    }
    void build() {
        queue<pNode> que;
        for(que.push(root); !que.empty(); que.pop()) {
            pNode cur = que.front();
            for(int i = 0; i < char_size; ++i) {
                pNode ch = cur->ch[i];
                if(!ch)
                    continue;
                ch->fail = (*this)(cur->fail, i);
                ch->cnt += ch->fail->cnt;
                que.push(ch);
            }
        }
    }

  private:
    pNode new_node() {
        pool.emplace_back(make_unique<Node>());
        return pool.back().get();
    }
    vector<unique_ptr<Node>> pool;
};