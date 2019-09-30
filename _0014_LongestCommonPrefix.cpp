#include "headers.hpp"

std::string LeetCode::_0014_LongestCommonPrefix::longestCommonPrefix(std::vector<std::string>& strs) {
    std::string res;
    if(strs.empty){
        return res;
    }

    size_t minL = strs[0].size();
    for(int i = 0; i != strs.size(); ++i) {
        if(strs[i].size() < minL) {
            minL = strs[i].size();
        }
    }

    if(minL == 0) {
        return res;
    }

    for(int j = 0; j != minL; ++j) {
        char key = strs[0][j];
        for(int i = 0; i != strs.size(); ++i) {
            if(strs[i][j] != key) {
                return res;
            }
        }
        res += key;
    }
    return res;
}
