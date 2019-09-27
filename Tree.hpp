
// Tree Node
template<typename T>
struct TreeNode{
    T val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0), left(nullptr), right(nullptr) {}
    TreeNode(const T& v) : val(v), left(nullptr), right(nullptr) {}
};
