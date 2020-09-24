#include "LeetCode_DFS.hpp"
#include <functional>

//! Copy from solution 
//! 有点绕，不过仔细看一下答案还是不难的。
void LC::_0129_SumRootToLeafNumbers::DFS(TreeNode* root, int carryValue) {
    carryValue = carryValue * 10 + root->val; //! 每下一层都把上面一层的值乘以10 带下来;
    if(root->left == nullptr && root->right == nullptr) {
        sum += carryValue;
    }
    if(root->left) {
        DFS(root->left, carryValue);
    }
    if(root->right) {
        DFS(root->right, carryValue);
    }
}

int LC::_0129_SumRootToLeafNumbers::sumNumbers(TreeNode* root) {
    sum = 0;
    if(root) {
        DFS(root, 0);
    }
    return sum;
}

// ! copy from the solution
std::vector<std::vector<int>> LC::_0254_FactorCombinations::getFactors(int n) {
    std::vector<std::vector<int>> res;
    std::function<void(int, int, std::vector<int>)> DFS = [&](int n, int start,
    std::vector<int> out) { 
        if(n == 1) {
            if(out.size() > 1) {
                res.push_back(out);
                return;
            }
        }

        for(int i = start; i <= n; ++i) {
            if(n % i != 0) {
                continue;
            }
            out.push_back(i);
            DFS(n / i, i, out);
            out.pop_back();
        }
    };

    DFS(n, 2, {});
    return res;
}


bool LC::_0261_GraphValidTree::validTree(int n, std::vector<std::vector<int>>& edges) {
    if(n <= 0) {
        return false;
    }
    if(edges.size() != n - 1) {
        return false;
    }
    std::vector<std::unordered_set<int>> graph(n);

    for(auto e : edges) {
        std::vector<int> visited(n, false);
        if(DFS(graph, visited, e[0], e[1])) {
            return false;
        }
        graph[e[0]].insert(e[1]);
        graph[e[1]].insert(e[0]);
    }
    return true;
}

bool LC::_0261_GraphValidTree::DFS(std::vector<std::unordered_set<int>>& graph, std::vector<int>& visited, int source, int target) {
    if(source == target) {
        return true;
    }
    visited[source] = true;
    for(auto& adj : graph[source]) {
        if(!visited[adj]) {
            if(DFS(graph, visited, adj, target)) {
                return true;
            }
        }
    }
    return false;
}



// Facebook 
//! Copy from the solution
// Need to see the solution again
std::vector<std::string> LC::_0282_ExpressionAddOperators::addOperators(std::string num, int target) {
    std::string exp;
    std::vector<std::string> ans;
    DFS(num, target, 0, exp, 0, 0, ans);
    return ans;
}

void LC::_0282_ExpressionAddOperators::DFS(const std::string& num, const int target, int pos, 
    std::string exp, long prev, long curr, std::vector<std::string>& ans) 
{
    if(pos == num.length()) {
        if(curr == target) {
            ans.push_back(exp);
        }
        return;
    }

    for(int l = 1; l <= num.size() - pos; ++l) {
        std::string t = num.substr(pos, l);
        if(t[0] == '0' && t.length() > 1) {
            continue;
        }
        long n = std::stol(t);
        if(n > INT_MAX) {
            break;
        }
        if(pos == 0) {
            DFS(num, target, l, t, n, n, ans);
            continue;
        }
        DFS(num, target, pos + l, exp + '+' + t, n, curr + n, ans);
        DFS(num, target, pos + l, exp + '-' + t, -n, curr - n, ans);
        DFS(num, target, pos + l, exp + '*' + t, prev * n, curr - prev + prev * n, ans);
    }
}