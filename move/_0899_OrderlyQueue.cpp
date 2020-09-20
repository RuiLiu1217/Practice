#include "headers.hpp"
#include <algorithm>

std::string LeetCode::_0899_OrderlyQueue::orderlyQueue(std::string S, int K) {
    if(K > 1) {
        std::sort(S.begin(), S.end());
        return S;
    } else {
        std::vector<int> minIdx;
        char minC = 'z';
        for(int i = 0; i < S.size(); ++i) {
            if(S[i] < minC) {
                minIdx.clear();
                minC = S[i];
                minIdx.push_back(i);
            } else if(S[i] == minC) {
                minIdx.push_back(i);
            }
        }
        
        std::string res = S;
        for(int i = 0; i < minIdx.size(); ++i) {
            std::string right = S.substr(0, minIdx[i]);
            std::string left = S.substr(minIdx[i]);
            std::string tmp = left + right;
            if(tmp < res) {
                res = tmp;
            }
        }
        return res;
    }
}