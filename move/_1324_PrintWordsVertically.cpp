#include "headers.hpp"
#include <iostream>
#include <sstream>
std::vector<std::string> LeetCode::_1324_PrintWordsVertically::printVertically(std::string s) {
    std::istringstream iss(s);
    std::string token;
    std::vector<std::string> tokens;
    while(getline(iss, token, ' ')) {
        if(!token.empty()) {
            tokens.push_back(token);
        }            
    }
    int maxLen = 0;
    for(auto& t : tokens) {
        if(t.size() > maxLen) {
            maxLen = t.size();
        }
    }
    std::vector<std::string> res(maxLen, std::string(tokens.size(), ' '));
    for(int i = 0; i < tokens.size(); ++i) {
        for(int j = 0; j < tokens[i].size(); ++j) {
            res[j][i] = tokens[i][j];
        }
    }
    for(auto& r : res) {
        int j = r.size()-1;
        while(j >= 0 && r[j] == ' ') {
            --j;
        }
        r = r.substr(0, j+1);
    }
    return res;
}