#include "headers.hpp"
#include <stack>
namespace LeetCode {
class _0590_Node {
public:
    int val;
    std::vector<_0590_Node*> children;

    _0590_Node() {}

    _0590_Node(int _val) {
        val = _val;
    }

    _0590_Node(int _val, std::vector<_0590_Node*> _children) {
        val = _val;
        children = _children;
    }
};
}

static void posorder(LeetCode::_0590_Node* root, std::vector<int>& res) {
    if(root) {
        for(auto child : root->children) {
            posorder(child, res);
        }
        res.push_back(root->val);
    }
}
static void postorderIter(LeetCode::_0590_Node* root, std::vector<int>& res) {
    using Node = LeetCode::_0590_Node;
    Node* p = root;
    std::stack<std::pair<Node*, int>> stack;
    if(p == nullptr) {
        return;
    }
    stack.push(std::make_pair(p, 0));
    while(!stack.empty()) {
        if(stack.top().second == 0) {
            p = stack.top().first;
            stack.pop();
            stack.push(std::make_pair(p, 1));
            for(int i = p->children.size() - 1; i >= 0; --i) {
                if(p->children[i] != nullptr) {
                    stack.push(std::make_pair(p->children[i], 0));
                }
            }
        } else {
            res.push_back(stack.top().first->val);
            stack.pop();
        }
    }
}



std::vector<int> LeetCode::_0590_NaryTreePostOrderTraversal::postorder(LeetCode::_0590_Node* root) {
    std::vector<int> res;
    postorderIter(root, res);
    return res;
}