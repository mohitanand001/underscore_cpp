#ifndef TEST_INCLUDES_H

#include "catch.hpp"
#include "underscore.hpp"

#include <iostream>

inline void display(int x) {
    std::cout << x << " ";
}

inline int incr(int x) {
    x = x + 1;
    return x;
}

inline int mulp(int x) {
    return x * 10;
}

inline bool is_odd(int x) {
    return x % 2 == 1;
}

inline int multiply(int x, int y) {
    return x * y;
}

#endif //TEST_INCLUDES_H
