#include "headers.hpp"

int LeetCode::_0477_TotalHammingDistance::totalHammingDistance(std::vector<int>& nums) {
    int size = nums.size();
    if (size < 2) return 0;
    int ans = 0;
    int *zeroOne = new int[2];
    while (true)
    {
        int zeroCount = 0;
        zeroOne[0] = 0;
        zeroOne[1] = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0) zeroCount++;
            zeroOne[nums[i] % 2]++;
            nums[i] = nums[i] >> 1;
        }
        ans += zeroOne[0] * zeroOne[1];
        if (zeroCount == nums.size()) return ans;
    }
}