#include "headers.hpp"

// 典型的数论题目，会的话就很容易，不会的话就超级难。考察中国剩余定理
bool LeetCode::_1250_CheckIfItIsAGoodArray::isGoodArray(std::vector<int>& nums) {
    int g = nums[0];
    for(int i = 1; i < nums.size(); ++i) {
        g = gcd(g, nums[i]);
        if(g == 1) {
            return true;
        }
    }
    return g == 1;
}

int LeetCode::_1250_CheckIfItIsAGoodArray::gcd(int a, int b) {
    if(a < b) {
        return this->gcd(b, a);
    }
    if(a % b == 0) {
        return b;
    } else {
        return this->gcd(b, a % b);
    }
}