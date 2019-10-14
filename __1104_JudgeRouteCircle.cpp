#include "headers.hpp"

bool LintCode::_1104_JudgeRouteCircle::judgeCircle(std::string &moves) {
    int x = 0; 
    int y = 0;
    for(int i = 0; i < moves.size(); ++i) {
        if(moves[i] == 'U') {
            ++y;
        } else if(moves[i] == 'D') {
            --y;
        } else if(moves[i] == 'L') {
            ++x;
        } else if(moves[i] == 'R') {
            --x;
        }
    }
    return (x == 0) && (y == 0);
}