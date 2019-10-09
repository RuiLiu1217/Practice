#include "headers.hpp"
#include <algorithm>
 std::vector<int> LeetCode::_0260_SingleNumberII::singleNumber(const std::vector<int> &nums)
{
    int r = 0;
    const int n = nums.size();
    int i = 0;
    int lastBit = 0;
    std::vector<int> ret(2, 0);
    std::for_each(nums.begin(), nums.end(), [&](auto n) { r ^= n; });

    lastBit = r & (~(r - 1)); // Get the last one bit;
    std::for_each(nums.begin(), nums.end(), [&](auto n) {
        ret[(lastBit & n) == 0] ^= n;
    });

    return ret;
}