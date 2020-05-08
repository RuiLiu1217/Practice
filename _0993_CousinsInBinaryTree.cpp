#include "headers.hpp"
bool LeetCode::_0993_CousinsInBinaryTree::isCousins(TreeNode<int>* root, int x, int y) {
    TreeNode<int>* p = root;
    std::queue<std::pair<TreeNode<int>*, TreeNode<int>*>> q;
    q.push({root, nullptr});
    while(!q.empty()) {
        const int N = q.size();
        TreeNode<int>* px = nullptr;
        TreeNode<int>* py = nullptr;
        for(int i = 0; i < N; ++i) {
            auto [cur, parent] = q.front();
            q.pop();
            if(cur->val == x) {
                px = parent;
            }
            if(cur->val == y) {
                py = parent;
            }
            
            if(cur->left) {
                q.push({cur->left, cur});
            }
            if(cur->right) {
                q.push({cur->right, cur});
            }
        }
        if((px && !py) || (!px && py)) {
            return false;
        }
        if(px && py) {
            return px != py;
        }
    }
    return false;
}