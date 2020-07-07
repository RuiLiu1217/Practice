#include "headers.hpp"

// Facebook
std::string LeetCode::_0067_AddBinary::addBinary(std::string a, std::string b) {
    std::stack<char> ast;
    std::stack<char> bst;
    std::stack<char> resst;
    for(auto& ch : a)
    {
        ast.push(ch);
    }
    for(auto& ch : b)
    {
        bst.push(ch);
    }

    int carry = 0;
    while(!ast.empty() && !bst.empty())
    {
        int cha = ast.top() - '0';
        int chb = bst.top() - '0';
        ast.pop();
        bst.pop();
        int re = cha + chb + carry;
        if(re >= 2)
        {
            re -= 2;
            carry = 1;
        } else {
            carry = 0;
        }
        resst.push(static_cast<char>('0' + re));            
    }

    while(!ast.empty())
    {
        int cha = ast.top() - '0';
        ast.pop();
        int re = cha + carry;
        if(re >= 2)
        {
            re -= 2;
            carry = 1;
        } else {
            carry = 0;
        }
        resst.push(static_cast<char>('0' + re));
    }

    while(!bst.empty())
    {
        int chb = bst.top() - '0';
        bst.pop();
        int re = chb + carry;
        if(re >= 2)
        {
            re -= 2;
            carry = 1;
        } else {
            carry = 0;
        }
        resst.push(static_cast<char>('0' + re));
    }

    if(carry == 1)
    {
        resst.push('1');
    }
    std::string res;
    while(!resst.empty())
    {
        res = res + resst.top();
        resst.pop();
    }
    return res;
}
