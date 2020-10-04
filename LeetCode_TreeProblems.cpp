#include "LeetCode_TreeProblems.hpp"
#include <queue>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <stack>
#include <sstream>
#include <map>
#include <unordered_map>
#include <functional>

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

std::vector<int> LC::_0144_BinaryTreePreOrderTraversal::preorderTraversal(LC::TreeNode* root) {
    LC::TreeNode* p = root;
    std::stack<LC::TreeNode*> st;
    std::vector<int> res;
    while(p != nullptr || !st.empty()) {
        if(p != nullptr) {
            res.push_back(p->val);
            st.push(p);
            p = p->left;
        } else {
            LC::TreeNode* q = st.top();
            st.pop();
            p = q->right;
        }
    }
    return res;
}

std::vector<int> LC::_0145_BinaryTreePostorderTraversal::postorderTraversal(LC::TreeNode* root) {
    LC::TreeNode* p = root;
    std::stack<std::pair<LC::TreeNode*, int>> st;
    std::vector<int> res;
    while(p != nullptr || !st.empty()) {
        while(p != nullptr) {
            st.push(std::make_pair(p, 0));
            p = p->left;
        }
        if(!st.empty()) {
            auto temp = st.top();
            st.pop();
            if(temp.second == 0) {
                temp.second = 1;
                st.push(temp);
                p = temp.first->right;
            } else {
                res.emplace_back(temp.first->val);
                p = nullptr; // need to set it as null, otherwise, there will be an error.
            }
        }
    }
    return res;
}



LC::_0173_BinarySearchTreeIterator::_0173_BinarySearchTreeIterator(LC::TreeNode* root) {
    TreeNode* p = root;
    while(p != nullptr) {
        st.push(p);
        p = p->left;
    }
}

/** @return the next smallest number */
int LC::_0173_BinarySearchTreeIterator::next() {
    if(hasNext()) {
        TreeNode* q = st.top();
        st.pop();
        TreeNode* p = q->right;
        while(p) {
            st.push(p);
            p = p->left;
        }
        return q->val;
    } else {
        return INT_MAX;
    }        
}

/** @return whether we have a next smallest number */
bool LC::_0173_BinarySearchTreeIterator::hasNext() {
    return !st.empty();
}


// Tree Level-traversal
std::vector<int> LC::_0199_BinaryTreeRightSideView::rightSideView(TreeNode* root) {
    if(!root) {
        return std::vector<int>();
    }
    std::queue<TreeNode*> Q;
    std::vector<int> res;
    Q.push(root);
    
    while(!Q.empty()) {
        const int N = Q.size();
        int v = -1;
        for(int i = 0; i < N; ++i) {
            auto t = Q.front();
            Q.pop();
            v = t->val;
            if(t->left) {
                Q.push(t->left);
            }
            if(t->right) {
                Q.push(t->right);
            }
        }
        res.push_back(v);            
    }
    return res;
}


// Todo: I don't know why the solution is totally different from what I think of but my solution can pass.
int LC::_0222_CountCompleteTreeNodes::countNodes(TreeNode* root) {
    if(!root) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

LC::TreeNode* LC::_0226_InvertBinaryTree::invertTree(LC::TreeNode* root)  {
    if(!root) {
        return nullptr;
    } else {
        TreeNode* lft = invertTree(root->left);
        TreeNode* rgh = invertTree(root->right);
        root->left = rgh;
        root->right = lft;
        return root;
    }    
}


std::vector<std::string> LC::_0257_BinaryTreePaths::binaryTreePaths(LC::TreeNode* root) {
    if(root == nullptr) {
        return {};
    }
    if(root->left == nullptr && root->right == nullptr) {
        return {std::to_string(root->val)};
    }
    std::vector<std::string> leftString = binaryTreePaths(root->left);
    std::vector<std::string> rightString = binaryTreePaths(root->right);
    std::vector<std::string> res;
    for(int i = 0; i < leftString.size(); ++i) {
        res.push_back(std::to_string(root->val) + "->" + leftString[i]);
    }
    for(int i = 0; i < rightString.size(); ++i) {
        res.push_back(std::to_string(root->val) + "->" + rightString[i]);
    }
    return res;
}


std::string LC::_0428_SerializeAndDeserializeNAryTree::serialize(NAryNode* root) {
    std::string res;
    serializeHelper(root, res);
    return res;
}

LC::NAryNode* LC::_0428_SerializeAndDeserializeNAryTree::deserialize(std::string data) {
    std::istringstream iss(data);
    return deserializeHelper(iss);
}


LC::TreeNode* LC::_0235_LowestCommonAncestor::lowestCommonAncestorRecursive(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root) {
        return nullptr;
    }

    if (root->val > p->val && root->val > q->val) {
        return lowestCommonAncestorRecursive(root->left, p, q);
    }

    if (root->val < p->val && root->val < q->val) {
        return lowestCommonAncestorRecursive(root->right, p, q);
    }
    return root;
}

