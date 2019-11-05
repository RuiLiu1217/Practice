#include "headers.hpp"
#include <algorithm>
bool LeetCode::_0679_24Games::judgePoint24(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    do {
        if (valid(nums)) return true;
    } while(next_permutation(nums.begin(), nums.end()));
    return false;
}

bool LeetCode::_0679_24Games::valid(std::vector<int>& nums) {
    double a = nums[0], b = nums[1], c = nums[2], d = nums[3];
    if (valid(a+b, c, d) || valid(a-b, c, d) || valid(a*b, c, d) || valid(a/b, c, d)) return true;
    if (valid(a, b+c, d) || valid(a, b-c, d) || valid(a, b*c, d) || valid(a, b/c, d)) return true;
    if (valid(a, b, c+d) || valid(a, b, c-d) || valid(a, b, c*d) || valid(a, b, c/d)) return true;
    return false;
}
bool LeetCode::_0679_24Games::valid(double a, double b, double c) {
    if(valid(a+b, c) || valid(a-b, c) || valid(a*b, c) || (b && valid(a/b, c))) {
        return true;
    }
    if(valid(a, b+c) || valid(a, b-c) || valid(a, b*c) || (c && valid(a, b/c))) {
        return true;
    }
    return false;
}
bool LeetCode::_0679_24Games::valid(double a, double b) {
    if( std::abs(a+b-24.0) < 0.0001 ||
        std::abs(a-b-24.0) < 0.0001 ||
        std::abs(a*b-24.0) < 0.0001 ||
        (b && std::abs(a/b-24.0) < 0.0001)) {
            return true;
        }
    return false;
}