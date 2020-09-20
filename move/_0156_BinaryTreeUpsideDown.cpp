#include "headers.hpp"

// I totally don't understand this problem
// just copy the solution
TreeNode<int>* _0156_BinaryTreeUpsideDown::upsideDownBinaryTree(TreeNode<int>* root) {
    if(!root) {
        return nullptr;
    }
    TreeNode<int>* temp = nullptr;
    TreeNode<int>* prev = nullptr;
    TreeNode<int>* next = nullptr;
    TreeNode<int>* curr = root;
    while(curr) {
        next = curr->left;
        curr->left = temp;
        temp = curr->right;
        curr->right = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}