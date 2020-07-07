#include "headers.hpp"

int LeetCode::_0339_NestedListWeightSum::depthSum(std::vector<NestedInteger>& nestedList) {
    return depthSum(nestedList, 1);
}

int LeetCode::_0339_NestedListWeightSum::depthSum(std::vector<NestedInteger>& nestedList, int depth) {
    int sum = 0;
    for(auto& nstl : nestedList) {
        if(nstl.isInteger()) {
            sum += nstl.getInteger() * depth;
        } else {
            auto& list = nstl.getList();
            sum += depthSum(list, depth + 1);
        }
    }
    return sum;
}