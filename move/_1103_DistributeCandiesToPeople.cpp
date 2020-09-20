#include "headers.hpp"

std::vector<int> LeetCode::_1103_DistributeCandiesToPeople::distributeCandies(int candies, int num_people) {
    // Simulation based
    std::vector<int> res(num_people, 0);
    for(int i = 0; candies > 0; ++i) {
        res[i % num_people] += std::min(candies, i + 1);
        candies -= (i + 1);
    }
    return res;
};
