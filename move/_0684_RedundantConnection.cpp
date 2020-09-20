#include "headers.hpp"
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <vector>
// DFS
// Just use the DFS to find out, if DFS can connect source and target with the given edge before this edge is added 
// to the graph, there must be circle.
static bool dfs(std::vector<std::unordered_set<int>>& graph, std::vector<int>& visited, int source, int target) {
    if(!visited[source]) {
        visited[source] = 1;
        if(source == target) {
            return true;
        }
        for(int adj : graph[source]) {
            if(dfs(graph, visited, adj, target)) {
                return true;
            }
        }
    }
    return false;
}
std::vector<int> LeetCode::_0684_RedundantConnection::findRedundantConnection(std::vector<std::vector<int>>& edges) {
    std::vector<std::unordered_set<int>> graph;
    int maxN = 0;
    for(int i = 0; i < edges.size(); ++i) {
        maxN = std::max(maxN, edges[i][0]);
        maxN = std::max(maxN, edges[i][1]);
    }
    graph.resize(maxN);

    std::vector<int> visited(maxN, 0);
    for(auto e : edges) {
        std::fill(begin(visited), end(visited), 0);
        if(!graph[e[0]].empty() && !graph[e[1]].empty()
        && dfs(graph, visited,  e[0], e[1])) {
            return e;
        }
        graph[e[0]].insert(e[1]);
        graph[e[1]].insert(e[0]);
    }
    return {};
}