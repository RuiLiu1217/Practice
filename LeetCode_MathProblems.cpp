#include "LeetCode_MathProblems.hpp"
#include <cmath>
#include <climits>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <vector>
#include <numeric>
#include <functional>
/*
Google
*/
int LC::_0007_ReverseInteger::reverse(int x) {
    long long res = 0; // Consider the overflow
    while(x) {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return (res < INT_MIN || res > INT_MAX) ? 0 : res; // The difficulty is the attention of overflow
}


// Google
bool LC::_0009_PalindromeNumber::isPalindrome(int x) {
   if(x < 0) {
        return false;
    }
    
    int t = x;
    long res = 0;
    while(t) {
        res = res * 10 + t % 10;
        t /= 10;
    }
    return res == x;
}



//! TODO: 
// Facebook
int LC::_0029_DivideTwoIntegers::divide(int dividend, int divisor) {
    if(dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }
    if(divisor == 1) {
        return dividend;
    }
    long dvd = std::labs(dividend); // LONG DATATYPE ABSOLUTE VALUE
    long dvs = std::labs(divisor);
    long ans = 0;
    int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
    
    while (dvd >= dvs) {
        long temp = dvs, m = 1;
        while (temp << 1 <= dvd) {
            temp <<= 1;
            m <<= 1;
        }
        dvd -= temp;
        ans += m;
    }
    return sign * ans;
}

// String, Mathematics, Recursive
int LC::_0171_ExcellSheetColumnNumber::titleToNumber(std::string s) {
    if(s.empty()) {
        return 0;
    }
    if(s.size() == 1) {
        return (s[0] - 'A' + 1);
    }
    else {
        char ss = s.back();
        std::string subS = s.substr(0, s.size() - 1);
        return titleToNumber(subS) * 26 + (ss - 'A' + 1);
    }
}

std::string LC::_0168_ExcelSheetColumnTitle::convertToTitle(int n) {
    return n == 0 ? "" : convertToTitle(n / 26) + (char) (--n % 26 + 'A');
}

// Recursive, mathematics
int LC::_0172_FactorialTrailingZeroes::trailingZeroes(int n) {
    return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
}


int LC::_0202_HappyNumber::gat(int n) {
    int sum = 0;
    while(n > 0) {
        sum += std::pow(n % 10, 2);
        n = n / 10;
    }
    return sum;
}

bool LC::_0202_HappyNumber::isHappy(int n) {
    int newN = gat(n);
    std::unordered_set<int> loops;
    if(newN == 1) {
        return true;
    }
    while(!loops.count(newN)) {
        loops.insert(newN);
        newN = gat(newN);
        if(newN == 1) {
            return true;
        }
    }
    return false;        
}


// Very tricky solution
int LC::_0204_CountPrimes::countPrimes(int n) {
    if(n <= 2) {
        return 0;
    }
    std::vector<bool> isPrime(n,true);
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 4; i < n; i = i + 2) {
        isPrime[i] = false;
    }

    int sqt = std::sqrt(n);
    for(int i = 3; i <= sqt; i = i + 2) {
        if(isPrime[i]) {
            for(int j = i * i; j < n; j = j + i) {
                isPrime[j] = false;
            }
        }
    }
    return std::count(isPrime.begin(), isPrime.end(), true);   
}


// Tag: Computational Geometry
int LC::_0223_RectangleArea::computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int x = std::min(G, C) > std::max(E, A) ? (std::min(G, C) - std::max(E, A)) : 0;
    int y = std::min(D, H) > std::max(B, F) ? (std::min(D, H) - std::max(B, F)) : 0;
    return (D - B) * (C - A) + ((G - E) * (H - F) - x * y); // calculate minus first to avoid overflow
}


bool LC::_0231_PowerOfTwo::isPowerOfTwo(int n) {
    return (n > 0) && !(n & (n - 1));
}


