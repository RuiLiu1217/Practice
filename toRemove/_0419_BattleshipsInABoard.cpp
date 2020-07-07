#include "headers.hpp"
/*
题目大意
    战列舰计数。就是求用x组成的区域有几个。单独的一个或者连续的一条线都算一个。另外就是战列舰不会交叉，不会平行。
    
    解题方法
    方法比较简单，直接数就行。如果一个位置有x，并且 这个位置在最左边或者不在最左边但是该位置左侧是，
    并且(这个位置在最上边或者不在最上边但是该位置上侧是，那么就是一个新的战列舰，计数即可。
*/

int LeetCode::_0419_BattleshipsInABoard::countBattleships(std::vector<std::vector<char>>& board) {
    const int M = board.size();
    if(M == 0) {
        return 0;
    }
    const int N = board[0].size();
    if(N == 0) {
        return 0;
    }
    int count = 0;
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < N; ++j) {
            if(board[i][j] == 'X' && (i == 0 || board[i-1][j] == '.') && (j == 0 || board[i][j-1] == '.')) {
                ++count;
            }
        }
    }
    return count;
}