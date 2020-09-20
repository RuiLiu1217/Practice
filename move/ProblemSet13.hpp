#ifndef PROBLEM_SET13_HPP
#define PROBLEM_SET13_HPP

#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>

#include "Tree.hpp"
#include "LinkList.hpp"

namespace LeetCode {
/*
You are given a square board of characters. You can move on the board starting 
at the bottom right square marked with the character 'S'.
You need to reach the top left square marked with the character 'E'. The rest 
of the squares are labeled either with a numeric character 1, 2, ..., 9 or with 
an obstacle 'X'. In one move you can go up, left or up-left (diagonally) only if 
there is no obstacle there.
Return a list of two integers: the first integer is the maximum sum of numeric 
characters you can collect, and the second is the number of such paths that you
 can take to get that maximum sum, taken modulo 10^9 + 7.
In case there is no path, return [0, 0].

Input: board = ["E23","2X2","12S"]
Output: [7,1]

Input: board = ["E12","1X1","21S"]
Output: [4,2]

Input: board = ["E11","XXX","11S"]
Output: [0,0]
 
Constraints:

2 <= board.length == board[i].length <= 100
*/
class _1301_NumberOfPathsWithMaxScore {
public:
    std::vector<int> pathsWithMaxScore(std::vector<std::string>& bd);
};

class _1302_DeepestLeavesSum {
public:
    int deepestLeavesSum(TreeNode<int>* root);
};

/*
Given an integer n, return any array containing n unique integers such that they add up to 0.

Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].

Input: n = 3
Output: [-1,0,1]

Input: n = 1
Output: [0]

Constraints:
1 <= n <= 1000
*/
class _1304_FindNUniqueIntegersSumupToZero {
public:
    std::vector<int> sumZero(int n);
};

/*
Given two binary search trees root1 and root2.
Return a list containing all the integers from both trees sorted in ascending order.

Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]

Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
Output: [-10,0,0,1,2,5,7,10]

Input: root1 = [], root2 = [5,1,7,0,2]
Output: [0,1,2,5,7]

Input: root1 = [0,-10,10], root2 = []
Output: [-10,0,10]

Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]

Constraints:
Each tree has at most 5000 nodes.
Each node's value is between [-10^5, 10^5].
*/
class _1305_AllElementsInTwoBinarySearchTrees {
public:
    std::vector<int> getAllElements(TreeNode<int>* root1, TreeNode<int>* root2);
};

/*
Given a string s formed by digits ('0' - '9') and '#' . We want to map s to English 
lowercase characters as follows:

Characters ('a' to 'i') are represented by ('1' to '9') respectively.
Characters ('j' to 'z') are represented by ('10#' to '26#') respectively. 
Return the string formed after mapping.
It's guaranteed that a unique mapping will always exist.

Input: s = "10#11#12"
Output: "jkab"
Explanation: "j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".

Input: s = "1326#"
Output: "acz"

Input: s = "25#"
Output: "y"

Input: s = "12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#"
Output: "abcdefghijklmnopqrstuvwxyz"

Constraints:
1 <= s.length <= 1000
s[i] only contains digits letters ('0'-'9') and '#' letter.
s will be valid string such that mapping is always possible.
*/
class _1309_DecryptStringFromAlphabetToIngeterMapping {
public:
    std::string freqAlphabets(std::string s);
};

/*
Given the array arr of positive integers and the array queries where 
queries[i] = [Li, Ri], for each query i compute the XOR of elements 
from Li to Ri (that is, arr[Li] xor arr[Li+1] xor ... xor arr[Ri] ). 
Return an array containing the result for the given queries.

Input: arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
Output: [2,7,14,8] 
Explanation: 
The binary representation of the elements in the array are:
1 = 0001 
3 = 0011 
4 = 0100 
8 = 1000 
The XOR values for queries are:
[0,1] = 1 xor 3 = 2 
[1,2] = 3 xor 4 = 7 
[0,3] = 1 xor 3 xor 4 xor 8 = 14 
[3,3] = 8
Example 2:

Input: arr = [4,8,2,10], queries = [[2,3],[1,3],[0,0],[0,3]]
Output: [8,0,4,4]
*/
class _1310_XORQueriesOfASubarray {
public:
    std::vector<int> xorQueries(std::vector<int>& arr, std::vector<std::vector<int>>& queries);
};
 
/*
We are given a list nums of integers representing a list compressed with run-length 
encoding. Consider each adjacent pair of elements [a, b] = [nums[2*i], nums[2*i+1]] 
(with i >= 0). For each such pair, there are a elements with value b in the 
decompressed list.
Return the decompressed list.

Input: nums = [1,2,3,4]
Output: [2,4,4,4]
Explanation: The first pair [1,2] means we have freq = 1 and val = 2 so we generate the array [2].
The second pair [3,4] means we have freq = 3 and val = 4 so we generate [4,4,4].
At the end the concatenation [2] + [4,4,4,4] is [2,4,4,4].

Constraints:

2 <= nums.length <= 100
nums.length % 2 == 0
1 <= nums[i] <= 100
*/
class _1313_DecompressRunLengthEncodedList { 
public:
    std::vector<int> decompressRLElist(std::vector<int>& nums);
};

/*
Given a m * n matrix mat and an integer K, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for i - K <= r <= i + K, j - K <= c <= j + K, and (r, c) is a valid position in the matrix.

Example 1:
Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 1
Output: [[12,21,16],[27,45,33],[24,39,28]]

Example 2:
Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 2
Output: [[45,45,45],[45,45,45],[45,45,45]]

Constraints:
m == mat.length
n == mat[i].length
1 <= m, n, K <= 100
1 <= mat[i][j] <= 100
*/
class _1314_MatrixBlockSum {
public:
    std::vector<std::vector<int>> matrixBlockSum(std::vector<std::vector<int>>& mat, int K);
};

/*
Given a binary tree, return the sum of values of nodes with even-valued grandparent. 
(A grandparent of a node is the parent of its parent, if it exists.)
If there are no nodes with an even-valued grandparent, return 0.

Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 18
Explanation: The red nodes are the nodes with even-value grandparent while the blue 
nodes are the even-value grandparents. 

Constraints:

The number of nodes in the tree is between 1 and 10^4.
The value of nodes is between 1 and 100.
*/
class _1315_SumOfNodesWithEvenvaluedGrandparent {
public:
    int sumEvenGrandparent(TreeNode<int>* root);
};

/*
Given an integer n. No-Zero integer is a positive integer 
which doesn't contain any 0 in its decimal representation.
Return a list of two integers [A, B] where:

A and B are No-Zero integers.
A + B = n
It's guarateed that there is at least one valid solution. 
If there are many valid solutions you can return any of them.

Input: n = 2            Output: [1,1]
Explanation: A = 1, B = 1. A + B = n and both A and B don't 
contain any 0 in their decimal representation.

Input: n = 11           Output: [2,9]
Input: n = 10000        Output: [1,9999]
Input: n = 69           Output: [1,68]
Input: n = 1010         Output: [11,999]

Constraints:

2 <= n <= 10^4
*/
class _1317_ConvertIntegerToTheSumOfTwoNonZeroIntegers {
public:
    std::vector<int> getNoZeroIntegers(int n);
};


/*
Given a positive integer num consisting only of digits 6 and 9.
Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).

Input: num = 9669
Output: 9969
Explanation: 
Changing the first digit results in 6669.
Changing the second digit results in 9969.
Changing the third digit results in 9699.
Changing the fourth digit results in 9666. 
The maximum number is 9969.

Input: num = 9996
Output: 9999
Explanation: Changing the last digit 6 to 9 results in the maximum number.

Input: num = 9999
Output: 9999
Explanation: It is better not to apply any change. 

Constraints:

1 <= num <= 10^4
num's digits are 6 or 9.
*/
class _1323_Maximum69Number {
public:
    int maximum69Number(int num);
};

/*
Given a string s. Return all the words vertically in the same order in which they appear in s.
Words are returned as a list of strings, complete with spaces when is necessary. (Trailing spaces are not allowed).
Each word would be put on only one column and that in one column there will be only one word.


Input: s = "HOW ARE YOU"
Output: ["HAY","ORO","WEU"]
Explanation: Each word is printed vertically. 
 "HAY"
 "ORO"
 "WEU"

Input: s = "TO BE OR NOT TO BE"
Output: ["TBONTB","OEROOE","   T"]
Explanation: Trailing spaces is not allowed. 
"TBONTB"
"OEROOE"
"   T"

Input: s = "CONTEST IS COMING"
Output: ["CIC","OSO","N M","T I","E N","S G","T"]

Constraints:

1 <= s.length <= 200
s contains only upper case English letters.
It's guaranteed that there is only one space between 2 words.
*/
class _1324_PrintWordsVertically {
public:
    std::vector<std::string> printVertically(std::string s);
};

/*
Given a m * n matrix mat of integers, sort it diagonally in 
ascending order from the top-left to the bottom-right then 
return the sorted array.

Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]

Constraints:
m == mat.length
n == mat[i].length
1 <= m, n <= 100
1 <= mat[i][j] <= 100
*/
class _1329_SortTheMatrixDiagonally {
public:
    std::vector<std::vector<int>> diagonalSort(std::vector<std::vector<int>>& mat);
};


/*
1337. The K Weakest Rows in a Matrix
User Accepted:3626
User Tried:3781
Total Accepted:3727
Total Submissions:5595
Difficulty:Easy
Given a m * n matrix mat of ones (representing soldiers) and zeros (representing civilians), return the indexes of the k weakest rows in the matrix ordered from the weakest to the strongest.

A row i is weaker than row j, if the number of soldiers in row i is less than the number of soldiers in row j, or they have the same number of soldiers but i is less than j. Soldiers are always stand in the frontier of a row, that is, always ones may appear first and then zeros.

 

Example 1:

Input: mat = 
[[1,1,0,0,0],
 [1,1,1,1,0],
 [1,0,0,0,0],
 [1,1,0,0,0],
 [1,1,1,1,1]], 
k = 3
Output: [2,0,3]
Explanation: 
The number of soldiers for each row is: 
row 0 -> 2 
row 1 -> 4 
row 2 -> 1 
row 3 -> 2 
row 4 -> 5 
Rows ordered from the weakest to the strongest are [2,0,3,1,4]
Example 2:

Input: mat = 
[[1,0,0,0],
 [1,1,1,1],
 [1,0,0,0],
 [1,0,0,0]], 
k = 2
Output: [0,2]
Explanation: 
The number of soldiers for each row is: 
row 0 -> 1 
row 1 -> 4 
row 2 -> 1 
row 3 -> 1 
Rows ordered from the weakest to the strongest are [0,2,3,1]
 

Constraints:

m == mat.length
n == mat[i].length
2 <= n, m <= 100
1 <= k <= m
matrix[i][j] is either 0 or 1.

struct comp {
  bool operator()(std::pair<int, int> const & p1, std::pair<int, int> const & p2) {
      return p1.first > p2.first || (p1.first == p2.first && p1.second > p2.second);
  }
};
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int,int>>, comp> pq;
        for(int i = 0; i < mat.size(); ++i) {
            pq.push({std::accumulate(begin(mat[i]), end(mat[i]), 0), i});
        }
        
        std::vector<int> res;
        int t = 0;
        while (t < k) {
            res.push_back(pq.top().second);
            pq.pop();
            ++t;
        }
        return res;
    }
};


1338. Reduce Array Size to The Half
User Accepted:3238
User Tried:3451
Total Accepted:3301
Total Submissions:5000
Difficulty:Medium
Given an array arr.  You can choose a set of integers and remove all the occurrences of these integers in the array.

Return the minimum size of the set so that at least half of the integers of the array are removed.

 

Example 1:

Input: arr = [3,3,3,3,5,5,5,2,2,7]
Output: 2
Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] which has size 5 (i.e equal to half of the size of the old array).
Possible sets of size 2 are {3,5},{3,2},{5,2}.
Choosing set {2,7} is not possible as it will make the new array [3,3,3,3,5,5,5] which has size greater than half of the size of the old array.
Example 2:

Input: arr = [7,7,7,7,7,7]
Output: 1
Explanation: The only possible set you can choose is {7}. This will make the new array empty.
Example 3:

Input: arr = [1,9]
Output: 1
Example 4:

Input: arr = [1000,1000,3,7]
Output: 1
Example 5:

Input: arr = [1,2,3,4,5,6,7,8,9,10]
Output: 5
 

Constraints:

1 <= arr.length <= 10^5
arr.length is even.
1 <= arr[i] <= 10^5

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        const int N = arr.size();
        std::unordered_map<int, int> map;
        for(int i = 0; i < arr.size(); ++i) {
            ++map[arr[i]];
        }
        std::vector<std::pair<int,int>> statistic;
        for(auto& m : map) {
            statistic.push_back(m);
        }
        std::sort(begin(statistic), end(statistic), [](auto& a, auto& b){
            return (a.second > b.second);
        });
        int removeNum = 0;
        int accumuNum = 0;
        for(int i = 0; i < statistic.size(); ++i) {
            ++removeNum;
            accumuNum += statistic[i].second;
            if(accumuNum >= N / 2) {
                break;
            }
        }
        return removeNum;
    }
};
*/

/*
Given a binary tree root. Split the binary tree into two subtrees by removing 1 
edge such that the product of the sums of the subtrees are maximized.
Since the answer may be too large, return it modulo 10^9 + 7.

Input: root = [1,2,3,4,5,6]
Output: 110
Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)

Input: root = [1,null,2,3,4,null,null,5,6]
Output: 90
Explanation:  Remove the red edge and get 2 binary trees with sum 15 and 6.Their product is 90 (15*6)

Input: root = [2,3,9,10,7,8,6,5,4,11,1]
Output: 1025

Input: root = [1,1]
Output: 1

Constraints:

Each tree has at most 50000 nodes and at least 2 nodes.
Each node's value is between [1, 10000].
*/
class _1339_MaximumProductOfSplittedBinaryTree {
private:
    std::unordered_map<TreeNode<int>*, int> map;
public:
    int maxProduct(TreeNode<int>* root);
    int subSum(TreeNode<int>* root);
};



/*
Given two numbers, hour and minutes. Return the smaller angle 
(in sexagesimal units) formed between the hour and the minute 
hand.
Input: hour = 12, minutes = 30
Output: 165

Input: hour = 3, minutes = 30
Output: 75

Input: hour = 3, minutes = 15
Output: 7.5

Input: hour = 4, minutes = 50
Output: 155

Input: hour = 12, minutes = 0
Output: 0

Constraints:
1 <= hour <= 12
0 <= minutes <= 59
Answers within 10^-5 of the actual value will be accepted as correct.
*/
class _1344_AngleBetweenHandsOfAClock {
public:
    double angleClock(int hour, int minute);
};


/*
Given an integer array arr. You have to sort the integers in the array
in ascending order by the number of 1's in their binary representation
and in case of two or more integers have the same number of 1's you 
have to sort them in ascending order.

Return the sorted array.

Example 1:
Input: arr = [0,1,2,3,4,5,6,7,8]
Output: [0,1,2,4,8,3,5,6,7]
Explantion: [0] is the only integer with 0 bits.
[1,2,4,8] all have 1 bit.
[3,5,6] have 2 bits.
[7] has 3 bits.
The sorted array by bits is [0,1,2,4,8,3,5,6,7]

Example 2:
Input: arr = [1024,512,256,128,64,32,16,8,4,2,1]
Output: [1,2,4,8,16,32,64,128,256,512,1024]
Explantion: All integers have 1 bit in the binary representation, 
you should just sort them in ascending order.

Example 3:
Input: arr = [10000,10000]
Output: [10000,10000]

Example 4:
Input: arr = [2,3,5,7,11,13,17,19]
Output: [2,3,5,17,7,11,13,19]

Example 5:
Input: arr = [10,100,1000,10000]
Output: [10,100,10000,1000]
 
Constraints:

1 <= arr.length <= 500
0 <= arr[i] <= 10^4
*/
class _1356_SortIntegersByTheNumberOf1Bits {
public: 
    std::vector<int> sortByBits(std::vector<int>& arr);
};

/*
Given a string s consisting only of characters a, b and c.
Return the number of substrings containing at least one 
occurrence of all these characters a, b and c.

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one 
occurrence of the characters a, b and c are "abc", "abca", 
"abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" 
and "abc" (again). 

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one 
occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 

Input: s = "abc"
Output: 1

Constraints:

3 <= s.length <= 5 x 10^4
s only consists of a, b or c characters.
*/
class _1358_NumberOfSubstringsContainingAllThreeCharacters {
private:
    int count[3];
    bool contains3() {
        return count[0] >= 1 && count[1] >= 1 && count[2] >= 1;
    }
public:
    int numberOfSubstrings(std::string s);
};

/*
Given n orders, each order consist in pickup and delivery services. 
Count all valid pickup/delivery possible sequences such that 
delivery(i) is always after of pickup(i). 

Since the answer may be too large, return it modulo 10^9 + 7.

Input: n = 1
Output: 1
Explanation: Unique order (P1, D1), Delivery 1 always is after of Pickup 1.

Input: n = 2
Output: 6
Explanation: All possible orders: 
(P1,P2,D1,D2), (P1,P2,D2,D1), (P1,D1,P2,D2), (P2,P1,D1,D2), (P2,P1,D2,D1) and (P2,D2,P1,D1).
This is an invalid order (P1,D2,P2,D1) because Pickup 2 is after of Delivery 2.
Example 3:

Input: n = 3
Output: 90

1 <= n <= 500
*/
class _1359_CountAllValidPickupAndDeliveryOptions {
public:
    int countOrders(int n );
};


/*
Given a string s. You should re-order the string using the following algorithm:

Pick the smallest character from s and append it to the result.
Pick the smallest character from s which is greater than the last appended character to the result and append it.
Repeat step 2 until you cannot pick more characters.
Pick the largest character from s and append it to the result.
Pick the largest character from s which is smaller than the last appended character to the result and append it.
Repeat step 5 until you cannot pick more characters.
Repeat the steps from 1 to 6 until you pick all characters from s.
In each step, If the smallest or the largest character appears more than once you can choose any occurrence and append it to the result.

Return the result string after sorting s with this algorithm.

Input: s = "aaaabbbbcccc"
Output: "abccbaabccba"
Explanation: After steps 1, 2 and 3 of the first iteration, result = "abc"
After steps 4, 5 and 6 of the first iteration, result = "abccba"
First iteration is done. Now s = "aabbcc" and we go back to step 1
After steps 1, 2 and 3 of the second iteration, result = "abccbaabc"
After steps 4, 5 and 6 of the second iteration, result = "abccbaabccba"
Example 2:

Input: s = "rat"
Output: "art"
Explanation: The word "rat" becomes "art" after re-ordering it with the mentioned algorithm.

Input: s = "leetcode"
Output: "cdelotee"

Input: s = "ggggggg"
Output: "ggggggg"

Input: s = "spo"
Output: "ops"
 

Constraints:

1 <= s.length <= 500
s contains only lower-case English letters.
*/
class _1370_IncreasingDecreasingString {
public:
    std::string sortString(std::string s);
};

/*
Given two binary trees original and cloned and given a reference to a node 
target in the original tree.
The cloned tree is a copy of the original tree. Return a reference to the 
same node in the cloned tree. Note that you are not allowed to change any 
of the two trees or the target node and the answer must be a reference to 
a node in the cloned tree.
Follow up: Solve the problem if repeated values on the tree are allowed.

Input: tree = [7,4,3,null,null,6,19], target = 3
Output: 3
Explanation: In all examples the original and cloned trees are shown. The target node is a green node from the original tree. The answer is the yellow node from the cloned tree.

Input: tree = [7], target =  7
Output: 7

Input: tree = [8,null,6,null,5,null,4,null,3,null,2,null,1], target = 4
Output: 4

Input: tree = [1,2,3,4,5,6,7,8,9,10], target = 5
Output: 5

Input: tree = [1,2,null,3], target = 2
Output: 2

Constraints:

The number of nodes in the tree is in the range [1, 10^4].
The values of the nodes of the tree are unique.
target node is a node from the original tree and is not null.
*/
class _1379_FindACorrespondingNodeOfABinaryTreeInACloneOfThatTree {
public:
    TreeNode<int>* getTargetCopy(TreeNode<int>* original, TreeNode<int>* cloned, TreeNode<int>* target);
};

/*
Given a binary search tree, return a balanced binary search tree with 
the same node values.
A binary search tree is balanced if and only if the depth of the two 
subtrees of every node never differ by more than 1.
If there is more than one answer, return any of them.


Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, 
[3,1,4,null,2,null,null] is also correct.

Constraints:

The number of nodes in the tree is between 1 and 10^4.
The tree nodes will have distinct values between 1 and 10^5.
*/
class _1382_BalanceABinarySearchTree {
public:
    TreeNode<int>* balanceBST(TreeNode<int>* root);
private:
    TreeNode<int>* createBST(const std::vector<int>& arr, int start, int end);
    std::vector<int> inOrderTraverse(TreeNode<int>* root);
};

/*
Given a string s and an integer k. You should construct k non-empty palindrome strings using all the characters in s.
Return True if you can use all the characters in s to construct k palindrome strings or False otherwise.


Input: s = "annabelle", k = 2
Output: true
Explanation: You can construct two palindromes using all characters in s.
Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"

Input: s = "leetcode", k = 3
Output: false
Explanation: It is impossible to construct 3 palindromes using all the characters of s.

Input: s = "true", k = 4
Output: true
Explanation: The only possible solution is to put each character in a separate string.

Input: s = "yzyzyzyzyzyzyzy", k = 2
Output: true
Explanation: Simply you can put all z's in one string and all y's in the other string. Both strings will be palindrome.

Input: s = "cr", k = 7
Output: false
Explanation: We don't have enough characters in s to construct 7 palindromes.
 

Constraints:

1 <= s.length <= 10^5
All characters in s are lower-case English letters.
1 <= k <= 10^5
*/
class _1400_ConstructKPalindromeStrings {
public:
    // Two conditions:
    // 1. the number of odd times characters must be <= k
    // 2. the total length of the string must >= k;
    bool canConstruct(std::string s, int k); 
};


}

#endif