std::vector<std::string> LC::_1447_SimplifiedFractions::simplifiedFractions(int n) {
    std::vector<std::string> res;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j < i; ++j) {
            if(std::gcd(i,j) == 1) {
                res.push_back(std::to_string(j) + "/" + std::to_string(i));
            }
        }
    }
    
    return res;
}


bool LC::_0263_UglyNumber::isUgly(int num) {
    if(!num) {
        return false;
    }
    while(num%2 == 0) {
        num = num / 2;
    }
    while(num%3 == 0) {
        num = num / 3;
    }
    while(num%5 == 0) {
        num = num / 5;
    }

    return num == 1;
}

// 一个数各个位置的数相加得到一个新的数，
// 如此往复一直加到个位数，快速计算这个个
// 位数的办法有个公式，如果这个数是0，就
// 直接返回0，否则将原先的数mod 9， 如果
// 能被 9 整除，则返回9， 否则返回这个余数
int LC::_0258_AddDigits::addDigits(int num) {
    if(num == 0) {
        return 0;
    }
    int v = (num % 9);
    return v == 0 ? 9 : v;
}


// Facebook
std::vector<std::vector<int>> LC::_0311_SparseMatrixMultiplication::multiply(std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& B) {
    const int MA = A.size();
    if(MA == 0) {
        return {};
    }
    const int NA = A[0].size();
    if(NA == 0) {
        return {};
    }
    const int MB = B.size();
    if(MB == 0) {
        return {};
    }
    const int NB = B[0].size();
    if(NB == 0) {
        return {};
    }
    
    std::vector<std::unordered_set<int>> colA(MA);
    for(int i = 0; i < MA; ++i) {
        for(int j = 0; j < NA; ++j) {
            if(A[i][j]) {
                colA[i].insert(j);
            }
        }
    }
    
    std::vector<std::vector<int>> res(MA, std::vector<int>(NB));
    for(int i =0; i < MA; ++i) {
        std::unordered_set<int>& idxA = colA[i];
        for(int j = 0; j < NB; ++j) {
            int sum = 0;    
            for(int k = 0; k < MB; ++k) {
                if(B[k][j] && idxA.count(k)) {
                    sum += A[i][k] * B[k][j];
                }
            }
        
            res[i][j] = sum;
        }
    }
    return res;
}
 

// Totally maths problem
bool LC::_0326_PowerOfThree::isPowerOfThree(int n) {
    return (n > 0 && (1162261467 % n == 0)); // 32-bit integer the largest 3^n is 1162261467
}

bool LC::_0342_PowerOfFour::isPowerOfFour(int num) {
    if(num == 0) {
        return false;
    }
    const int v1 = 0x55555555;
    return ((num & (num-1)) == 0) && ((num | v1) == v1);
}

// Newtown method
bool LC::_0367_ValidPerfectSquare::isPerfectSquare(int x) {
    long r = x;
    while(r * r > x) {
        r = (r + x / r) / 2;
    }
    return r * r == x;
}

// 这是一道数学题，需要仔细分析到底这道题在考什么
// 1337 只有两个因子: 7 和 191, 
// phi of them is itself - 1, 这时候可以用欧拉定理
// https://en.wikipedia.org/wiki/Euler's_theorem, 
// it's just Fermat's little theorem if the mod n is prime.
// see how 1140 is calculated out:
// phi(1337) = phi(7) * phi(191) = 6 * 190 = 1140

// 这道题一下子蒙住了，完全灭有想法，实际上这道题是之前求一个大数的大幂的扩展。

// 这道题题让我们求一个数的很大的次方对1337取余的值，
// 那么这道题和之前那道Pow(x, n)的解法很类似，我们都得
// 对半缩小，不同的是后面都要加上对1337取余
static int myPow(int x, int n) {
    if (n == 0) {
        return 1;
    }
    if(n == 1) {
        return x % 1337;
    }
    return myPow(x % 1337, n / 2) * myPow(x % 1337, n - n / 2) % 1337;
}


int LC::_0372_SuperPow::superPow(int a, std::vector<int>& b) {
    long long res = 1;
    for(int i = 0; i < b.size(); ++i) {
        res = myPow(res, 10) * myPow(a, b[i]) % 1337;
    }
    return res;
}


