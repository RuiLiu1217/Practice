#ifndef BASICCALCULATOR_HPP
#define BASICCALCULATOR_HPP

#include <string>
#include <stack>
#include <functional>
// Only integers, assume no syntax error
int priority(char opt)
{
    int p = 0;
    if (opt == '(')
        p = 1;
    if (opt == '+' || opt == '-')
        p = 2;
    if (opt == '*' || opt == '/')
        p = 3;
    return p;
}

void calculate(std::stack<double>& numStack, char opt) {
    
    double rOpNum = numStack.top(); 
    numStack.pop();
    double lOpNum = numStack.top(); 
    numStack.pop();
    double result = 0;
    switch(opt) {
        case '+' :
            result = lOpNum + rOpNum;
            break;
        case '-' :
            result = lOpNum - rOpNum;
            break;
        case '*' :
            result = lOpNum * rOpNum;
            break;
        case '/' :
            result = lOpNum / rOpNum;
            break;
        default:
            break;
    }
    numStack.push(result);
}

double calculator(std::string str) {
    int I = 0;
    int J = str.size() - 1;
    while(str[I] == ' ') {
        ++I;
    }
    while(str[J] == ' ') {
        --J;
    }
    std::string tmp;
    std::stack<double> numStack;
    std::stack<char> opStack;
    
    for(size_t i = 0; i < str.size(); ++i) {
        char token = str[i];

        if(token == '+' || token == '-' || token == '*' || token == '/') {
            if(!tmp.empty()) {
                numStack.push(std::stod(tmp));
                tmp.clear();
            }
            if(opStack.empty()) {
                opStack.push(token);
            } else {
                int tokenPri = priority(token);
                char topOp = opStack.top();
                int topOpPri = priority(topOp);
                if(tokenPri > topOpPri) {
                    opStack.push(token);
                } else {
                    while(tokenPri <= topOpPri) {
                        opStack.pop();
                        calculate(numStack, topOp);
                        if(opStack.size() > 0) {
                            topOp = opStack.top();
                            topOpPri = priority(topOp);
                        } else {
                            break;
                        }
                    }
                    opStack.push(token);
                }
            }
        } else if(token == '(') {
            if(!tmp.empty()) {
                numStack.push(std::stod(tmp));
                tmp.clear();
            }
            opStack.push(token);
        } else if(token == ')') {
            if(!tmp.empty()) {
                numStack.push(std::stod(tmp));
                tmp.clear();
            }
            while(opStack.top() != '(') {
                char topOp = opStack.top();
                calculate(numStack, topOp);
                opStack.pop();
            }
            opStack.pop();
        } else {
            tmp += str[i];
        }
    }

    if(!tmp.empty()) {
        numStack.push(std::stod(tmp));
        tmp.clear();
    }
    
    while(!opStack.empty()) {
        char topOp = opStack.top();
        calculate(numStack, topOp);
        opStack.pop();
    }
    return numStack.top();
}

// 224. Basic Calculator
// Calculate the expression with only number, +/- and ()
int calculate1(std::string &s) {
        std::stack<int> stk;
        long num = 0;
        long sum = 0;
        int sign = 1;
        for (char c : s) {
            if (std::isdigit(c)) {
                num = num * 10 + (int)c - '0';
            } else if (c == '+') {
                sum += num * sign;
                num = 0;
                sign = 1;
            } else if (c == '-') {
                sum += num * sign;
                num = 0;
                sign = -1;
            } else if (c == '(') {
                stk.push(sum);
                stk.push(sign);
                sign = 1;
                sum = 0;
            } else if (c == ')') {
                sum += sign * num;
                num = 0;
                sum *= stk.top(); stk.pop();
                sum += stk.top(); stk.pop();
            }
        }
        sum += sign * num;
        return sum;
    }

#endif