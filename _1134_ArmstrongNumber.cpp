#include "headers.hpp"
// Amazon
bool LeetCode::_1134_ArmstrongNumber::isArmstrong(int N) {
    int sum = 0;
    int n = N;
    std::stack<int> d;
    int dig = 0;
    while(N) {
        ++dig;
        d.push(N % 10);
        N /= 10;
    }
    while(!d.empty()) {
        sum += std::pow(d.top(), dig);
        d.pop();
    }
    return sum == n;
}