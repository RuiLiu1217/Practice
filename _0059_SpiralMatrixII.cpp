#include "headers.hpp"

std::vector<std::vector<int>> LeetCode::_0059_SpiralMatrixII::generateMatrix(int n)
{
    vector<vector<int>> res;
    if (n == 0)
    {
        return res;
    }
    res.resize(n);
    for (int i = 0; i != n; ++i)
    {
        res[i].resize(n);
    }
    int t = 1;
    int i = 0;
    int j = 0;
    int rowCount = n - 1;
    int colCount = n;
    int rowPowIdx = 0;
    int colPowIdx = 0;
    bool isCountingRow = false;
    int count = 0;

    for (int aa = 0; aa != n; ++aa)
    {
        for (int bb = 0; bb != n; ++bb)
        {
            res[i][j] = t++;
            if (isCountingRow)
            {
                i = i + pow(-1, rowPowIdx);
                ++count;
                if (count == rowCount)
                {
                    isCountingRow = false;
                    ++rowPowIdx;
                    rowCount = rowCount - 1;
                    i = i + pow(-1, rowPowIdx);
                    j = j + pow(-1, colPowIdx);
                    count = 0;
                }
            }
            else
            {
                j = j + pow(-1, colPowIdx);
                ++count;
                if (count == colCount)
                {
                    isCountingRow = true;
                    ++colPowIdx;
                    colCount = colCount - 1;
                    i = i + pow(-1, rowPowIdx);
                    j = j + pow(-1, colPowIdx);
                    count = 0;
                }
            }
        }
    }
    return res;
}