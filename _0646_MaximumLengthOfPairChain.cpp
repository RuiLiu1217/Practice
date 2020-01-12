#include "headers.hpp"
#include <algorithm>

int LeetCode::_0646_MaximumLengthOfPairChain::findLongestChain(std::vector<std::vector<int>>& pairs) {
    if(pairs.size() == 0) {
        return 0;
    }
    if(pairs.size() == 1) {
        return 1;
    }
    std::sort(pairs.begin(), pairs.end(), [](std::vector<int> a, std::vector<int> b){
        return (a[0] < b[0]) || (a[0] == b[0] && a[1] < b[1]);
    });
    
    std::vector<int> DP(pairs.size(), 1);
    for(int i = 1; i < pairs.size(); ++i) {
        for(int j = i - 1; j >= 0; --j) {
            if(pairs[i][0] > pairs[j][1]) {
                DP[i] = std::max(DP[i], DP[j] + 1);
            }
        }
    }
    
    auto p = std::max_element(DP.begin(), DP.end());
    return *p;
}