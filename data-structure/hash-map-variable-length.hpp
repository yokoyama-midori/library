#pragma once
#include "../template.hpp"
template <class Val> struct HashMap {
    int sz, mask, cnt;
    vector<bool> used;
    vector<ll> keys;
    vector<Val> vals;
    HashMap(int n = 1) {
        sz = 1;
        while(sz < 2 * n) {
            sz <<= 1;
        }
        mask = sz - 1;
        cnt = 0;
        keys.resize(sz);
        vals.resize(sz);
        used.resize(sz);
    }

    Val &operator[](const ll &key) {
        if(cnt * 2 >= sz) {
            reallocate();
        }
        ll i = index(key);
        if(!used[i]) {
            used[i] = true;
            keys[i] = key;
            cnt++;
        }
        return vals[i];
    }
    bool contains(const ll &key) {
        ll i = index(key);
        return used[i];
    }
    // for(auto [key,val]:mp.enumerate()){}
    // みたいに書いたときにvalを変更したいがこの書き方でいい?
    vector<pair<ll, Val &>> enumerate() {
        vector<pair<ll, Val &>> res;
        rep(i, sz) {
            if(used[i]) {
                res.push_back({keys[i], vals[i]});
            }
        }
        return res;
    }
    int size() const { return cnt; }

  private:
    int hash(ll x) {
        // https://judge.yosupo.jp/submission/186759
        static const ll r =
            std::chrono::steady_clock::now().time_since_epoch().count();
        x += r;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return (x ^ (x >> 31)) & mask;
    }
    int index(const ll &key) {
        ll i = hash(key);
        while(used[i] and keys[i] != key) {
            i = (i + 1) & mask;
        }
        return i;
    }
    void reallocate() {
        ll old_sz = sz;
        sz <<= 1;
        mask = sz - 1;
        cnt = 0;

        vector<ll> old_keys;
        vector<Val> old_vals;
        vector<bool> old_used;
        keys.swap(old_keys);
        vals.swap(old_vals);
        used.swap(old_used);
        keys.resize(sz);
        vals.resize(sz);
        used.resize(sz);

        rep(i, old_sz) {
            if(old_used[i]) {
                ll key = old_keys[i];
                Val val = old_vals[i];
                (*this)[key] = val;
            }
        }
        return;
    }
};