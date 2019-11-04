#include "headers.hpp"
#include <algorithm>
TreeNode<int>* LeetCode::_0105_ConstructBinaryTreeFromPreorderAndInorderTraversal::buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    if(preorder.size() == 0 || inorder.size() == 0) {
        return nullptr;
    } else {
        TreeNode<int>* root = new TreeNode<int>(preorder[0]);
        auto iterInOrder = std::find(inorder.begin(), inorder.end(), preorder[0]);
        int idxInOrder = iterInOrder - inorder.begin();
        std::vector<int> lftInOrder(inorder.begin(), iterInOrder);
        std::vector<int> rghInOrder(iterInOrder+1, inorder.end());
        
        std::vector<int> lftPreOrder(preorder.begin()+1, preorder.begin()+1+idxInOrder);
        std::vector<int> rghPreOrder(preorder.begin()+1+idxInOrder, preorder.end());
        root->left = buildTree(lftPreOrder, lftInOrder);
        root->right = buildTree(rghPreOrder, rghInOrder);
        return root;
    }
}