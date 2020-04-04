#include "headers.hpp"
#include <algorithm>
/*
Type: Array
*/
static TreeNode<int>* tb(std::vector<int>& preorder, int ps, int pe, std::vector<int>& inorder, int is, int ie) {
    if(ps > pe) {
        return nullptr;
    }
    if(ps == pe) {
        TreeNode<int>* r = new TreeNode<int>(preorder[ps]);
        return r;
    }
    int rootV = preorder[ps];
    auto iter = std::find(inorder.begin() + is, inorder.begin() + ie + 1, rootV);
    int iterIdx = iter - inorder.begin();
    int leftLen = iterIdx - is;
    int rightLen = ie - iterIdx;
    TreeNode<int>* root = new TreeNode<int>(preorder[ps]);
    root->left = tb(preorder, ps + 1, ps + leftLen, inorder, is, iterIdx - 1);
    root->right = tb(preorder, ps+leftLen+1, pe, inorder, iterIdx + 1, ie);
    return root;
    
}

TreeNode<int>* LeetCode::_0105_ConstructBinaryTreeFromPreorderAndInorderTraversal::buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    return tb(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}

