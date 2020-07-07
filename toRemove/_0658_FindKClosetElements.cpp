#include "headers.hpp"
#include <queue>
class Compare {
public:
    int x;
public:
    Compare(const int v) : x(v) {}
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return std::abs(a.first - x) > std::abs(b.first - x) || 
            (std::abs(a.first - x) == std::abs(b.first - x) && a.second > b.second);
    }
};


std::vector<int> LeetCode::_0658_FindKClosetElements::findClosetElements(std::vector<int>& arr, int k, int x) {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Compare> q{Compare(x)};
    for(int i = 0; i < arr.size(); ++i) {
        q.push({arr[i], i});
    }

    std::vector<int> res;
    for(int i = 0; i < k; ++i) {
        if(!q.empty()) {
            res.push_back(q.top().first);
            q.pop();
        }
    }

    std::sort(begin(res), end(res));
    return res;
}