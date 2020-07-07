#include "headers.hpp"

// std::string serialize(TreeNode<int>* root) {
//     if(!root) {
//         return {};
//     }
//     std::string res;
//     int v = root->val;
//     res += static_cast<char>(v & 0xff);
//     v >>= 8;
//     res += static_cast<char>(v & 0xff);
//     v >>= 8;
//     res += static_cast<char>(v & 0xff);
//     v >>= 8;
//     res += static_cast<char>(v & 0xff);
//     if(!root->left && !root->right) {
//         return res;
//     }
//     std::string left = serialize(root->left);
//     std::string right = serialize(root->right);
//     res += left;
//     res += right;
//     return res;
// }

// TreeNode<int>* deserialize(std::string s) {
//     if(s.empty()) {
//         return nullptr;
//     }
//     int v = 0;
//     v |= static_cast<int>(s[0]);
//     v |= static_cast<int>(s[1] << 8);
//     v |= static_cast<int>(s[2] << 16);
//     v |= static_cast<int>(s[3] << 24);
//     TreeNode<int>* root = new TreeNode<int>(v);
//     if(s.size() == 4) {        
//         return root;
//     }

//     int i = 1;
//     int l = 0;
//     l |= static_cast<int>(s[i * 4]);
//     l |= static_cast<int>(s[i * 4 + 1] << 8);
//     l |= static_cast<int>(s[i * 4 + 2] << 16);
//     l |= static_cast<int>(s[i * 4 + 3] << 24);
//     while(l < v) {
//         ++i;
//         l = 0;
//         l |= static_cast<int>(s[i * 4]);
//         l |= static_cast<int>(s[i * 4 + 1] << 8);
//         l |= static_cast<int>(s[i * 4 + 2] << 16);
//         l |= static_cast<int>(s[i * 4 + 3] << 24);
//     }
//     std::string subsLeft = s.substr(1, i * 4);
//     std::string subsRight = s.substr(i * 4);
//     root->left = deserialize(subsLeft);
//     root->right = deserialize(subsRight);
// }

class _0449_SerializeAndDeserializeBST {
public:
    // Encodes a tree to a single string.
    std::string serialize(TreeNode<int>* root) {
        std::string s;
        serialize(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode<int>* deserialize(std::string data) {
        int pos = 0;
        return deserialize(data, pos, INT_MIN, INT_MAX);
    }

private:
    void serialize(TreeNode<int>* root, std::string& s) {
        if(!root) {
            return;
        }
        s.append(reinterpret_cast<const char*>(&root->val), sizeof(root->val));
        serialize(root->left, s);
        serialize(root->right, s);
    }
    
    TreeNode<int>* deserialize(const std::string& s, int& pos, int curMin, int curMax) {
        if(pos >= s.size()) {
            return nullptr;
        }
        int val = *reinterpret_cast<const int*>(s.data() + pos);
        if(val < curMin || val > curMax) {
            return nullptr;
        }
        pos += sizeof(val);
        TreeNode<int>* root = new TreeNode<int>(val);
        root->left = deserialize(s, pos, curMin, val);
        root->right = deserialize(s, pos, val, curMax);
        return root;
    }
};
