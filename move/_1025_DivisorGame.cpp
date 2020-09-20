#include "headers.hpp"
#include <cmath>
bool LeetCode::_1025_DivisorGame::divisorGame(int N) {
    if(N == 1) {
        return false;
    }
    if(N == 2) {
        return true;
    }
    std::vector<bool> winTable(N+1, 0);
    winTable[0] = false;
    winTable[1] = false;
    winTable[2] = true;

    for(int i = 3; i <= N; ++i) {
        int sq = std::sqrt(i);
        bool willWin = false;
        for(int j = 1; j <= sq; ++j) {
            if(i % j == 0) {
                willWin |= (!winTable[i - j]);
            }
        }
        winTable[i] = willWin;
    }

    return winTable[N];
}