LC::TreeNode* LC::_0235_LowestCommonAncestor::lowestCommonAncestorIterative(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root) {
        return nullptr;
    }

    LC::TreeNode *t = root;
    while(true) {
        if (t->val > p->val && t->val > q->val) {
            t = t->left;
        } else if (t->val < p->val && t->val < q->val) {
            t = t->right;
        } else {
            return t;
        }
    }
}

/* 
! Representative problem
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
LC::TreeNode* LC::_0236_LowestCommonAncestorBinaryTree::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root || root == p || root == q) {
        return root;
    }
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if(left && right) {
        return root;
    }
    return left ? left : right;
}


bool LC::_0255_VerifyPreorderSequenceInBinarySearchTree::verifyPreorder(std::vector<int>& preorder) {
    if(preorder.size() == 0) {
        return true;
    }
    return isPreorder(preorder, 0, preorder.size());
}

bool LC::_0255_VerifyPreorderSequenceInBinarySearchTree::isPreorder(std::vector<int>& preorder, int startIdx, int endIdx) {
    if(startIdx == endIdx) {
        return true;
    }
    
    if(endIdx - startIdx == 1) {
        return true;
    }
    
    int v = preorder[startIdx];
    int newLeftEndIdx = startIdx + 1;
    while(newLeftEndIdx < endIdx && preorder[newLeftEndIdx] < v) {
        ++newLeftEndIdx;
    }
    int testIdx = newLeftEndIdx;
    while(testIdx < endIdx) {
        if(preorder[testIdx] < v) {
            return false;
        }
        ++testIdx;
    }
    
    return isPreorder(preorder, startIdx + 1, newLeftEndIdx) && isPreorder(preorder, newLeftEndIdx, endIdx);
}


// Facebook
int LC::_0270_ClosetBinarySearchTreeValue::closestValue(TreeNode* root, double target) {
    int closet = root->val;
    while(root) {
        if(std::abs(closet - target) >= std::abs(root->val - target)) {
            closet = root->val;
        }
        root = target < root->val ? root->left : root->right;
    }
    return closet;
}


LC::TreeNode* LC::_0285_InorderSuccessorInBST::getNext() {
    if(!st.empty()) {
        TreeNode* p = st.top();  st.pop();
        TreeNode* t = p->right;
        while(t) {
            st.push(t);
            t = t->left;
        }
        return p;
    } else {
        return nullptr;
    }
}

LC::TreeNode* LC::_0285_InorderSuccessorInBST::inorderSuccessor(TreeNode* root, TreeNode* p) {
    while(root) {
        st.push(root);
        root = root->left;
    }
    while(true) {
        TreeNode* t = getNext();
        if(!t || t == p) {
            break;
        }
    }
    return getNext();
}


std::vector<std::vector<int>> LC::_0314_BinaryTreeVertialOrderTraversal::verticalOrder(TreeNode* root) {
    if(!root) {
        return {};
    }
    std::map<int, std::map<int, std::vector<int>>> nodes;
    std::queue<std::pair<TreeNode*, std::pair<int, int>>> q;
    q.push({root, {0, 0}});
    while(!q.empty()) {
        const int N = q.size();
        for(int i = 0; i < N; ++i) {
            auto f = q.front();
            q.pop();
            TreeNode* node = f.first;
            int x = f.second.first;
            int y = f.second.second;
            nodes[x][y].push_back(node->val);
            if(node->left) {
                q.push({node->left, {x-1,y+1}});
            }
            if(node->right) {
                q.push({node->right, {x+1, y+1}});
            }
        }
    }
    
    std::vector<std::vector<int>> res;
    for(auto& n : nodes) {
        std::vector<int> col;
        for(auto& t : n.second) {
            col.insert(col.end(), begin(t.second), end(t.second));
        }
        res.push_back(col);
    }
    return res;        
}

//! COPY FROM THE SOLUTION
//! https://www.cnblogs.com/grandyang/p/5174738.html
/* 
我们通过举一些正确的例子，比如"9,3,4,#,#,1,#,#,2,#,6,#,#" 或者"9,3,4,#,#,1,#,#,2,#,6,#,#"等等，可以观察出如下两个规律：
1. 数字的个数总是比#号少一个
2. 最后一个一定是#号
那么我们加入先不考虑最后一个#号，那么此时数字和#号的个数应该相同，如果我们初始化一个为0的计数器，遇到数字，计数器加1，遇到#号，
计数器减1，那么到最后计数器应该还是0。下面我们再来看两个返回False的例子，"#,7,6,9,#,#,#"和"7,2,#,2,#,#,#,6,#"，那么通过这
两个反例我们可以看出，如果根节点为空的话，后面不能再有节点，而且不能有三个连续的#号出现。所以我们再加减计数器的时候，如果遇到#
号，且此时计数器已经为0了，再减就成负数了，就直接返回False了，因为正确的序列里，任何一个位置i，在[0, i]范围内的#号数都不大于
数字的个数的。当循环完成后，我们检测计数器是否为0的同时还要看看最后一个字符是不是#号。
*/

