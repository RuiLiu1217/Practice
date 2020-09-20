#include "headers.hpp"

int LeetCode::_0742_ClosetLeafInABinaryTree::findClosetLeaf(TreeNode<int>* root, int k) {
    createGraph(root, k);
    std::queue<TreeNode<int>*> q;
    q.push(key);
    std::unordered_set<TreeNode<int>*> visited;
    while(!q.empty()) {
        const int N = q.size();
        for(int i = 0; i < N; ++i) {
            auto f = q.front();
            q.pop();
            visited.insert(f);
            
            if(f->left == nullptr && f->right == nullptr) {
                return f->val;
            }
            auto neighbors = graph[f];
            for(auto n : neighbors) {
                if(!visited.count(n)) {
                    q.push(n);
                }
            }
        }
    }
    return -1;
}

void LeetCode::_0742_ClosetLeafInABinaryTree::createGraph(TreeNode<int>* root, int k) {
    if(!root) {
        return;
    }
    
    if(root->val == k) {
        key = root;
    }
    if(root->left) {
        graph[root].insert(root->left);
        graph[root->left].insert(root);
    }
    if(root->right) {
        graph[root].insert(root->right);
        graph[root->right].insert(root);
    }
    createGraph(root->left, k);
    createGraph(root->right, k);
}