#pragma once
#include "../template.hpp"
template <class Val> struct HashMap {
    int sz, mask, cnt;
    vector<bool> used;
    vector<u64> keys;
    vector<Val> vals;
    explicit HashMap(unsigned n = 8)
        : sz(bit_ceil(2 * n)), mask(sz - 1), cnt(0), used(sz, false),
          keys(sz, 0), vals(sz, Val{}) {}

    Val &operator[](const u64 &key) {
        if(cnt * 2 >= sz) {
            reallocate();
        }
        int i = index(key);
        if(!used[i]) {
            used[i] = true;
            keys[i] = key;
            cnt++;
        }
        return vals[i];
    }
    bool contains(const u64 &key) const { return used[index(key)]; }

  private:
    int find_next(int i) const {
        while(i < sz and !used[i]) {
            i++;
        }
        return i;
    }

  public:
    template <bool IsConst> struct basic_iterator {
        using iterator_category = forward_iterator_tag;
        using value_type = pair<const u64, Val>;
        using difference_type = ptrdiff_t;
        using map_pointer = conditional_t<IsConst, const HashMap *, HashMap *>;
        using value_reference = conditional_t<IsConst, const Val &, Val &>;

      private:
        map_pointer map_ptr_;
        int current_idx_;

        friend struct basic_iterator<!IsConst>;

      public:
        basic_iterator() : map_ptr_(nullptr), current_idx_(0) {}
        basic_iterator(map_pointer ptr, int idx)
            : map_ptr_(ptr), current_idx_(idx) {}

        // iteratorからconst_iteratorへの変換
        template <bool OtherIsConst>
        basic_iterator(const basic_iterator<OtherIsConst> &other)
            requires(IsConst and !OtherIsConst)
            : map_ptr_(other.map_ptr_), current_idx_(other.current_idx_) {}

        auto operator*() const {
            return pair<const u64 &, value_reference>(
                map_ptr_->keys[current_idx_], map_ptr_->vals[current_idx_]);
        }

        basic_iterator &operator++() {
            current_idx_ = map_ptr_->find_next(current_idx_ + 1);
            return *this;
        }

        basic_iterator operator++(int) {
            basic_iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        template <bool OtherIsConst>
        bool operator==(const basic_iterator<OtherIsConst> &other) const {
            return current_idx_ == other.current_idx_;
        }

        template <bool OtherIsConst>
        bool operator!=(const basic_iterator<OtherIsConst> &other) const {
            return !(*this == other);
        }
    };

    using iterator = basic_iterator<false>;
    using const_iterator = basic_iterator<true>;

    iterator begin() { return iterator(this, find_next(0)); }
    iterator end() { return iterator(this, sz); }
    const_iterator begin() const { return const_iterator(this, find_next(0)); }
    const_iterator end() const { return const_iterator(this, sz); }
    const_iterator cbegin() const { return const_iterator(this, find_next(0)); }
    const_iterator cend() const { return const_iterator(this, sz); }

    int size() const { return cnt; }

  private:
    int hash(u64 x) const {
        // https://judge.yosupo.jp/submission/186759
        static const u64 r =
            chrono::steady_clock::now().time_since_epoch().count();
        x += r;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return (x ^ (x >> 31)) & mask;
    }
    int index(const u64 &key) const {
        int i = hash(key);
        while(used[i] and keys[i] != key) {
            i = (i + 1) & mask;
        }
        return i;
    }
    void reallocate() {
        int old_sz = sz;
        sz <<= 1;
        mask = sz - 1;
        cnt = 0;

        // Unqualified call to 'std::move' (fix
        // available)clang(-Wunqualified-std-cast-call)　<-std::をつけないと警告出る
        vector<u64> old_keys = std::move(keys);
        vector<Val> old_vals = std::move(vals);
        vector<bool> old_used = std::move(used);

        keys.assign(sz, 0);
        vals.assign(sz, Val{});
        used.assign(sz, false);

        for(int i = 0; i < old_sz; ++i) {
            if(old_used[i]) {
                (*this)[old_keys[i]] = move(old_vals[i]);
            }
        }
    }
};