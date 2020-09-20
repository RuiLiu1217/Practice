#include "headers.hpp"
#include <unordered_map>

std::vector<std::vector<int>> LeetCode::_1282_GroupThePeopleGivenTheGroupSizeTheyBelongTo::groupThePeople(std::vector<int>& groupSizes) {
    std::unordered_map<int, std::unordered_set<int>> map; // map from size to index;
    for(int i = 0; i < groupSizes.size(); ++i) {
        map[groupSizes[i]].insert(i);
    }
    std::vector<std::vector<int>> res;
    std::vector<int> group;
    for(auto& g : map) {
        int groupSize = g.first;
        int count = 0;
        for(auto idx : g.second) {
            group.push_back(idx);
            ++count;
            if(count == groupSize) {
                res.push_back(group);
                group.clear();
                count = 0;
            }
        }
    }

    return res;    
}