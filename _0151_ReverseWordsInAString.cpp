#include "headers.hpp"
#include <algorithm>
// Not O(1) space complexity solution is much easier than O(1) space complexity
std::string LeetCode::_0151_ReverseWordsInAString::reverseWords(std::string s) {
    int i = 0;
    std::stack<char> st;
    std::string res;
    s += " ";
    while(i < s.size()) {
        if(s[i] == ' ') {
            std::string temp;
            while(!st.empty()) {
                temp += st.top();
                st.pop();
            }
            if(temp.size() > 0) {
                if(res.size() > 0) {
                    res += " ";
                }
                res += temp;
            }
        } else {
            st.push(s[i]);
        }
        ++i;
    }
    std::reverse(res.begin(), res.end());
    return res;
}

static void reverseword(std::string& s, int i, int j) {
    while(i < j) {
        std::swap(s[i],s[j]);
        ++i;
        --j;
    }
}
static std::string reverseWords_O1(std::string s) {
    int i = 0;
    int j = 0;
    int l = 0;
    int len = s.length();
    int wordcount = 0;

    while(true) {
        while(i < len && s[i] == ' ') {
            ++i;
        }
        if(i == len) {
            break;
        }
        if(wordcount) {
            s[j++] = ' ';
        }
        l = j;
        while(i < len && s[i] != ' ') {
            s[j] = s[i];
            j++;
            i++;
        }
        reverseword(s, l, j-1);
        wordcount++;
    }
}