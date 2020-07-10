#include <gtest/gtest.h>
#include "../LeetCode_TreeProblems.hpp"

TEST(LC, _1485_) {

}

TEST(LC, _0098_ValidateBinarySearchTree) {
    LC::_0098_ValidateBinarySearchTree obj;
    LC::TreeNode* root = new LC::TreeNode(2);
    root->left = new LC::TreeNode(1);
    root->right = new LC::TreeNode(3);
    EXPECT_TRUE(obj.isValidBST(root));
}

TEST(LC, _0100_SameTree) {
    LC::_0100_SameTree obj;
    LC::TreeNode* root = new LC::TreeNode(2);
    root->left = new LC::TreeNode(1);
    root->right = new LC::TreeNode(3);

    LC::TreeNode* root2 = new LC::TreeNode(2);
    root2->left = new LC::TreeNode(1);
    root2->right = new LC::TreeNode(3);
    EXPECT_TRUE(obj.isSameTree(root, root2));

    LC::TreeNode* root3 = new LC::TreeNode(1);
    root3->left = new LC::TreeNode(1);
    root3->right = new LC::TreeNode(4);


    EXPECT_FALSE(obj.isSameTree(root, root3));

}