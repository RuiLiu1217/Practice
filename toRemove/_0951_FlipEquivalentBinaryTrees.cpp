#include "headers.hpp"

bool LeetCode::_0951_FlipEquivalentBinaryTrees::flipEquiv(TreeNode<int>* root1, TreeNode<int>* root2) {
    if(!root1 && !root2) {
        return true;
    } else if ((!root1 && root2) || (root1 &&!root2)) {
        return false;
    } else if (root1->val != root2->val){
        return false;
    } else {
        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
            (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
    }
}