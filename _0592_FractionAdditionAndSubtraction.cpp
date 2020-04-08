#include "headers.hpp"
#include <string>
#include <sstream>
#include <math.h>
#include <numeric>

std::string fractionAddition(std::string expression) {
    std::istringstream in(expression);
    int A = 0, B = 1, a, b;
    char _;
    while (in >> a >> _ >> b) {
        A = A * b + a * B;
        B *= b;
        int g = std::abs(std::gcd(A, B));
        A /= g;
        B /= g;
    }
    return std::to_string(A) + '/' + std::to_string(B);
}