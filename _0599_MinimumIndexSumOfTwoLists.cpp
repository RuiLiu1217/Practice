#include "headers.hpp"
#include <unordered_map>
std::vector<std::string> LeetCode::_0599_MinimumIndexSumOfTwoLists::findRestaruant(std::vector<std::string>& list1, std::vector<std::string>& list2) {
    std::unordered_map<std::string, int> l1;
    for(int i = 0; i < list1.size(); ++i) {
        l1[list1[i]] = i;
    }
    std::vector<std::string> res;
    int minV = INT_MAX;
    for(int i = 0; i < list2.size(); ++i) {
        if(l1.find(list2[i]) != l1.end()) {
            if(l1[list2[i]] + i < minV) {
                res.clear();
                minV = l1[list2[i]] + i;
                res.push_back(list2[i]);
            } else if(l1[list2[i]] + i == minV) {
                res.push_back(list2[i]);
            }
        }
    }
    
    return res;
}