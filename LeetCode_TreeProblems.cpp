#include "LeetCode_TreeProblems.hpp"
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <cmath>

// Facebook

/*
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        auto [min, max, isValid] = isValidBSTImpl(root);
        return isValid;
    }
    
    std::tuple<double, double, bool> isValidBSTImpl(TreeNode* root) {
        if(!root) {
            return {INT_MAX + 1.0, INT_MIN - 1.0, true};
        } else if(root->left == nullptr && root->right == nullptr) {
            return {root->val, root->val, true};
        } else {
            auto [lmin, lmax, leftBST] = isValidBSTImpl(root->left);
            auto [rmin, rmax, rightBST] = isValidBSTImpl(root->right);
            double val = root->val;
            bool isValid = lmax < val && rmin > val && leftBST && rightBST;
            return {std::min(lmin, val), std::max(rmax, val), isValid};
        }
    }
};
*/
bool LC::_0098_ValidateBinarySearchTree::isValidBST(TreeNode* root) {
    if(!root) {
        return true;
    }
    if(root->left == nullptr && root->right == nullptr) {
        return true;
    }

    TreeNode* p = root;
    std::stack<TreeNode*> st;
    int preV = INT_MIN;
    bool notfound = true;
    while(p != nullptr || !st.empty()) {
        if(p != nullptr) {
            st.push(p);
            p = p->left;
        } else {
            TreeNode* q = st.top();
            st.pop();
            // Make the decision, if it is the first time get the value, just let it go
            // if not, we need to compare whether the current value is larger than
            // the previous value.
            if(notfound) {
                preV = q->val;
                notfound = false;
            } else {
                if(q->val <= preV) {
                    return false;
                } else {
                    preV = q->val;
                }
            }
            p = q->right;
        }
    }
    return true;
}

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



