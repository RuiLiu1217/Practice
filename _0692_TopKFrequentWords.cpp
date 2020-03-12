#include "headers.hpp"
#include <unordered_map>
#include <queue>

std::vector<std::string> LeetCode::_0692_TopKFrequentWords::topKFrequent(std::vector<std::string>& words, int k) {
    std::unordered_map<std::string, int> freq;
    for(auto w : words) {
        ++freq[w];
    }

    using Pair = std::pair<std::string, int>;
    auto cmp = [](Pair& a, Pair& b) {
        return a.second < b.second || (a.second == b.second && a.first > b.first);};
    
    std::priority_queue<Pair, std::vector<Pair>, decltype(cmp)> pq(cmp);
    for(auto f : freq) {
        pq.push(f);
    }
    std::vector<std::string> res;
    for(int i = 0; i < k; ++i) {
        res.push_back(pq.top().first);
        pq.pop();
    }
    return res;
}