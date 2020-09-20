#include "headers.hpp"
#include <cmath>
int LeetCode::_0441_ArrangingCoins::arrangeCoins(int n) {
    double appo = std::sqrt(static_cast<double>(n) * 2.0 + 0.25);
    return std::floor(appo - 0.5);
}