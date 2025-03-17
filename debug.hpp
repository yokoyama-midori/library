#include <bits/stdc++.h>
using namespace std;
string trim_whitespace(const string &str) {
    string result = str;
    erase_if(result, [](char c) { return isspace(c); });
    return result;
}
/*
    Streamable(string含む) -> そのまま出力
    - is_modint(.val()->int) -> .val()して出力
    以下のものは順に再帰的に出力する
    - pair,tuple
    -ranges::begin(),ranges::end()が使える型(vector,deque,set,map,....)
*/
template <class... Args> void debug_print(const tuple<Args...> &);
template <ranges::range Iterable>
    requires(!Streamable<Iterable>)
void debug_print(const Iterable &);

template <Streamable T> void debug_print(const T &value) { cout << value; }
template <is_modint mint>
    requires(!Streamable<mint>)
void debug_print(const mint &value) {
    cout << value.val();
}
template <class F, class S> void debug_print(const pair<F, S> &value) {
    cout << "[";
    debug_print(value.first);
    cout << ", ";
    debug_print(value.second);
    cout << "]";
}
template <size_t N = 0, class T> void enum_tuple(const T &value) {
    if constexpr(N < tuple_size<T>::value) {
        const auto &x = get<N>(value);
        debug_print(x);
        if(N + 1 < tuple_size<T>::value) {
            cout << ", ";
            enum_tuple<N + 1, T>(value);
        }
    }
}
template <class... Args> void debug_print(const tuple<Args...> &value) {
    cout << "[";
    enum_tuple(value);
    cout << "]";
}
template <ranges::range Iterable>
    requires(!Streamable<Iterable>)
void debug_print(const Iterable &v) {
    cout << "[";
    for(auto itr = v.begin(); itr != v.end(); itr++) {
        if(itr != v.begin())
            cout << ", ";
        debug_print(*itr);
    }
    cout << "]";
}

template <typename T> void debug_impl(const string &names, const T &value) {
    string name = trim_whitespace(names);
    cout << name << ": ";
    debug_print(value);
    cout << endl;
}

template <typename T, typename... Args>
void debug_impl(const string &names, const T &head, const Args &...rest) {
    size_t pos = names.find(',');
    string name = trim_whitespace(names.substr(0, pos));
    cout << name << ": ";
    debug_print(head);
    cout << ", ";
    debug_impl(names.substr(pos + 1), rest...);
}
#define debug(...) debug_impl(#__VA_ARGS__, __VA_ARGS__)