#include "headers.hpp"

bool LeetCode::_0261_GraphValidTree::validTree(int n, std::vector<std::vector<int>>& edges) {
    if(n <= 0) {
        return false;
    }
    if(edges.size() != n - 1) {
        return false;
    }
    std::vector<std::unordered_set<int>> graph(n);

    for(auto e : edges) {
        std::vector<int> visited(n, false);
        if(DFS(graph, visited, e[0], e[1])) {
            return false;
        }
        graph[e[0]].insert(e[1]);
        graph[e[1]].insert(e[0]);
    }
    return true;
}

bool LeetCode::_0261_GraphValidTree::DFS(std::vector<std::unordered_set<int>>& graph, std::vector<int>& visited, int source, int target) {
    if(source == target) {
        return true;
    }
    visited[source] = true;
    for(auto& adj : graph[source]) {
        if(!visited[adj]) {
            if(DFS(graph, visited, adj, target)) {
                return true;
            }
        }
    }
    return false;
}