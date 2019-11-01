#include "headers.hpp"

std::vector<int> LeetCode::_0167_TwoSumII_InputArrayIsSorted::twoSum(std::vector<int>& numbers, int target) {
    std::vector<int> res;
    int i = 0;
    int j = numbers.size() - 1;
    while(i < j) {
        int sum = numbers[i] + numbers[j];
        if(sum < target) {
            ++i;
        } else if(sum > target) {
            --j;
        } else {
            res.push_back(i + 1);
            res.push_back(j + 1);
            ++i;
            --j;
        }
    }
    return res;
}