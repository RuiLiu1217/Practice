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


// Another time solve it, but still cannot rembember how to do 

class Solution {
private:
    std::unordered_set<int> toDelVal;
    std::vector<TreeNode<int>*> res;
public:
    std::vector<TreeNode<int>*> delNodes(TreeNode<int>* root, std::vector<int>& to_delete) {
        for(int i = 0; i < to_delete.size(); ++i) {
            toDelVal.insert(to_delete[i]);
        }
        root = Delete(root, true);
        return res;
    }
    
    TreeNode<int>* Delete(TreeNode<int>* node, bool isRoot) {
        if(node == nullptr) {
            return nullptr;
        }
        
        bool del = (toDelVal.find(node->val) != toDelVal.end());
        if(isRoot && !del) {
            res.push_back(node);
        }
        node->left = Delete(node->left, del);
        node->right = Delete(node->right, del);
        return del ? nullptr : node;
    }
};