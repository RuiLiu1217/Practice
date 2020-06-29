#include "LintCode.hpp"
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_set>
#include <numeric>
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
        for(int i = start, j = end; j > i; ++i, --j) {
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

// 1038
int LintCode::_1038_JewelsAndStones::numJewelInStones(std::string& J, std::string& S) {
    std::unordered_set<char> jewels;
    for(int i = 0; i < J.size(); ++i) {
        jewels.insert(J[i]);
    }

    int bt = 0;
    for(int i = 0; i < S.size(); ++i) {
        if(jewels.find(S[i]) != jewels.end()) {
            ++bt;
        }
    }
    return bt;
}

// 1104
bool LintCode::_1104_JudgeRouteCircle::judgeCircle(std::string &moves) {
    int x = 0; 
    int y = 0;
    for(int i = 0; i < moves.size(); ++i) {
        if(moves[i] == 'U') {
            ++y;
        } else if(moves[i] == 'D') {
            --y;
        } else if(moves[i] == 'L') {
            ++x;
        } else if(moves[i] == 'R') {
            --x;
        }
    }
    return (x == 0) && (y == 0);
}

// 1115
std::vector<double> LintCode::_1115_AverageOfLevelsInBinaryTree::averageOfLevels(TreeNode<int>* root) {
    TreeNode<int>* h = root;
    std::queue<TreeNode<int>*> q;
    if(!h) {
        return std::vector<double>();
    }
    q.push(h);
    double sum = 0;

    std::vector<double> res;
    while(!q.empty()) {
        const int N = q.size();
        double sum = 0;
        for(int i = 0; i < N; ++i) {
            auto tp = q.front();
            q.pop();
            sum += tp->val;
            if(tp->left) {
                q.push(tp->left);
            }
            if(tp->right) {
                q.push(tp->right);
            }
        }
        res.push_back(static_cast<double>(sum) / static_cast<double>(N));
    }
    return res;
}

// 1126
TreeNode<int>* LintCode::_1126_MergeTwoBinaryTrees::mergeTrees(TreeNode<int> * t1, TreeNode<int> * t2) {
    if(t1 && t2) {
        int v = t1->val + t2->val;
        TreeNode<int>* h = new TreeNode<int>(v);
        h->left = mergeTrees(t1->left, t2->left);
        h->right = mergeTrees(t1->right, t2->right);
        return h;
    } else {
        return t1 ? t1 : t2;
    }
}

// 1317
int LintCode::_1317_CountCompleteTreeNodes::countNodes(TreeNode<int>* root) {
    if(!root) {
        return 0;
    } else if(root->left == nullptr && root->right == nullptr) {
        return 1;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

// 1332
int LintCode::_1332_NumberOf1Bits::hammingWeight(unsigned int n) {  
    int res = 0;
    while(n) {
        res += (n & 1);
        n >>= 1;
    }
    return res;
}

// 1355
std::vector<std::vector<int>> LintCode::_1355_PascalsTriangle::generate(int numRows) {
    std::vector<std::vector<int>> res;
    res.push_back({1});
    if(numRows == 1) {
        return res;
    }
    res.push_back({1,1});
    if(numRows == 2) {
        return res;
    } else {
        for(int i = 2; i < numRows; ++i) {
            std::vector<int> c;
            c.reserve(i+1);
            c.push_back(1);
            for(int j = 0; j < res[i-1].size() - 1; ++j) {
                c.push_back(res[i-1][j] + res[i-1][j+1]);
            }
            c.push_back(1);
            res.push_back(c);
        }
        return res;
    }
}

// 1511
// Totall copy from the solution
int LintCode::_1511_MirrorReflection::mirrorReflection(int p, int q) {
    int g = std::gcd(p, q);
    int lcm = p * (q / g);
    int x = lcm / p;
    int y = lcm / q;
    if( y % 2) {
        if(x % 2) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 2;
    }
}


// 1508
int LintCode::_1508_ScoreAfterFlippingMatrix::matrixScore(std::vector<std::vector<int>>& A) {
    for(int i = 0; i < A.size(); ++i) {
        if(A[i][0] == 0) {
            flipRow(A, i);
        }
    }
    
    for(int j = 1; j < A[0].size(); ++j) {
        if (countOnes(A, j) < A[0].size() / 2) {
            flipCol(A, j);
        }
    }
    int res = 0;
    for(int i = 0; i < A.size(); ++i) {
        res += toNum(A[i]);
    }
    return res;
}

void LintCode::_1508_ScoreAfterFlippingMatrix::flipRow(std::vector<std::vector<int>>& A, int rowIdx) {
    for(int i = 0; i < A[rowIdx].size(); ++i) {
        if(A[rowIdx][i] == 0) {
            A[rowIdx][i] = 1;
        } else {
            A[rowIdx][i] = 0;
        }
    }
}

void LintCode::_1508_ScoreAfterFlippingMatrix::flipCol(std::vector<std::vector<int>>& A, int colIdx) {
    const int colNum = A.size();
    for(int j = 0; j < colNum; ++j) {
        if (A[j][colIdx] == 0) {
            A[j][colIdx] = 1;
        } else {
            A[j][colIdx] = 0;
        }
    }
}

int LintCode::_1508_ScoreAfterFlippingMatrix::countOnes(std::vector<std::vector<int>>& A, int colIdx) {
    const int colNum = A.size();
    int count = 0;
    for(int j = 0; j < colNum; ++j) {
        if (A[j][colIdx] == 1) {
            ++count;
        }
    }
    return count;
}

int LintCode::_1508_ScoreAfterFlippingMatrix::toNum(std::vector<int>& v) {
    int res = 0;
    for(auto& t : v) {
        res <<= 1;
        res += t;
    }
    return res;
}


// 1535
std::string LintCode::_1535_ToLowerCase::toLowerCase(std::string &str) {
     for(char& c : str) {
        if(c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a';
        }
    }
    return str;
}


// 1592
std::vector<std::string> LintCode::_1592_FindAndReplacePattern::findAndReplacePattern(std::vector<std::string> &words, std::string &pattern) {
    std::vector<std::string> res;    
    for(int i = 0; i < words.size(); ++i) {
        if(samePattern(words[i], pattern)) {
            res.push_back(words[i]);
        }
    }
    return res;
}

bool LintCode::_1592_FindAndReplacePattern::samePattern(std::string& A, std::string& B) {
    std::unordered_map<char, char> mpa;
    std::unordered_map<char, char> mpb;
    if(A.size() != B.size()) {
        return false;
    }
    
    for(int i = 0; i < A.size(); ++i) {
        if(mpa.find(A[i]) == mpa.end()) {
            if(mpb.find(B[i]) != mpb.end()) {
                return false;
            }
            
            mpa[A[i]] = B[i];
            mpb[B[i]] = A[i];
        } else {
            if(mpa[A[i]] != B[i] || mpb.find(B[i]) == mpb.end() || mpb[B[i]] != A[i]) {
                return false;
            }
        }
    }
    return true;
}