#include "headers.hpp"

int LeetCode::_0062_UniquePaths::uniquePaths(int m, int n)
{
    TABLE.resize(m + 1);
    for (int i = 0; i < TABLE.size(); ++i)
    {
        TABLE[i].resize(n + 1);
        for (int j = 0; j < TABLE[i].size(); ++j)
        {
            TABLE[i][j] = -1;
        }
    }

    return uniquePaths_impl(m, n);
}

int LeetCode::_0062_UniquePaths::uniquePaths_impl(int m, int n)
{
    if (TABLE[m][n] != -1)
    {
        return TABLE[m][n];
    }
    if (m == 0 || n == 0)
    {
        TABLE[m][n] = 0;
        return 0;
    }
    if (m == 1 || n == 1)
    {
        TABLE[m][n] = 1;
        return 1;
    }
    int u = uniquePaths_impl(m - 1, n);
    int l = uniquePaths_impl(m, n - 1);
    TABLE[m][n] = u + l;
    return TABLE[m][n];
}