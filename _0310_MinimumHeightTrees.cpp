#include "headers.hpp"
#include <unordered_set>
#include <queue>

std::vector<int> LeetCode::_0310_MinimumHeightTrees::findMinHeightTrees(int n, std::vector<std::vector<int>>& edges) {
    if(n == 1) {
        return {0};
    }

    std::vector<int> res;
    std::vector<std::unordered_set> adj(n);

    for(auto edge : edges) {
        adj[edge[0]].insert(edge[1]);
        adj[edge[1]].insert(edge[0]);
    }

    std::queue<int> q;
    for(int i = 0; i < n; ++i) {
        if(adj[i].size() == 1) {
            q.push(i);
        }
    }

    while(n > 2) {
        int size = q.size();
        n -= size;

        for(int i = 0; i < size; ++i) {
            int top = q.front();
            q.pop();
            for(auto a : adj[top]) {
                adj[a].erase(top);
                if(adj[a].size() == 1) {
                    q.push(a);
                }
            }
        }
    }
    while(!q.empty()) {
        res.push_back(q.front());
        q.pop();
    }
    return res;
}

/*
vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if(edges.size() == 0 && n == 0) {
        return {};
    } else if(edges.size() == 0) {
        return {0};
    }
    std::vector<std::vector<int>> adjTable(n);
    for(int i = 0; i < edges.size(); ++i) {
        adjTable[edges[i][0]].push_back(edges[i][1]);
        adjTable[edges[i][1]].push_back(edges[i][0]);
    }
    
    
    std::vector<int> depths(n, 0);
    int minDepth = INT_MAX;
    for(int i = 0; i < adjTable.size(); ++i) {
        std::vector<int> visited(n, 0);

        BFS(adjTable, visited, i, 0, depths[i]);
        if(minDepth > depths[i]) {
            minDepth = depths[i];
        }
    }
    
    std::vector<int> res;
    for(int i = 0; i < depths.size(); ++i) {
        if(depths[i] == minDepth) {
            res.push_back(i);
        }
    }
    return res;
}

void BFS(const std::vector<std::vector<int>>& adjTable, 
    std::vector<int>& visited, int start, int depth, int& maxDepth) {
    if(depth > maxDepth) {
        maxDepth = depth;
    }
    
    if(visited[start] == 0) {
        visited[start] = 1;
        std::vector<int> toVisit = adjTable[start];
        if(toVisit.size() == 0) {
            return;
        } else {
            for(int i = 0; i < toVisit.size(); ++i) {
                BFS(adjTable, visited, toVisit[i], depth + 1, maxDepth);
            }
        }
    }
}
*/