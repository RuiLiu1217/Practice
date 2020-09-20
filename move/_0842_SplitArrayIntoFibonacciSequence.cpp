#include "headers.hpp"

// Copy from the solution,
// The difficulity is how to construct the backtracking function interface
static bool helper(std::string s, std::vector<int>& res, int idx) {
    if(idx == s.length() && res.size() >= 3) {
        return true;
    }
    
    for(int i = idx; i < s.length(); ++i) {
        if(s[idx] == '0' && i > idx) { // 开头数字不能是0， 可以自己是0
            break;
        }
        long num = std::stol(s.substr(idx, i - idx + 1));
        if(num > INT_MAX) {
            break;
        }
        int size = res.size();
        // early termination
        if(size >= 2 && num > static_cast<long>(res[res.size() - 1]) + static_cast<long>(res[res.size() - 2])) {
            break;
        }
        
        if(size <= 1 || num == static_cast<long>(res[res.size() - 1]) + static_cast<long>(res[res.size() - 2])) {
            res.push_back(num);
            if(helper(s, res, i+1)) {
                return true;
            }
            res.pop_back();
        }
    }
    return false;
}

std::vector<int> LeetCode::_0842_SplitArrayIntoFibonacciSequence::splitIntoFibonacci(std::string S) {
    std::vector<int> res;
    helper(S, res, 0);
    return res;
}