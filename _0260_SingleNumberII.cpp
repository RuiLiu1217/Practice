#include "headers.hpp"
#include <algorithm>
 std::vector<int> LeetCode::_0260_SingleNumberII::singleNumber(const std::vector<int> &nums) {
    int r = 0;
    std::for_each(begin(nums),end(nums), [&](auto n){ r ^= n;});
    int lasDigit = r & (~(r - 1));
    
    std::vector<int> ret(2, 0);
    std::for_each(begin(nums), end(nums), [&](auto n){
        ret[(lasDigit & n) == 0] ^= n;
    });
    return ret;
}