bool LC::_0100_SameTree::isSameTree(TreeNode *p, TreeNode *q) {
    if (p==nullptr && q==nullptr) {
        return true;
    }
    if ((p == nullptr && q != nullptr) ||(p != nullptr && q == nullptr)) {
        return false;
    }
    
    if(p->val != q->val) {
        return false;
    } else {
        return (isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
    }
    
}




std::vector<LC::TreeNode*> LC::_0095_UniqueBinarySearchTreeII::generateTrees(int n) {
    return generateTreeHelper(1, n);
}

std::vector<LC::TreeNode*>  LC::_0095_UniqueBinarySearchTreeII::generateTreeHelper(int l, int r) {
    if(l > r) {
        return {};
    }
    if(l == r) {
        TreeNode* root = new TreeNode(l);
        std::vector<TreeNode*> res{root};
        return res;
    }
    std::vector<TreeNode*> res;
    for(int i = l; i <= r; ++i) {
        std::vector<TreeNode*> lft = generateTreeHelper(l, i-1);
        std::vector<TreeNode*> rgh = generateTreeHelper(i+1, r);
        if(lft.size() == 0 && rgh.size() == 0) {
            TreeNode* root = new TreeNode(i);
            res.push_back(root);
        } else if(lft.size() == 0 && rgh.size() != 0) {
            for(int rr = 0; rr < rgh.size(); ++rr) {
                TreeNode* root = new TreeNode(i);
                root->right = rgh[rr];                
                res.push_back(root);
            }
        } else if(lft.size() != 0 && rgh.size() == 0) {
            for(int ll = 0; ll < lft.size(); ++ll) {
                TreeNode* root = new TreeNode(i);
                root->left = lft[ll];                
                res.push_back(root);
            }
        } else {
            for(int ll = 0; ll < lft.size(); ++ll) {
                for(int rr = 0; rr < rgh.size(); ++rr) {
                    TreeNode* root = new TreeNode(i);
                    root->left = lft[ll];                
                    root->right = rgh[rr];                
                    res.push_back(root);
                }
            }
        }
    }
    return res;
}


bool LC::_0101_SymmetricTree::isSymmetric(TreeNode* root) {
    return preOrderIter(root);
}

bool LC::_0101_SymmetricTree::preOrderIter(TreeNode* root) {
    TreeNode *p = root;
    TreeNode *q = root;
    std::stack<TreeNode*> stLft;
    std::stack<TreeNode*> stRgh;
    while (p != nullptr || !stLft.empty()) {
        if (p != nullptr) {
            if (q == nullptr || p->val != q->val) {
                return false;
            }
            stLft.push(p);
            stRgh.push(q);
            p = p->left;
            q = q->right;
        } else {
            TreeNode* tmplft = stLft.top();
            stLft.pop();
            TreeNode* tmpRgh = nullptr;
            if (stRgh.empty()) {
                return false;
            } else {
                tmpRgh = stRgh.top();
                stRgh.pop();
            }
            p = tmplft->right;
            q = tmpRgh->left;
        }
    }
    return true;
}


std::vector<std::vector<int>> LC::_0102_BinaryTreeLevelOrderTraversal::levelOrder(TreeNode* root) {
    TreeNode* p = root;
    std::queue<TreeNode*> q;
    q.push(p);
    if(!root) {
        return {};
    }

    std::vector<std::vector<int>> res;
    while(!q.empty()) {
        const int N = q.size();
        std::vector<int> tmp;
        for(int i = 0; i < N; ++i) {
            TreeNode* t = q.front();
            q.pop();
            tmp.push_back(t->val);

            if(t->left) {
                q.push(t->left);
            }
            if(t->right) {
                q.push(t->right);
            }
        }
        res.push_back(tmp);
    }
    return res;
}


std::vector<std::vector<int>> LC::_0103_BinaryTreeZigzagLevelOrderTraversal::zigzagLevelOrder(TreeNode* root) {
    TreeNode* p = root;
    if(!p) {
        return {};
    }
    
    std::queue<TreeNode*> qu;
    qu.push(p);
    int l = 1;

    std::vector<std::vector<int>> res;
    while(!qu.empty()) {
        const int N = qu.size();
        std::vector<int> tmp;
        for(int i = 0; i < N; ++i) {
            TreeNode* t = qu.front();
            qu.pop();

            tmp.push_back(t->val);

            if(t->left) {
                qu.push(t->left);
            }
            if(t->right) {
                qu.push(t->right);
            }
        }
        if(l%2==0) {
            std::reverse(tmp.begin(), tmp.end());
        }
        res.push_back(tmp);
        ++l;
    }
    return res;
}


int LC::_0104_MaximumDepthOfBinaryTree::maxDepth(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    }
    if(root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}


/*
Type: Array
*/
static LC::TreeNode* tb(std::vector<int>& preorder, int ps, int pe, std::vector<int>& inorder, int is, int ie) {
    if(ps > pe) {
        return nullptr;
    }
    if(ps == pe) {
        LC::TreeNode* r = new LC::TreeNode(preorder[ps]);
        return r;
    }
    int rootV = preorder[ps];
    auto iter = std::find(inorder.begin() + is, inorder.begin() + ie + 1, rootV);
    int iterIdx = iter - inorder.begin();
    int leftLen = iterIdx - is;
    int rightLen = ie - iterIdx;
    LC::TreeNode* root = new LC::TreeNode(preorder[ps]);
    root->left = tb(preorder, ps + 1, ps + leftLen, inorder, is, iterIdx - 1);
    root->right = tb(preorder, ps+leftLen+1, pe, inorder, iterIdx + 1, ie);
    return root;
    
}

LC::TreeNode* LC::_0105_ConstructBinaryTreeFromPreorderAndInorderTraversal::buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    return tb(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}



LC::TreeNode* LC::_0106_ConstructBinaryTreeFromInorderAndPostorderTraversal::buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
    return buildTree(inorder, 0, inorder.size(), postorder, 0, postorder.size());
}


LC::TreeNode* LC::_0106_ConstructBinaryTreeFromInorderAndPostorderTraversal::buildTree(std::vector<int>& inorder, int inStart, int inEnd, 
                       std::vector<int>& postorder, int postStart, int postEnd) {
    if(postStart >= postEnd) {
        return nullptr;
    }
    
    TreeNode* root = new TreeNode(postorder[postEnd - 1]);
    if(postEnd - postStart == 1) {            
        return root;
    }

    auto iter = std::find(inorder.begin() + inStart, inorder.begin() + inEnd, root->val);
    int lftLength = std::distance(inorder.begin() + inStart, iter);
    
    root->left = buildTree(inorder, inStart, inStart + lftLength,
                            postorder, postStart, postStart + lftLength);
    root->right = buildTree(inorder, inStart + lftLength + 1, inEnd,
                            postorder, postStart + lftLength, postEnd - 1); // 这道题的index计算折磨了半天
    
    return root;
}


