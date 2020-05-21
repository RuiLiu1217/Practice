#include "headers.hpp"

bool LeetCode::_1430_CheckIfAStringIsAValidSequenceFromRootToLeavesPathInaBinaryTree::isValidSequence(TreeNode<int>* root, std::vector<int>& arr) {
    return isValidSequence(root, arr, 0); 
}

bool LeetCode::_1430_CheckIfAStringIsAValidSequenceFromRootToLeavesPathInaBinaryTree::isValidSequence(TreeNode<int>* root, std::vector<int>& arr, int startIdx) {
    if(!root || startIdx >= arr.size() || root->val != arr[startIdx]) {
        return false;
    } else {
        if(root->left == nullptr && root->right == nullptr) {
            return startIdx == arr.size() - 1;
        } else {
            return isValidSequence(root->left, arr, startIdx + 1) ||
                   isValidSequence(root->right, arr, startIdx + 1);
        }
    }
}
