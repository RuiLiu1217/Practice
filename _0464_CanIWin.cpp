#include "headers.hpp"

// 抄答案的，需要重新看答案。

// M: maxChoosableInteger
// T: target
bool LeetCode::_0464_CanIWin::canIWin(int M, int T) {
    const int sum = M * (M + 1) / 2;
    if(sum < T) {
        return false;
    }
    if(T <= 0) {
        return true;
    }
    m_ = std::vector<char>(1 << M, 0);
    return canIWin(M, T, 0);
}

bool LeetCode::_0464_CanIWin::canIWin(int M, int T, int state) {
    if(T <= 0) return false;
    if(m_[state]) {
        return m_[state] == 1;
    }
    for(int i = 0; i < M; ++i) {
        if(state & (1<<i)) { // number i used
            continue; 
        }
        
        // The next player can not win, current player wins
        if(!canIWin(M, T - (i+1), state | (1 << i))) {
            return m_[state] = 1;
        }
    }
    m_[state] = -1;
    return false;
}
