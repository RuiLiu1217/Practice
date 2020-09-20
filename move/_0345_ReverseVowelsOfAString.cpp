#include "headers.hpp"
std::string LeetCode::_0345_ReverseVowelsOfAString::reverseVowels(std::string s) {
    std::stack<char> st;
    for(int i = 0; i!=s.size(); ++i)
    {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
            s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
        {
            st.push(s[i]);
        }
    }
    
    for(int i = 0; i!=s.size(); ++i)
    {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
            s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
        {
            char c = st.top();
            s[i] = c;
            st.pop();
        }
    }
    return s;
}