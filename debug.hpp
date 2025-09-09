#include "./other/type-utils.hpp"
/*
    - Streamable(string含む) -> そのまま出力
    - is_modint(.val()->int) -> .val()して出力
    以下のものは順に再帰的に出力する
    - pair,tuple
    - ranges::begin(),ranges::end()が使える型(vector,deque,set,map,....)
*/
template <class... Args> void debug_print(const std::tuple<Args...> &);
template <std::ranges::range Iterable>
    requires(!Streamable<Iterable>)
void debug_print(const Iterable &);

template <Streamable T> void debug_print(const T &value) { std::cerr << value; }
template <is_modint mint>
    requires(!Streamable<mint>)
void debug_print(const mint &value) {
    std::cerr << value.val();
}
template <class F, class S> void debug_print(const std::pair<F, S> &value) {
    std::cerr << "[";
    debug_print(value.first);
    std::cerr << ", ";
    debug_print(value.second);
    std::cerr << "]";
}
template <size_t N = 0, class T> void enum_tuple(const T &value) {
    if constexpr(N < std::tuple_size<T>::value) {
        const auto &x = get<N>(value);
        debug_print(x);
        if(N + 1 < std::tuple_size<T>::value) {
            std::cerr << ", ";
            enum_tuple<N + 1, T>(value);
        }
    }
}
template <class... Args> void debug_print(const std::tuple<Args...> &value) {
    std::cerr << "[";
    enum_tuple(value);
    std::cerr << "]";
}
template <std::ranges::range Iterable>
    requires(!Streamable<Iterable>)
void debug_print(const Iterable &v) {
    std::cerr << "[";
    for(auto itr = std::ranges::begin(v); itr != std::ranges::end(v); itr++) {
        if(itr != std::ranges::begin(v))
            std::cerr << ", ";
        debug_print(*itr);
    }
    std::cerr << "]";
}

#include <boost/preprocessor.hpp>

#define DEBUG_PRINT_VAR_I(r, data, i, elem)                                    \
    std::cerr << BOOST_PP_STRINGIZE(elem) << ": ";                             \
    debug_print(elem);                                                         \
    std::cerr << BOOST_PP_IF(                                                  \
        BOOST_PP_NOT_EQUAL(i, BOOST_PP_DEC(BOOST_PP_SEQ_SIZE(data))), ", ",    \
        "");

#define debug(...)                                                             \
    do {                                                                       \
        BOOST_PP_SEQ_FOR_EACH_I(DEBUG_PRINT_VAR_I,                             \
                                BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__),         \
                                BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))         \
        std::cerr << std::endl;                                                \
    } while(0)
