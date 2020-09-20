#include "headers.hpp"

bool LeetCode::_0785_IsGraphBipartitle::isBipartitle(std::vector<std::vector<int>>& graph) {
    colored.resize(graph.size());
    for(int i = 0; i < colored.size(); ++i) {
        colored[i] = 0;
    }
    for(int i = 0; i < colored.size(); ++i) {
        if(colored[i] == 0 && !Color(graph, i, 1)) {
            return false;
        }
    }
    return true;
}

bool LeetCode::_0785_IsGraphBipartitle::Color(const std::vector<std::vector<int>>& graph, int I, int color) {
    if(colored[I] != 0) {
        return colored[I] == color;
    } 
    colored[I] = color;
    const std::vector<int>& adjPoint = graph[I];
    for(auto& n : adjPoint) {
        if(!Color(graph, n, -color)) {
            return false;
        }
    }
    return true;
}


// BFS based solution
bool isBipartite_BFS(std::vector<std::vector<int>>& graph) {
    std::vector<bool> visited(graph.size(), false);
    std::vector<int> color(graph.size(), -1);
    for(int i = 0; i < graph.size(); ++i) {
        int C = 0;
        if(!visited[i]) {
            std::queue<int> q;
            q.push(i);
            while(!q.empty()) {
                const int N = q.size();
                for(int t = 0; t < N; ++t) {
                    int start = q.front();
                    q.pop();
                    visited[start] = true;

                    color[start] = C;
                    auto& adj = graph[start];
                    for(int& a : adj) {
                        if(visited[a] && color[a] == C) {
                            return false;
                        }

                        if(!visited[a]) {
                            q.push(a);
                        }
                    }
                }
                C = (C + 1) % 2;
            }
        }
    }
    return true;
}