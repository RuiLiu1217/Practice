#include "headers.hpp"
#include <string>
#include <stack>

std::string LeetCode::_0394_DecodeString::decodeString(std::string s) {
    std::string temp;
    std::stack<std::string> st;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] >= '0' && s[i] <= '9') { // digits
            if(temp.size() > 0 && !(temp[0] >= '0' && temp[0] <= '9')) {
                st.push(temp);
                temp = "";
            }
            temp += s[i];
        } else if(s[i] != '[' && s[i] != ']') { // not digits, not '[' or ']'
            if(temp.size() > 0 && (temp[0] >= '0' && temp[0] <= '9')) {
                st.push(temp);
                temp = "";
            }
            temp += s[i];
        } else if(s[i] == '[') {
            if(temp.size() > 0) {
                st.push(temp);
                temp = "";
            }
            st.push("[");
        } else { // ']';
            if(temp.size() > 0) {
                st.push(temp);
                temp = "";
            }
            std::string toRepeat;
            while(!st.empty() && st.top() != "[") {
                toRepeat = st.top() + toRepeat;
                st.pop();
            }
            st.pop(); // pop [
            std::string rt = st.top();
            st.pop();
            int repeatTime = std::stoi(rt);
            std::string r;
            for(int i = 0; i < repeatTime; ++i) {
                r += toRepeat;
            }
            st.push(r);
        }
    }
    
    std::string res;
    while(!st.empty()) {
        res = st.top() + res;
        st.pop();
    }
    if(temp.size() > 0) {
        res += temp;
    }
    return res;
}