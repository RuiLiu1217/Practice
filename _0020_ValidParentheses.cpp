#include "headers.hpp"
#include <stack>

bool LeetCode::_0020_ValidParentheses::isValid(std:string& s) {
    // () 1 [] 2 {} 3
    std::stack<int> st;
    for(int i = 0 ; i!= s.size(); ++i)
    {
        if(s[i] == '(') {
            st.push(1);
        } else if(s[i] == '[') {
            st.push(2);
        } else if(s[i] == '{') {
            st.push(3);
        } else if(s[i] == ')') {
            if(!st.empty() && st.top() == 1) {
                st.pop();
            } else {
                return false;
            }
        } else if(s[i] == ']') {
            if(!st.empty() && st.top() == 2) {
                st.pop();
            } else {
                return false;
            }
        } else if(s[i] == '}') {
            if(!st.empty() && st.top() == 3) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}