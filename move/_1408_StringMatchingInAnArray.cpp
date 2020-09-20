#include "headers.hpp"

// 一下子蒙住了
std::vector<std::string> _1408_StringMatchingInAnArray::stringMatching(std::vector<std::string>& words) {
    std::vector<std::string> ans;
    const int n = words.size();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (words[j].find(words[i]) != string::npos) {
                ans.push_back(words[i]);
                break;
            }
        }
    return ans;        
}