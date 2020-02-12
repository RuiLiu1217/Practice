#include "headers.hpp"

std::vector<std::string> LeetCode::_0257_BinaryTreePaths::binaryTreePaths(TreeNode<int>* root) {
    if(root == nullptr) {
        return {};
    }
    if(root->left == nullptr && root->right == nullptr) {
        return {std::to_string(root->val)};
    }
    std::vector<std::string> leftString = binaryTreePaths(root->left);
    std::vector<std::string> rightString = binaryTreePaths(root->right);
    std::vector<std::string> res;
    for(int i = 0; i < leftString.size(); ++i) {
        res.push_back(std::to_string(root->val) + "->" + leftString[i]);
    }
    for(int i = 0; i < rightString.size(); ++i) {
        res.push_back(std::to_string(root->val) + "->" + rightString[i]);
    }
    return res;
}