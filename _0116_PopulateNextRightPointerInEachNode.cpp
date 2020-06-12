#include "headers.hpp"


LeetCode::_0116_PopulatingNextRightPointerInEachNode::Node* LeetCode::_0116_PopulatingNextRightPointerInEachNode::connect(LeetCode::_0116_PopulatingNextRightPointerInEachNode::Node* root) {
    if(root==nullptr) {
        return root;
    }
    if(root->left != nullptr && root->right != nullptr) {
        root->left->next = root->right;
        if(root->next != nullptr) {
            root->right->next = root->next->left;
        }
        root->left = connect(root->left);
        root->right = connect(root->right);
    }
    return root;
}