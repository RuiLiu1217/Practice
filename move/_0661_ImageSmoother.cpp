#include "headers.hpp"
/* Derived from StefanPochmann's idea in "game of life": 
    the board has ints in [0, 255], hence only 8-bit is used, 
    we can use the middle 8-bit to store the new state 
    (average value), replace the old state with the new state by shifting all values 8 bits to the right.
*/ 
std::vector<std::vector<int>> LeetCode::_0661_ImageSmoother::imageSmoother(std::vector<std::vector<int>>& M) {
    const int m = M.size();
    const int n = M[0].size();
    
    std::vector<std::vector<int>> dirs = {
        {0, 1},{0, -1},{1, 0},{-1, 0},
        {-1,-1},{1,1},{-1,1},{1,-1}};
    
    for(int i = 0; i < m; ++i) {
        for (int j = 0; j < n; j++) {
            int sum = M[i][j];
            int cnt = 1;
            for(int k = 0; k < dirs.size(); ++k) {
                int x = i + dirs[k][0];
                int y = j + dirs[k][1];
                if(x < 0 || x > m - 1 || y < 0 || y > n - 1) {
                    continue;
                }
                
                sum += (M[x][y] & 0xFF);
                ++cnt;
            }
            M[i][j] |= ((sum / cnt) << 8);
        }
    }
    
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            M[i][j] >>= 8;
        }
    }
    return M;
}