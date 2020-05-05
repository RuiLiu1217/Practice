#include "headers.hpp"

int LeetCode::_1422_MaximumScoreAfterSplittingAString::maxScore(std::string s) {
    int left = (s[0] == '0');
    int right = 0;
    for(int i = 1; i <s.size(); ++i) {
        if(s[i] == '1') {
            ++right;
        }
    }
    int max = left + right;
    for(int i = 1; i < s.size() - 1; ++i) {
        if(s[i] == '0') {
            ++left;
        } else {
            --right;
        }
        max = std::max(max, left + right);
    }
    return max;
}