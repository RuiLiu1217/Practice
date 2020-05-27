#include "headers.hpp"

int LeetCode::_0230_KthSmallestElementInABST::kthSmallest(TreeNode<int>* root, int k) {
    TreeNode<int>* p = root;
    std::stack<TreeNode<int>*> st;
    TreeNode<int>* q = nullptr;
    int count = 1;
    while(p != nullptr || !st.empty()) {
        if(p != nullptr) {
            st.push(p);
            p = p->left;
        } else {
            q = st.top();
            st.pop();
            if(count == k) {
                break;
            } else {
                ++count;
                p = q->right;
            }
        }
    }
    return q->val;
}

// A better solution:
// 由于 BST 的性质，可以快速定位出第k小的元素是在左子树还是右子树，
// 首先计算出左子树的结点个数总和 cnt，如果k小于等于左子树结点总和 
// cnt，说明第k小的元素在左子树中，直接对左子结点调用递归即可。如果
// k大于 cnt+1，说明目标值在右子树中，对右子结点调用递归函数，注意
// 此时的k应为 k-cnt-1，应为已经减少了 cnt+1 个结点。如果k正好等于
// cnt+1，说明当前结点即为所求，返回当前结点值即可，参见代码如下：
static int count(TreeNode<int>* node) {
    if(!node) {
        return 0;
    }
    return 1 + count(node->left) + count(node->right);
}
static int kthSmallest(TreeNode<int>* root, int k) {
    int cnt = count(root->left);
    if(k <= cnt) {
        return kthSmallest(root->left, k);
    } else if(k > cnt + 1) {
        return kthSmallest(root->right, k - cnt - 1);
    }
    return root->val;
}