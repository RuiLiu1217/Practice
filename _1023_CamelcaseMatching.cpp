#include "headers.hpp"
#include <regex>
std::vector<bool> LeetCode::_1023_CamelcaseMatching::camelMatch(std::vector<std::string>& queries, std::string pattern) {
    std::vector<int> res1 = prefixMatchingBased(queries, pattern);
    std::vector<int> res2 = regularExpressionBased(queries, pattern);
    return res2;
}


std::vector<bool> LeetCode::_1023_CamelcaseMatching::prefixMatchingBased(std::vector<std::string>& queries, std::string pattern) {
    std::vector<bool> res;
    for(std::string& query : queries) {
        res.push_back(canMatch_prefixMatchingBased(query, pattern));
    }
    return res;
}

std::vector<bool> LeetCode::_1023_CamelcaseMatching::regularExpressionBased(std::vector<std::string>& queries, std::string pattern) {
    std::vector<bool> res;
    for(std::string& query : queries) {
        res.push_back(canMatch_regularExpressionBased(query, pattern));
    }
    return res;
}


bool LeetCode::_1023_CamelcaseMatching::canMatch_prefixMatchingBased(std::string query, std::string pattern) {
    int i = 0;
    for (char & c : query)
        if (i < pattern.length() && c == pattern[i]) i++;
        else if (c < 'a') return false; // if it is a captial char but not matched, return false immediately.
    return i == pattern.length();
}

bool LeetCode::_1023_CamelcaseMatching::canMatch_regularExpressionBased(std::string query, std::string pattern) {
    std::string p = "[a-z]*";
    for(char &c : pattern) {
        p += std::string(1, c) + "[a-z]*";
    }
    std::regex r(p);
    return std::regex_match(query, r);
}