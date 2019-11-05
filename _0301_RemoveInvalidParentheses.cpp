#include "headers.hpp"
// 这道题是hard题，最难的一点是一开始怎么能想到用DFS
// 看答案的：
std::vector<std::string> LeetCode::_0301_RemoveInvalidParentheses::removeInvalidParentheses(const std::string& s) {
    int l = 0;
    int r = 0;

    // 计算有多少个左括号，右括号落单
    for(const char ch : s) {
        l += (ch == '(');
        if(l == 0) {
            r += (ch == ')');
        } else {
            l -= (ch == ')');
        }
    }

    std::vector<std::string> ans;
    DFS(s, 0, l, r, ans);
    return ans;
}


bool LeetCode::_0301_RemoveInvalidParentheses::isValid(const std::string& s) {
    int count = 0;
    for(const char ch : s) {
        if(ch == '(') ++count;
        if(ch == ')') --count;
        if(count < 0) {
            return false;
        }
    }
    return count == 0;    
}



void LeetCode::_0301_RemoveInvalidParentheses::DFS(const std::string& s, int start, int l, int r, std::vector<std::string>& ans) {
    if(l == 0 && r == 0) {
        if(isValid(s)) {
            ans.push_back(s);
            return;
        }
    }

    for(int i = start; i < s.length(); ++i) {
        if(i != start && s[i] == s[i-1]) continue; // remove duplicate for example: "))))))"

        if(s[i] == '(' || s[i] == ')') {
            std::string curr = s;
            curr.erase(i, 1); // remove the i-th parentheses
            if(s[i] == ')') {
                DFS(curr, i, l, r-1, ans);
            } else if(s[i] == '(') {
                DFS(curr, i, l-1, r, ans);
            }
        }
    }
}