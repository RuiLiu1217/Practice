#include "LeetCode_TreeProblems.hpp"

LC::_1485_CloneBinaryTreeWithRandomPointer::NodeCopy* LC::_1485_CloneBinaryTreeWithRandomPointer::copyRandomBinaryTree(LC::_1485_CloneBinaryTreeWithRandomPointer::Node* root) {
    if(!root) {
        return nullptr;
    }
    if(map.find(root) != map.end()) {
        return map[root];
    }
    LC::_1485_CloneBinaryTreeWithRandomPointer::NodeCopy *newroot = new LC::_1485_CloneBinaryTreeWithRandomPointer::NodeCopy(root->val);
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