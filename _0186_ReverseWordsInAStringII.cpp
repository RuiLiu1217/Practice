#include "headers.hpp"

void LeetCode::_0186_ReverseWordsInAStringII::reverse(std::vector<char>& s) {
    int startIdx = 0;
    int endIdx = 0;
    while(endIdx < s.size()) {
        while(endIdx < s.size() && s[endIdx] != ' ') {
            ++endIdx;
        }

        int i = startIdx;
        int j = endIdx - 1;
        while(i < j) {
            std::swap(s[i++], s[j--]);
        }
        startIdx = endIdx + 1;
        endIdx = startIdx;
    }

    int i = 0;
    int j = s.size() - 1;
    while(i < j) {
        std::swap(s[i++], s[j--]);
    }
}
