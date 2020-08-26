#include "headers.hpp"

std::vector<int> _1557_MinimumNumberOfVerticesToReachAllNodes::findSmallestSetOfVertices(int n, std::vector<std::vector<int>>& edges) {
    std::vector<int> inDegrees(n, 0);
    for(const auto& e : edges) {
        ++inDegrees[e[1]];
    }
    std::vector<int> res;
    for(int i = 0; i < inDegrees.size(); ++i) {
        if(inDegrees[i] == 0) {
            res.push_back(i);
        }
    }
    return res;
}