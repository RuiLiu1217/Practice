#include "headers.hpp"
#include <cmath>

/*

Type: Array

*/

std::vector<int> LeetCode::_0054_SpiralMatrix::spiralOrder(std::vector<std::vector<int>>& matrix) {
    int i = 0;
    int j = 0;
    const int M = matrix.size();
    if(M == 0) {
        return {};
    }

    const int N = matrix[0].size();
    const int totNum = M * N;
    std::vector<int> res;
    int rowCount = M - 1;
    int colCount = N;
    int rowPowIdx = 0;
    int colPowIdx = 0;
    bool isCountingRow = false;
    int count = 0;
    for(int idx = 0; i < totNum; ++idx) {
        res.push_back(matrix[i][j]);
        if(isCountingRow) {
            i += std::pow(-1, rowPowIdx);
            ++count;
            if(count == rowCount) {
                isCountingRow = false;
                ++rowPowIdx;
                rowCount -= 1;
                i += std::pow(-1, rowPowIdx);
                j += std::pow(-1, colPowIdx);
                count = 0;
            }
        } else {
            j += std::pow(-1, colPowIdx);
            ++count;
            if(count == colCount) {
                isCountingRow = true;
                ++colPowIdx;
                colCount -= 1;
                i += std::pow(-1, rowPowIdx);
                j += std::pow(-1, colPowIdx);
                count = 0;
            }
        }
    }
    return res;
}
