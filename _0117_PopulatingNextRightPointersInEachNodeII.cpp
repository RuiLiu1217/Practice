#include "headers.hpp"

Node* LeetCode::_0117_PopulatingNextRightPointersInEachNodeII::connect(Node* root) {
    if(root == nullptr) {
        return nullptr;
    }
    Node* p = root;
    std::queue<std::pair<Node*, int>> q;
    q.push({p, 0});
    while(!q.empty()) {
        const int N = q.size();
        for(int i = 0; i < N; ++i) {
            auto a = q.front();
            auto t = a.first;
            
            q.pop();
            if(!q.empty() && a.second == q.front().second) {
                t->next = q.front().first;
            }
            if(t->left) {
                q.push({t->left, a.second + 1});
            }
            if(t->right) {
                q.push({t->right, a.second + 1});
            }
        }
    }
    return root;
}