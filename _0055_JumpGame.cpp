#include "headers.hpp"

bool LeetCode::_0055_JumpGame::canJump(std::vector<int> &nums)
{
    int t = nums.size() - 1;
    for (int i = nums.size() - 2; i >= 0; --i) {
        if (nums[i] >= t - i) {
            t = i;
        }
    }
    return t == 0;
}