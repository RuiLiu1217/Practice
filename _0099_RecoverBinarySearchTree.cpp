#include "headers.hpp"

void LeetCode::_0099_RecoverBinarySearchTree::recoverTree(TreeNode<int>* root) {
    TreeNode<int>* first = nullptr;
    TreeNode<int>* second = nullptr;
    TreeNode<int>* prev = new TreeNode<int>(INT_MIN);
    while(root != nullptr) {
        TreeNode<int>* node = root->left;
        if(node != nullptr) {
            while(node->right != nullptr && node->right != root) {
                node = node->right;
            }

            if(node->right == nullptr) {
                node->right = root;
                root = root->left;
                continue;
            } else {
                node->right = nullptr;
            }
        }

        if(root->val < prev->val) {
            if(first == nullptr) {
                first = prev;
            }
            second = root;
        }
        prev = root;
        root = root->right;
    }
    std::swap(first->val, second->val);
}