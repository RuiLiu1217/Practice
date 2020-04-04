#include "headers.hpp"
#include <cmath>

/*
Type: Array
*/

std::vector<std::vector<int>> LeetCode::_0059_SpiralMatrixII::generateMatrix(int n)
{
    std::vector<std::vector<int>> res;
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
                i = i + std::pow(-1, rowPowIdx);
                ++count;
                if (count == rowCount)
                {
                    isCountingRow = false;
                    ++rowPowIdx;
                    rowCount = rowCount - 1;
                    i = i + std::pow(-1, rowPowIdx);
                    j = j + std::pow(-1, colPowIdx);
                    count = 0;
                }
            }
            else
            {
                j = j + std::pow(-1, colPowIdx);
                ++count;
                if (count == colCount)
                {
                    isCountingRow = true;
                    ++colPowIdx;
                    colCount = colCount - 1;
                    i = i + std::pow(-1, rowPowIdx);
                    j = j + std::pow(-1, colPowIdx);
                    count = 0;
                }
            }
        }
    }
    return res;
}

/*
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        std::vector<int> stepSeries;
        int m = n-1;
        stepSeries.push_back(m);
        while(m >= 1) {
            stepSeries.push_back(m);
            stepSeries.push_back(m);
            --m;
        }
        std::vector<std::vector<int>> dir;
        int direct = 0;
        for(int i = 0; i < stepSeries.size(); ++i) {
            if(direct == 0) {
                dir.push_back({0, 1});
            } else if(direct == 1) {
                dir.push_back({1, 0});
            } else if(direct == 2) {
                dir.push_back({0, -1});
            } else if(direct == 3) {
                dir.push_back({-1, 0});
            }
            ++direct;
            direct = direct % 4;
        }
        
        std::vector<std::vector<int>> res(n, std::vector<int>(n, 0));
        int I = 0;
        int J = 0;
        int v = 2;
        res[0][0] = 1;
        for(int i = 0; i < stepSeries.size(); ++i) {
            int s = stepSeries[i];
            std::vector<int> d = dir[i];
            for(int si = 0; si < s; ++si) {
                I = I + d[0];
                J = J + d[1];
                res[I][J] = v;
                ++v;
            }
        }
        return res;
    }
};
*/