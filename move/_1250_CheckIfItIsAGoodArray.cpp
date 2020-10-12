#include "headers.hpp"

// 典型的数论题目，会的话就很容易，不会的话就超级难。考察中国剩余定理
bool LeetCode::_1250_CheckIfItIsAGoodArray::isGoodArray(std::vector<int>& nums) {
    int g = nums[0];
    for(int i = 1; i < nums.size(); ++i) {
        g = std::gcd(g, nums[i]);
        if(g == 1) {
            return true;
        }
    }
    return g == 1;
}
