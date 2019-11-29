#include "headers.hpp"

std::vector<TreeNode<int>*> LeetCode::_1110_DeleteNodesAndReturnForest::delNodes(TreeNode<int>* root, std::vector<int>& to_delete) {
    for(int i : to_delete) {
        toDeleteSet.insert(i);
    }
    helper(root, result, toDeleteSet, true);
    return result;
    
}
TreeNode<int>* LeetCode::_1110_DeleteNodesAndReturnForest::helper(TreeNode<int>* node, std::vector<TreeNode<int>*>& result,
                std::unordered_set<int>& toDeleteSet, bool isRoot) {
    if(node == nullptr) {
        return nullptr;
    }
    bool deleted = (toDeleteSet.find(node->val) != toDeleteSet.end());
    if(isRoot && !deleted) {
        result.push_back(node);
    }
    node->left = helper(node->left, result, toDeleteSet, deleted);
    node->right = helper(node->right, result, toDeleteSet, deleted);
    return deleted ? nullptr : node;
}