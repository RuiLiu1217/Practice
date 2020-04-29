#include "headers.hpp"
bool LeetCode::_0993_CousinsInBinaryTree::isCousins(TreeNode<int>* root, int x, int y) {
    TreeNode<int>* p = root;
    std::queue<std::pair<TreeNode<int>*, TreeNode<int>*>> q;
    q.push({root, nullptr});
    while(!q.empty()) {
        const int N = q.size();
        bool foundX = false;
        bool foundY = false;
        TreeNode<int>* px = nullptr;
        TreeNode<int>* py = nullptr;
        for(int i = 0; i < N; ++i) {
            auto fr = q.front();
            q.pop();
            TreeNode<int>* cur = fr.first;
            TreeNode<int>* parent = fr.second;
            if(cur->val == x) {
                foundX = true;
                px = parent;
            }
            if(cur->val == y) {
                foundY = true;
                py = parent;
            }
            
            if(cur->left) {
                q.push({cur->left, cur});
            }
            if(cur->right) {
                q.push({cur->right, cur});
            }
        }
        if(foundX && foundY) {
            if(px != py) {
                return true;
            }
        }
    }
    return false;
}