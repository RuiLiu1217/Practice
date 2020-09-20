#include "headers.hpp"
#include <stack>
#include <string>
#include <cassert>
bool LeetCode::_1106_ParsingABolleanExpression::parseBoolExpr(std::string expression) {
    std::stack<char> operation;
    std::stack<char> values;
    for(char c : expression) {
        if(c == '!' || c == '&' || c == '|') {
            operation.push(c);
        } else if(c == '(' || c == 't' || c == 'f') {
            values.push(c);
        } else if(c == ')') {
            if (!operation.empty()) {
                char op = operation.top();
                operation.pop();
                std::vector<char> v;
                while(!values.empty() && values.top() != '(') {
                    v.push_back(values.top());
                    values.pop();
                }
                
                if(!values.empty() && values.top() == '(') {
                    values.pop();
                    if(op == '!') {
                        assert(v.size() == 1);
                        if(v[0] == 't') {
                            values.push('f');
                        } else {
                            values.push('t');
                        }
                    } else if(op == '&') {
                        bool isTrue = true;
                        for(int i = 0; i < v.size(); ++i) {
                            if(v[i] == 'f') {
                                isTrue = false;
                                break;
                            }
                        }
                        if(isTrue) {
                            values.push('t');
                        } else {
                            values.push('f');
                        }
                    } else if(op == '|') {
                        bool isTrue = false;
                        for(int i = 0; i < v.size(); ++i) {
                            if(v[i] == 't') {
                                isTrue = true;
                                break;
                            }
                        }
                        if(isTrue) {
                            values.push('t');
                        } else {
                            values.push('f');
                        }
                    }
                }
            }
        }
    }
    return values.top() == 't';
}