#include "headers.hpp"

int LeetCode::_0809_ExpressiveWords::expressiveWords(std::string S, std::vector<std::string>& words) {
    int res = 0;
    for(auto& W : words) {
        if(check(S, W)) {
            ++res;
        }
    }
    return res;
}

bool LeetCode::_0809_ExpressiveWords::check(std::string S, std::string W) {
    int n = S.size();
    int m = W.size();
    int j = 0;
    for(int i = 0; i < n; ++i) {
        if(j < m && S[i] == W[j]) {
            ++j;
        } else if (i > 1 && S[i-2] == S[i - 1] && S[i-1] == S[i]);
        else if(0 < i && i < n-1 && S[i - 1] == S[i] && S[i] == S[i+1]);
        else {
            return false;
        }
    }
    return j == m;
}