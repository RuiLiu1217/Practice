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