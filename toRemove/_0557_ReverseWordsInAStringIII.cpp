#include "headers.hpp"
#include <stack>

std::string reverseWords(std::string s) {
    std::stack<char> st;
    std::string res;
    for(int i = 0; i != s.size(); ++i)
    {
        if(s[i] == ' ')
        {
            std::string tmpStr;
            while(!st.empty())
            {
                tmpStr = tmpStr + st.top();
                st.pop();
            }
            res = res + tmpStr + ' ';
        } else {
            st.push(s[i]);
        }
    }
    std::string tmpStr2;
    while(!st.empty())
    {
        tmpStr2 = tmpStr2 + st.top();
        st.pop();    
    }
    res = res + tmpStr2 + ' ';
    res.resize(res.size()-1);
    return res;
}