#include "headers.hpp"

TreeNode<int>* LeetCode::_1038_BinarySearchTreeToGreaterSumTree::bstToGst(TreeNode<int>* root) {
    traverse(root);
    TreeNode<int>* b = new TreeNode<int>(0);
    vis.push(b);
    while(!vis.empty()) {
        TreeNode<int>* p1 = vis.top();
        vis.pop();
        if(vis.empty()) {
            return root;
        }
        TreeNode<int>* p2 = vis.top();
        vis.pop();
        p2->val = p1->val + p2->val;
        vis.push(p2);
    }
    return root;
}

void LeetCode::_1038_BinarySearchTreeToGreaterSumTree::traverse(TreeNode<int>* root) {
    if(!root) {
        return;
    }
    traverse(root->left);
    vis.push(root);
    traverse(root->right);
}