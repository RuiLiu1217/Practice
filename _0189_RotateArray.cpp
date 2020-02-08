#include "headers.hpp"
// Array operation
void LeetCode::_0189_RotateArray::rotate(std::vector<int>& nums, int k) {
    int numVecSize = nums.size();
    k = k % numVecSize;
    if(k != 0) {
        int i1 = 0;
        int i2 = numVecSize - k - 1;
        int i3 = numVecSize - k;
        int i4 = numVecSize - 1;
        while(i1 < i2) {
            std::swap(nums[i1],nums[i2]);
            i1++;
            i2--;
        }
        while(i3 < i4) {
            std::swap(nums[i3], nums[i4]);
            i3++;
            i4--;
        }
        i1 = 0;
        i2 = numVecSize-1;
        while(i1<i2) {
            std::swap(nums[i1], nums[i2]);
            i1++;
            i2--;
        }
    }
}