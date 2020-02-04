#include "headers.hpp"
#include <algorithm>

static TreeNode<int>* buildTree(std::vector<int>& preorder, int ps, int pe, std::vector<int>& inorder, int is, int ie) {
    if(ps > pe) {
        return nullptr;
    }
    if(ps == pe) {
        TreeNode* r = new TreeNode(preorder[ps]);
        return r;
    }
    int rootV = preorder[ps];
    auto iter = std::find(inorder.begin() + is, inorder.begin() + ie + 1, rootV);
    int iterIdx = iter - inorder.begin();
    int leftLen = iterIdx - is;
    int rightLen = ie - iterIdx;
    TreeNode* root = new TreeNode(preorder[ps]);
    root->left = buildTree(preorder, ps + 1, ps + leftLen, inorder, is, iterIdx - 1);
    root->right = buildTree(preorder, ps+leftLen+1, pe, inorder, iterIdx + 1, ie);
    return root;
    
}

TreeNode<int>* LeetCode::_0105_ConstructBinaryTreeFromPreorderAndInorderTraversal::buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}

