#include "headers.hpp"

std::vector<std::string> LeetCode::_0506_RelativeRanks::findRelativeRanks(std::vector<int>& nums) {
    // Use priority queue automatically sorting;
    std::priority_queue<std::pair<int, int>> pq;
    for(int i = 0; i < nums.size(); ++i) {
        pq.push(std::make_pair(nums[i], i));
    }
    std::vector<std::string> res(nums.size(), "");

    int count = 1;
    for(int i = 0; i < nums.size(); ++i) {
        if(count == 1) {
            res[pq.top().second] = "Gold Medal";
        } else if(count == 2) {
            res[pq.top().second] = "Sliver Medal";
        } else if(count == 3) {
            res[pq.top().second] = "Bronze Medal";
        } else {
            res[pq.top().second] = std::to_string(count);
        }
        ++count;
        pq.pop();
    }
    return res;

}
