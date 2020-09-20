#include "headers.hpp"

LeetCode::_0385_MiniParser::NestedInteger  LeetCode::_0385_MiniParser::deserialize(std::string s) {
    if(s.empty()) return NestedInteger();
    if(s[0] != '[') return NestedInteger(std::stoi(s));
    if(s.size() <= 2) return NestedInteger();
    
    NestedInteger res;
    int startIdx = 1;
    int countLeft = 0;
    for(int i = 1; i < s.size(); ++i) {
        if(countLeft == 0 && (s[i] == ',' || i == s.size() - 1)) {
            res.add(deserialize(s.substr(startIdx, i - startIdx)));
            startIdx = i + 1;
        } else if(s[i] == '[') {
            ++countLeft;
        } else if(s[i] == ']') {
            --countLeft;
        }
    }
    return res;
}