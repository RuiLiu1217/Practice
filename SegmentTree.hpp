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

class SegmentTreeArrayBased {
private:
    std::vector<int> tree;
public:
    // Segment tree Array based
    void buildSegTree(std::vector<int>& arr, int treeIndex, int lo, int hi) {
        if(lo == hi) {
            tree[treeIndex] = arr[lo];
            return;
        }
        int mid = (hi - lo) / 2 + lo;
        buildSegTree(arr, treeIndex * 2 + 1, lo, mid);  // index is 0 based.
        buildSegTree(arr, treeIndex * 2 + 2, mid+1, hi);

        tree[treeIndex] = merge(tree[treeIndex * 2 + 1], tree[treeIndex * 2 + 2]); //
    }
    // query range [i    j]
    // index range [lo    hi]
    // several cases:
    // 1.  [i   j] |
    //             | [lo  hi]
    //  or 
    //    [lo  hi] |
    //             |  [i  j]
    // complete outside the range

    // 2.  [lo  i   j   hi] // Complete inside the range --> directly return the tree[treeIndex]
    // 3.  [lo    mid    hi] --> mid = lo + (hi - lo) / 2
    // 3.1
    //      [lo    mid  i  hi]  --> querySegTree(2 * treeIndex + 2, mid+1, hi, i, j)
    // 3.2
    //      [lo j  mid     hi]  --> querySegTree(2 * treeIndex + 1, lo, mid, i, j);
    // 3.3
    //      [lo i  mid  j  hi]  --> 
    //                              int left = querySegTree(2 * treeIndex + 1, low, mid, i, mid);
    //                              int right= querySegTree(2 * treeIndex + 2, mid+1, hi, mid+1, j);
    int querySegTree(int treeIndex, int lo, int hi, int i, int j) {
        // query for arr[i..j]
        if(lo > j || hi < i) {   // segment completely outside range
            return 0;
        }

        if(i <= lo && j >= hi) {  // segment completely inside range
            return tree[treeIndex];
        }
        int mid = lo + (hi - lo) / 2;
        if(i > mid) {
            return querySegTree(2 * treeIndex + 2, mid+1, hi, i, j);
        } else if(j <= mid) {
            return querySegTree(2 * treeIndex + 1, lo, mid, i, j);
        }
        int left = querySegTree(2 * treeIndex + 1, low, mid, i, mid);
        int right= querySegTree(2 * treeIndex + 2, mid+1, hi, mid+1, j);
        return merge(left, right);
    }

    void updateSegTree(int treeIndex, int lo, int hi, int arrIndex, int val) {
        if(lo == hi) {
            tree[treeIndex] = val;
            return;
        }

        int mid = lo + (hi - lo) / 2;
        if(arrIndex > mid) {
            updateSegTree(2 * treeIndex + 2, mid + 1, hi, arrIndex, val);
        } else if(arrIndex <= mid){
            updateSegTree(2 * treeIndex + 1, lo, mid, arrIndex, val);
        }

        tree[treeIndex] = merge(tree[treeIndex * 2 + 1], tree[treeIndex * 2 + 2]);
    }

private:
    int merge(int a, int b) {
        return a + b; // sum- Segment Tree
    }
};






#endif