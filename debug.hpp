#include <bits/stdc++.h>
using namespace std;
string trim_whitespace(const string &str) {
    string result = str;
    erase_if(result, [](char c) { return isspace(c); });
    return result;
}
/*
    - Streamable(string含む) -> そのまま出力
    - is_modint(.val()->int) -> .val()して出力
    以下のものは順に再帰的に出力する
    - pair,tuple
    - ranges::begin(),ranges::end()が使える型(vector,deque,set,map,....)
*/
template <class... Args> void debug_print(const tuple<Args...> &);
template <ranges::range Iterable>
    requires(!Streamable<Iterable>)
void debug_print(const Iterable &);

template <Streamable T> void debug_print(const T &value) { cerr << value; }
template <is_modint mint>
    requires(!Streamable<mint>)
void debug_print(const mint &value) {
    cerr << value.val();
}
template <class F, class S> void debug_print(const pair<F, S> &value) {
    cerr << "[";
    debug_print(value.first);
    cerr << ", ";
    debug_print(value.second);
    cerr << "]";
}
template <size_t N = 0, class T> void enum_tuple(const T &value) {
    if constexpr(N < tuple_size<T>::value) {
        const auto &x = get<N>(value);
        debug_print(x);
        if(N + 1 < tuple_size<T>::value) {
            cerr << ", ";
            enum_tuple<N + 1, T>(value);
        }
    }
}
template <class... Args> void debug_print(const tuple<Args...> &value) {
    cerr << "[";
    enum_tuple(value);
    cerr << "]";
}
template <ranges::range Iterable>
    requires(!Streamable<Iterable>)
void debug_print(const Iterable &v) {
    cerr << "[";
    for(auto itr = v.begin(); itr != v.end(); itr++) {
        if(itr != v.begin())
            cerr << ", ";
        debug_print(*itr);
    }
    cerr << "]";
}

template <typename T> void debug_impl(const string &names, const T &value) {
    string name = trim_whitespace(names);
    cerr << name << ": ";
    debug_print(value);
    cerr << endl;
}

template <typename T, typename... Args>
void debug_impl(const string &names, const T &head, const Args &...rest) {
    size_t pos = names.find(',');
    string name = trim_whitespace(names.substr(0, pos));
    cerr << name << ": ";
    debug_print(head);
    cerr << ", ";
    debug_impl(names.substr(pos + 1), rest...);
}
#define debug(...) debug_impl(#__VA_ARGS__, __VA_ARGS__)