bool LC::_0593_ValidSquare::validSquare(std::vector<int>& p1, std::vector<int>& p2, std::vector<int>& p3,
    std::vector<int>& p4) {

    std::function<std::vector<int>(const std::vector<int>& a, const std::vector<int>& b)> minus = [](const std::vector<int>& a,const std::vector<int>& b) {
        std::vector<int> res(2, 0);
        res[0] = a[0] - b[0];
        res[1] = a[1] - b[1];
        return res;        
    };

    std::function<int(const std::vector<int>&,const std::vector<int>&)> multiply = [](const std::vector<int>& a,const std::vector<int>& b) {
        return a[0] * b[0] + a[1] * b[1];
    };

    std::function<int(const std::vector<int>&)> lenSqu = [](const std::vector<int>& a) {
        return a[0] * a[0] + a[1] * a[1];
    };

    std::function<bool(const std::vector<int>&, const std::vector<int>&)> equal = [](const std::vector<int>& a,const std::vector<int>& b) {
        return (a[0] == b[0] && a[1] == b[1]);
    };

    if(p1 == p2 || p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4 || p3 == p4) {
        return false;
    }
    std::vector<int> v1 = minus(p2, p1);
    std::vector<int> v2 = minus(p3, p1);
    std::vector<int> v3 = minus(p4, p1);

    if(multiply(v1, v2) == 0) {
        if(lenSqu(v1) != lenSqu(v2)) {
            return false;
        }
        std::vector<int> w1 = minus(p4, p2);
        std::vector<int> w2 = minus(p4, p3);
        if(multiply(w1, w2) != 0) {
            return false;
        }
        return true;
    } else if(multiply(v1, v3) == 0) {
        if(lenSqu(v1) != lenSqu(v3)) {
            return false;
        }
        std::vector<int> w1 = minus(p3, p2);
        std::vector<int> w2 = minus(p3, p4);
        if(multiply(w1, w2) != 0) {
            return false;
        }
        return true;
    } else if(multiply(v2, v3) == 0) {
        if(lenSqu(v3) != lenSqu(v2)) {
            return false;
        }
        std::vector<int> w1 = minus(p3, p2);
        std::vector<int> w2 = minus(p2, p4);
        if(multiply(w1, w2) != 0) {
            return false;
        }
        return true;
    } else {
        return false;
    }
}

// !copy from the solution, I have no idea why
int LC::_0611_ValidTriangleNumber::triangleNumber(std::vector<int>& nums) {
    int count = 0;
    std::sort(nums.begin(), nums.end());
    if(nums.size() < 3) {
        return 0;
    }
    for(int i = 0; i < nums.size() - 2; ++i) { 
        int k = i + 2;
        for(int j = i + 1; j < nums.size() - 1 && nums[i] != 0; ++j) {
            while(k < nums.size() && nums[i] + nums[j] > nums[k]) {
                ++k;
            }
            count += k - j - 1;
        }
    }
    return count;
    
}

bool LC::_0633_SumOfSquareNumbers::judgeSquareSum(int c) {
    int hc = c / 2;
    for(int i = 0; i * i <= hc; ++i) {
        int res = c - i * i;
        int f = std::floor(std::sqrt(res)); // Usually the most general method is highly effective.
        if (f * f == res) {
            return true;
        }
    }
    return false;
}

bool LC::_0657_RobotReturnToOrigin::judgeCircle(std::string moves) {
    int x = 0;
    int y = 0;
    for(char c : moves) {
        if(c == 'L') {
            --x;
        } else if(c == 'R') {
            ++x;
        } else if(c == 'U') {
            ++y;
        } else if(c == 'D') {
            --y;
        }
    }
    return x == 0 && y == 0;
}


