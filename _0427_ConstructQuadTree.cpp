#include "headers.hpp"

QuadTreeNode* LeetCode::_0427_ConstructQuadTree::construct(std::vector<std::vector<int>>& grid) {
    int N = grid.size();
    if(N == 0) {
        return nullptr;
    }
    if(N == 1) {
        QuadTreeNode* res = new QuadTreeNode(grid[0][0], true, nullptr, nullptr, nullptr, nullptr);
        return res;
    }
    if(areConsistent(grid)) {
        QuadTreeNode* res = new QuadTreeNode(grid[0][0], true, nullptr, nullptr, nullptr, nullptr);
        return res;
    } else {
        std::vector<std::vector<std::vector<int>>> divideGrids = divideGrid(grid);
        QuadTreeNode* children[4];
        for(int i = 0; i < 4; ++i) {
            if(areConsistent(divideGrids[i])) {
                children[i] = new QuadTreeNode(divideGrids[i][0][0], true, 
                nullptr, nullptr, nullptr, nullptr);
            } else {
                children[i] = construct(divideGrids[i]);
            }
        }
        QuadTreeNode* res = new QuadTreeNode(grid[0][0], false, 
        children[0], children[1], children[2], children[3]);
        return res;
    }
}


QuadTreeNode *LeetCode::_0427_ConstructQuadTree::construct(std::vector<std::vector<int>> &grid, int rowStart, int rowEnd, int colStart, int colEnd)
{
    if (grid.size() == 0 || rowStart == rowEnd || colStart == colEnd)
    {
        return nullptr;
    }
    if (grid.size() == 1 || grid[0].size() == 1 || rowEnd - rowStart == 1 || colEnd - colStart == 1)
    {
        QuadTreeNode *res = new QuadTreeNode(grid[rowStart][colStart], true, nullptr, nullptr, nullptr, nullptr);
        return res;
    }
    if (areConsistent(grid, rowStart, rowEnd, colStart, colEnd))
    {
        QuadTreeNode *res = new QuadTreeNode(grid[rowStart][colStart], true, nullptr, nullptr, nullptr, nullptr);
        return res;
    }
    else
    {
        QuadTreeNode *children[4];
        children[0] = construct(grid, rowStart, rowStart + (rowEnd - rowStart) / 2, colStart, colStart + (colEnd - colStart) / 2);
        children[1] = construct(grid, rowStart, rowStart + (rowEnd - rowStart) / 2, colStart + (colEnd - colStart) / 2, colEnd);
        children[2] = construct(grid, rowStart + (rowEnd - rowStart) / 2, rowEnd, colStart, colStart + (colEnd - colStart) / 2);
        children[3] = construct(grid, rowStart + (rowEnd - rowStart) / 2, rowEnd, colStart + (colEnd - colStart) / 2, colEnd);
        QuadTreeNode *res = new QuadTreeNode(grid[rowStart][colStart], false, children[0], children[1], children[2], children[3]);
        return res;
    }
}


bool LeetCode::_0427_ConstructQuadTree::areConsistent(std::vector<std::vector<int>> &grid)
{
    const size_t M = grid.size();
    const size_t N = grid[0].size();
    int gld = grid[0][0];
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (grid[i][j] != gld)
            {
                return false;
            }
        }
    }
    return true;
}

bool LeetCode::_0427_ConstructQuadTree::areConsistent(std::vector<std::vector<int>> &grid, int rowStart, int rowEnd, int colStart, int colEnd)
{
    int gld = grid[rowStart][colStart];
    for (int i = rowStart; i < rowEnd; ++i)
    {
        for (int j = colStart; j < colEnd; ++j)
        {
            if (grid[i][j] != gld)
            {
                return false;
            }
        }
    }
    return true;
}

std::vector<std::vector<std::vector<int>>> LeetCode::_0427_ConstructQuadTree::divideGrid(std::vector<std::vector<int>> &grid)
{
    const size_t M = grid.size();
    const size_t N = grid[0].size();

    const size_t OM = M / 2;
    const size_t ON = N / 2;

    std::vector<std::vector<std::vector<int>>> res(4);
    res[0].resize(OM);
    res[1].resize(OM);
    res[2].resize(OM);
    res[3].resize(OM);
    for (int i = 0; i < OM; ++i)
    {
        res[0][i].resize(ON);
        res[1][i].resize(ON);
        res[2][i].resize(ON);
        res[3][i].resize(ON);
        for (int j = 0; j < ON; ++j)
        {
            res[0][i][j] = grid[i][j];
            res[1][i][j] = grid[i][j + ON];
            res[2][i][j] = grid[i + OM][j];
            res[3][i][j] = grid[i + OM][j + ON];
        }
    }
    return res;
}