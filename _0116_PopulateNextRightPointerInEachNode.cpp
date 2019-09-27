#include "headers.hpp"


void LeetCode::_0116_PopulatingNextRightPointerInEachNode::connect(Node* root) {
    if(root==nullptr) {
        return;
    }
    if(root->left != nullptr && root->right != nullptr) {
        root->left->next = root->right;
        if(root->next != nullptr) {
            root->right->next = root->next->left;
        }
        connect(root->left);
        connect(root->right);
    }
}