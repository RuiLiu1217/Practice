#include "LeetCode_DynamicProgrammingProblems.hpp"
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
// Tag: dynamic programming, string matching.
bool LC::_0010_RegularExpressionMatching::isMatch(std::string s, std::string p){
    const int M = s.length();
    const int N = p.length();

    // DP[i][j] means whether the first [0,i) substr of s 
    // matches with the first [0,j) substr of p.
    std::vector<std::vector<bool>> DP(M + 1, std::vector<bool>(N + 1, false));
    DP[0][0] = true;

    for(int i = 0; i <= M; ++i) {
        for(int j = 1; j <= N; ++j) {
            if(p[j-1] == '*') {
                DP[i][j] = DP[i][j-2] || (i && DP[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'));
            } else {
                DP[i][j] = i && DP[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
            }
        }
    }
    return DP[M][N];
}


int LC::_0062_UniquePaths::uniquePaths(int m, int n) {
    std::vector<std::vector<int>> DP(m, std::vector<int>(n, 0));
    DP[0][0] = 1;
    for(int j = 0; j < n; ++j) {
        DP[0][j] = 1;
    }
    for(int i = 0; i < m; ++i) {
        DP[i][0] = 1;
    }
    for(int i = 1; i < m; ++i) {
        for(int j = 1; j < n; ++j) {
            DP[i][j] = DP[i-1][j] + DP[i][j-1];
        }
    }
    return DP[m-1][n-1];
}



int LC::_0063_UniquePathsII::uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
    const int M = obstacleGrid.size();
    const int N = obstacleGrid[0].size();
    std::vector<std::vector<long long>> DP(M, std::vector<long long>(N));
    bool flag = false;
    for (int i = 0; i < M; ++i) {
        if (obstacleGrid[i][0] == 0) {
            DP[i][0] = 1;
        } else {
            DP[i][0] = -1;
            flag = true;
        }

        if (flag) {
            DP[i][0] = -1;
        }
    }

    flag = false;
    for (int j = 0; j < N; ++j) {
        if (obstacleGrid[0][j] == 0) {
            DP[0][j] = 1;
        } else {
            DP[0][j] = -1;
            flag = true;
        }

        if (flag) {
            DP[0][j] = -1;
        }
    }

    for (int i = 1; i < M; ++i) {
        for (int j = 1; j < N; ++j) {
            if (obstacleGrid[i][j] != 1) {
                if (DP[i - 1][j] == -1 && DP[i][j - 1] == -1) {
                    DP[i][j] = -1;
                } else if (DP[i - 1][j] != -1 && DP[i][j - 1] == -1) {
                    DP[i][j] = DP[i - 1][j];
                } else if (DP[i - 1][j] == -1 && DP[i][j - 1] != -1) {
                    DP[i][j] = DP[i][j - 1];
                } else {
                    DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
                }
            } else {
                DP[i][j] = -1;
            }
        }
    }
    return DP[M - 1][N - 1] == -1 ? 0 : DP[M - 1][N - 1];
}


int LC::_0064_MinimumPathSum::minPathSum(std::vector<std::vector<int>>& grid) {
    if(grid.size() == 0 || grid[0].size() == 0) {
        return 0;
    }
    std::vector<std::vector<int>> DP(grid.size(), std::vector<int>(grid[0].size()));
    
    DP[0][0] = grid[0][0];
    for(int j = 1; j < grid[0].size(); ++j) {
        DP[0][j] = DP[0][j-1] + grid[0][j];
    }
    for(int i = 1; i < grid.size(); ++i) {
        DP[i][0] = DP[i-1][0] + grid[i][0];
    }
    
    for(int i = 1; i < grid.size(); ++i) {
        for(int j = 1; j < grid[i].size(); ++j) {
            DP[i][j] = std::min(DP[i-1][j] , DP[i][j-1]) + grid[i][j];
        }
    }
    return DP.back().back();
}


int LC::_0070_ClimbingStairs::climbStairs(int n) {
    if(n < 3) {
        return n;
    }
    int f1 = 1;
    int f2 = 2;
    int f;
    for(int i = 3; i <= n; ++i) {
        f = f1 + f2;
        f1 = f2;
        f2 = f;
    }
    return f;
}

bool LC::_0097_InterleavingString::isInterleav(std::string s1, std::string s2, std::string s3) {
    if(s3.length() != s1.length() + s2.length())
        return false;

    bool table[s1.length() + 1][s2.length() + 1];

    for(int i = 0; i <= s1.length(); ++i) {
        for(int j = 0; j <= s2.length(); ++j) {
            if(i == 0 && j == 0) {
                table[i][j] = true;
            } else if(i == 0) {
                table[i][j] = (table[i][j-1] && s2[j-1] == s3[i+j-1]);
            } else if(j == 0) {
                table[i][j] = (table[i-1][j] && s1[i-1] == s3[i+j-1]);
            } else {
                table[i][j] = (table[i-1][j] && s1[i-1] == s3[i+j-1] ) || (table[i][j-1] && s2[j-1] == s3[i+j-1] );
            }
        }
    }
    return table[s1.length()][s2.length()];
}


//! 抄答案的，动态规划
// 由于需要在O(N)时间复杂度内完成，
// 这道题要求求最长连续序列，并给定了O(n)复杂度限制，我们的思路是，使用一个集合HashSet存入所有的数字，
// 然后遍历数组中的每个数字，如果其在集合中存在，那么将其移除，然后分别用两个变量pre和next算出其前一个
// 数跟后一个数，然后在集合中循环查找，如果pre在集合中，那么将pre移除集合，然后pre再自减1，直至pre不
// 在集合之中，对next采用同样的方法，那么next-pre-1就是当前数字的最长连续序列，更新res即可。这里再说下
// 为啥当检测某数字在集合中存在当时候，都要移除数字。这是为了避免大量的重复计算，就拿题目中的例子来说吧
// 我们在遍历到4的时候，会向下遍历3，2，1，如果都不移除数字的话，遍历到1的时候，还会遍历2，3，4。同样，
// 遍历到3的时候，向上遍历4，向下遍历2，1，等等等。如果数组中有大量的连续数字的话，那么就有大量的重复计
// 算，十分的不高效，所以我们要从HashSet中移除数字，代码如下：
int LC::_0128_LongestConsecutiveSequence::longestConsecutive(std::vector<int>& nums) {
    int res = 0;
    std::unordered_set<int> s(nums.begin(), nums.end());
    for (int val : nums) {
        if (!s.count(val)) continue;
        s.erase(val);
        int pre = val - 1, next = val + 1;
        while (s.count(pre)) s.erase(pre--);
        while (s.count(next)) s.erase(next++);
        res = std::max(res, next - pre - 1);
    }
    return res;
}


/* It is a typical DP problem. We design a DP vector, DP[i] means the maximum value that we can get from 
nums[0] to nums[i].

DP[0] = nums[0];
DP[1] = max(nums[0], nums[1]);
DP[2] = max(DP[0] + nums[0], nums[1]); 

Therefore, DP[i] = max(DP[i-2] + nums[i], DP[i-1]); */
int LC::_0198_HouseRobber::rob(std::vector<int>& nums) {
    if(nums.size() == 0) {
        return 0;
    }
    std::vector<int> DP(nums.size()+1, 0);
    DP[0] = nums[0];
    if(nums.size() == 1) {
        return nums[0];
    }
    DP[1] = std::max(nums[0], nums[1]);
    for(int i = 2; i < nums.size(); ++i) {
        DP[i] = std::max(DP[i-2] + nums[i], DP[i-1]);
    }
    
    return DP[nums.size()-1];
}

// Tag: dynamic programming, two times calculation, {0~N-1, 1~N}
int LC::_0213_HouseRobberII::rob(std::vector<int>& nums) {
    if(nums.size() == 0) {
        return 0;
    }
    if(nums.size() == 1) {
        return nums[0];
    }
    if(nums.size() == 2) {
        return std::max(nums[0], nums[1]);
    }
    
    std::vector<int> A(nums.begin(), nums.end() - 1);
    std::vector<int> B(nums.begin() + 1, nums.end());
    int rA = robHelp(A);
    int rB = robHelp(B);
    return std::max(rA, rB);        
}

int LC::_0213_HouseRobberII::robHelp(std::vector<int>& nums) {
    if(nums.size() == 1) {
        return nums[0];
    }
    if(nums.size() == 2) {
        return std::max(nums[0], nums[1]);
    }
    
    std::vector<std::vector<int>> DP(2, std::vector<int>(nums.size(), 0));
    DP[0][0] = 0;
    DP[1][0] = nums[0];
    for(int i = 1; i < nums.size(); ++i) {
        DP[0][i] = std::max(DP[0][i-1], DP[1][i-1]);
        DP[1][i] = DP[0][i-1] + nums[i];
    }
    return std::max(DP[0].back(), DP[1].back());
}


// Tag: Dynamic Programming
// Google
// TODO: state transition equation
int LC::_0221_MaximalSquare::maximalSquare(std::vector<std::vector<char>>& matrix) {
    const int M = matrix.size();
    if(M == 0) {
        return 0;
    }
    const int N = matrix[0].size();
    if(N == 0) {
        return 0;
    }
    
    std::vector<std::vector<int>> DP(M, std::vector<int>(N, 0));
    int maxS = 0;
    for(int j = 0; j < N; ++j) {
        if(matrix[0][j] == '1') {
            DP[0][j] = 1;
            maxS = std::max(maxS, DP[0][j]);
        }
    }
    for(int i = 0; i < M; ++i) {
        if(matrix[i][0] == '1') {
            DP[i][0] = 1;
            maxS = std::max(maxS, DP[i][0]);
        }
    }
    for(int i = 1; i < M; ++i) {
        for(int j = 1; j < N; ++j) {
            if(matrix[i][j] == '1') {
                DP[i][j] = std::min(std::min(DP[i-1][j], DP[i][j-1]), DP[i-1][j-1]) + 1;
                maxS = std::max(maxS, DP[i][j]);
            }
        }
    }
    return maxS * maxS;
}


int LC::_0264_UglyNumberII::nthUglyNumber(int n) {
    std::vector<int> res(1,1);
    int idx2 = 0;
    int idx3 = 0;
    int idx5 = 0;
    while(res.size() < n) {
        int nextNum = std::min(res[idx5] * 5, std::min(res[idx2] * 2, res[idx3] * 3));
        if(nextNum == res[idx5] * 5) {
            idx5++;
        }
        if(nextNum == res[idx2] * 2) {
            idx2++;
        }
        if(nextNum == res[idx3] * 3) {
            idx3++;
        }
        res.push_back(nextNum);
    }
    return res.back();
}

// Copy from the solution
// Use DP
//需要建立一个二维的 dp 数组，其中 dp[i][j] 表示从数字i到j之间猜中任意一个数字最少需要花费的钱数，
// 那么需要遍历每一段区间 [j, i]，维护一个全局最小值 global_min 变量，然后遍历该区间中的每一个数
// 字，计算局部最大值 local_max = k + max(dp[j][k - 1], dp[k + 1][i])，这个正好是将该区间在每
// 一个位置都分为两段，然后取当前位置的花费加上左右两段中较大的花费之和为局部最大值，为啥要取两者之
// 间的较大值呢，因为要 cover 所有的情况，就得取最坏的情况。然后更新全局最小值，最后在更新 dp[j][i]
// 的时候看j和i是否是相邻的，相邻的话赋为j，否则赋为 global_min。这里为啥又要取较小值呢，因为 dp 数
// 组是求的 [j, i] 范围中的最低 cost，比如只有两个数字1和2，那么肯定是猜1的 cost 低，
//!! Copy from the solution
int LC::_0375_GuessNumberHigherOrLowerII::getMoneyAmount(int n) {
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(n+1, 0));
    for(int i = 2; i <= n; ++i) {
        for(int j = i - 1; j > 0; --j) {
            int globalMin = INT_MAX;
            for(int k = j + 1; k < i; ++k) {
                int localMax = k + std::max(dp[j][k-1], dp[k+1][i]);
                globalMin = std::min(globalMin, localMax);
            }
            dp[j][i] = j+1 == i ? j : globalMin;
        }
    }
    return dp[1][n];
}


int LC::_0312_BurstBalloons::maxCoins(std::vector<int>& nums) {
    const int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    std::vector<std::vector<int>> DP(n+2, std::vector<int>(n+2, 0));
    // 现在是想知道 dp[i][j] 的值，这个区间可能比较大，但是如果知道了所有的小区间的 dp 值，
    // 然后聚沙成塔，逐步的就能推出大区间的 dp 值了。

    for(int len = 1; len <= n; ++len) {
        for(int left = 1; left <= n - len + 1; ++left) {
            int right = left + len - 1;
            for(int k = left; k <= right; ++k) {
                // 还是要遍历这个区间内的每个气球，就用k来遍历吧，k在区间 [i, j] 中，假如第k个气球最后被打爆，
                // 那么此时区间 [i, j] 被分成了三部分，[i, k-1]，[k]，和 [k+1, j]，只要之前更新过了 [i, k-1] 
                // 和 [k+1, j] 这两个子区间的 dp 值，可以直接用 dp[i][k-1] 和 dp[k+1][j]，那么最后被打爆的
                // 第k个气球的得分该怎么算呢，你可能会下意识的说，就乘以周围两个气球被 nums[k-1] * nums[k] * nums[k+1]，
                // 但其实这样是错误的，为啥呢？dp[i][k-1] 的意义是什么呢，是打爆区间 [i, k-1] 内所有的气球
                // 后的最大得分，此时第 k-1 个气球已经不能用了，同理，第 k+1 个气球也不能用了，相当于区间 [i, j] 中
                // 除了第k个气球，其他的已经爆了，那么周围的气球只能是第 i-1 个，和第 j+1 个了，所以得分应为 
                // nums[i-1] * nums[k] * nums[j+1]，分析到这里，状态转移方程应该已经跃然纸上了吧，如下所示：
                DP[left][right] = std::max(DP[left][right], nums[left-1] * nums[right+1] * nums[k] + DP[left][k-1] + DP[k+1][right]);
            }
        }
    }
    return DP[1][n];
}


bool LC::_0139_WordBreak::wordBreak(std::string s, std::vector<std::string>& wordDict) {
    std::unordered_set<std::string> wd(begin(wordDict), end(wordDict));
    std::vector<bool> DP(s.size() + 1, false);
    DP[0] = true; // empty string definitely can be divided, it means whether the substr s[0, i) can be divided
    for(int len = 0; len < DP.size(); ++len) {
        for(int j = 0; j < len; ++j) {
            if(DP[j] && wd.count(s.substr(j, len - j))) {
                DP[len] = true;
                break;
            }
        }
    }
    return DP.back();
}

int LC::_0322_CoinChange::coinChangeDP(std::vector<int>& coins, int amount) {
    std::vector<int> DP(amount + 1, INT_MAX);
    DP[0] = 0;
    for(int c : coins) {
        if(c <= amount) {
            DP[c] = 1;
        }
    }
    for(int m = 1; m <= amount; ++m) {
        for(int c : coins) {
            if(m >= c) {
                DP[m] = std::min(DP[m], DP[m-c] == INT_MAX ? INT_MAX : DP[m-c] + 1);
            }
        }
    }
    return DP[amount] == INT_MAX ? -1 : DP[amount];
}

int LC::_0322_CoinChange::coinChange(std::vector<int>& coins, int amount) {
    std::sort(coins.rbegin(), coins.rend());
    int ans = INT_MAX;
    coinChange(coins, 0, amount, 0,  ans);
    return ans == INT_MAX ? -1 : ans;
}
void LC::_0322_CoinChange::coinChange(const std::vector<int>& coins, int s, int amount, int count, int& ans) {
    const int coin = coins[s];
    
    if(s == coins.size() - 1) {
        if(amount % coin == 0) {
            ans = std::min(ans, count + amount / coin);
        }
    } else {
        for(int k = amount / coin; k >= 0 && k + count < ans; --k) {
            coinChange(coins, s+1, amount - k * coin, count + k, ans);
        }
    }
}

int LC::_0343_IntegerBreak::intergerBreak(int n) {
    if(n == 1) {
        return 0;
    } 
    if(n == 2) {
        return 1;
    }
    std::vector<int> DP(n+1, 0);
    
    DP[0] = 0;
    DP[1] = 0;
    DP[2] = 1;
    for(int i = 3; i <= n; ++i) {
        int maxV = INT_MIN;
        for(int j = 1; j < i; ++j) {
            int v = std::max(DP[j], j) * std::max(DP[i-j], i-j);
            if(v > maxV) {
                maxV = v;
            }
        }
        DP[i] = maxV;
    }
    return DP[n];
}


std::vector<std::string> LC::_0472_ConcatenatedWords::findAllConcatenatedWordsInADict(std::vector<std::string>& words) {
    if(words.size() < 2) {
        return {};
    }

    std::vector<std::string> res;
    std::unordered_set<std::string> dict(begin(words), end(words));

    for(std::string word : words) {
        dict.erase(word);
        if(word.size() == 0) {
            continue;
        }

        std::vector<bool> DP(word.size() + 1, false);
        DP[0] = true;
        for(int l = 0; l < DP.size(); ++l) {
            for(int j = 0; j < l; ++j) {
                if(DP[j] && dict.count(word.substr(j, l - j))) {
                    DP[l] = true;
                    break;
                }
            }
        }
        if(DP.back()) {
            res.push_back(word);
        }
        dict.insert(word);
    }
    return res;
}

int LC::_0646_MaximumLengthOfPairChain::findLongestChain(std::vector<std::vector<int>>& pairs) {
    std::sort(begin(pairs), end(pairs), [](std::vector<int> a, std::vector<int> b) {
        return (a[0] < b[0]) || (a[0] == b[0] && a[1] < b[1]);
    });
    
    std::vector<int> DP(pairs.size(), 1);
    for(int i = 1; i < DP.size(); ++i) {
        for(int k = i-1; k >= 0; --k) {
            if(pairs[i][0] > pairs[k][1]) {
                DP[i] = std::max(DP[i], DP[k] + 1);
            }
        }
    }
    return *std::max_element(begin(DP), end(DP));
}


// 完全抄答案的，Huahua的解法
// NOTE: This is a NP problem, any polynomial-time algorithm is incorrect otherwise P = NP.
// dp[m] := whether state m is reachable, where m is the bitmask of courses studied.
// For each semester, we enumerate all possible states from 0 to 2^n – 1, if that state is 
// reachable, then we choose c (c <= k) courses from n and check whether we can study those 
// courses.
// If we can study those courses, we have a new reachable state, we set dp[m | courses] = true.
// Time complexity: O(n*2^n*2^n) = O(n*n^4) <– This will be much smaller in practice.
// and can be reduced to O(n*3^n).
// Space complexity: O(2^n)
// Helper function: __builtin_popcount(int) function is used to count the number of one’s(set bits) in an integer.
static int numberOfCourses(int mask) {
    return __builtin_popcount(mask);
}
int LC::_1494_ParallelCoursesII::minNumberOfSemesters(int n, std::vector<std::vector<int>>& dependencies, int k) {
    const int S = 1 << n; // 各门课是否已经被上过用0-1表示，那么就有S中组合。 S每个位表示某门课是否已经上过
    std::vector<int> deps(n); // n 个元素，每个元素表示这门课 i 的dependency mask for course i.
    for(const auto& d : dependencies) {
        deps[d[1] - 1] |= 1 << (d[0] - 1); // 第d[1]门课的先决条件为 以d[0]编码的一个数字。
    }

    std::vector<int> dp(S); // 一共有S种状态, dp[s] 表示这个 s 的各个位如果是1，则这门课上过，否则没上过，那么dp[s]表示s这样一种上课组合能否到达.
    dp[0] = 1; // 什么课都不上是最初的状态，肯定是可达的
    for(int d = 1; d <= n; ++d) { // 最多d个学期能把所有课上完
        std::vector<int> tmp(S); // 一个新学期起始状态
        for(int s = 0; s < S; ++s) { // 把所有状态都试一遍
            if(!dp[s]) {
                continue; // 如果这个状态不可达，则跳过
            }
            int mask = 0;
            for(int i = 0; i < n; ++i) { // 开始选课
                if(
                    !(s & (1 << n)) &&  // 这门课不在可达状态中，即还没上过
                    (s & deps[i]) == deps[i] //这门课的所有先决课程已经上完了
                ) {
                    mask |= (1 << i); // 选这门课
                }
            }

            // Prunning, take all.
            if(numberOfCourses(mask) <= k) { // 选的课数量少于规定的量
                tmp[s | mask] = 1; // 所有课都上
            } else { // 选择的课程多于k个
                //只能上其中的子集
                // try all subsets
                for(int c = mask; c ; c = (c - 1) & mask) {
                    if(numberOfCourses(c) <= k) {
                        tmp[s | c] = 1;
                    }
                }
            }
            if(tmp.back()) { // 表示最后所有状态为tmp[0b111111] = 1, 即所有的课都上完了.
                return d; 
            }
        }
        dp.swap(tmp);
    }
    return -1;
}