#include "headers.hpp"

/*
       1
      / \
    -2   4
    /  / | \
   0 -2 -1 -1

node  |   0  1  2  3  4  5  6  
parent|  -1  0  0  1  2  2  2
value |   1 -2  4  0 -2 -1 -1

i = 6                       
                            v
value |   1 -2 [3] 0 -2 -1 -1
res   |   0  0  1  0  0  0  0

i = 5
                         v
value |   1 -2 [2] 0 -2 -1 -1
res   |   0  0  2  0  0  0  0

i = 4
                      v
value |   1 -2 [0] 0 -2 -1 -1
res   |   0  0  3  0  0  0  0

i = 3;
                   v
value |   1[-2] 0  0 -2 -1 -1
res   |   0  0  3  0  0  0  0

i = 2
                v
value |  [1]-2  0  0 -2 -1 -1
res   |   0  0  3  0  0  0  0

i = 1
              v
value |  [-1]-2  0  0 -2 -1 -1
res   |    1  0  3  0  0  0  0

*/
int LeetCode::_1273_DeleteTreeNodes::deleteTreeNodes(int nodes, std::vector<int>& parent, std::vector<int>& value) {
    std::vector<int> res(nodes, 0);
    for(int i = nodes - 1; i > 0; --i) {
        value[parent[i]] += value[i];
        res[parent[i]] += value[i] ? res[i] + 1 : 0;
    }
    return value[0] ? res[0] + 1 : 0;
}

static int deleteTreeNodeDFS(int nodes, std::vector<int>& parent, std::vector<int>& value) {
    // Create Graph
    std::vector<std::vector<int>> graph(nodes);
    for(int i = 0; i < nodes; ++i) {
        if(parent[i] != -1) {
            graph[parent[i]].push_back[i];
        }
    }
    return dfs(graph, value, 0)[1];
}

static std::vector<int> dfs(std::vector<std::vector<int>>& graph, std::vector<int>& value, int root) {
    int sum = value[root];
    int cntRemainNodes = 1;
    for(int child : graph[root]) {
        auto temp = dfs(graph, value, child);
        sum += temp[0];
        cntRemainNodes += temp[1];
    }
    if(sum == 0) {
        cntRemainNodes = 0;
    }
    return {sum, cntRemainNodes};
}
