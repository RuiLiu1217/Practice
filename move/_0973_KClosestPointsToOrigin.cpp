#include "headers.hpp"
#include <queue>

// Facebook

std::vector<std::vector<int>> LeetCode::_0973_KClosestPointsToOrigin::kCloset(std::vector<std::vector<int>>& points, int K) {
    auto comp = [](std::vector<int>& a, std::vector<int>& b) {
        return (a[0] * a[0] + a[1] * a[1]) >
            (b[0] * b[0] + b[1] * b[1]);
    };
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(comp)> q(comp);
    for(auto& p : points) {
        q.push(p);
    }
    std::vector<std::vector<int>> res;
    for(int i = 0; i < K; ++i) {
        res.push_back(q.top());
        q.pop();
    }
    return res;
}