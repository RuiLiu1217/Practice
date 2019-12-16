#include "headers.hpp"
std::vector<int> LeetCode::_0728_SelfDividingNumbers::selfDividingNumbers(int left, int right) {
    std::vector<int> res;
    for(int i = left; i<=right;++i) {
        std::vector<int> div;
        int t = i;
        bool canuse = true;
        while(t) {
            if(!(t%10)) { // contains 0
                canuse = false;
                break;
            }
            div.push_back(t%10);
            t = t/10;
        }
        if(canuse) {
            bool isDiv = true;
            for(auto& nd : div) {
                if(i % nd) {
                    isDiv = false;
                    break;
                }
            }
            if(isDiv) {
                res.push_back(i);                
            }
        }
    }
    return res;
}