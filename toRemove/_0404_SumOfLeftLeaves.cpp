#include "headers.hpp"

int LeetCode::_0404_SumOfLeftLeaves::sumOfLeftLeaves(TreeNode<int>* root) {
    if(!root) {
        return 0;
    }
    int sum = 0;
    if(root->left && root->left->left == nullptr && root->left->right == nullptr) {
        sum = root->left->val;
    }
    return sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}