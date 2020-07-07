#include "headers.hpp"
// Tag: Tree, 
// Todo: I don't know why the solution is totally different from what I think of but my solution can pass.
int LeetCode::_0222_CountCompleteTreeNodes::countNodes(TreeNode<int>* root) {
    if(!root) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}