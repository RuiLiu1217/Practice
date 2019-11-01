#include "headers.hpp"

// 用一个 map 来建立当前节点pointer 与 要clone 的节点pointer 的映射。
LeetCode::_0133_CloneGraph::Node* LeetCode::_0133_CloneGraph::cloneGraph(Node* node) {
    if(map.find(node) == map.end()) {  // 如果没有这个节点，说明还没有clone 它
        Node* newNode = new Node(node->val, std::vector<Node*>{}); // 新建一个节点
        map[node] = newNode; // 他的映射建立，以后再遇到它就不用clone 了;
        
        for(int i = 0; i < node->neighbors.size(); ++i) {
            newNode->neighbors.push_back(cloneGraph(node->neighbors[i]));  // 基于DFS， 新节点的每个neighbor 都是从旧节点 neighbor 的 clone.
        }
        return newNode;
    } else {
        return map[node]; // 如果这个节点已经有了，就不需要clone了，直接返回新节点的指针。
    }
}