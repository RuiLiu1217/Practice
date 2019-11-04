#include "headers.hpp"

bool LeetCode::_0110_BalancedBinaryTree::isBalanced(TreeNode<int>* root) {
    if(root== nullptr)
        return true;
    if(root->left == nullptr && root->right == nullptr)
    {
        return true;
    }
    if(root->left != nullptr && root->right == nullptr)
    {
        if(height(root->left) == 1)
        {
            return true;
        }
        else{
            return false;
        }
    }
    if(root->right != nullptr && root->left == nullptr)
    {
        if(height(root->right)==1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return isBalanced(root->left) && isBalanced(root->right) && (abs(height(root->left) - height(root->right)) <= 1);
}

int LeetCode::_0110_BalancedBinaryTree::height(TreeNode<int>* root) {
    if(root == nullptr)
    {
        return 0;
    }
    if(root->left == nullptr && root->right == nullptr)
    {
        return 1;
    }
    return 1 + std::max(height(root->left),height(root->right));
}
