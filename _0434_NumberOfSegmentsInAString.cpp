#include "headers.hpp"

int LeetCode::_0434_NumberOfSegmentsInAString::countSegments(std::string s) {
    int segments = 0;
    bool canset = true;
    for(auto& c : s) {
        if(c != ' ') {
            if(canset == true) {
                ++segments;
            }
            canset = false; // 当前这个字符不是空格，直到遇到下一个空格前，我们都认为是一个单词
            continue;
        } else {
            canset = true;
            continue;
        }
    }
    return segments;
}