// !Tree Traversal

// 树的遍历
// 先序遍历
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
};

// 递归
void preorderRecursive(TreeNode* root, std::vector<int>& res) {
    if(!root) {return;}
    res.push_back(root->val);
    preorderRecursive(root->left, res);
    preorderRecursive(root->right, res);
}

// 迭代
void preorderIterative(TreeNode* root, std::vector<int>& res) {
    TreeNode* p = root;
    std::stack<TreeNode*> st;
    while(p != nullptr || !st.empty()) {
        if(p != nullptr) {
            res.push_back(p->val);

            p = p->left;
        } else {
            TreeNode* q = st.top();
            st.pop();

            p = q->right;
        }
    }
}

// 中序遍历
// 递归
void inorderRecursive(TreeNode* root, std::vector<int>& res) {
    if(!root) {return;}
    inorderRecursive(root->left, res);
    res.push_back(root->val);
    inorderRecursive(root->right, res);
}

// 迭代
void inorderIterative1(TreeNode* root, std::vector<int>& res) {
    TreeNode* p = root;
    std::stack<TreeNode*> st;
    while(p != nullptr || !st.empty()) {
        if(p != nullptr) {
            st.push(p);
            p = p->left;
        } else {
            TreeNode* q = st.top(); st.pop();
            res.push_back(q->val);

            p = q->right;
        }
    }
}
void inorderIterative2(TreeNode* root, std::vector<int>& res) {
    TreeNode* p = root;
    std::stack<TreeNode*> st;
    while(p != nullptr || !st.empty()) {
        while(p != nullptr) {
            st.push(p);
            p = p->left;
        }
        p = st.top(); st.pop();
        res.push_back(p->val);
        p = p->right;
    }
}

// Morris Traversal
void inorderMorris(TreeNode* root, std::vector<int>& res) {
    TreeNode* cur = root;
    TreeNode* pre = nullptr;
    while(cur) {
        if(cur->left) {
            TreeNode* p = cur->left;
            while(p->right && p->right != cur) {
                p = p->right;
            }

            if(!p->right) {
                p->right = cur;
                cur = cur->left;
                continue;
            } else {
                p->right = nullptr;
            }
        }
        res.push_back(cur->val);

        pre = cur;
        cur = cur->right;
    }
}

// 后序遍历

// 递归
void postorderRecursive(TreeNode* root, std::vector<int>& res) {
    if(!res) {return;}
    postorderRecursive(root->left, res);
    postorderRecursive(root->right, res);
    res.push_back(root->val);
}
// 迭代
void postorderIterative(TreeNode* root, std::vector<int>& res) {
    TreeNode* p = root;
    std::stack<std::pair<TreeNode*, int>> st;
    while(p != nullptr || !st.empty()) {
        while(p != nullptr) {
            st.push_back({p, 0});
            p = p->left;
        }
        if(!st.empty()) {
            auto [ptr, time] = st.top(); st.pop();
            if(time == 0) {
                st.push({ptr, 1});
                p = ptr->right;
            } else {
                res.push_back(ptr->val);
                p = nullptr;
            }
        }
    }
}

// Binary Search Tree Iterator
// 二叉搜索树迭代器;
class BSTIter {
private:
    std::stack<TreeNode*> st;
public:
    BSTIter(TreeNode* root) {
        while(root) {
            st.push(root);
            root = root->left;
        }
    }
    bool hasNext() {
        return !st.empty();
    }
    int next() {
        if(hasNext()) {
            TreeNode* p = st.top();
            st.pop();
            int val = p->val;
            TreeNode* t = p->right;
            while(t) {
                st.push(t);
                t = t->left;
            }
            return val;
        } else {
            return INT_MIN; // cannot find the value;
        }
    }
};

/*******************************************************/
// ! Union Find
class UnionFind {
public:
    struct Element {
        int parent;
        int rank;
        int size;
    };
    std::vector<Element> mSet;
    UnionFind(int n) {
        mSet.resize(n);
        int i = 0;
        for(auto& m : mSet) {
            m.parent = i++;
            m.rank = 0;
            m.size = 1;
        }
    }

    int find(int x) {
        if(mSet[x].parent != x) {
            mSet[x].parent = find(mSet[x].parent);
        }
        return mSet[x].parent;
    }

    int UnionByRank(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);
        if(xRoot == yRoot) {
            return;
        }
        if(mSet[xRoot].rank < mSet[yRoot].rank) {
            std::swap(xRoot, yRoot);
        }

