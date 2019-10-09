#ifndef TREE_HPP
#define TREE_HPP
// Tree Node
template <typename T>
struct TreeNode
{
    T val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(const T &v) : val(v), left(nullptr), right(nullptr) {}
};

template <typename T>
struct NaryTreeNode
{
public:
    T data;
    std::vector<NaryTreeNode<T> *> children;

    NaryTreeNode() {}
    NaryTreeNode(int _val, std::vector<NaryTreeNode<T> *> _children)
    {
        data = _val;
        children = _children;
    }
};

// Quad Tree
struct QuadTreeNode
{
public:
    int val;
    bool isLeaf;
    QuadTreeNode *topLeft;
    QuadTreeNode *topRight;
    QuadTreeNode *bottomLeft;
    QuadTreeNode *bottomRight;
    QuadTreeNode() {}
    QuadTreeNode(int v, int isL, QuadTreeNode *tl, QuadTreeNode *tr, QuadTreeNode *bl, QuadTreeNode *br)
    {
        val = v;
        isLeaf = isL;
        topLeft = tl;
        topRight = tr;
        bottomLeft = bl;
        bottomRight = br;
    }
};

#endif