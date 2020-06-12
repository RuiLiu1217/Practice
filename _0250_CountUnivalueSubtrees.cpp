#include "headers.hpp"

bool LeetCode::_0250_CountUnivalueSubtrees::isUnique(TreeNode<int>* root) {
    if(root->left == nullptr && root->right == nullptr) {
        ++count;
        return true;
    }
    bool isUniVal = true;
    if(root->left) {
        isUniVal &= (isUnique(root->left) && root->left->val == root->val);
    }
    if(root->right) {
        isUniVal &= (isUnique(root->right) && root->right->val == root->val);
    }
    if(!isUniVal) {
        return false;
    }
    ++count;
    return true;
}

int LeetCode::_0250_CountUnivalueSubtrees::countUnivalSubtrees(TreeNode<int>* root) {
    if(!root) {
        return 0;
    }
    isUnique(root);
    return count;
}