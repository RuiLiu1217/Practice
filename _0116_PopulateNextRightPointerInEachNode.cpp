#include "headers.hpp"


void LeetCode::_0116_PopulatingNextRightPointerInEachNode::connect(Node* root) {
    if(root==nullptr) {
        return nullptr;
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