std::vector<std::vector<int>> LC::_0107_BinaryTreeLevelOrderTraversalII::levelOrderBottom(LC::TreeNode* root) {
    std::queue<TreeNode*> q;
    q.push(root);
    std::vector<std::vector<int>> res;
    while (!q.empty()) {
        const int N = q.size();
        std::vector<int> tmp;
        for (int i = 0; i < N; ++i) {
            auto t = q.front();
            q.pop();
            tmp.push_back(t->val);

            if (t->left) {
                q.push(t->left);
            }
            if (t->right) {
                q.push(t->right);
            }
        }
        res.push_back(tmp);
    }
    std::reverse(res.begin(), res.end());
    return res;
};


LC::TreeNode* LC::_0108_ConvertSortedArrayToBinarySearchTree::sortedArrayToBST(std::vector<int>& nums) {
    return bst(nums, 0, nums.size() - 1);
}

LC::TreeNode* LC::_0108_ConvertSortedArrayToBinarySearchTree::bst(std::vector<int>& nums, int start, int end) {
    if(start > end || end < 0) { // end < 0 is a edge conditional case
        return nullptr;
    }
    if(start == end) {
        TreeNode* p = new TreeNode(nums[start]);
        return p;
    } else {
        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = bst(nums, start, mid - 1);
        root->right = bst(nums, mid + 1, end);
        return root;
    }
}



LC::TreeNode* LC::_0109_ConvertSortedListToBinarySearchTree::sortedListToBST(LC::_0109_ConvertSortedListToBinarySearchTree::ListNode* head) {
    if(!head) {
        return nullptr;
    }
    LC::_0109_ConvertSortedListToBinarySearchTree::ListNode* lRoot = nullptr;
    LC::_0109_ConvertSortedListToBinarySearchTree::ListNode* lleft = nullptr;
    LC::_0109_ConvertSortedListToBinarySearchTree::ListNode* lright= nullptr;
    split(head, lRoot, lleft, lright);
    
    TreeNode* root = new TreeNode(lRoot->val);
    root->left = sortedListToBST(lleft);
    root->right = sortedListToBST(lright);
    return root;
}
    
