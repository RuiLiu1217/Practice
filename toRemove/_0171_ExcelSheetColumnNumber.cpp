#include "headers.hpp"
// String, Mathematics, Recursive
int LeetCode::_0171_ExcellSheetColumnNumber::titleToNumber(std::string s) {
    if(s.empty()) {
        return 0;
    }
    if(s.size() == 1) {
        return (s[0] - 'A' + 1);
    }
    else {
        char ss = s.back();
        std::string subS = s.substr(0, s.size() - 1);
        return titleToNumber(subS) * 26 + (ss - 'A' + 1);
    }
}