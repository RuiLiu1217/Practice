#include "headers.hpp"

std::vector<std::vector<int>> LeetCode::_0830_PositionsOfLargeGroups::largetGroupPositions(std::string S) {
    S = S + "=";
    if(S.size()==1) {
        return std::vector<std::vector<int>>();
    }
    std::vector<std::vector<int>> res;
    char pre = S[0];
    int count = 1;
    for(int i = 1; i < S.size(); ++i) {
        if(S[i] == pre) {
            ++count;
        } else {
            if(count >= 3) {
                std::vector<int> ele{i - count, i - 1};
                res.push_back(ele);
            }
            count = 1;
        }
        pre = S[i];
    }
    return res;
}
