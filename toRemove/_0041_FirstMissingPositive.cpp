#include "headers.hpp"

// Solution: Copy from solution
// Hint:
// 扫描数组中每个数：
// 1. 如果A[i]<1或者A[i]>n。说明A[i]一定不是first missing positive。跳过
// 2. 如果A[i] = i+1，说明A[i]已经在正确的位置，跳过
// 3. 如果A[i]!=i+1，且0<A[i]<=n，应当将A[i]放到A[A[i]-1]的位置，所以可以交换两数。
// 这里注意，当A[i] = A[A[i]-1]时会陷入死循环。这种情况下直接跳过。
int LeetCode::_0041_FirstMissingPositive::firstMissingPositive(std::vector<int>& nums) {
    const int N = nums.size();
    for(int i = 0; i < N; ++i) {
        while(nums[i] > 0 && nums[i] <= N && nums[nums[i] - 1] != nums[i]) {
            std::swap(nums[i], nums[nums[i] - 1]);
        }
    }

    for(int i = 0; i < N; ++i) {
        if(nums[i] != i + 1) {
            return i + 1;
        }
    }
    return N + 1;
}