void LC::_0109_ConvertSortedListToBinarySearchTree::split(
    LC::_0109_ConvertSortedListToBinarySearchTree::ListNode* head, 
    LC::_0109_ConvertSortedListToBinarySearchTree::ListNode*& root, 
    LC::_0109_ConvertSortedListToBinarySearchTree::ListNode*& left, 
    LC::_0109_ConvertSortedListToBinarySearchTree::ListNode*& right) {
    if(!head) {
        root = nullptr;
        left = nullptr;
        right = nullptr;
        return;
    }
    
    if(!head->next) {
        root = head;
        left = nullptr;
        right = nullptr;
        return;
    }
    
    LC::_0109_ConvertSortedListToBinarySearchTree::ListNode* nh = new LC::_0109_ConvertSortedListToBinarySearchTree::ListNode(INT_MAX);
    nh->next = head;
    
    LC::_0109_ConvertSortedListToBinarySearchTree::ListNode* slow = nh;
    LC::_0109_ConvertSortedListToBinarySearchTree::ListNode* fast = nh;
    while(fast && fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    root = slow->next;
    slow->next = nullptr;
    right = root->next;
    root->next = nullptr;
    left = nh->next;
    nh->next = nullptr;
    delete nh;
    return;
    
}


bool LC::_0110_BalancedBinaryTree::isBalanced(TreeNode* root) {
    if(root== nullptr)
        return true;
    if(root->left == nullptr && root->right == nullptr) {
        return true;
    }
    if(root->left != nullptr && root->right == nullptr) {
        if(height(root->left) == 1) {
            return true;
        } else {
            return false;
        }
    }
    if(root->right != nullptr && root->left == nullptr) {
        if(height(root->right)==1) {
            return true;
        } else {
            return false;
        }
    }
    return isBalanced(root->left) && isBalanced(root->right) && (abs(height(root->left) - height(root->right)) <= 1);
}

int LC::_0110_BalancedBinaryTree::height(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    }
    if(root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    return 1 + std::max(height(root->left),height(root->right));
}


int LC::_0111_MinimumDepthOfBinaryTree::minDepth(TreeNode* root) {
    if(!root) {
        return 0;
    } else if(!root->left) {
        return minDepth(root->right) + 1;
    } else if(!root->right) {
        return minDepth(root->left) + 1;
    } else {
        return std::min(minDepth(root->left), minDepth(root->right)) + 1;
    }
}

bool LC::_0112_PathSum::hasPathSum(TreeNode* root, int sum) {
    if(root == nullptr) {
        return false;
    }

    if(root->left == nullptr && root->right == nullptr) {
        return (sum == root->val);
    }

    if(root->left == nullptr && root->right != nullptr) {
        return hasPathSum(root->right,sum - root->val);
    }

    if(root->left != nullptr && root->right == nullptr) {
        return hasPathSum(root->left,sum - root->val);
    }
    
    return (hasPathSum(root->left,sum-root->val) || hasPathSum(root->right,sum-root->val));
}

std::vector<std::vector<int>> LC::_0113_PathSumII::pathSum(TreeNode* root, int sum) {
    std::vector<int> tmp;
    std::vector<std::vector<int>> res;
    pathSum(root, sum, tmp, res);
    return res;
}

void LC::_0113_PathSumII::pathSum(TreeNode* root, int sum, std::vector<int> tmp, std::vector<std::vector<int>>& res) {
    if(root == nullptr) {
        return;            
    } else if(root->val == sum && root->left == nullptr && root->right == nullptr) {
        tmp.push_back(root->val);
        res.push_back(tmp);
        return;
    }
    tmp.push_back(root->val);
    pathSum(root->left, sum - root->val, tmp, res);
    pathSum(root->right, sum - root->val, tmp, res);
}

/** 这个解法非常巧妙，记得当时是看答案得到的
 * 一般能想到的方法就是用一个栈或者queue之类的，对树做一次遍历，然后按照栈或者队列中的指针一个一个连起来;
 * 这里是直接处理，也就是如果见到一个节点有左右孩子，那么右子树一定接在左子树最有叶子节点的后面，然后依次调用
 * 如果该节点只有左孩子，那么想办法把他变成右孩子。如果只有右孩子，就不用管了。
 **/
void LC::_0114_FlattenBinaryTreeToLinkedList::flatten(TreeNode* root) {
    TreeNode* ptr = root;
    while(root) {
        if(root->left && root->right) {
            TreeNode* p = root->left;
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



LC::_0116_PopulatingNextRightPointerInEachNode::Node* LC::_0116_PopulatingNextRightPointerInEachNode::connect(
    LC::_0116_PopulatingNextRightPointerInEachNode::Node* root) {
    if(root==nullptr) {
        return root;
    }
    if(root->left != nullptr && root->right != nullptr) {
        root->left->next = root->right;
        if(root->next != nullptr) {
            root->right->next = root->next->left;
        }
        root->left = connect(root->left);
        root->right = connect(root->right);
    }
    return root;
}


LC::_0117_PopulatingNextRightPointersInEachNodeII::Node* LC::_0117_PopulatingNextRightPointersInEachNodeII::connect(Node* root) {
    if(root == nullptr) {
        return nullptr;
    }
    Node* p = root;
    std::queue<std::pair<Node*, int>> q;
    q.push({p, 0});
    while(!q.empty()) {
        const int N = q.size();
        for(int i = 0; i < N; ++i) {
            auto a = q.front();
            auto t = a.first;
            
            q.pop();
            if(!q.empty() && a.second == q.front().second) {
                t->next = q.front().first;
            }
            if(t->left) {
                q.push({t->left, a.second + 1});
            }
            if(t->right) {
                q.push({t->right, a.second + 1});
            }
        }
    }
    return root;
}


// Facebook
// 这道题的解法还是很巧妙的，
// 设计一个 helper 函数，这个函数以树的某个节点为参数，它返回"以这个节点为一侧端点的最长路径"。也就是选左边子树还是选右边子树.
// 然后在这个函数里面夹带一个全局变量，这个全局变量才是要求解的结果
int LC::_0124_BinaryTreeMaximumPathSum::helper(TreeNode* root) {
    if(!root) {
        return 0;
    }
    int left = std::max(helper(root->left), 0); // 一旦发现比0小说明这条路径 不如不要了
    int right = std::max(helper(root->right), 0);
    res = std::max(res, left + right + root->val);
    return std::max(left, right) + root->val;
}
int LC::_0124_BinaryTreeMaximumPathSum::maxPathSum(TreeNode* root) {
    res = INT_MIN;
    helper(root);
    return res;
}