bool LC::_0331_VerifyPreorderSerializationOfABinaryTree::isValidSerialization(std::string preorder) {
    std::stack<std::pair<std::string, int>> Q;
    if(preorder.size() == 1 && preorder[0] == '#') {
        return true;
    }
    preorder += ',';
    std::string curStr;
    
    for(int i = 0; i < preorder.size(); ++i) {
        char c = preorder[i];
        if(c == ',') {
            if(!curStr.empty()) {
                if(curStr == "#") {
                    if(Q.empty()) {
                        return false;
                    } else {
                        if(Q.top().second == 2) {
                            auto& t = Q.top();
                            t.second = 1;
                        } else {
                            while(!Q.empty() && Q.top().second == 1) {
                                Q.pop();
                            }
                            if(!Q.empty()) {
                                Q.top().second = 1;
                            } else {
                                return i == preorder.size() - 1;
                            }   
                        }
                    }
                } else {
                    Q.push(std::make_pair(curStr, 2));
                }
                curStr.clear();
            } else {
                return false;
            }
        } else {
            curStr += c;
        }
    }
    return Q.empty();
}

int LC::_0404_SumOfLeftLeaves::sumOfLeftLeaves(TreeNode* root) {
    if(!root) {
        return 0;
    }
    int sum = 0;
    if(root->left && root->left->left == nullptr && root->left->right == nullptr) {
        sum = root->left->val;
    }
    return sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}

// Facebook
using Nod = LC::_0426_ConvertBinarySearchTreeToSortedDoublyLinkedList::Node;
Nod* LC::_0426_ConvertBinarySearchTreeToSortedDoublyLinkedList::treeToDoublyList(Nod* root) {
    std::pair<Nod*, Nod*> res = conn(root);
    return res.first;
}

