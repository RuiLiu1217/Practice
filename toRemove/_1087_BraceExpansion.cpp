#include "headers.hpp"
#include <sstream>
#include <algorithm>

std::vector<std::string> LeetCode::_1087_BraceExpansion::expand(std::string S) {
    return foo(S);
}

std::vector<std::string> LeetCode::_1087_BraceExpansion::foo(std::string S) {
    std::vector<std::string> res;
    res.push_back("");
    for(int i = 0; i < S.size(); ) {
        if(S[i] == '{') {
            int k = i + 1;
            while(k < S.size() && S[k] != '}') {
                ++k;
            }

            std::string subs = S.substr(i + 1, k - i - 1);
            std::istringstream ss(subs);
            std::string token;
            std::vector<std::string> tokens;
            while(getline(ss, token, ',')) {
                tokens.push_back(token);
            }

            std::vector<std::string> newResult;
            for(auto r : res) {
                for(auto t : tokens) {
                    newResult.push_back(r + t);
                }
            }
            res = newResult;
            i = k + 1;
        } else {
            for(auto& r : res) {
                r += S[i];
            }
            ++i;
        }
    }
    std::sort(begin(res), end(res));
    return res;
}