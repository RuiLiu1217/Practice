#include "headers.hpp"

std::string LeetCode::_0541_ReverseStringII::reverseStr(std::string s, int k) {
    std::string res;
    int times = 0;
    for(int i = 0; i < s.size(); i+=k) {
        if(times % 2 == 0) {
            std::stack<char> st;
            int j = i;
            int count = 0;
            while(count < k && j < s.size()) {
                st.push(s[j++]);
                ++count;
            }
            while(!st.empty()) {
                res += st.top();
                st.pop();
            }
        } else {
            int j = i;
            int count = 0;
            while(count < k && j < s.size()) {
                res += s[j++];
                ++count;
            }
        }
        times += 1;            
    }
    return res;
}