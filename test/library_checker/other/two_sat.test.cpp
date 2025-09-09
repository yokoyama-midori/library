// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/two_sat
#include "../../../other/twosat.hpp"
#include "../../../template.hpp"
void solve() {
    string tmp;
    input(tmp, tmp);
    INT(n, m);
    TwoSat ts(n);
    rep(m) {
        INT(a, b, c);
        ts.add_clause(abs(a) - 1, a > 0, abs(b) - 1, b > 0);
    }
    auto f = ts.satisfiable();
    if(f) {
        print("s SATISFIABLE");
        write("v ");
        for(int i = 0; i < n; ++i) {
            write(ts.ans[i] ? i + 1 : -i - 1);
            write(' ');
        }
        print(0);
    } else {
        print("s UNSATISFIABLE");
    }
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    solve();
}
