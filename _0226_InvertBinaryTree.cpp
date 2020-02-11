#include "headers.hpp"

TreeNode<int>* LeetCode::_0226_InvertBinaryTree::invertTree(TreeNode<int>* root)  {
    if(!root) {
        return nullptr;
    } else {
        TreeNode<int>* lft = invertTree(root->left);
        TreeNode<int>* rgh = invertTree(root->right);
        root->left = rgh;
        root->right = lft;
        return root;
    }    
}