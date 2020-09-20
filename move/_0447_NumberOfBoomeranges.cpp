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

/* 抄的答案： 
int numberOfBoomerangs(vector<pair<int, int>>& points) {
    int booms = 0;
    for (auto &p : points) {
        unordered_map<double, int> ctr(points.size());
        for (auto &q : points)
            booms += 2 * ctr[hypot(p.first - q.first, p.second - q.second)]++;
    }
    return booms;
}
Try each point as the "axis" of the boomerang, i.e., the "i" part of the triple. Group its distances to all other points by distance, counting the boomerangs as we go. No need to avoid q == p, as it'll be alone in the distance == 0 group and thus won't influence the outcome.

Submitted five times, accepted in 1059, 1022, 1102, 1026 and 1052 ms, average is 1052.2 ms. The initial capacity for ctr isn't necessary, just helps make it fast. Without it, I got accepted in 1542, 1309, 1302, 1306 and 1338 ms.

*/