#include "headers.hpp"
//需要反复练习并说出缘由的一道题。 一道典型的DP题目，不过有点懵住了。看答案得到的结果
/*
If you think this algorithm is not easy to understand, you can try this example:
        0 0 0 1 0 0 0 
        0 0 1 1 1 0 0 
        0 1 1 1 1 1 0 
The vector "left" and "right" from row 0 to row 2 are as follows
// 这里的主要思想是一行一行算，如何计算一个已知高度的矩形的面积，那就看他左边最少有多宽，右边最多有多宽
row 0:
        l: 0 0 0 3 0 0 0 // 这里存储的是矩形底边开始的起始位置index
        r: 7 7 7 4 7 7 7 // 这里存储的是矩形底边结束的终止位置index
row 1:
        l: 0 0 2 3 2 0 0 // 中间那个为3 而不是2 的原因是他的左上角是0，因此这个矩形往右看的话也就只能从3开始算底边.
        r: 7 7 5 4 5 7 7 
row 2:
        l: 0 1 2 3 2 1 0
        r: 7 6 5 4 5 6 7
The vector "left" is computing the left boundary. Take (i,j)=(1,3) for example. 
On current row 1, the left boundary is at j=2. However, because matrix[1][3] is 
1, you need to consider the left boundary on previous row as well, which is 3. 
So the real left boundary at (1,3) is 3.
*/

int LeetCode::_0085_MaximalRectangle::maximalRectangle(std::vector<std::vector<char>>& matrix) {
    if(matrix.empty()) {
        return 0;
    }
    const int M = matrix.size();
    const int N = matrix[0].size();
    std::vector<int> left(N, 0);
    std::vector<int> right(N, N);
    std::vector<int> height(N, 0);

    int maxA = 0;
    for(int i = 0; i < M; ++i) {
        int curLeft = 0;
        int curRight = N;
        for(int j = 0; j < N; ++j) {
            if(matrix[i][j] == '1') {
                ++height[j];
            } else {
                height[j] = 0;
            }
        }

        for(int j = 0; j < N; ++j) {
            if(matrix[i][j] == '1') {
                left[j] = std::max(left[j], curLeft);
            } else {
                left[j] = 0;
                curLeft = j + 1;
            }
        }

        for(int j = N - 1; j >= 0; --j) {
            if(matrix[i][j] == ' 1') {
                right[j] = std::min(right[j], curRight);
            } else {
                right[j] = N;
                curRight = j;
            }
        }

        for(int j = 0; j < N; ++j) {
            maxA = std::max(maxA, (right[j] - left[j]) * height[j]);
        }
    }
    return maxA;
}