#include "headers.hpp"

static void backtracking(std::string S, int startIdx, std::string& tmp, std::vector<std::string>& res) {
    if(startIdx == S.size()) {
        res.push_back(tmp);
        return;
    }
    char c = S[startIdx];
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        tmp += std::tolower(c);
        backtracking(S, startIdx+1, tmp, res);
        tmp.pop_back();
        tmp += std::toupper(c);
        backtracking(S, startIdx+1, tmp, res);
        tmp.pop_back();
    } else {
        tmp += c;
        backtracking(S, startIdx+1, tmp, res);
        tmp.pop_back();
    }
}

std::vector<std::string> LeetCode::_0784_LetterCasePermutation::letterCasePermutation(std::string S) {
    std::string tmp;
    std::vector<std::string> res;
    backtracking(S, 0, tmp, res);
    return res;
}
