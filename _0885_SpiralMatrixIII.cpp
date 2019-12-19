#include "headers.hpp"

std::vector<std::vector<int>> LeetCode::_0885_SpiralMatrixIII::spiralMatrixIII(int R, int C, int r0, int c0) {
    std::vector<std::vector<int>> res;
    int stepRCol = 1;
    int stepDRow = 1;
    int stepLCol = 2;
    int stepURow = 2;
    int totSteps = R * C;
    int leftStep = 1;
    int moveDirection = 0;
    
    while(totSteps > 0) {
        if(r0 < R && r0 >=0 && c0 < C && c0 >= 0) {
            res.push_back(std::vector<int>({r0, c0}));
            --totSteps;
            if(totSteps == 0) {
                return res;
            }
            
        }
        switch (moveDirection) {
            case 0:
                ++c0;
                --leftStep;
                if(leftStep == 0) {
                    moveDirection = 1;
                    leftStep = stepDRow;
                    stepRCol += 2;
                }
                break;
            case 1:
                ++r0;
                --leftStep;
                if(leftStep == 0) {
                    moveDirection = 2;
                    leftStep = stepLCol;
                    stepDRow += 2;
                }
                break;
            case 2:
                --c0;
                --leftStep;
                if(leftStep == 0) {
                    moveDirection = 3;
                    leftStep = stepURow;
                    stepLCol += 2;
                }
                break;
            case 3:
                --r0;
                --leftStep;
                if(leftStep == 0) {
                    moveDirection = 0;
                    leftStep = stepRCol;
                    stepURow += 2;
                }
                break;                    
        }         
    }
    return res;
}