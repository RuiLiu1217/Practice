#include "headers.hpp"
// 有点绕，不过仔细看一下答案还是不难的。
void LeetCode::_0129_SumRootToLeafNumbers::DFS(TreeNode<int>* root, int carryValue) {
    carryValue = carryValue * 10 + root->val; // 每下一层都把上面一层的值乘以10 带下来;
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

int LeetCode::_0129_SumRootToLeafNumbers::sumNumbers(TreeNode<int>* root) {
    sum = 0;
    if(root) {
        DFS(root, 0);
    }
    return sum;
}

