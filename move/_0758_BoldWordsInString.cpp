#include "headers.hpp"

std::string LeetCode::_0758_BoldWordsInString::boldWords(std::vector<std::string>& words, std::string S) {
    std::vector<bool> isBold(S.length(), false);
    for(int i = 0; i < S.length(); ++i) {
        for(std::string& w : words) {
            int wl = w.length();
            if(S.substr(i, wl) == w) {
                setBold(isBold, i, wl);
            }
        }
    }
    
    std::string res;
    for(int i = 0; i < S.size(); ++i) {
        if(!isBold[i]) {
            res += S[i];
            continue;
        }
        int endP = i;
        while(endP < S.length() && isBold[endP]) {
            ++endP;
        }
        res += "<b>" + S.substr(i, endP - i) + "</b>";
        i = endP - 1;
    }
    return res;
}

void LeetCode::_0758_BoldWordsInString::setBold(std::vector<bool>& isBold, int i, int wl) {
    for(int t = 0; t < wl; ++t) {
        if(t + i < isBold.size()) {
            isBold[t + i] = true;
        }
    }
}