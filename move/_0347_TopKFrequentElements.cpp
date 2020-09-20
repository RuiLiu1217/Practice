#include "headers.hpp"
#include <unordered_map>
#include <queue>

std::vector<int> LeetCode::_0347_TopKFrequentElements::topKFrequent(std::vector<int>& nums, int k) {
    using Number = int;
    using Frequency = int;

    std::unordered_map<Number, Frequency> mp;
    for(auto num : nums) {
        ++mp[num];
    }

    std::vector<int> res;
    std::priority_queue<std::pair<Frequency, Number>> pq;
    for(auto & it : mp) {
        pq.push(std::make_pair(it.second, it.first));
        if(pq.size() > (int)mp.size() - k) {
            res.push_back(pq.top().second); // .second is the number.
            pq.pop();
        }
    }

    return res;
}