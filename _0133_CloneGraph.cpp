#include "headers.hpp"

LeetCode::_0133_CloneGraph::Node* LeetCode::_0133_CloneGraph::cloneGraph(Node* node) {
    if(map.find(node) == map.end()) {
        Node* newNode = new Node(node->val, std::vector<Node*>{});
        map[node] = newNode;
        
        for(int i = 0; i < node->neighbors.size(); ++i) {
            newNode->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        return newNode;
    } else {
        return map[node];
    }
}