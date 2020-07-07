#include "headers.hpp"
#include <algorithm>

std::string LeetCode::_0179_LargestNumber::largestNumber(std::vector<int>& nums) {
    std::vector<std::string> numstr;
    for(int i = 0; i < nums.size(); ++i) {
        numstr.push_back(std::to_string(nums[i]));
    }
    std::sort(numstr.begin(), numstr.end(), [](std::string& s1, std::string& s2) {
        return s1 + s2 > s2 + s1; // avoid 30, 3 --> 303 instead of 330
    });
    
    std::string res;
    for(auto n : numstr) {
        res += n;
    }
    // remove heading "0"s
    while(res[0]=='0' && res.length()>1) {
        res.erase(0,1);
    }
        
    return res;
}