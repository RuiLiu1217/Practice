#include "headers.hpp"
#include <algorithm>
#include <utility>
std::vector<std::pair<int, int>> LeetCode::_0406_QueueReconstructionByHeight::reconstructQueue(std::vector<std::pair<int, int>>& people) {
    int n = people.size();
    if (n == 0) {
        return {};
    }
    std::sort(people.begin(), people.end(), [](std::pair<int, int>& p1, std::pair<int,int>& p2) {
        return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);});

    std::vector<std::pair<int, int>> res;
    for (const auto& p : people) {
        res.insert(res.begin() + p.second, p);
    }
    return res;
}