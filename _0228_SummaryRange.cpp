#include "headers.hpp"

std::vector<std::string> LeetCode::_0228_SummaryRange::summaryRanges(std::vector<int>& nums) {
    std::vector<std::string> res;
    if(nums.size() == 0) {
        return {};
    }
    int left = nums[0];
    int right = nums[0];
    for(int i = 1; i < nums.size(); ++i) {
        int cur = nums[i];
        if(nums[i-1] == cur - 1) {
            right = cur;
        } else {
            right = nums[i-1];
            if(left == right) {
                res.push_back(std::to_string(left));
            } else {
                res.push_back(std::to_string(left) + "->" + std::to_string(right));
            }
            left = cur;
            right = cur;
        }
    }
    
    if(left == right) {
        res.push_back(std::to_string(left));
    } else {
        res.push_back(std::to_string(left) + "->" + std::to_string(right));
    }        
    return res;
}