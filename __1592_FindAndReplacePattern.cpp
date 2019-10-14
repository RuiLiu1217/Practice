#include "headers.hpp"

std::vector<std::string> LintCode::_1592_FindAndReplacePattern::findAndReplacePattern(std::vector<std::string> &words, std::string &pattern) {
    // Write your code here.
    std::vector<std::string> res;
    
    for(int i = 0; i < words.size(); ++i) {
        if(samePattern(words[i], pattern)) {
            res.push_back(words[i]);
        }
    }
    return res;
}

bool LintCode::_1592_FindAndReplacePattern::samePattern(std::string& A, std::string& B) {
    std::unordered_map<char, char> mpa;
    std::unordered_map<char, char> mpb;
    if(A.size() != B.size()) {
        return false;
    }
    
    for(int i = 0; i < A.size(); ++i) {
        if(mpa.find(A[i]) == mpa.end()) {
            if(mpb.find(B[i]) != mpb.end()) {
                return false;
            }
            
            mpa[A[i]] = B[i];
            mpb[B[i]] = A[i];
        } else {
            if(mpa[A[i]] != B[i] || mpb.find(B[i]) == mpb.end() || mpb[B[i]] != A[i]) {
                return false;
            }
        }
    }
    return true;
}