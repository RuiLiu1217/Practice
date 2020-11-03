#ifndef LEETCODE_DFS_HPP
#define LEETCODE_DFS_HPP
#include "LeetCode_TreeProblems.hpp"
#include <unordered_map>
#include <unordered_set>
namespace LC {
/*
    Tag: DFS
    Todo
    Given a binary tree containing digits from 0-9 only, each root-to-leaf path 
    could represent a number. An example is the root-to-leaf path 1->2->3 which 
    represents the number 123. Find the total sum of all root-to-leaf numbers.
    Note: A leaf is a node with no children.

    Example:

    Input: [1,2,3]
        1
       / \
      2   3
    Output: 25
    Explanation:
    The root-to-leaf path 1->2 represents the number 12.
    The root-to-leaf path 1->3 represents the number 13.
    Therefore, sum = 12 + 13 = 25.
    Example 2:

    Input: [4,9,0,5,1]
        4
       / \
      9   0
     / \
    5   1
    Output: 1026
    Explanation:
    The root-to-leaf path 4->9->5 represents the number 495.
    The root-to-leaf path 4->9->1 represents the number 491.
    The root-to-leaf path 4->0 represents the number 40.
    Therefore, sum = 495 + 491 + 40 = 1026. */
class _0129_SumRootToLeafNumbers {
private:
    void DFS(TreeNode* root, int carryValue);
    int sum;
public:
    _0129_SumRootToLeafNumbers() : sum(0) {}
    int sumNumbers(TreeNode* root);
};

/*
Tag: palindrome, string, Dynamic programming, DFS
TODO:
Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s.

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]
*/
class _0131_PalindromePartitioning {
public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        std::vector<std::string> tmp;
        std::vector<std::vector<std::string>> res;
        partition(s, 0, s.size(), tmp, res);
        return res;
    }
private:
    void partition(std::string& s, int start, int end,std::vector<std::string>& tmp, std::vector<std::vector<std::string>>& res) {
        if(start == end) {
            res.push_back(tmp);
            return;
        }
        
        for(int len = 1; len <= end - start; ++len) {
            std::string subS = s.substr(start, len);
            if(isPalindrome(s, start, start + len - 1)) {
                tmp.push_back(s.substr(start, len));
                partition(s, start + len, end, tmp, res);
                tmp.pop_back();
            }
        }
    }
    bool isPalindrome(std::string& s, int start, int end) {
        while(start < end) {
            if(s[start] != s[end]) {
                return false;
            }
            ++start;
            --end;
        }
        return true;
    }
};

/*
Tag: string, palindrome, dynamic programming
TODO:

Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.

Example:

Input: "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/
class _0132_PalindromePartitioningII {
public:
    int minCut(std::string s) {
        const int n = s.length(); 
        std::vector<std::vector<int>> isPalindrome(n, std::vector<int>(n, 1)); // isPalindrome[i][j]  s[i~j] is a palindrome
        for(int l = 2; l <= n; ++l) { // substring length
            for(int i = 0, j = i + l - 1; j < n; ++i, ++j) {
                isPalindrome[i][j] = s[i] == s[j] && isPalindrome[i+1][j-1];
            }
        }

        std::vector<int> DP(n, n); // DP[i] the minimum cuts from s[0] to s[i]

        for(int i = 0; i < n; ++i) {
            if(isPalindrome[0][i]) {
                DP[i] = 0; // no need to cut
                continue;
            }

            for(int j = 0; j < i; ++j) {
                if(isPalindrome[j+1][i]) { // cut from j which is between 0 to i
                    DP[i] = std::min(DP[i], DP[j] + 1);
                }
            }
        }
        return DP[n - 1];
    }
};

/*
Numbers can be regarded as product of its factors. For example,

8 = 2 x 2 x 2;
  = 2 x 4.
Write a function that takes an integer n and return all possible combinations of its factors.

Note:

You may assume that n is always positive.
Factors should be greater than 1 and less than n.
Example 1:

Input: 1
Output: []
Example 2:

Input: 37
Output:[]
Example 3:

Input: 12
Output:
[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]
Example 4:

Input: 32
Output:
[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]
*/
class _0254_FactorCombinations {
public:
    // Copy from the solution
    std::vector<std::vector<int>> getFactors(int n);
private:
    void DFS(std::vector<std::vector<int>>& res, std::vector<int>& tmp, int n);
};


/*
Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge is a 
pair of nodes), write a function to check whether these edges make up a valid tree.

Input: n = 5, and edges = [[0,1], [0,2], [0,3], [1,4]]
Output: true

Input: n = 5, and edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
Output: false
Note: you can assume that no duplicate edges will appear in edges. Since all edges 
are undirected, [0,1] is the same as [1,0] and thus will not appear together in edges.
*/
class _0261_GraphValidTree {
public:
    bool validTree(int n, std::vector<std::vector<int>>& edges);
    bool DFS(std::vector<std::unordered_set<int>>& graph, std::vector<int>& visited, int source, int target);
    //! Try to rewrite it using Union-Find
};