std::pair<Nod*, Nod*> LC::_0426_ConvertBinarySearchTreeToSortedDoublyLinkedList::conn(Nod* root) {
    if(!root) {
        return {nullptr, nullptr};
    }
    if(root->left == nullptr && root->right == nullptr) {
        root->left = root;
        root->right = root;
        return {root, root};
    }

    auto [lhead, ltail] = conn(root->left);
    auto [rhead, rtail] = conn(root->right);

    // There are edge cases to be considered.
    if(lhead == nullptr && rhead == nullptr) {
        root->left = root;
        root->right = root;
        return {root, root};
    } else if(lhead == nullptr && rhead != nullptr) {
        root->right = rhead;
        rhead->left = root;
        root->left = rtail;
        rtail->right = root;
        return {root, rtail};
    } else if(lhead != nullptr && rhead == nullptr) {
        root->left = ltail;
        root->right = lhead;
        lhead->left = root;
        ltail->right = root;
        return {lhead, root};
    } else {
        root->left = ltail;
        root->right = rhead;
        ltail->right = root;
        rhead->left = root;
        lhead->left = rtail;
        rtail->right = lhead;
        return {lhead, rtail};
    }
}

LC::QuadTreeNode* LC::_0427_ConstructQuadTree::construct(std::vector<std::vector<int>>& grid) {
    int N = grid.size();
    if(N == 0) {
        return nullptr;
    }
    if(N == 1) {
        QuadTreeNode* res = new QuadTreeNode(grid[0][0], true, nullptr, nullptr, nullptr, nullptr);
        return res;
    }
    if(areConsistent(grid)) {
        QuadTreeNode* res = new QuadTreeNode(grid[0][0], true, nullptr, nullptr, nullptr, nullptr);
        return res;
    } else {
        std::vector<std::vector<std::vector<int>>> divideGrids = divideGrid(grid);
        QuadTreeNode* children[4];
        for(int i = 0; i < 4; ++i) {
            if(areConsistent(divideGrids[i])) {
                children[i] = new QuadTreeNode(divideGrids[i][0][0], true, nullptr, nullptr, nullptr, nullptr);
            } else {
                children[i] = construct(divideGrids[i]);
            }
        }
        QuadTreeNode* res = new QuadTreeNode(grid[0][0], false, children[0], children[1], children[2], children[3]);
        return res;
    }
}

LC::QuadTreeNode *LC::_0427_ConstructQuadTree::construct(std::vector<std::vector<int>> &grid, int rowStart, int rowEnd, int colStart, int colEnd) {
    if (grid.size() == 0 || rowStart == rowEnd || colStart == colEnd) {
        return nullptr;
    }
    if (grid.size() == 1 || grid[0].size() == 1 || rowEnd - rowStart == 1 || colEnd - colStart == 1) {
        QuadTreeNode *res = new QuadTreeNode(grid[rowStart][colStart], true, nullptr, nullptr, nullptr, nullptr);
        return res;
    }
    if (areConsistent(grid, rowStart, rowEnd, colStart, colEnd)) {
        QuadTreeNode *res = new QuadTreeNode(grid[rowStart][colStart], true, nullptr, nullptr, nullptr, nullptr);
        return res;
    } else {
        QuadTreeNode *children[4];
        children[0] = construct(grid, rowStart, rowStart + (rowEnd - rowStart) / 2, colStart, colStart + (colEnd - colStart) / 2);
        children[1] = construct(grid, rowStart, rowStart + (rowEnd - rowStart) / 2, colStart + (colEnd - colStart) / 2, colEnd);
        children[2] = construct(grid, rowStart + (rowEnd - rowStart) / 2, rowEnd, colStart, colStart + (colEnd - colStart) / 2);
        children[3] = construct(grid, rowStart + (rowEnd - rowStart) / 2, rowEnd, colStart + (colEnd - colStart) / 2, colEnd);
        QuadTreeNode *res = new QuadTreeNode(grid[rowStart][colStart], false, children[0], children[1], children[2], children[3]);
        return res;
    }
}

bool LC::_0427_ConstructQuadTree::areConsistent(std::vector<std::vector<int>> &grid) {
    const size_t M = grid.size();
    const size_t N = grid[0].size();
    int gld = grid[0][0];
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (grid[i][j] != gld) {
                return false;
            }
        }
    }
    return true;
}

bool LC::_0427_ConstructQuadTree::areConsistent(std::vector<std::vector<int>> &grid, int rowStart, int rowEnd, int colStart, int colEnd) {
    int gld = grid[rowStart][colStart];
    for (int i = rowStart; i < rowEnd; ++i) {
        for (int j = colStart; j < colEnd; ++j) {
            if (grid[i][j] != gld) {
                return false;
            }
        }
    }
    return true;
}

