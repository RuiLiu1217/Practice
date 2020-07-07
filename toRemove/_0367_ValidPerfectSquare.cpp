#include "headers.hpp"
// Newtown method
bool LeetCode::_0367_ValidPerfectSquare::isPerfectSquare(int x) {
    long r = x;
    while(r * r > x) {
        r = (r + x / r) / 2;
    }
    return r * r == x;
}