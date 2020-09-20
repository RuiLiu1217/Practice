#include "headers.hpp"

void LeetCode::_1269_NumberOfWaysToStayInTheSamePlaceAfterSomeSteps::updateDP(std::vector<long long>& cur, std::vector<long long>& nex, const int N) {
    nex[0] = (cur[0] + cur[1]) % MOD;
    for(int i = 1; i < N - 1; ++i) {
        nex[i] = (cur[i] + cur[i-1] + cur[i+1]) % MOD;
    }
    nex[N-1] = (cur[N-1] + cur[N-2]) % MOD;        
}

int LeetCode::_1269_NumberOfWaysToStayInTheSamePlaceAfterSomeSteps::numWays(int steps, int arrLen) {
    if (arrLen > 2 * steps) {
        arrLen = steps * 2;
    }
    if(steps == 1 || arrLen == 1) {
        return 1;
    }
    std::vector<long long> cur(arrLen, 0);
    std::vector<long long> nex(arrLen, 0);
    cur[0] = 1;
    for(int s = 0; s < steps; ++s) {
        updateDP(cur, nex, arrLen);
        std::swap(cur, nex);            
    }
    return static_cast<int>(cur[0]);
}