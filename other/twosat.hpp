#include "../graph/graph-template.hpp"
#include "../graph/strongly-connected-components.hpp"
#include "../template.hpp"
/**
 * @brief Two Satisfiability(2-SAT)
 * ac-libraryと大体同じ
 * satisfiable()を呼びtrueが返ってきた場合ansに解が入っている
 */
struct TwoSat {
    int n;
    Graph<bool> graph;
    vector<bool> ans;

    TwoSat(int n) : n(n), graph(2 * n), ans(n) {}
    void add_clause(int i, bool f, int j, bool g) {
        int x = i + (f ? 0 : n), nx = i + (f ? n : 0);
        int y = j + (g ? 0 : n), ny = j + (g ? n : 0);
        graph.add_directed_edge(nx, y);
        graph.add_directed_edge(ny, x);
    }
    bool satisfiable() {
        StronglyConnectedComponents scc(graph);
        for(int i = 0; i < n; ++i) {
            if(scc.comp[i] == scc.comp[n + i])
                return false;
            ans[i] = scc.comp[i] > scc.comp[n + i];
        }
        return true;
    }
};