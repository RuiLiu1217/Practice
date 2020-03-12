#include "headers.hpp"

/*
Google
*/
std::vector<std::string> LeetCode::_0017_LetterCombinationsOfAPhoneNumber::letterCombinations(std::string& digits) {
    const int N = digits.size();
    if(N == 0) {
        return {};
    }
    std::vector<std::string> res;
    letterCombination(digits, 0, N, "", res);
    return res;
}

void LeetCode::_0017_LetterCombinationsOfAPhoneNumber::letterCombination(const std::string& digits, int i, int N, std::string tmp, std::vector<std::string>& res) {
 if(i == N) {
        res.push_back(tmp);
        return;
    }
    if(digits[i] == '2') {
        letterCombination(digits, i + 1, N, tmp + 'a', res);
        letterCombination(digits, i + 1, N, tmp + 'b', res);
        letterCombination(digits, i + 1, N, tmp + 'c', res);
    } else 
    if(digits[i] == '3') {
        letterCombination(digits, i + 1, N, tmp + 'd', res);
        letterCombination(digits, i + 1, N, tmp + 'e', res);
        letterCombination(digits, i + 1, N, tmp + 'f', res);
    } else 
    if(digits[i] == '4') {
        letterCombination(digits, i + 1, N, tmp + 'g', res);
        letterCombination(digits, i + 1, N, tmp + 'h', res);
        letterCombination(digits, i + 1, N, tmp + 'i', res);
    } else
    if(digits[i] == '5') {
        letterCombination(digits, i + 1, N, tmp + 'j', res);
        letterCombination(digits, i + 1, N, tmp + 'k', res);
        letterCombination(digits, i + 1, N, tmp + 'l', res);
    } else
    if(digits[i] == '6') {
        letterCombination(digits, i + 1, N, tmp + 'm', res);
        letterCombination(digits, i + 1, N, tmp + 'n', res);
        letterCombination(digits, i + 1, N, tmp + 'o', res);
    } else 
    if(digits[i] == '7') {
        letterCombination(digits, i + 1, N, tmp + 'p', res);
        letterCombination(digits, i + 1, N, tmp + 'q', res);
        letterCombination(digits, i + 1, N, tmp + 'r', res);
        letterCombination(digits, i + 1, N, tmp + 's', res);
    } else 
    if(digits[i] == '8') {
        letterCombination(digits, i + 1, N, tmp + 't', res);
        letterCombination(digits, i + 1, N, tmp + 'u', res);
        letterCombination(digits, i + 1, N, tmp + 'v', res);
    } else
    if(digits[i] == '9') {
        letterCombination(digits, i + 1, N, tmp + 'w', res);
        letterCombination(digits, i + 1, N, tmp + 'x', res);
        letterCombination(digits, i + 1, N, tmp + 'y', res);
        letterCombination(digits, i + 1, N, tmp + 'z', res);
    }
}