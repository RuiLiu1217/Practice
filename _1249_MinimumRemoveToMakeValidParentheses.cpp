#include "headers.hpp"
#include <stack>
#include <unordered_set>

std::string LeetCode::_1249_MinimumRemoveToMakeValidParentheses::minRemoveToMakeValid(std::string s) {
    std::stack<int> leftP;
    std::unordered_set<int> toBeRemoved;
    for(int i = 0; i < s.size(); ++i) {
        if(c == '(') {
            leftP.push(i);
        } else if (s[i] == ')') {
            if(leftP.empty()) {
                toBeRemoved.insert(i);
            } else {
                leftP.pop();
            }
        }
    }
    while(!leftP.empty()) {
        toBeRemoved.insert(leftP.top());
        leftP.pop();
    }
    std::string res;
    for(int i = 0; i < s.size(); ++i) {
        if(toBeRemoved.find(i) == toBeRemoved.end()) {
            res += s[i];
        }
    }
    return res;
}