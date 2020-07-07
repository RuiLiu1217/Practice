#include "headers.hpp"

bool LeetCode::_0657_RobotReturnToOrigin::judgeCircle(std::string moves) {
    int totalMove = moves.size();
    int px = 0;
    int py = 0;
    int i = 0;
    while(i != totalMove)
    {
        switch(moves[i])
        {
            case 'R':
                px++;
                break;
            case 'L':
                px--;
                break;
            case 'U':
                py++;
                break;
            case 'D':
                py--;
                break;
        }
        ++i;
    }
    return ((px == 0) && (py == 0));
}