#include "headers.hpp"
// 这题本身不难，可是容易蒙住。
// 这道题应该受到原先去除排序数组中重复元素的启发。如果每个元素只能出现一次，代码实现如下：
/*
int removeDuplicates(std::vector<int>& nums) {
    int i = 0;
    for(int n : nums) {
        if( i < 1 || n > nums[i-1]) { // 这里可以看出每次向前看一个数，比较看与当前这个数是否一样如果一样就继续往下看。
            nums[i++] = n;
        }
    }
    return i;
}
    那么如果每次往前看两个位置，如果比他大，那么就应该更新当前元素
*/
int LeetCode::_0080_RemoveDuplicatesFromSortedArrayII::removeDuplicates(std::vector<int>& nums) {
    int i = 0;
    for(int n : nums) {
        if(i < 2 || n > nums[i-2]) {
            nums[i++] = n;
        }
    }
    return i;
}
 