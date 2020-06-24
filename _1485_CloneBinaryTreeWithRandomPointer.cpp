#include "headers.hpp"

LeetCode::_1485_CloneBinaryTreeWithRandomPointer::NodeCopy* LeetCode::_1485_CloneBinaryTreeWithRandomPointer::copyRandomBinaryTree(LeetCode::_1485_CloneBinaryTreeWithRandomPointer::Node* root) {
    if(!root) {
        return nullptr;
    }
    if(map.find(root) != map.end()) {
        return map[root];
    }
    LeetCode::_1485_CloneBinaryTreeWithRandomPointer::NodeCopy *newroot = new LeetCode::_1485_CloneBinaryTreeWithRandomPointer::NodeCopy(root->val);
    map[root] = newroot;        
    if(root->left) {
        newroot->left = copyRandomBinaryTree(root->left);
    }
    if(root->right) {
        newroot->right = copyRandomBinaryTree(root->right);
    }
    if(root->random) {
        newroot->random = copyRandomBinaryTree(root->random);
    }
    return newroot;
}