std::vector<std::vector<std::vector<int>>> LC::_0427_ConstructQuadTree::divideGrid(std::vector<std::vector<int>> &grid) {
    const size_t M = grid.size();
    const size_t N = grid[0].size();

    const size_t OM = M / 2;
    const size_t ON = N / 2;

    std::vector<std::vector<std::vector<int>>> res(4);
    res[0].resize(OM);
    res[1].resize(OM);
    res[2].resize(OM);
    res[3].resize(OM);
    for (int i = 0; i < OM; ++i) {
        res[0][i].resize(ON);
        res[1][i].resize(ON);
        res[2][i].resize(ON);
        res[3][i].resize(ON);
        for (int j = 0; j < ON; ++j) {
            res[0][i][j] = grid[i][j];
            res[1][i][j] = grid[i][j + ON];
            res[2][i][j] = grid[i + OM][j];
            res[3][i][j] = grid[i + OM][j + ON];
        }
    }
    return res;
}

std::vector<std::vector<int>> LC::_0429_NaryTreelevelOrderTraversal::levelOrder(NaryTreeNode* root) {
    if(!root) {
        return {};
    }
    std::vector<std::vector<int>> res;
    std::queue<NaryTreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        const int N = q.size();
        std::vector<int> tmp;
        for(int i = 0; i < N; ++i) {
            NaryTreeNode* t = q.front();
            q.pop();
            tmp.push_back(t->data);
            for(int j = 0; j < t->children.size(); ++j) {
                if((t->children)[j]) {
                    q.push((t->children)[j]);
                }
            }
        }
        res.push_back(tmp);
    }
    return res;
}

LC::_0510_InorderSuccessorInBSTII::Node* LC::_0510_InorderSuccessorInBSTII::inorderSuccessor(Node* node) {
    if(!node) {
        return nullptr;
    }

    if(node->right) {
        Node* potSucc = node->right;
        while(potSucc->left) {
            potSucc = potSucc->left;
        }
        return potSucc;
    } else {
        while(node->parent && node->parent->left != node) { //! important! this logic is hard to think of
            node = node->parent;
        }
        return node->parent;
    }
}

int LC::_0559_MaximumDepthOfNaryTree::maxDepth(LC::NaryTreeNode* root) {
    if(!root) {
        return 0;
    } else {
        int height = 0;
        for(int i = 0; i < root->children.size(); ++i) {
            int curH = maxDepth(root->children[i]);
            if(curH > height) {
                height = curH;
            }
        }
        return height + 1;
    }
}

bool LC::_0572_SubtreeOfAnotherTree::isSubtree(TreeNode* s, TreeNode* t) {
    TreeNode* p = s;
    std::stack<TreeNode*> st;
    while(p != nullptr || !st.empty()) {
        if(p != nullptr) {
            if(isSame(p, t)) {
                return true;
            }
            st.push(p);
            p = p->left;
        } else {
            TreeNode* q = st.top();
            st.pop();
            p = q->right;
        }
    }
    return false;
}

bool LC::_0572_SubtreeOfAnotherTree::isSame(TreeNode* s, TreeNode* t) {
    if(s == nullptr && t == nullptr) {
        return true;
    }
    if(s == nullptr && t != nullptr) {
        return false;
    }
    if(s != nullptr && t == nullptr) {
        return false;
    }
    return (s->val == t->val) && isSame(s->left, t->left) && isSame(s->right, s->right);
}


std::vector<int> LC::_0589_NaryTreePreorderTraversal::preorder(NaryTreeNode* root) {
    std::stack<NaryTreeNode*> st;
    if(!root) {
        return std::vector<int>();
    } else {
        NaryTreeNode* p = root;
        st.push(p);
        std::vector<int> res;
        while(!st.empty()) {
            NaryTreeNode* tp = st.top();
            res.push_back(tp->data);
            st.pop();
            for(int i = tp->children.size()-1; i >= 0; --i) {
                st.push(tp->children[i]);
            }
        }
        return res;
    }
}

