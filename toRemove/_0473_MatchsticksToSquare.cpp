#include "headers.hpp"
#include <algorithm>
#include <numeric>

bool LeetCode::_0473_MatchsticksToSquare::makesquare(std::vector<int>& nums) {
    if(nums.size() < 4) {
        return false;
    }
    int totlen = std::accumulate(begin(nums), end(nums), 0);
    if(totlen % 4) {
        return false;
    }
    int edge = totlen / 4;
    for(int i = 0; i < nums.size(); ++i) {
        if(nums[i] > edge) {
            return false;
        }
    }
    std::sort(begin(nums), end(nums), [](int a, int b){return a > b;});
    std::vector<int> edges(4, 0);
    return DFS(nums, 0, edges, edge);
}

bool LeetCode::_0473_MatchsticksToSquare::DFS(std::vector<int>& nums, int startidx, std::vector<int>& edges, const int EDGE) {
    if(startidx == nums.size()) {
        return edges[0] == edges[1] && edges[1] == edges[2] && edges[2] == edges[3];
    }
    
    for(int i = 0; i < 4; ++i) {
        if(edges[i] + nums[startidx] <= EDGE) {
            edges[i] += nums[startidx];
            if(DFS(nums, startidx + 1, edges, EDGE)) {
                return true;
            }
            edges[i] -= nums[startidx];
        }
    }
    return false;
}