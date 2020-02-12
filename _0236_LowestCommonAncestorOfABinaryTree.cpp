#include "headers.hpp"

/*
我们只能在二叉树中来搜索p和q，然后从路径中找到最后一个相同的节点即为父节点，
可以用递归来实现，在递归函数中，首先看当前结点是否为空，若为空则直接返回空，
若为p或q中的任意一个，也直接返回当前结点。否则的话就对其左右子结点分别调用
递归函数，由于这道题限制了p和q一定都在二叉树中存在，那么如果当前结点不等于
p或q，p和q要么分别位于左右子树中，要么同时位于左子树，或者同时位于右子树，
那么我们分别来讨论：

- 若p和q分别位于左右子树中，那么对左右子结点调用递归函数，会分别返回p和q结
点的位置，而当前结点正好就是p和q的最小共同父结点，直接返回当前结点即可，这
就是题目中的例子1的情况。

- 若p和q同时位于左子树，这里有两种情况，一种情况是 left 会返回p和q中较高的
那个位置，而 right 会返回空，所以最终返回非空的 left 即可，这就是题目中的
例子2的情况。还有一种情况是会返回p和q的最小父结点，就是说当前结点的左子树中
的某个结点才是p和q的最小父结点，会被返回。

- 若p和q同时位于右子树，同样这里有两种情况，一种情况是 right 会返回p和q中
较高的那个位置，而 left 会返回空，所以最终返回非空的 right 即可，还有一种
情况是会返回p和q的最小父结点，就是说当前结点的右子树中的某个结点才是p和q的
最小父结点，会被返回，写法很简洁，代码如下：
*/
TreeNode<int>* LeetCode::_0236_LowestCommonAncestorOfABinaryTree::lowestCommonAncestor(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q) {
    if(!root || root == p || root == q) {
        return root;
    }
    TreeNode<int>* left = lowestCommonAncestor(root->left, p, q);
    TreeNode<int>* right = lowestCommonAncestor(root->right, p, q);
    if(left && right) {
        return root;
    }
    return left ? left : right;
}
