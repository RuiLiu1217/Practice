#include "headers.hpp"

bool LeetCode::_0663_EqualTreePartition::checkEqualTree(TreeNode<int>* root) {
    int totalSum = treeSum(root);
    if(totalSum % 2) {
        return false;
    }
    bool dividable = false;
    int res = foo(root, totalSum / 2, dividable);
    return dividable;
}

int LeetCode::_0663_EqualTreePartition::treeSum(TreeNode<int>* root) {
    if(!root) {
        return 0;
    }
    return treeSum(root->left) + treeSum(root->right) + root->val;
}

int LeetCode::_0663_EqualTreePartition::foo(TreeNode<int>* root, int target, bool& dividable) {
    if(!root) {
        return 0;
    }
    
    int left = foo(root->left, target, dividable);
    int right = foo(root->right, target, dividable);
    if((root->left && left == target) || (root->right && right == target)) { // ! I forgot why need to judge root->left or root->right is not nullptr
        dividable = true;
    }
    return left + right + root->val;        
}