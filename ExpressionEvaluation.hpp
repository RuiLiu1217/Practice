#ifndef EXPRESSIONEVALUATION_HPP
#define EXPRESSIONEVALUATION_HPP
#include <string>
#include <stack>
#include <vector>
namespace ExpressionEval {
// 中缀表达式求值
// : 题目描述：给定一个表达式，求该表达式的值
// Facebook 原题：
// 给定一个表达式，表达式中只含有 整数，+, * 三种 符号， 求这个表达式的值

// Scan this expression, and split it with the delimiter "+" and return 
// a vector of sub expressions, every expression is either a number or 
// a expression with multiplication.
// 1+2*3+2
// 2*1+5
// 1*2
// 1+4

std::vector<std::string> split(std::string exp, char delimiter) {
    exp += delimiter;
    std::string tmp;
    std::vector<std::string> res;
    for(char c : exp) {
        if(c == delimiter) {
            res.push_back(tmp);
            tmp.clear();
        } else {
            tmp += c;
        }
    }
    return res;
}

int expressionEval(std::string exp) {
    std::vector<std::string> expressions = split(exp, '+');
    int res = 0;
    for(auto e : expressions) {
        if(e.find("*") == std::string::npos) {
            res += std::stoi(e);
        } else {
            std::vector<std::string> expMultiply = split(e, '*');
            int temp = 1;
            for(auto m : expMultiply) {
                temp *= std::stoi(m);
            }
            res += temp;
        }
    }
    return res;
}

/*
Implement a basic calculator to evaluate a simple expression string.
The expression string may contain open ( and closing parentheses ), 
the plus + or minus sign -, non-negative integers and empty spaces .

Input: "1 + 1"
Output: 2

Input: " 2-1 + 2 "
Output: 3

Input: "(1+(4+5+2)-3)+(6+8)"
Output: 23
Note:
You may assume that the given expression is always valid.
Do not use the eval built-in library function.
*/
class BasicCalculatorI {

};

}


#endif