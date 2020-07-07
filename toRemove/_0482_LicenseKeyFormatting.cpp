#include "headers.hpp"

std::string LeetCode::_0482_LicenseKeyFormatting::licenseKeyFormatting(std::string S, int K) {
    std::string res;
    int count = 0;
    for(int i = S.size() - 1; i >= 0; --i) {
        if(S[i] == '-') {
            continue;
        } else {
            if(S[i] <= 'z' && S[i] >= 'a') {
                S[i] += ('A' - 'a');
            }
            res += S[i];
            ++count;
            if(count == K) {
                res += '-';
                count = 0;
            }
        }
    }
    std::reverse(begin(res), end(res));
    int i = 0;
    while(res[i] == '-') {
        ++i;
    }
    return res.substr(i);
}