/*
Given a string that contains only digits 0-9 and a target value, return all possibilities to 
add binary operators (not unary) +, -, or * between the digits so they evaluate to the target 
value.

Input: num = "123", target = 6
Output: ["1+2+3", "1*2*3"] 

Input: num = "232", target = 8
Output: ["2*3+2", "2+3*2"]

Input: num = "105", target = 5
Output: ["1*0+5","10-5"]

Input: num = "00", target = 0
Output: ["0+0", "0-0", "0*0"]

Input: num = "3456237490", target = 9191
Output: []
*/
class _0282_ExpressionAddOperators {
public:
    std::vector<std::string> addOperators(std::string num, int target);
private:
    void DFS(const std::string& num, const int target, int pos, std::string exp, long prev, long curr, std::vector<std::string>& ans);
};

    
/*
Remove the minimum number of invalid parentheses in order to make the input string valid. 
Return all possible results. Note: The input string may contain letters other than the 
parentheses ( and ).

Input: "()())()"
Output: ["()()()", "(())()"]

Input: "(a)())()"
Output: ["(a)()()", "(a())()"]

Input: ")("
Output: [""]
*/
class _0301_RemoveInvalidParentheses {
public:
    std::vector<std::string> removeInvalidParentheses(const std::string& parentheses) {
        auto [l, r] = numOfParenthesesToBeRemoved(parentheses);
        std::vector<std::string> res;
        DFS(parentheses, 0, l, r, res);
        return res;
    }
private:
    std::pair<int, int> numOfParenthesesToBeRemoved(const std::string& s) {
        int l = 0;
        int r = 0;
        for(char c : s) {
            if(c == '(') {
                ++l;
            } else if(c == ')') {
                if(l == 0) {
                    ++r;
                } else {
                    --l;
                }
            }
        }
        return std::pair<int, int>(l, r);
    }
    bool isValid(const std::string& s) {
        int count = 0;
        for(char c : s) {
            if(c == '(') {
                ++count;
            } else if(c == ')') {
                --count;
            }
            if(count < 0) {
                return false;
            }
        }
        return count == 0;
    }
    void DFS(std::string s, int start, int l, int r, std::vector<std::string>& ans) {
        if(l < 0 || r < 0) {return;}
        if(l == 0 && r == 0 && isValid(s)) {
            ans.push_back(s);
            return;
        }

        for(int i = start; i < s.size(); ++i) {
            if(i != start && s[i-1] == s[i]) {
                continue;
            }
            if(s[i] == '(' || s[i] == ')') {
                std::string curr = s;
                curr.erase(i, 1);
                if(s[i] == '(') {
                    DFS(curr, i, l-1, r, ans);
                } else {
                    DFS(curr, i, l, r-1, ans);
                }
            }
        }
    }
};

/*
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) 
connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
Count the number of distinct islands. An island is considered to be the same as another if and only if one island 
can be translated (and not rotated or reflected) to equal the other.

Example 1:
11000
11000
00011
00011
Given the above grid map, return 1.
Example 2:
11011
10000
00001
11011
Given the above grid map, return 3.

Notice that:
11
1
and
 1
11
are considered different island shapes, because we do not consider reflection / rotation.
Note: The length of each dimension in the given grid does not exceed 50.
*/
class _0694_NumberOfDistinceIslands {
private:
int M;
int N;
void DFS(std::vector<std::vector<int>>& grid, std::string& path, int i, int j, const int I, const int J);
public:
    int numDistinctIslands(std::vector<std::vector<int>>& grid);
};

/*
Tag: DFS,
Google

We can rotate digits by 180 degrees to form new digits. 
When 0, 1, 6, 8, 9 are rotated 180 degrees, they become 
0, 1, 9, 8, 6 respectively. When 2, 3, 4, 5 and 7 are 
rotated 180 degrees, they become invalid.
A confusing number is a number that when rotated 180 degrees 
becomes a different number with each digit valid.(Note that 
the rotated number can be greater than the original number.)

Given a positive integer N, return the number of confusing 
numbers between 1 and N inclusive.

Input: 20
Output: 6
Explanation: 
The confusing numbers are [6,9,10,16,18,19].
6 converts to 9.
9 converts to 6.
10 converts to 01 which is just 1.
16 converts to 91.
18 converts to 81.
19 converts to 61.

Input: 100
Output: 19
Explanation: 
! Notice that 100, 80 are both confused, the problem defines "rotate digits by 180 degrees", not "rotate the whole number by 180 degrees"
The confusing numbers are [6,9,10,16,18,19,60,61,66,68,80,81,86,89,90,91,98,99,100]. 
 
Note:
1 <= N <= 10^9
! Copy from the Solution
*/
class _1088_ConfusingNumberII {
private:
    int count = 0;
    const std::vector<int> mp = {0, 1, 2, 3, 4, 5, 9, 7, 8, 6};
public:
    int confusingNumberII(int N) {
        count = 0;
        for(int x : {1, 6, 8, 9}) { // ! 0 cannot be the start of the number.
            DFS(x, N);
        }
        return count;
    }

    void DFS(long long n, int N) {
        if(n > N) {
            return;
        }
        if(isConfusing(n)) {
            ++count;
        }
        for(int x : {0, 1, 6, 8, 9}) {
            DFS(n * 10 + x, N); //! DFS based on number = number * 10 + last digit, this is also the way to generate all numbers given the digit set.
        }
    }
    bool isConfusing(int x) {
        int arr[10];
        int i = 0;
        while(x) {
            arr[i++] = x % 10;
            x /= 10;
        }
        for(int l = 0, r = i - 1; l <= r; ++l, --r) {
            if(arr[l] != mp[arr[r]]) {
                return true;
            }
        }
        return false;
    }
};

}
#endif