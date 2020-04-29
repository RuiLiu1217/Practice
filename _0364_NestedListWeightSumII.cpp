#include "headers.hpp"

int LeetCode::_0364_NestedListWeightSumII::depthSumInv(std::vector<NestedInteger>& nestedList, int level) {
    int unweighted = 0;
    int weighted = 0;
    while(!nestedList.empty()) {
        std::vector<NestedInteger> tmp;
        for(auto& iter : nestedList) {
            if(iter.isInteger()) {
                unweighted += iter.getInteger();
            } else {
                const std::vector<NestedInteger>& t = iter.getList();
                for(int i = 0; i < t.size(); ++i) {
                    tmp.push_back(t[i]);
                }
            }
        }
        weighted += unweighted;
        nestedList = tmp;
    }
    return weighted;
}