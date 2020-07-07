#include "headers.hpp"

void LeetCode::_0671_SecondMinimumNodeInABinaryTree::dfs(TreeNode<int>* root) {
    if(root != nullptr) {
        if(min1 < root->val && root->val < ans) {
            ans = root->val;
        } else if(min1 == root->val) {
            dfs(root->left);
            dfs(root->right);
        }
    }
}

int LeetCode::_0671_SecondMinimumNodeInABinaryTree::findSecondMinimumValue(TreeNode<int>* root) {
    if(root) {
        min1 = root->val;
        dfs(root);
        return ans < INT_MAX? ans:-1;
    }
    return -1;
}