#include "headers.hpp"

std::vector<std::string> LeetCode::_1441_BuildAnArrayWithStackOperations::buildArray(std::vector<int>& target, int n) {
    int count = 1;
    int dis = 0;
    std::vector<std::string> res;
    for(int t : target) {
        while(t > count) {
            res.push_back("Push");
            res.push_back("Pop");
            ++count;
        }
        res.push_back("Push");
        ++count;
    }
    return res;
}