std::vector<int> LC::_0590_NaryTreePostOrderTraversal::postorder(LC::NaryTreeNode* root) {
    // Implementation of the post order recursively
    std::function<void(LC::NaryTreeNode*, std::vector<int>&)> postOrderRecursive = [&](LC::NaryTreeNode* root, std::vector<int>& res){
        if(root) {
            for(auto child : root->children) {
                postOrderRecursive(child, res);
            }
            res.push_back(root->data);
        }
    };

    LC::NaryTreeNode* p = root;
    std::stack<std::pair<LC::NaryTreeNode*, int>> stack;
    if(p == nullptr) {
        return {};
    }
    std::vector<int> res;
    stack.push({p, 0});
    while(!stack.empty()) { // Very important skills to write a post order traversal of a tree
        if(stack.top().second == 0) {
            p = stack.top().first;
            stack.pop();
            stack.push({p, 1});
            for(int i = p->children.size() - 1; i >= 0; --i) { // reverse order to push children
                if(p->children[i]) {
                    stack.push({p->children[i], 0});
                }
            }
        } else {
            res.push_back(stack.top().first->data);
            stack.pop();
        }
    }
    return res;
}

LC::TreeNode* LC::_0617_MergeTwoBinaryTrees::mergeTrees(LC::TreeNode* t1, LC::TreeNode* t2) {
    if(t1 == nullptr && t2 == nullptr) {
        return nullptr;
    } else if(t1 == nullptr && t2 != nullptr) {
        return t2;
    } else if(t1 != nullptr && t2 == nullptr) {
        return t1;
    }else {
        TreeNode* root = new TreeNode(t1->val + t2->val);
        root->left = mergeTrees(t1->left, t2->left);
        root->right = mergeTrees(t1->right, t2->right);
        return root;
    }
}


std::vector<double> LC::_0637_AverageOfLevelsInBinaryTree::averageOfLevels(TreeNode* root) {
    std::queue<TreeNode*> q;
    q.push(root);
    std::vector<double> res;
    while(!q.empty()) {
        const int N = q.size();
        long sum = 0;
        for(int i = 0; i < N; ++i) {
            auto f = q.front();
            sum += f->val;                
            q.pop();
            
            if(f->left) {
                q.push(f->left);
            }
            if(f->right) {
                q.push(f->right);
            }
        }
        res.push_back(sum / static_cast<double>(N));
    }
    return res;
}


LC::TreeNode* LC::_0654_MaximumBinaryTree::constructMaximumBinaryTree(std::vector<int>& nums) {
    return constructMaximumBinaryTree_impl(nums.begin(), nums.end());
}
LC::TreeNode* LC::_0654_MaximumBinaryTree::constructMaximumBinaryTree_impl(std::vector<int>::iterator l, std::vector<int>::iterator r) {
    if(l == r) {
        return nullptr;
    }
    std::vector<int>::iterator it = std::max_element(l, r);
    TreeNode* root = new TreeNode(*it);
    root->left = constructMaximumBinaryTree_impl(l, it);
    root->right =constructMaximumBinaryTree_impl(it + 1, r);
    return root;
}

bool LC::_0663_EqualTreePartition::checkEqualTree(TreeNode* root) {
    int totalSum = treeSum(root);
    if(totalSum % 2) {
        return false;
    }
    bool dividable = false;
    int res = foo(root, totalSum / 2, dividable);
    return dividable;
}

int LC::_0663_EqualTreePartition::treeSum(TreeNode* root) {
    if(!root) {
        return 0;
    }
    return treeSum(root->left) + treeSum(root->right) + root->val;
}

int LC::_0663_EqualTreePartition::foo(TreeNode* root, int target, bool& dividable) {
    if(!root) {
        return 0;
    }
    
    int left = foo(root->left, target, dividable);
    int right = foo(root->right, target, dividable);
    if((root->left && left == target) || (root->right && right == target)) { // ! I forgot why need to judge root->left or root->right is not nullptr
        dividable = true;
    }
    return left + right + root->val;        
}