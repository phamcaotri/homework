//#include "input.h"
//using namespace adv;

#include <iostream>
#include <cstdarg>
#include <algorithm>
#include <vector>
using namespace std;

template<typename... Type>
void input(Type&... a) {
  (cin >> ... >> a);
}

template<typename... Type>
void input2(Type&... a) {
  ((cin >> a), ...);
}

template<typename... Type>
void output(Type... a) {
    ((cout << a), ...);
}

template<typename... Type>
auto sum(Type... a) {
    return (a + ...);
}


template<typename... Type>
auto Max(Type... a) {
    auto max = (a, ...);
    ((max = (max > a ? max : a)), ...);
    return max;
}

template<typename... Type>
auto Min(Type... a) {
    auto min = (a, ...);
    ((min = (min < a ? min : a)), ...);
    return min;
}

template<typename... Type>
auto Avg(Type... a) {
    return (a + ...) / sizeof...(a);
}




int main() {
    int a = 0;
    input(a);
    float b, c;
    input(b, c);
    output("ket qua ", b, " + ", c, " = ", b + c, "\n");
    output("ket qua ", b, " - ", c, " = ", b - c, "\n");
    output("tong cua: ", b, " + ", c, " + ", a, " = ", sum(b, c, a), "\n");
    output("max cua: ", b, " va ", c, " va ", a, " = ", Max(b, c, a), "\n");
    output("min cua: ", b, " va ", c, " va ", a, " = ", Min(b, c, a), "\n");
    output("avg cua: ", b, " va ", c, " va ", a, " = ", Avg(b, c, a), "\n");
    return 0;
}