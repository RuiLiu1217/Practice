#include "LeetCode_DFS.hpp"


//! Copy from solution 
//! 有点绕，不过仔细看一下答案还是不难的。
void LC::_0129_SumRootToLeafNumbers::DFS(TreeNode* root, int carryValue) {
    carryValue = carryValue * 10 + root->val; //! 每下一层都把上面一层的值乘以10 带下来;
    if(root->left == nullptr && root->right == nullptr) {
        sum += carryValue;
    }
    if(root->left) {
        DFS(root->left, carryValue);
    }
    if(root->right) {
        DFS(root->right, carryValue);
    }
}

int LC::_0129_SumRootToLeafNumbers::sumNumbers(TreeNode* root) {
    sum = 0;
    if(root) {
        DFS(root, 0);
    }
    return sum;
}
