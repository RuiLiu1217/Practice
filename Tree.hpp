
// Tree Node
template<typename T>
struct TreeNode{
    T val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0), left(nullptr), right(nullptr) {}
    TreeNode(const T& v) : val(v), left(nullptr), right(nullptr) {}
};

template<typename T>
struct NaryTreeNode {
    public:
        T data;
        std::vector<NaryTreeNode<T>*> children;

        NaryTreeNode() {}
        NaryTreeNode(int _val, std::vector<NaryTreeNode<T>*> _children) {
            data = _val;
            children = _children;
        }
};
