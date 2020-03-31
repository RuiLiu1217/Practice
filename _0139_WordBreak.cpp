#include "headers.hpp"

// Facebook


// Backtracking (TLE)
// bool LeetCode::_0139_WordBreak::wordBreak(std::string s, std::vector<std::string>& wordDict) {
//     std::unordered_set<std::string> wd(wordDict.begin(), wordDict.end());
//     return wordBreak(s, wd);
// }

// bool LeetCode::_0139_WordBreak::wordBreak(std::string s, std::unordered_set<std::string>& wd) {
//     if(s.empty()) {
//         return true;
//     }
//     for(auto& w : wd) {
//         if(s.size() >= w.size() && s.substr(0, w.size()) == w) {
//             if(wordBreak(s.substr(w.size()), wd)) {
//                 return true;
//             }
//         }
//     }
//     return false;
// }



 // DP is a better solution
static bool wordBreakDP(std::string s, std::vector<std::string>& wordDict) {
    std::unordered_set<std::string> wd(begin(wordDict), end(wordDict));
    std::vector<bool> DP(s.size() + 1, false);
    DP[0] = true; // empty string definitely can be divided, it means whether the s[0, i) can be divided
    for(int i = 0 ; i < DP.size(); ++i) {
        for(int j = 0; j < i; ++j) {
            if(DP[j] && wd.count(s.substr(j, i-j))) {
                DP[i] = true;
                break;
            }
        }
    }
    return DP.back();
}


// This problem cannot use Backtracing to solve !!! will TLE
// USE DP to solve it.
bool LeetCode::_0139_WordBreak::wordBreak(std::string s, std::vector<std::string>& wordDict) {
    std::unordered_set<std::string> wordD(wordDict.cbegin(), wordDict.cend());
    return wordBreak(s, wordD);
}

bool LeetCode::_0139_WordBreak::wordBreak(std::string& s, const std::unordered_set<std::string>& wordDict) {
    if(hasSolution.count(s)) {
        return hasSolution[s];
    }
    if(wordDict.count(s)) {
        return hasSolution[s] = true;
    }
    
    for(int i = 0; i < s.size(); ++i) {
        std::string left = s.substr(0, i);
        std::string right = s.substr(i);
        if(wordDict.count(right) && wordBreak(left, wordDict)) {
            return hasSolution[s] = true;
        }
    }
    return hasSolution[s] = false;
}