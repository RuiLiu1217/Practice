#include "headers.hpp"
// Tag: topological sorting, Graph
// TODO: DFS based topological sorting 
LeetCode::_0207_CourseSchedule::Graph LeetCode::_0207_CourseSchedule::createGraph(
    int numCourses, std::vector<std::vector<int>>& prerequisites) {
    Graph g(numCourses);
    for(auto p : prerequisites) {
        g[p[1]].push_back(p[0]);
    }
    return g;
}

bool LeetCode::_0207_CourseSchedule::isCyclicUtils(LeetCode::_0207_CourseSchedule::Graph g, 
    int v, std::vector<bool>& visited, std::vector<bool>& recStack) {
    if(visited[v] == false) {
        visited[v] = true;
        recStack[v] = true;
        
        auto& adj = g[v];
        for(auto i : adj) {
            if(!visited[i] && isCyclicUtils(g, i, visited, recStack)) {
                return true;
            } else if(recStack[i]) {
                return true;
            }
        }
    }
    recStack[v] = false;
    return false;
}

std::vector<int> LeetCode::_0207_CourseSchedule::computeIndegrees(LeetCode::_0207_CourseSchedule::Graph& g) {
    std::vector<int> degrees(g.size(), 0);
    for (auto adj : g) {
        for (int v : adj) {
            degrees[v]++;
        }
    }
    return degrees;
}

bool LeetCode::_0207_CourseSchedule::canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
    Graph g = createGraph(numCourses, prerequisites);
    std::vector<int> degrees = computeIndegrees(g);
    for (int i = 0; i < numCourses; i++) {
        int j = 0;
        for (; j < numCourses; j++) {
            if (!degrees[j]) {
                break;
            }
        }
        if (j == numCourses) {
            return false;
        }
        degrees[j]--;
        for (int v : g[j]) {
            degrees[v]--;
        }
    }
    return true;
}