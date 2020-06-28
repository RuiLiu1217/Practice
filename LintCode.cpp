#include "LintCode.hpp"
#include <algorithm>
// 0001
int LintCode::_0001_APlusBProblem::aplusb(int a, int b) {
    int carry = 0;
    int res = 0;
    for(int i = 0; i < 32; ++i) {
        int t1 = a & 1;
        int t2 = b & 1;
        int tail = (t1 ^ t2 ^ carry);
        if((t1 == 1 && t2 == 1) || 
            (t1 == 1 && carry == 1) ||
            (t2 == 1 && carry == 1)) {
                carry = 1;
            } else {
                carry = 0;
            }
        res |= (tail << i);
        a >>= 1;
        b >>= 1;
    }
    return res;
}

// 0002
long long LintCode::_0002_TrailingZeros::trailingZeros(long long n) { 
    long long res = 0;
    while(n) {
        res += (n / 5); // The number of tailing zeros is totally decided by number of 5. 
        n /= 5;
    }
    return res;
}

// 0004
int LintCode::_0004_UglyNumberII::nthUglyNumber(int n) {
    std::vector<int> ugly;
    ugly.reserve(n+1);
    ugly.push_back(1);

    int i2 = 0, i3 = 0, i5 = 0;

    while(ugly.size() < n) {
        const int next2 = ugly[i2] * 2;
        const int next3 = ugly[i3] * 3;
        const int next5 = ugly[i5] * 5;
        const int next = std::min({next2, next3, next5});
        if(next == next2) ++i2;   // 这种写法，当我们有多个ugly数与翻新相对应时，要同时更新多个index. 我自己的实现就是没有这样的考虑，导致程序错误
        if(next == next3) ++i3; 
        if(next == next5) ++i5;
        ugly.push_back(next);
    }
    return ugly.back();
}

// 0006
std::vector<int> LintCode::_0006_MergeTwoSortedArrays::mergeSortedArray(std::vector<int> &A, std::vector<int> &B) {
    std::vector<int> res(A.size() + B.size(), 0);
    int i = 0; 
    int j = 0;
    int t = 0;
    while(i < A.size() && j < B.size()) {
        if(A[i] < B[j]) {
            res[t++] = A[i++];
        } else {
            res[t++] = B[j++];
        }
    }

    std::copy(A.begin() + i, A.end(), res.begin() + t);
    std::copy(B.begin() + j, B.end(), res.begin() + t);
    
    return res;
}

// 0008
void LintCode::_0008_RotateString::rotateString(std::string &str, int offset) {
    // write your code here
    int strSize = str.size(); 
    if(str.empty()) {
        return;
    }
    offset = offset % strSize;
    std::function<void(int start, int end)> SWAP = [&](int start, int end) {
        for(int i = start, j = start; j > i; ++i, --j) {
            std::swap(str[i], str[j]);
        }
    };

    SWAP(0, strSize - offset - 1);
    SWAP(strSize - offset, strSize -1);
    SWAP(0, strSize -1);
}

// 0009
std::vector<std::string> LintCode::_0009_FizzBuzz::fizzBuzz(int n) {
    // write your code here
    std::vector<std::string> res;
    for(int i = 1; i <= n; ++i) {
        if( (i%3 == 0) && (i%5 == 0)) {
            res.push_back("fizz buzz");
        } else if ((i%3==0)) {
            res.push_back("fizz");
        } else if ((i%5==0)) {
            res.push_back("buzz");
        } else {
            res.push_back(std::to_string(i));
        }
    }
    return res;
}


// 1010 
int LintCode::_1010_MaxIncreaseToKeepCitySkyline::maxIncreaseKeepingSkyline(std::vector<std::vector<int>> &grid) {
    std::vector<std::vector<int>> res;
    std::vector<int> rowMax(grid.size());
    std::vector<int> colMax(grid[0].size());
    for(int i = 0; i < grid.size(); ++i) {
        int rm = grid[i][0];
        for(int j = 0; j < grid[i].size(); ++j) {
            if(rm < grid[i][j]) {
                rm = grid[i][j];
            }
        }
        rowMax[i] = rm;
    }
    
    for(int j = 0; j < grid[0].size(); ++j) {
        int cm = grid[0][j];
        for(int i = 0; i < grid.size(); ++i) {
            if(cm < grid[i][j]) {
                cm = grid[i][j];
            }
        }
        colMax[j] = cm;
    }

    int count = 0;
    for(int i = 0; i < grid.size(); ++i) {
        for(int j = 0; j < grid[i].size(); ++j) {
            int minIJ = std::min(rowMax[i], colMax[j]);
            count += (minIJ - grid[i][j]);
        }
    }
    return count;
}

