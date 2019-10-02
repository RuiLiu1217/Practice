#include "headers.hpp"

int LeetCode::_0063_UniquePathsII::uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    const int M = obstacleGrid.size();
    const int N = obstacleGrid[0].size();
    std::vector<std::vector<long long>> DP(M, std::vector<long long>(N));
    bool flag = false;
    for (int i = 0; i < M; ++i)
    {
        if (obstacleGrid[i][0] == 0)
        {
            DP[i][0] = 1;
        }
        else
        {
            DP[i][0] = -1;
            flag = true;
        }

        if (flag)
        {
            DP[i][0] = -1;
        }
    }

    flag = false;
    for (int j = 0; j < N; ++j)
    {
        if (obstacleGrid[0][j] == 0)
        {
            DP[0][j] = 1;
        }
        else
        {
            DP[0][j] = -1;
            flag = true;
        }

        if (flag)
        {
            DP[0][j] = -1;
        }
    }

    for (int i = 1; i < M; ++i)
    {
        for (int j = 1; j < N; ++j)
        {
            if (obstacleGrid[i][j] != 1)
            {
                if (DP[i - 1][j] == -1 && DP[i][j - 1] == -1)
                {
                    DP[i][j] = -1;
                }
                else if (DP[i - 1][j] != -1 && DP[i][j - 1] == -1)
                {
                    DP[i][j] = DP[i - 1][j];
                }
                else if (DP[i - 1][j] == -1 && DP[i][j - 1] != -1)
                {
                    DP[i][j] = DP[i][j - 1];
                }
                else
                {
                    DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
                }
            }
            else
            {
                DP[i][j] = -1;
            }
        }
    }
    return DP[M - 1][N - 1] == -1 ? 0 : DP[M - 1][N - 1];
}
