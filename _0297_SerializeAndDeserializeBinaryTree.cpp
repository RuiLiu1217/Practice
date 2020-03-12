#include "headers.hpp"
#include <iostream>
#include <sstream>
// !!! Copy from solution !!!
// Learn the usage of sstream

static void Serialize(TreeNode<int>* root, std::ostringstream& out) {
    if(!root) {
        out<<"# ";
    } else {
        out<<(std::to_string(root->val) + " ");
        Serialize(root->left, out);
        Serialize(root->right, out);
    }
}

std::string LeetCode::_0297_SerializeAndDeserializeBinaryTree::serialize(TreeNode<int>* root) {
    std::ostringstream out;
    Serialize(root, out);
    return out.str();
}

static TreeNode<int>* Deserialize(std::istringstream& in) {
    std::string d;
    in>>d;
    if(d == "#") {
        return nullptr;
    }
    TreeNode<int>* root = new TreeNode<int>(std::stoi(d));
    root->left = Deserialize(in);
    root->right = Deserialize(in);
    return root;
}

TreeNode<int> deserialize(std::string data) {
    std::istringstream in(data);
    return Deserialize(in);
}