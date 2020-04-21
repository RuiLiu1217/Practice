#include "headers.hpp"

int LeetCode::_0575_DistributeCandies::distributeCandies(std::vector<int>& candies) {
    std::unordered_set<int> sisCandy;
    int candySize = candies.size();
    for (int i = 0; i < candies.size(); ++i) {
        if (sisCandy.find(candies[i]) == sisCandy.end()) {
            if (sisCandy.size() >= candySize / 2) {
                return sisCandy.size();
            } else {
                sisCandy.insert(candies[i]);
            }
        }
    }
    return sisCandy.size();
}