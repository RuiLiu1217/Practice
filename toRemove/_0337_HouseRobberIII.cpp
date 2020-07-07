#include "headers.hpp"

int LeetCode::_0337_HouseRobberIII::rob(TreeNode<int>* root) {
    Map[nullptr] = 0;
    return robHelper(root);
}

int LeetCode::_0337_HouseRobberIII::robHelper(TreeNode<int>* root) {
    if(root == nullptr) {
        return Map[nullptr];
    }
    if(root->left == nullptr && root->right == nullptr) {
        Map[root] = root->val;
        return Map[root];
    }
    if(Map.find(root) != Map.end()) {
        return Map[root];
    }

    // If the current root is robbed
    int robCur = root->val + ((root->left != nullptr) ? robHelper(root->left->left) + robHelper(root->left->right): 0) + 
                             ((root->right != nullptr) ? robHelper(root->right->left) + robHelper(root->right->right) : 0);
    
    // If the current root is not robbed;
    int nrbCur = robHelper(root->left) + robHelper(root->right);
    Map[root] = std::max(robCur, nrbCur);
    return Map[root];

}