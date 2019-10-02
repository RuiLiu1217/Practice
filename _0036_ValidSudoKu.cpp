#include "headers.hpp"
bool LeetCode::_0036_ValidSudoku::isValidSudoku(std::vector<std::vector<char>> &board)
{
    bool valid = true;
    for (int i = 0; i != 9; ++i)
    {
        valid &= ~(existDuplicatePerRow(board, i));
        if (valid == false)
        {
            return false;
        }
    }
    for (int i = 0; i != 9; ++i)
    {
        valid &= ~(existDuplicatePerColumn(board, i));
        if (valid == false)
        {
            return false;
        }
    }
    for (int i = 0; i != 3; ++i)
    {
        for (int j = 0; j != 3; ++j)
        {
            valid &= ~(existDuplicatePerSquare(board, i, j));
            if (valid == false)
            {
                return false;
            }
        }
    }
    return valid;
}

bool LeetCode::_0036_ValidSudoku::existDuplicatePerSquare(vector<vector<char>> &board, int i, int j)
{
    vector<int> ext(9, 0);
    for (int ii = 0; ii != 3; ++ii)
    {
        for (int jj = 0; jj != 3; ++jj)
        {
            char tmp = board[ii + i * 3][jj + j * 3];
            if (tmp >= '1' && tmp <= '9')
            {
                if (ext[tmp - '1'] == 0)
                {
                    ext[tmp - '1'] = 1;
                }
                else
                {
                    return true;
                }
            }
        }
    }
    return false;
}
bool LeetCode::_0036_ValidSudoku::existDuplicatePerRow(vector<vector<char>> &board, int i)
{
    vector<int> ext(9, 0);
    for (int ii = 0; ii != 9; ++ii)
    {
        char tmp = board[i][ii];
        if (tmp >= '1' && tmp <= '9')
        {
            if (ext[tmp - '1'] == 0)
            {
                ext[tmp - '1'] = 1;
            }
            else
            {
                return true;
            }
        }
    }
    return false;
}
bool LeetCode::_0036_ValidSudoku::existDuplicatePerColumn(vector<vector<char>> &board, int j)
{
    vector<int> ext(9, 0);
    for (int ii = 0; ii != 9; ++ii)
    {
        char tmp = board[ii][j];
        if (tmp >= '1' && tmp <= '9')
        {
            if (ext[tmp - '1'] == 0)
            {
                ext[tmp - '1'] = 1;
            }
            else
            {
                return true;
            }
        }
    }
    return false;
}
