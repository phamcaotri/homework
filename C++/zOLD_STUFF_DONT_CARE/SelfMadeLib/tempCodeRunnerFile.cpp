template<typename... Type>
auto Max(Type... a) {
    auto list = (a, ...);
}