        mSet[yRoot].parent = xRoot; // xRoot <-- yRoot; // rank大的那个总成为parent
        if(mSet[xRoot].rank == mSet[yRoot].rank) {
            ++mSet[xRoot].rank;
        }
    }
    int UnionBySize(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);
        if(xRoot == yRoot) {
            return;
        }

        if(mSet[xRoot].size < mSet[yRoot].size) {
            std::swap(xRoot, yRoot);
        }
        mSet[yRoot].parent = mSet[xRoot];
        mSet[xRoot].size += mSet[yRoot].size;
    }
};

/*******************************************************/
// ! Segment Tree
// 树型表达
// 给一个数组, 从start = 0 到 end = n， 一共n+1个元素
struct SegTreeNode {
    int start;
    int end;    // The interval it represent
    int val;    // 在区间内具有某种意义的值，比如最大值，或者最小值或者统计和之类的;
    SegTreeNode* left;
    SegTreeNode* right;
    SegTreeNode(int start, int end, int val) : start(start), end(end), val(val), left(nullptr), right(nullptr) {}
};
struct SegTreeOp { // 比如某种特殊的操作
    int operator()(int a, int b) {
        return a + b; // 可以根据实际需要做调整;
    }
};

SegTreeNode* buildTree(int start, int end, std::vector<int>& vals) {
    if(start == end) {
        return new SegTreeNode(start, end, vals[start]);
    }
    int mid = start + (end - start) / 2;
    SegTreeNode* left = buildTree(start, mid, vals); // 注意 start, mid, end之间的界限关系, mid 是包含在左边的
    SegTreeNode* right = buildTree(mid+1, end, vals);
    SegTreeNode* root = new SegTreeNode(start, end, SegTreeOp(left->val, right->val));
    root->left = left;
    root->right = right;
    return r;
}

void updateTree(SegTree* root, int index, int val) {
    if(root->start == root->end && root->start == index) {
        root->val = val; // just update one value
        return;
    }
    int mid = root->start + (root->end - root->start) / 2;
    if(index <= mid) { // 包含在左边即当下标小于等于 mid时，总是要更新左边
        updateTree(root->left, index, val);
    } else {
        updateTree(root->right, index, val);
    }
    root->val = SegTreeOp(root->left->val, root->right->val);
}

int queryTree(SegTree* root, int i, int j) {
    if(root->start == i && root->end == j) {
        return root->val;
    }
    int mid = root->start + (root->end - root->start) / 2;
    if(j <= mid) { // mid 包含在左边;
        return queryTree(root->left, i, j);
    } else if(i > mid) {
        return queryTree(root->right, i, j);
    } else {
        int left = queryTree(root->left, i, mid); // 不是j 而是mid为了缩小范围
        int right = queryTree(root->right, mid+1, j); // 不是i而是mid+1，同理
        return SegTreeOp(left, right);
    }
}

// Segment Tree Array 表示
class SegTreeArray {
private:
    std::vector<int> tree;
    int n; // length of the array
public:
    // Segment Tree Array Based
    void buildTree(std::vector<int>& arr) {
        // insert leaf nodes in tree 
        n = arr.size();
        for (int i=0; i < n; i++){
            tree[n+i] = arr[i];       
        }
        // build the tree by calculating parents 
        for (int i = n - 1; i > 0; --i) {
            tree[i] = tree[i<<1] + tree[i<<1 | 1];
        }
    }
    // function to get sum on interval [l, r), (r is exclusive)
    int query(int i, int j) {
        int res = 0;
        for(l += n, r +=n; l < r ; l >>= 1, r >>= 1) {
            if(l & 1) {
                res += tree[l++];
            }
            if(r & 1) {
                res += tree[--r];
            }
        }
        return res;
    }
    
    void update(int p, int val) {
        // set value at position p 
        tree[p + n] = val; 
        p = p + n;     
        // move upward and update parents 
        for (int i=p; i > 1; i >>= 1) 
        {
            tree[i>>1] = tree[i] + tree[i^1]; 
        }
    }
};

/****************************************************************************/
// ! Reverse Single Link
struct LinkNode {
    int val;
    LinkNode* next;
};

LinkNode* reverseRecursive(LinkNode* head) {
    if(!head || !head->next) {
        return head;
    }
    LinNode* nh = reverseRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return nh;
}

LinkNode* reverseIterative(LinkNode* head) { //! 容易绕住，需要多加练习;
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while(curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}