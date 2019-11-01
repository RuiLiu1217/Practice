#include "headers.hpp"

// 说白了就是递归地求解所有，回溯一下.
std::vector<std::vector<std::string>> LeetCode::_0131_PalindromePartitioning::partition(std::string s) {
    std::vector<std::string> tmp;
    std::vector<std::vector<std::string>> res;
    partition(s, 0, s.size() - 1, tmp, res);
    return res;
}
    
void LeetCode::_0131_PalindromePartitioning::partition(std::string& s, int start, int end,std::vector<std::string>& tmp, std::vector<std::vector<std::string>>& res) {
    if(start > end) {
        res.push_back(tmp);
        return;
    }
    
    for(int i = start; i <= end; ++i) {
        if(isPalindrome(s, start, i)) {
            tmp.push_back(s.substr(start, i - start + 1));
            partition(s, i+1, end, tmp, res);
            tmp.pop_back();
        }
    }
}
    
bool LeetCode::_0131_PalindromePartitioning::isPalindrome(std::string& s, int start, int end) {
    while(start < end) {
        if(s[start] != s[end]) {
            return false;
        }
        ++start;
        --end;
    }
    return true;
}

