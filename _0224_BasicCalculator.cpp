#include "headers.hpp"
// !!! Copy from the solution
void LeetCode::_0224_BasicCalculator::pushNum(std::stack<double>& numStack, std::string& tmp) {
    if(!tmp.empty()) {
        numStack.push(std::stod(tmp));
        tmp.clear();
    }
}

void LeetCode::_0224_BasicCalculator::cal(std::stack<double>& numStack, char op) {
    double rOpNum = numStack.top();
    numStack.pop();
    double lOpNum = numStack.top();
    numStack.pop();
    int res = 0;
    switch(op) {
        case '+' :
            res = lOpNum + rOpNum;
            break;
        case '-' :
            res = lOpNum - rOpNum;
            break;
        case '*' :
            res = lOpNum * rOpNum;
            break;
        case '/' :
            res = lOpNum / rOpNum;
            break;
    }
    numStack.push(res);
}

int LeetCode::_0224_BasicCalculator::priority(char op) {
    int p = 0;
    if(op == '(') {
        p = 1;
    }
    if(op == '+' || op == '-') {
        p = 2;
    }
    if(op == '*' || op == '/') {
        p = 3;
    }
    return p;
}

int LeetCode::_0224_BasicCalculator::calculate(std::string s) {
    size_t startIdx = 0;
    size_t endIdx = s.size() - 1;
    while(s[startIdx] == ' ') {
        ++startIdx;
    }
    while(s[endIdx] == ' ') {
        --endIdx;
    }

    std::stack<double> numStack;
    std::stack<char> opStack;
    std::string tmp;
    for(size_t i = startIdx; i <= endIdx; ++i) {
        char token = s[i];
        if(token == '+' || token == '-' || token == '*' || token == '/') {
            pushNum(numStack, tmp);
            if(opStack.empty()) {
                opStack.push(token);
            } else {
                int curPri = priority(token);
                char topOp = opStack.top();
                int topPri = priority(topOp);
                if(curPri > topPri) {
                    opStack.push(token);
                } else {
                    while(curPri <= topPri) {
                        opStack.pop();
                        cal(numStack, topOp);
                        if(opStack.size() > 0) {
                            topOp = opStack.top();
                            topPri = priority(topOp);
                        } else {
                            break;
                        }
                    }
                    opStack.push(token);
                }
            }
        } else if(token == '(') {
            pushNum(numStack, tmp);
            opStack.push(token);
        } else if(token == ')') {
            pushNum(numStack, tmp);
            // Calculate until see the '('
            while(!opStack.empty() && opStack.top() != '(') {
                char topOp = opStack.top();
                cal(numStack, topOp);
                opStack.pop();
            }
            opStack.pop(); // pop "(";
        } else if(token >= '0' && token <= '9') {
            tmp += token;
        } else {
            continue;
        }
    }

    if(!tmp.empty()) {
        numStack.push(std::stod(tmp));
        tmp.clear();
    }
    while(!opStack.empty()) {
        char topOp = opStack.top();
        cal(numStack, topOp);
        opStack.pop();
    }
    return numStack.top();
}