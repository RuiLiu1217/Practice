#include "headers.hpp"

TreeNode<int>* LeetCode::_0700_SearchInABinarySearchTree::searchBST(TreeNode<int>* root, int val) {
    if(!root) {
        return nullptr;
    }
    if(root->val == val) {
        return root;
    }
    int rootVal = root->val;
    if(rootVal > val) {
        return searchBST(root->left, val);
    } else {
        return searchBST(root->right, val);
    }    
}