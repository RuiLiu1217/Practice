#include "headers.hpp"
#include <algorithm>

// 一道经典的DFS 题目，如何保留经过的路径……，需要再看几遍好记住
static std::vector<std::vector<int>> DFS(const std::vector<std::vector<int>>& graph, int sv, int ev) {
    if(sv == ev) {
        return {{sv}};
    }
    std::vector<std::vector<int>> res;
    for(auto v : graph[sv]) {
        std::vector<std::vector<int>> tmp = DFS(graph, v, ev);
        for(auto t : tmp) {
            t.push_back(sv);
            res.push_back(t);
        }
    }
    return res;
}
std::vector<std::vector<int>> LeetCode::_0797_AllPathsFromSourceToTarget::allPathsSourceTarget(std::vector<std::vector<int>>& graph) {
    std::vector<std::vector<int>> res = DFS(graph, 0, graph.size() - 1);
    for(auto & V : res) {
        std::reverse(V.begin(), V.end());
    }
    return res;
}