//! Copy from the solution
int LC::_1015_SmallestIntegerDivisibleByK::smallestRepunitDivByK(int K) {
    if(K % 2 == 0 || K % 5 == 0) {
        return -1;
    }
    int i = 0;
    int mod = 0;
    std::unordered_set<int> remainder;
    while(true) {
        mod = (mod * 10 + 1) % K;
        if(remainder.count(mod)) {
            return -1;
        }
        ++i;
        if(mod == 0) {
            return i;
        }
        remainder.insert(mod);
    }
    return -1;
}


//这道题完全是数学题，考的是概率，结论是令人有点难以理解的0.5.具体的分析：
// 通过条件概率，构造递推公式，假设 n 个人的答案为 f(n). 已知 f(1)=1.
// 假设现在有 n 个人，如果第一个人选了 1 号座位，则第 n 个人必定会坐到自己的座位上。这个事件发生的概率为 1/n.
// 如果第一个人选了 n 号座位，则第 n 个人永远不会坐到自己的座位上。这个事件发生的概率也为 1/n.
// 接下来，不妨假设第一个人选了 j 号座位，其中 2<=j<=n−1，则第二个到第 j−1 个人都会坐到自己的座位上，第 j 个人
// 到第 n 个人的座位有可能被打乱。此时，如果第 j 个人选择了第一个人的座位，则第 n 个人必定会坐到自己的座位上。
// 如果第 j 个人选了 n 号座位，则第 n 个人永远不会坐到自己的座位上，所以规模变成了 n−j+1 个人的问题。
// 综上，当 n>=2 时，递推公式可以为 
//           $f(n) = \frac{1}{n}\dot 1 + \frac{1}{n}\dot 0 + \frac{1}{n}\sum_{j=2}^{n-1}f(n-j+1) 
//                 = \frac{1}{n}\sum_{j=1}^{n-1}f(j)

// 对于 n>=2 时，又有 (n+2)⋅f(n+1)=∑j=2n+1f(j)，通过等式相减，可以得到 (n+1)⋅f(n+1)=(n+1)⋅f(n) 。已知 
// f(n)≠0，所以 f(n)=f(n+1) 对 n≥2n≥2 成立。
// f(2)=0.5，所以当 n≥2 时，f(n)=0.5
double LC::_1227_AirplaneSeatAssignmentProbability::nthPersionGetsNthSeat(int n) {
    return n==1?1:0.5;
}

int LC::_1228_MissingNumberInArithmeticProgression::missingNumber(std::vector<int>& arr) {
    int first = arr[0], last = arr[0], sum = 0, n = arr.size();
    for (int a : arr) {
        first = std::min(first, a);
        last = std::max(last, a);
        sum += a;
    }
    return (first + last) * (n + 1) / 2 - sum; // the problem mentioned that the removed value is not the first or the last value
}


bool LC::_1232_CheckIfItIsAStraightLine::checkStraightLine(std::vector<std::vector<int>>& coordinates) {
    if(coordinates.size() <= 2) {
        return true;
    }
    
    const int difx = coordinates[1][0] - coordinates[0][0];
    const int dify = coordinates[1][1] - coordinates[0][1];
    for(int i = 2; i < coordinates.size(); ++i) {
        const int dx = coordinates[i][0] - coordinates[i-1][0];
        const int dy = coordinates[i][1] - coordinates[i-1][1];
        
        if(difx == 0) {
            if(dx != 0) {
                return false;
            }
        }
        if(dify == 0) {
            if(dy != 0) {
                return false;
            }
        }
        if (dify * dx != dy * difx) {
            return false;
        }
    }
    return true;
}


int LC::_1323_Maximum69Number::maximum69Number(int num) {
    std::string a = std::to_string(num);
    size_t i = a.find('6');
    if(i < a.size()) {
        a[i] = '9';
    }
    return std::stoi(a);
}

double LC::_1344_AngleBetweenHandsOfAClock::angleClock(int hour, int minutes) {
    double hpos = hour * 30 + 0.5 * minutes;
    double mpos = 6.0 * minutes;
    double posDiff = std::abs(mpos - hpos);
    if (posDiff > 180.0) {
        posDiff = 360.0 - posDiff;
    }
    return posDiff;
}