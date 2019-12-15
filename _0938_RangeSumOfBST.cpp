#include "headers.hpp"

int LeetCode::_0938_RangeSumOfBST::rangeSumBST(TreeNode<int>* root, int L, int R) {
    if(!root) {
        return 0;
    }
    if(root->val < L) {
        return rangeSumBST(root->right, L, R);
    } else if(root->val > R) {
        return rangeSumBST(root->left, L, R);
    } else {
        return root->val + rangeSumBST(root->right, L, R) + rangeSumBST(root->left, L, R);
    }
}