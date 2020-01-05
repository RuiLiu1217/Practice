#include "headers.hpp"
#include <algorithm>

std::string LeetCode::_0761_SpecialBinaryString::makeLargestSpecial(std::string S) {
    S = "1" + S + "0";
        std::string res = makeLargestSpecialHelp(S);
        return res.substr(1, res.size() - 2);
}

std::string LeetCode::_0761_SpecialBinaryString::makeLargestSpecialHelp(std::string S) {
    std::string suS = S.substr(1, S.size() - 2);
    if(suS == "") {
        return "10";
    }
    std::vector<std::string> toSort;
    std::string tmp;
    int count = 0;
    for(int i = 0; i < suS.size(); ++i) {
        if(suS[i] == '1') {
            ++count;
        } else {
            --count;
        }
        tmp += suS[i];
        if(count == 0) {
            tmp = makeLargestSpecialHelp(tmp);
            toSort.push_back(tmp);
            tmp.clear();
        }
    }
    
    std::sort(toSort.begin(), toSort.end(), std::greater<std::string>());
    std::string res;
    res += "1";
    for(int i = 0; i < toSort.size(); ++i) {
        res += toSort[i];
    }
    res += "0";
    
    return res;
}