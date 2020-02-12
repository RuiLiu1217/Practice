#include "headers.hpp"

int LeetCode::_0258_AddDigits::addDigits(int num) {
    if(num == 0) {
        return 0;
    }
    int v = (num % 9);
    return v == 0 ? 9 : v;
}