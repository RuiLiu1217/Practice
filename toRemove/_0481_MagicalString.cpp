#include "headers.hpp"
int LeetCode::_0481_MagicalString::magicalString(int n) {
    if(n == 1) {
        return 1;
    } else {
        // Generate the string
        std::string res = "122";
        int idx = 2;
        while(idx < n) {
            char toAdded;
            if(res.back() == '1') {
                toAdded = '2';
            } else {
                toAdded = '1';
            }
            int repTime = res[idx];
            if(repTime == '1') {
                res += toAdded;
            } else {
                res += toAdded;
                res += toAdded;
            }
            ++idx;
        }
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            if(res[i] == '1') {
                ++ans;
            }
        }
        return ans;
    }
}

