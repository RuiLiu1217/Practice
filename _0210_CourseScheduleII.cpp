#include "headers.hpp"
#include <queue>
std::vector<int> LeetCode::_0210_CourseScheduleII::findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {
    std::vector<int> inDegree(numCourses, 0);
    std::vector<std::vector<int>> graph(numCourses, std::vector<int>());
    for(auto edge : prerequisites) {
        graph[edge[1]].push_back(edge[0]);
        ++inDegree[edge[0]];
    }
    
    // BFS
    std::vector<int> res;
    BFS(graph, inDegree, res);
    return res.size() == numCourses ? res : std::vector<int>();
}

void LeetCode::_0210_CourseScheduleII::BFS(const std::vector<std::vector<int>>& graph, std::vector<int>& inDegree, std::vector<int>& res) {
    std::vector<int> visited(inDegree.size(), 0);
    std::queue<int> q;
    for(int i = 0; i < inDegree.size(); ++i) {
        if(inDegree[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int canLearn = q.front();
        res.push_back(canLearn);
        q.pop();
        visited[canLearn] = 1;
        
        std::vector<int> toLearn = graph[canLearn];
        for(int i = 0; i < toLearn.size(); ++i) {
            --inDegree[toLearn[i]];
            if(inDegree[toLearn[i]] == 0 && !visited[toLearn[i]]) {
                q.push(toLearn[i]);
            }
        }
    }        
}