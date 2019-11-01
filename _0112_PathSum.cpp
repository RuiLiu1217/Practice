#include "headers.hpp"

bool LeetCode::_0112_PathSum::hasPathSum(TreeNode<int>* root, int sum) {
    if(root == nullptr)
    {
        return false;
    }
    if(root->left == nullptr && root->right == nullptr)
    {
        return (sum == root->val);
    }

    if(root->left == nullptr && root->right != nullptr) {
        return hasPathSum(root->right,sum - root->val);
    }
    if(root->left != nullptr && root->right == nullptr) {
        return hasPathSum(root->left,sum - root->val);
    }
    
    return (hasPathSum(root->left,sum-root->val) || hasPathSum(root->right,sum-root->val));
}