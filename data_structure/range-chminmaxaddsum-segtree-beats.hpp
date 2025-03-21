#include "../data_structure/segtree-beats.hpp"
#include "../template.hpp"
namespace RangeChMinMaxAddSum {
struct S {
    ll min, min2, max, max2;
    // min2,max2は2番目の最小最大,但し値が1種類のときは全部一致させる
    // 値が2種類のときmin == max2 and max == min2でありmappingの際は注意が必要
    ll sz, szmin, szmax, sum;
    bool fail;
    S(ll x, ll sz = 1)
        : min(x), min2(x), max(x), max2(x), sum(x * sz), sz(sz), fail(false),
          szmin(sz), szmax(sz) {};
    S()
        : min(inf), min2(inf), max(-inf), max2(-inf), sz(0), szmin(0), szmax(0),
          sum(0), fail(false) {}

    bool operator==(const S &other) const {
        return min == other.min and min2 == other.min2 and max == other.max and
               max2 == other.max2 and sz == other.sz and
               szmin == other.szmin and szmax == other.szmax and
               sum == other.sum;
    }
};
S e() {
    S res(0, 0);
    res.min = res.min2 = inf, res.max = res.max2 = -inf;
    res.fail = false;
    return res;
};
void chmin2(ll &m, ll &m2, ll val) {
    if(val < m) {
        m2 = m, m = val;
    } else if(m < val and val < m2) {
        m2 = val;
    }
}
ll second_lowest(S &a, S &b) {
    ll m = inf, m2 = inf;
    chmin2(m, m2, a.min), chmin2(m, m2, a.min2), chmin2(m, m2, b.min),
        chmin2(m, m2, b.min2);
    return (m2 == inf ? m : m2);
}
ll second_heighest(S &a, S &b) {
    ll m = inf, m2 = inf;
    chmin2(m, m2, -a.max), chmin2(m, m2, -a.max2), chmin2(m, m2, -b.max),
        chmin2(m, m2, -b.max2);
    return (m2 == inf ? -m : -m2);
}
S op(S a, S b) {
    if(a.fail)
        return a;
    if(b.fail)
        return b;
    S res;
    res.min = min(a.min, b.min);
    res.max = max(a.max, b.max);
    res.min2 = second_lowest(a, b);
    res.max2 = second_heighest(a, b);
    res.sum = a.sum + b.sum;
    res.sz = a.sz + b.sz;
    res.szmin = a.szmin * (a.min == res.min) + b.szmin * (b.min == res.min);
    res.szmax = a.szmax * (a.max == res.max) + b.szmax * (b.max == res.max);
    return res;
}
struct F {
    // min -> max -> add の順
    ll min, max, add;
    bool operator==(const F &other) const {
        return min == other.min && max == other.max && add == other.add;
    }
};
F id() { return F(inf, -inf, 0); }
S mapping(F f, S s) {
    if(s.fail or f == id())
        return s;
    if(s.sz == 1) {
        ll x = s.min;
        chmin(x, f.min);
        chmax(x, f.max);
        x += f.add;
        return S(x, s.sz);
    }
    // f.min
    if(f.min > s.max2) {
        // f.minを処理できる
        ll dif = min(0LL, f.min - s.max);
        s.sum += dif * s.szmax;
        s.max += dif;
        if(s.min2 + dif == s.max) {
            s.min2 = s.max;
        }
    } else if(f.min <= s.min) {
        // 全部x
        ll x = max(f.max, f.min) + f.add;
        return S(x, s.sz);
    } else {
        s.fail = true;
        return s;
    }
    // f.max
    if(f.max < s.min2) {
        ll dif = max(0LL, f.max - s.min);
        s.sum += dif * s.szmin;
        s.min += dif;
        if(s.max2 + dif == s.min) {
            s.max2 = s.min;
        }
    } else if(f.max >= s.max) {
        return S(f.max + f.add, s.sz);
    } else {
        s.fail = true;
        return s;
    }
    s.min += f.add, s.min2 += f.add, s.max += f.add, s.max2 += f.add;
    s.sum += f.add * s.sz;
    return s;
}
F composition(F f, F g) {
    F res;
    if(f == id())
        return g;
    if(g == id())
        return f;
    res.min = min(g.min, f.min - g.add);
    res.max = max(g.max, f.max - g.add);
    if(g.max >= f.min - g.add) {
        res.min = res.max = f.min - g.add;
    }
    if(f.max - g.add >= g.min) {
        res.min = res.max = f.max - g.add;
    }
    res.add = f.add + g.add;
    return res;
}
using segtree = segtree_beats<S, op, e, F, mapping, composition, id>;
} // namespace RangeChMinMaxAddSum
using RangeChMinMaxAddSum::F;
using RangeChMinMaxAddSum::S;
using RangeChMinMaxAddSum::segtree;