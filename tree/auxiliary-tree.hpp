#pragma once
#include "tree/euler-tour.hpp"
// https://smijake3.hatenablog.com/entry/2019/09/15/200200#%E3%82%BD%E3%83%BC%E3%83%882%E5%9B%9E%E3%81%AE%E6%96%B9%E6%B3%95
// https://nyaannyaan.github.io/library/tree/auxiliary-tree.hpp
template <class G> struct AuxiliaryTree {
    G g;
    EulerTour<G> et;
    AuxiliaryTree(G &g) : g(g), et(g) {}
    AuxiliaryTree(G &g, EulerTour<G> &et) : g(g), et(et) {}

    // 頂点集合vsを受け取り
    // {aux tree,vs:aux treeの頂点番号->gでの頂点番号}を返す
    // aux tree : 親->子のみ含まれる
    // N = size(g),M=size(vs)として
    // O(M log N) 
    // LCAを高速化すれば O(M log M)
    template <class T> pair<vector<vector<T>>, vector<T>> get(vector<T> vs) {
        if(vs.empty())
            return {};
        auto comp = [&](T i, T j) { return et.in[i] < et.in[j]; };
        sort(all(vs), comp);
        for(int i = 1, sz = vs.size(); i < sz; i++) {
            vs.push_back(et.lca(vs[i - 1], vs[i]));
        }
        sort(all(vs), comp);
        vs.erase(unique(all(vs)), end(vs));
        vector<vector<T>> aux(vs.size());
        stack<T> st;
        st.push(0);
        rep(i, 1, vs.size()) {
            while(et.out[vs[st.top()]] < et.in[vs[i]]) {
                st.pop();
            }
            aux[st.top()].push_back(i);
            st.push(i);
        }
        return {aux, vs};
    }
};
