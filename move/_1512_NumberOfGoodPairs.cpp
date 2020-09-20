#include "headers.hpp"
#include <unordered_map>
int _1512_NumberOfGoodPairs::numIdenticalPairs(std::vector<int>& nums) {
    std::unordered_map<int, std::unordered_set<int>> map;
    for(int i = 0; i < nums.size(); ++i) {
        map[nums[i]].insert(i);
    }
    int res = 0;
    for(auto& m : map) {
        const int setSize = m.second.size();
        if(setSize > 1) {
            res += setSize * (setSize - 1) / 2;
        }
    }
    return res;
}