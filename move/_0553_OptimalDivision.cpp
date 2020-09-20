#include "headers.hpp"

std::string LeetCode::_0553_OptimalDivision::optimalDivision(std::vector<int>& nums) {
    if(nums.size() == 0) {
        return "";
    }
    if(nums.size() == 1) {
        return std::to_string(nums[0]);
    }
    if(nums.size() == 2) {
        return std::to_string(nums[0]) + "/" + std::to_string(nums[1]);
    }
    std::string toReturn = std::to_string(nums[0]) + "/(";
    for(int i = 1; i < nums.size() - 1; ++i) {
        toReturn += (std::to_string(nums[i]) + "/");
    }
    toReturn += std::to_string(nums[nums.size() - 1]) + ")";
    return toReturn;
}