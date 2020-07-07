#include "headers.hpp"
// 这个解法非常巧妙，记得当时是看答案得到的
// 一般能想到的方法就是用一个栈或者queue之类的，对树做一次遍历，然后按照栈或者队列中的指针一个一个连起来;
// 这里是直接处理，也就是如果见到一个节点有左右孩子，那么右子树一定接在左子树最有叶子节点的后面，然后依次调用
// 如果该节点只有左孩子，那么想办法把他变成右孩子。如果只有右孩子，就不用管了。
void LeetCode::_0114_FlattenBinaryTreeToLinkedList::flatten(TreeNode<int>* root) {
    TreeNode<int>* ptr = root;
    while(root) {
        if(root->left && root->right) {
            TreeNode<int>* p = root->left;
            while(p->right) {
                p = p->right;
            }
            p->right = root->right;
            root->right = nullptr;
        }
        if(root->left) {
            root->right = root->left;
            root->left = nullptr;
        }
        root = root->right;
    }
}