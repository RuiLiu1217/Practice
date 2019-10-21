#include "headers.hpp"
#include <unordered_map>
#include <unordered_set>

static int distanceSquare(std::vector<int>& a, std::vector<int>& b) {
    return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
}

int LeetCode::_0447_NumberOfBoomerangs::numberOfBoomerangs(std::vector<std::vector<int>>& points) {
    using Index = int;
    using DistanceSquare = int;
    std::unordered_map<Index, std::unordered_map<DistanceSquare, std::unordered_set<Index>>> Map;
    for(int i = 0; i < points.size(); ++i) {
        for(int j = i + 1; j < points.size(); ++j) {
            int dis = distanceSquare(points[i], points[j]);
            Map[i][dis].insert(j); // 以点i为中心，距离为dis的点的集合
            Map[j][dis].insert(i);
        }
    }
    
    int res = 0;
    for(auto& it : Map) {
        auto& m = it.second;
        for(auto& t : m) {
            if(t.second.size() >= 2) {
                res += t.second.size() * (t.second.size()-1);
            }
        }
    }
    return res;
}