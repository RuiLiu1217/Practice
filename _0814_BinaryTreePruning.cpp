#include "headers.hpp"

TreeNode<int>* LeetCode::_0814_BinaryTreePruning::pruneTree(TreeNode<int>* root) {
    if(!root) {
        return nullptr;
    }
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if(root->val == 0 && !root->left && !root->right) {
        delete root;
        root = nullptr;
    }
    return root;
}