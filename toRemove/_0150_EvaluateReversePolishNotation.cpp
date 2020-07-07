#include "headers.hpp"
#include <stack>

int LeetCode::_0150_EvaluateReversePolishNotation::evalRPN(std::vector<std::string>& tokens) {
    std::stack<int> res;
    for(auto s : tokens) {
        if(s == "+" || s == "-" || s == "*" || s == "/") {
            if(res.empty()) {
                return INT_MIN;
            } else {
                int b = res.top();
                res.pop();
                if(res.empty()) {
                    return INT_MIN;
                }
                int a = res.top();
                res.pop();
                
                int c = 0;
                if(s == "+") {
                    c = a + b;
                } else if(s == "-") {
                    c = a - b;
                } else if(s == "*") {
                    c = a * b;
                } else if(s == "/") {
                    c = a / b;
                }
                res.push(c);
            }
        } else {
            res.push(std::stoi(s));
        }
    }
    return res.top();
}