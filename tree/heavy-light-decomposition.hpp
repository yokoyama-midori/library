// https://github.com/kth-competitive-programming/kactl/blob/main/content/graph/HLD.h
// https://nyaannyaan.github.io/library/tree/heavy-light-decomposition.hpp
#include "../template.hpp"
template <class G> struct HLD {
    int n;
    G &g;
    vector<int> sz, in, par, root;
    HLD(G &g)
        : n(g.size()), g(g), sz(n, 1), in(n), par(n, -1), root(n, -1), id(0) {
        dfs_sz(0, -1);
        dfs_hld(0);
    };
    // 行きがけ順に並べた列に対するO(log n)回の操作に変換する
    template <class F> void path_query(int u, int v, F &&f, bool vertex = true) {
        for(;; v = par[root[v]]) {
            if(in[u] > in[v])
                swap(u, v);
            if(root[u] == root[v])
                break;
            f(in[root[v]], in[v] + 1);
        }
        f(in[u] + !vertex, in[v] + 1);
    }
    // edge未対応
    template <class F>
    void path_query_noncommutative(int u, int v, F &&f, bool vertex = true) {
        assert(vertex);
        bool flip = false;
        vector<int> l, r;
        for(;; v = par[root[v]]) {
            if(in[u] > in[v]) {
                flip = !flip;
                swap(u, v);
                swap(l, r);
            }
            if(root[u] == root[v])
                break;
            r.emplace_back(v);
            r.emplace_back(root[v]);
        }
        if(flip) {
            swap(u, v);
            swap(l, r);
        }
        r.emplace_back(v);
        r.emplace_back(u);
        for(int i = 0; i + 1 < ssize(l); i += 2) {
            f(in[l[i]], in[l[i + 1]]);
        }
        for(int i = ssize(r) - 1; i > 0; i -= 2) {
            f(in[r[i]], in[r[i - 1]]);
        }
    }

  private:
    int id;
    void dfs_sz(int cur, int p) {
        for(int i = 0; i < ssize(g[cur]); ++i) {
            auto &to = g[cur][i];
            if(p == to) {
                swap(to, g[cur].back());
                g[cur].pop_back();
                --i;
                continue;
            }
            par[to] = cur;
            dfs_sz(to, cur);
            sz[cur] += sz[to];
            if(sz[to] > sz[g[cur][0]])
                swap(to, g[cur][0]);
        }
    }
    void dfs_hld(int cur) {
        in[cur] = id++;
        for(auto &to : g[cur]) {
            root[to] = (g[cur].front() == to) ? root[cur] : to;
            dfs_hld(to);
        }
    }
};