#ifndef SEGMENT_TREE
#define SEGMENT_TREE
#include <vector>
// Binary Tree
// build(start, end, vals)
// update(index, value)
// rangeQuery(start, end)

struct SegmentTreeNode {
    int start;
    int end;
    int sum; // can be max/min,
    SegmentTreeNode* left;
    SegmentTreeNode* right;
    SegmentTreeNode(int start, int end, int sum) : start(start), end(end), sum(sum), left(nullptr), right(nullptr) {}
};

class Add {
public:
    int operator()(int a, int b) {
        return a + b;
    }
};

template<typename OP>
SegmentTreeNode* buildTree(int start, int end, const std::vector<int>& vals) {
    if(start == end) {
        SegmentTreeNode* r = new SegmentTreeNode(start, end, vals[start]);
        return r;
    }
    int mid = start + (end - start) / 2;
    SegmentTreeNode* left = buildTree(start, mid, vals);
    SegmentTreeNode* right = buildTree(mid+1, end, vals);
    SegmentTreeNode* r = new SegmentTreeNode(start, end, OP(left->sum, right->sum));
    r->left = left;
    r->right = right;
    return r;
}

template<typename OP>
void updateTree(SegmentTreeNode* root, int index, int val) {
    if(root->start == root->end && root->start == index) {
        root->sum = val;
        return;
    }
    int mid = root->start + (root->end - root->start) / 2;
    if(index <= mid) {
        updateTree(root->left, index, val);
    } else {
        updateTree(root->right, index, val);
    }
    root->sum = OP(root->left->sum, root->right->sum);
}

template<typename OP>
int query(SegmentTreeNode* root, int i, int j) {
    if(root->start == i && root->end == j) {
        return root->sum;
    }
    int mid = root->start + (root->end - root->start) / 2;
    if (j <= mid) {
        return query(root->left, i, j);
    } else if(i > mid) {
        return query(root->right, i, j);
    } else {
        return OP(query(root->left, i, mid), query(root->right, mid+1, j));
    }
}


#endif