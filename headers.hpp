#ifndef HEADERS_HPP
#define HEADERS_HPP
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include "Tree.hpp"
#include "LinkList.hpp"

#include "ProblemSet1.hpp" // Problem 1 - 100
#include "ProblemSet2.hpp" // Problem 101 - 200
#include "ProblemSet3.hpp" // Problem 201 - 300
#include "ProblemSet4.hpp" // Problem 301 - 400
#include "ProblemSet5.hpp" // Problem 401 - 500
#include "ProblemSet6.hpp" // Problem 501 - 600
#include "ProblemSet7.hpp" // Problem 601 - 700
#include "ProblemSet8.hpp" // Problem 701 - 800
#include "ProblemSet9.hpp" // Problem 801 - 900
#include "ProblemSet10.hpp" // Problem 901 - 1000
#include "ProblemSet11.hpp" // Problem 1001 - 1100

namespace LeetCode
{




/* 1103. distribute candies to people:
We distribute some number of candies, to a row of n = num_people 
people in the following way:
We then give 1 candy to the first person, 2 candies to the second 
person, and so on until we give n candies to the last person.Then, 
we go back to the start of the row, giving n + 1 candies to the 
first person, n + 2 candies to the second person, and so on until 
we give 2 * n candies to the last person.
This process repeats (with us giving one more candy each time, and 
moving to the start of the row after we reach the end) until we run 
out of candies. The last person will receive all of our remaining 
candies (not necessarily one more than the previous gift).
Return an array (of length num_people and sum candies) that represents 
the final distribution of candies. 

Example 1:

Input: candies = 7, num_people = 4
Output: [1,2,3,1]
Explanation:
On the first turn, ans[0] += 1, and the array is [1,0,0,0].
On the second turn, ans[1] += 2, and the array is [1,2,0,0].
On the third turn, ans[2] += 3, and the array is [1,2,3,0].
On the fourth turn, ans[3] += 1 (because there is only one candy left), and the final array is [1,2,3,1].
Example 2:

Input: candies = 10, num_people = 3
Output: [5,2,3]
Explanation: 
On the first turn, ans[0] += 1, and the array is [1,0,0].
On the second turn, ans[1] += 2, and the array is [1,2,0].
On the third turn, ans[2] += 3, and the array is [1,2,3].
On the fourth turn, ans[0] += 4, and the final array is [5,2,3].
*/
class _1103_DistributeCandiesToPeople {
public:
    std::vector<int> distributeCandies(int candies, int num_people);
};

/*
In an infinite binary tree where every node has two children, the nodes are 
labelled in row order.
In the odd numbered rows (ie., the first, third, fifth,...), the labelling 
is left to right, while in the even numbered rows (second, fourth, sixth,...), 
the labelling is right to left.

Given the label of a node in this tree, return the labels in the path from 
the root of the tree to the node with that label.

Input: label = 14
Output: [1,3,4,14]

Input: label = 26
Output: [1,2,6,10,26]
*/
class _1104_PathInZigzagLabelledBinaryTree {
public:
    std::vector<int> pathInZigZagTree(int label);
};

/*
We have a sequence of books: the i-th book has thickness books[i][0] 
and height books[i][1]. 
We want to place these books in order onto bookcase shelves that have 
total width shelf_width.
We choose some of the books to place on this shelf (such that the sum 
of their thickness is <= shelf_width), then build another level of 
shelf of the bookcase so that the total height of the bookcase has 
increased by the maximum height of the books we just put down. We repeat 
this process until there are no more books to place.

Note again that at each step of the above process, the order of the 
books we place is the same order as the given sequence of books. 
For example, if we have an ordered list of 5 books, we might place the 
first and second book onto the first shelf, the third book on the second 
shelf, and the fourth and fifth book on the last shelf.

Return the minimum possible height that the total bookshelf can be after 
placing shelves in this manner.

Input: books = [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]], shelf_width = 4
Output: 6
Explanation:
The sum of the heights of the 3 shelves are 1 + 3 + 2 = 6.
Notice that book number 2 does not have to be on the first shelf.

Constraints:
1 <= books.length <= 1000
1 <= books[i][0] <= shelf_width <= 1000
1 <= books[i][1] <= 1000
*/
class _1105_FillingBookcaseShelves {
public:
    int minHeightShelves(std::vector<std::vector<int>>& books, int shelf_width);
};


/*
Return the result of evaluating a given boolean expression, represented as a string.

An expression can either be:

"t", evaluating to True;
"f", evaluating to False;
"!(expr)", evaluating to the logical NOT of the inner expression expr;
"&(expr1,expr2,...)", evaluating to the logical AND of 2 or more inner expressions expr1, expr2, ...;
"|(expr1,expr2,...)", evaluating to the logical OR of 2 or more inner expressions expr1, expr2, ...
 

Example 1:

Input: expression = "!(f)"
Output: true
Example 2:

Input: expression = "|(f,t)"
Output: true
Example 3:

Input: expression = "&(t,f)"
Output: false
Example 4:

Input: expression = "|(&(t,f,t),!(t))"
Output: false
 

Constraints:

1 <= expression.length <= 20000
expression[i] consists of characters in {'(', ')', '&', '|', '!', 't', 'f', ','}.
expression is a valid expression representing a boolean, as given in the description.
*/
class _1106_ParsingABolleanExpression {
public:
    bool parseBoolExpr(std::string expression);
};


/*
Given a valid (IPv4) IP address, return a defanged version of that IP address.
A defanged IP address replaces every period "." with "[.]".

Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"

Input: address = "255.100.50.0"
Output: "255[.]100[.]50[.]0"

Constraints: The given address is a valid IPv4 address.
*/
class _1108_DefangingAnIPAddress {
public:
    std::string defangIPaddr(std::string address); 
};

/*
  Given the root of a binary tree, each node in the tree has a distinct value.
  After deleting all nodes with a value in to_delete, we are left with a forest 
  (a disjoint union of trees). 
  Return the roots of the trees in the remaining forest. You may return the 
  result in any order.

  Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
  Output: [[1,2,null,4],[6],[7]]

Constraints:

    The number of nodes in the given tree is at most 1000.
    Each node has a distinct value between 1 and 1000.
    to_delete.length <= 1000
    to_delete contains distinct values between 1 and 1000.
*/
class _1110_DeleteNodesAndReturnForest {
    // Copy from a solution
private:
    std::vector<TreeNode<int>*> result;
    std::unordered_set<int> toDeleteSet;
public:
    std::vector<TreeNode<int>*> delNodes(TreeNode<int>* root, std::vector<int>& to_delete);
    TreeNode<int>* helper(TreeNode<int>* node, std::vector<TreeNode<int>*>& result,
                    std::unordered_set<int>& toDeleteSet, bool isRoot);
};


/*
A string is a valid parentheses string (denoted VPS) if and only if it consists of "(" and ")" 
characters only, and:

It is the empty string, or
It can be written as AB (A concatenated with B), where A and B are VPS's, or
It can be written as (A), where A is a VPS.
We can similarly define the nesting depth depth(S) of any VPS S as follows:

depth("") = 0
depth(A + B) = max(depth(A), depth(B)), where A and B are VPS's
depth("(" + A + ")") = 1 + depth(A), where A is a VPS.
For example,  "", "()()", and "()(()())" are VPS's (with nesting depths 0, 1, and 2), and ")(" and "(()" are not VPS's.

Given a VPS seq, split it into two disjoint subsequences A and B, such that A and B are VPS's 
(and A.length + B.length = seq.length).
Now choose any such A and B such that max(depth(A), depth(B)) is the minimum possible value.
Return an answer array (of length seq.length) that encodes such a choice of A and B: 
answer[i] = 0 if seq[i] is part of A, else answer[i] = 1. 
Note that even though multiple answers may exist, you may return any of them.

Input: seq = "(()())"
Output: [0,1,1,1,1,0]

Input: seq = "()(())()"
Output: [0,0,0,1,1,0,1,1]

Constraints:

1 <= seq.size <= 10000
*/
class _1111_MaximumNestingDepthOfTwoValidParenthesesStrings {
public:
    std::vector<int> maxDepthAfterSplit(std::string seq);
};

/*
Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all 
elements in arr2 are also in arr1.
Sort the elements of arr1 such that the relative ordering of items in arr1 are 
the same as in arr2.  Elements that don't appear in arr2 should be placed at 
the end of arr1 in ascending order.

Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]
 
Constraints:

arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
Each arr2[i] is distinct.
Each arr2[i] is in arr1.
*/
class _1122_RelativeSortArray {
public:
    std::vector<int> relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2);
};

/*
In a project, you have a list of required skills req_skills, and a list of people.
The i-th person people[i] contains a list of skills that person has.
Consider a sufficient team: a set of people such that for every required skill in 
req_skills, there is at least one person in the team who has that skill. 
We can represent these teams by the index of each person: for example, 
team = [0, 1, 3] represents the people with skills people[0], people[1], and people[3].

Return any sufficient team of the smallest possible size, represented by the index of each person.
You may return the answer in any order.  It is guaranteed an answer exists.

Example 1:
Input: req_skills = ["java","nodejs","reactjs"], people = [["java"],["nodejs"],["nodejs","reactjs"]]
Output: [0,2]

Example 2:
Input: req_skills = ["algorithms","math","java","reactjs","csharp","aws"], 
people = [["algorithms","math","java"],["algorithms","math","reactjs"],["java","csharp","aws"],
["reactjs","csharp"],["csharp","math"],["aws","java"]]
Output: [1,2]
 
Constraints:

1 <= req_skills.length <= 16
1 <= people.length <= 60
1 <= people[i].length, req_skills[i].length, people[i][j].length <= 16
Elements of req_skills and people[i] are (respectively) distinct.
req_skills[i][j], people[i][j][k] are lowercase English letters.
Every skill in people[i] is a skill in req_skills.
It is guaranteed a sufficient team exists.
*/
class _1125_SmallestSufficientTeam {
public:
    std::vector<int> smallestSufficientTeam(
        std::vector<std::string>& req_skills, 
        std::vector<std::vector<std::string>>& people);
};

/*
Given two arrays of integers with equal lengths, return the 
maximum value of:

|arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|
where the maximum is taken over all 0 <= i, j < arr1.length. 

Input: arr1 = [1,2,3,4], arr2 = [-1,4,5,6]           :   Output: 13
Input: arr1 = [1,-2,-5,0,10], arr2 = [0,-2,-1,-7,-4] :   Output: 20

Constraints:
2 <= arr1.length == arr2.length <= 40000
-10^6 <= arr1[i], arr2[i] <= 10^6
*/
class _1131_MaximumOfAbsoluteValueExpression {
public:
    int maxAbsValExpr(std::vector<int>& arr1, std::vector<int>& arr2);
};


/*
Two players play a turn based game on a binary tree.  We are given the root
of this binary tree, and the number of nodes n in the tree. n is odd, and 
each node has a distinct value from 1 to n.
Initially, the first player names a value x with 1 <= x <= n, and the second 
player names a value y with 1 <= y <= n and y != x. The first player colors 
the node with value x red, and the second player colors the node with value 
y blue.
Then, the players take turns starting with the first player. In each turn, 
that player chooses a node of their color (red if player 1, blue if player 2) 
and colors an uncolored neighbor of the chosen node (either the left child,
 right child, or parent of the chosen node.)
If (and only if) a player cannot choose such a node in this way, they must 
pass their turn. If both players pass their turn, the game ends, and the 
winner is the player that colored more nodes.

You are the second player.  If it is possible to choose such a y to ensure 
you win the game, return true.  If it is not possible, return false.
这道题赢的条件是谁拿到更多的节点而不是节点的和。当时看到这个题有点懵，以为是算节点
的和。
*/
class _1145_BinaryTreeColoringGame {
public:
    bool btreeGameWinningMove(TreeNode<int>* root, int n, int x);
private:
    int l_;
    int r_;
    int nodes(TreeNode<int>* root, int x);
};

/*
Implement a SnapshotArray that supports the following interface:
SnapshotArray(int length) initializes an array-like data structure with the 
given length.  Initially, each element equals 0.

void set(index, val) sets the element at the given index to be equal to val.
int snap() takes a snapshot of the array and returns the snap_id: the total number of times we called snap() minus 1.
int get(index, snap_id) returns the value at the given index, at the time we took the snapshot with the given snap_id

Input: ["SnapshotArray","set","snap","set","get"]
[[3],[0,5],[],[0,6],[0,0]]
Output: [null,null,0,null,5]
Explanation: 
SnapshotArray snapshotArr = new SnapshotArray(3); // set the length to be 3
snapshotArr.set(0,5);  // Set array[0] = 5
snapshotArr.snap();  // Take a snapshot, return snap_id = 0
snapshotArr.set(0,6);
snapshotArr.get(0,0);  // Get the value of array[0] with snap_id = 0, return 5

Constraints:
1 <= length <= 50000
At most 50000 calls will be made to set, snap, and get.
0 <= index < length
0 <= snap_id < (the total number of times we call snap())
0 <= val <= 10^9
*/
class _1146_SnapshotArray {
private:
    std::vector<std::map<int, int>> A;
    int snap_id = 0;
public:
    _1146_SnapshotArray(int length);
    void set(int index, int val);
    int snap();
    int get(int index, int snaid);
};

/*
Given a string date representing a Gregorian calendar date formatted as YYYY-MM-DD, return the day number of the year.

Input: date = "2019-01-09"
Output: 9
Explanation: Given date is the 9th day of the year in 2019.

Input: date = "2019-02-10"
Output: 41

Input: date = "2003-03-01"
Output: 60

Input: date = "2004-03-01"
Output: 61

Constraints:
date.length == 10
date[4] == date[7] == '-', and all other date[i]'s are digits
date represents a calendar date between Jan 1st, 1900 and Dec 31, 2019.
*/
class _1154_DayOfTheYear {
public:
    int dayOfYear(std::string dt) {
        int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        int y = stoi(dt.substr(0, 4)), m = stoi(dt.substr(5, 2)), d = stoi(dt.substr(8));
        if (m > 2 && y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) ++d; 
        while (--m > 0) d += days[m - 1];
        return d;
    }    
};


/*
You are given an array of strings words and a string chars.
A string is good if it can be formed by characters from chars 
(each character can only be used once).
Return the sum of lengths of all good strings in words.

Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation: 
The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.

Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
Output: 10
Explanation: 
The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.

Note:

1 <= words.length <= 1000
1 <= words[i].length, chars.length <= 100
All strings contain lowercase English letters only.
*/
class _1160_FindWordsThatCanBeFormedByCharacters {
public:
    int countCharacters(std::vector<std::string>& words, std::string chars);
};

/*
Given the root of a binary tree, the level of its root is 1, the 
level of its children is 2, and so on.
Return the smallest level X such that the sum of all the values 
of nodes at level X is maximal.

Input: [1,7,0,7,-8,null,null]
Output: 2
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.
Note:

The number of nodes in the given tree is between 1 and 10^4.
-10^5 <= node.val <= 10^5
*/
class _1161_MaximumLevelSumOfABinaryTree {
public:
    int maxLevelSum(TreeNode<int>* root);
};

/*
Let's define a function f(s) over a non-empty string s, which calculates the frequency 
of the smallest character in s. For example, if s = "dcce" then f(s) = 2 because the 
smallest character is "c" and its frequency is 2.
Now, given string arrays queries and words, return an integer array answer, where each 
answer[i] is the number of words such that f(queries[i]) < f(W), where W is a word in words. 

Input: queries = ["cbd"], words = ["zaaaz"]      :      Output: [1]
Explanation: On the first query we have f("cbd") = 1, f("zaaaz") = 3 so f("cbd") < f("zaaaz").

Input: queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]   :   Output: [1,2]
Explanation: On the first query only f("bbb") < f("aaaa"). On the second query both f("aaa") and f("aaaa") are both > f("cc").

Constraints:

1 <= queries.length <= 2000
1 <= words.length <= 2000
1 <= queries[i].length, words[i].length <= 10
queries[i][j], words[i][j] are English lowercase letters.
*/
class _1170_CompareStringByFrequencyOfTheSmallestCharacter {
public:
    std::vector<int> numSmallerByFrequency(std::vector<std::string>& queries, std::vector<std::string>& words);
    
};



/*
Return the number of permutations of 1 to n so that prime numbers are at prime 
indices (1-indexed.) (Recall that an integer is prime if and only if it is greater 
than 1, and cannot be written as a product of two positive integers both smaller than it.)
Since the answer may be large, return the answer modulo 10^9 + 7.

Input: n = 5             :              Output: 12
Explanation: For example [1,2,5,4,3] is a valid permutation, but [5,2,3,4,1] is not because the prime number 5 is at index 1.

Input: n = 100           :              Output: 682289015
*/
class _1175_PrimeArrangements {
public:
    constexpr static auto MOD = static_cast<int>(1e9+7); // Use C++11 constexpr
    int numPrimeArrangements(int n, int primes, long long ans);
private:
    bool isPrime(int n);
};


/*
 1186 Maximum Subarray Sum With One Deletion
Given an array of integers, return the maximum sum for a non-empty subarray (contiguous elements) 
with at most one element deletion. In other words, you want to choose a subarray and optionally 
delete one element from it so that there is still at least one element left and the sum of the 
remaining elements is maximum possible.

Note that the subarray needs to be non-empty after deleting one element.

Input: arr = [1,-2,0,3]
Output: 4
Explanation: Because we can choose [1, -2, 0, 3] and drop -2, thus the subarray [1, 0, 3] becomes the maximum value.

Input: arr = [1,-2,-2,3]
Output: 3
Explanation: We just choose [3] and it's the maximum sum.

Input: arr = [-1,-1,-1,-1]
Output: -1
Explanation: The final subarray needs to be non-empty. You can't choose [-1] and delete -1 from it, 
then get an empty subarray to make the sum equals to 0. 

Constraints:

    1 <= arr.length <= 10^5
    -10^4 <= arr[i] <= 10^4

 */
class _1186_MaximumSubarraySumWithOneDeletion {
  public:
    int maximumSum(std::vector<int>& arr);
    
};




/*
Given a string text, you want to use the characters of text to form as many instances 
of the word "balloon" as possible.
You can use each character in text at most once. Return the maximum number of instances 
that can be formed.

Input: text = "nlaebolko"              :             Output: 1
Input: text = "loonbalxballpoon"       :             Output: 2
Input: text = "leetcode"               :             Output: 0
*/
class _1189_MaximumNumberOfBalloons {
public:
    int maxNumberOfBalloons(std::string text);
    bool updateBallon(std::vector<int>& map);
};

/*
You are given a string s that consists of lower case English letters and brackets. 
Reverse the strings in each pair of matching parentheses, starting from the innermost 
one. Your result should not contain any brackets.

Input: s = "(abcd)"                    :         Output: "dcba"
Input: s = "(u(love)i)"                :         Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.

Input: s = "(ed(et(oc))el)"            :         Output: "leetcode"
Input: s = "a(bcdefghijkl(mno)p)q"     :         Output: "apmnolkjihgfedcbq"

Constraints:
0 <= s.length <= 2000
s only contains lower case English characters and parentheses.
It's guaranteed that all parentheses are balanced.
*/
class _1190_ReverseSubstringsBetweenEachPairOfParentheses {
public:
    std::string reverseParentheses(std::string s);
};


/*
Given an array of distinct integers arr, find all pairs of elements with the minimum 
absolute difference of any two elements. 
Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] 
follows
a, b are from arr
a < b
b - a equals to the minimum absolute difference of any two elements in arr

Input: arr = [4,2,1,3]
Output: [[1,2],[2,3],[3,4]]
Explanation: The minimum absolute difference is 1. 
List all pairs with difference equal to 1 in ascending order.

Input: arr = [1,3,6,10,15]
Output: [[1,3]]

Input: arr = [3,8,-10,23,19,-4,-14,27]
Output: [[-14,-10],[19,23],[23,27]]

Constraints:

2 <= arr.length <= 10^5
-10^6 <= arr[i] <= 10^6
*/
class _1200_MinimumAbsoluteDifference {
public:
    std::vector<std::vector<int>> minimumAbsDifference(std::vector<int>& arr);
};

/*
Write a program to find the n-th ugly number.
Ugly numbers are positive integers which are divisible by a or b or c.

Input: n = 3, a = 2, b = 3, c = 5
Output: 4
Explanation: The ugly numbers are 2, 3, 4, 5, 6, 8, 9, 10... The 3rd is 4.
Example 2:

Input: n = 4, a = 2, b = 3, c = 4
Output: 6
Explanation: The ugly numbers are 2, 3, 4, 6, 8, 9, 10, 12... The 4th is 6.
Example 3:

Input: n = 5, a = 2, b = 11, c = 13
Output: 10
Explanation: The ugly numbers are 2, 4, 6, 8, 10, 11, 12, 13... The 5th is 10.
Example 4:

Input: n = 1000000000, a = 2, b = 217983653, c = 336916467
Output: 1999999984

Constraints:
1 <= n, a, b, c <= 10^9
1 <= a * b * c <= 10^18
It's guaranteed that the result will be in range [1, 2 * 10^9]
*/
class _1201_UglyNumberIII {
public:
    // it looks like a DP problem, but actually it is a Binary Search Problem
    // Calculate how many numbers from 1 to num are divisble by either a, b or c
    // using the formula:
    // num / a + num / b + num / c - num / lcm(ab) - num / lcm(bc) - num / lcm(ac) + num / lcm(abc)
    int nthUglyNumber(int n, int a, int b, int c);
private:
    long long gcb(long long a, long long b);
    long long lcm(long long a, long long b);
    int count(long long num, long long a, long long b, long long c);
};

/*
You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = 
[a, b] indicates 2 indices(0-indexed) of the string. You can swap the characters at any pair of 
indices in the given pairs any number of times.
Return the lexicographically smallest string that s can be changed to after using the swaps.

Input: s = "dcab", pairs = [[0,3],[1,2]]
Output: "bacd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[1] and s[2], s = "bacd"

Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
Output: "abcd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[0] and s[2], s = "acbd"
Swap s[1] and s[2], s = "abcd"

Input: s = "cba", pairs = [[0,1],[1,2]]
Output: "abc"
Explaination: 
Swap s[0] and s[1], s = "bca"
Swap s[1] and s[2], s = "bac"
Swap s[0] and s[1], s = "abc"
 

1 <= s.length <= 10^5
0 <= pairs.length <= 10^5
0 <= pairs[i][0], pairs[i][1] < s.length
s only contains lower case English letters.
*/
class _1202_SmallestStringWithSwaps {
public:
    std::string smallestStringWithSwaps(std::string s, std::vector<std::vector<int>>& pairs);
};

/*
Given an array of integers arr, write a function that returns true if and only if the 
number of occurrences of each value in the array is unique.

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the 
same number of occurrences.

Example 2:

Input: arr = [1,2]
Output: false
Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
*/
class _1207_UniqueNumberOfOccurances {
public:
    bool uniqueOccurrences(std::vector<int>& arr);
};


/*
Hint: 祖玛
Given a string s, a k duplicate removal consists of choosing k adjacent and 
equal letters from s and removing them causing the left and the right side 
of the deleted substring to concatenate together.
We repeatedly make k duplicate removals on s until we no longer can.
Return the final string after all such duplicate removals have been made.
It is guaranteed that the answer is unique.

Input: s = "abcd", k = 2                  :                Output: "abcd"
Input: s = "deeedbbcccbdaa", k = 3        :                Output: "aa"
Input: s = "pbbcggttciiippooaais", k = 2  :                Output: "ps"

Constraints:

1 <= s.length <= 10^5
2 <= k <= 10^4
s only contains lower case English letters.
*/
class _1209_RemoveAllAdjacentDuplicatesInStringII {
public:
    std::string removeDuplicates(std::string s, int k);
};


/*
Given an integer array arr and an integer difference, return the length of the 
longest subsequence in arr which is an arithmetic sequence such that the 
difference between adjacent elements in the subsequence equals difference.

Example 1:
Input: arr = [1,2,3,4], difference = 1
Output: 4
Explanation: The longest arithmetic subsequence is [1,2,3,4].

Example 2:
Input: arr = [1,3,5,7], difference = 1
Output: 1
Explanation: The longest arithmetic subsequence is any single element.

Example 3:
Input: arr = [1,5,7,8,5,3,4,2,1], difference = -2
Output: 4
Explanation: The longest arithmetic subsequence is [7,5,3,1].
 
Constraints:

1 <= arr.length <= 10^5
-10^4 <= arr[i], difference <= 10^4
*/
class _1218_LongestArithmeticSubsequenceOfGivenDifference {
public:
    int longestSubsequence(std::vector<int>& arr, int difference);
};

/*
Split a String in Balanced Strings
Balanced strings are those who have equal quantity of 'L' and 'R' characters.
Given a balanced string s split it in the maximum amount of balanced strings.
Return the maximum amount of splitted balanced strings.

Input: s = "RLRRLLRLRL"
Output: 4
Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.

Input: s = "RLLLLRRRLR"
Output: 3
Explanation: s can be split into "RL", "LLLRRR", "LR", each substring contains same number of 'L' and 'R'.

Input: s = "LLLLRRRR"
Output: 1
Explanation: s can be split into "LLLLRRRR".

Input: s = "RLRRRLLRLL"
Output: 2
Explanation: s can be split into "RL", "RRRLLRLL", since each substring contains an equal number of 'L' and 'R'

Constraints:
1 <= s.length <= 1000
s[i] = 'L' or 'R'
*/
class _1221_SplitAStringInBalancedStrings {
public:
    int balancedStringSplit(std::string s);
};


/*
On an 8x8 chessboard, there can be multiple Black Queens and one White King.
Given an array of integer coordinates queens that represents the positions of the 
Black Queens, and a pair of coordinates king that represent the position of the 
White King, return the coordinates of all the queens (in any order) that can 
attack the King.


Input: queens = [[0,1],[1,0],[4,0],[0,4],[3,3],[2,4]], king = [0,0]
Output: [[0,1],[1,0],[3,3]]
Explanation:  
The queen at [0,1] can attack the king cause they're in the same row. 
The queen at [1,0] can attack the king cause they're in the same column. 
The queen at [3,3] can attack the king cause they're in the same diagnal. 
The queen at [0,4] can't attack the king cause it's blocked by the queen at [0,1]. 
The queen at [4,0] can't attack the king cause it's blocked by the queen at [1,0]. 
The queen at [2,4] can't attack the king cause it's not in the same row/column/diagnal as the king.

Input: queens = [[0,0],[1,1],[2,2],[3,4],[3,5],[4,4],[4,5]], king = [3,3]
Output: [[2,2],[3,4],[4,4]]

Input: queens = [[5,6],[7,7],[2,1],[0,7],[1,6],[5,1],[3,7],[0,3],[4,0],[1,2],[6,3],[5,0],
[0,4],[2,2],[1,1],[6,4],[5,4],[0,0],[2,6],[4,5],[5,2],[1,4],[7,5],[2,3],[0,5],[4,2],[1,0],
[2,7],[0,1],[4,6],[6,1],[0,6],[4,3],[1,7]], king = [3,4]
Output: [[2,3],[1,4],[1,6],[3,7],[4,3],[5,4],[4,5]]
 

Constraints:

1 <= queens.length <= 63
queens[0].length == 2
0 <= queens[i][j] < 8
king.length == 2
0 <= king[0], king[1] < 8
At most one piece is allowed in a cell.
*/
class _1222_QueensThatCanAttackTheKing {
public:
    std::vector<std::vector<int>> queensAttackTheKing(std::vector<std::vector<int>>& queens, std::vector<int>& king);
};

/*
n passengers board an airplane with exactly n seats. The first passenger has 
lost the ticket and picks a seat randomly. But after that, the rest of 
passengers will:

Take their own seat if it is still available, 
Pick other seats randomly when they find their seat occupied 
What is the probability that the n-th person can get his own seat?

Input: n = 1                   :             Output: 1.00000
Input: n = 2                   ：            Output: 0.50000
Explanation: The second person has a probability of 0.5 to get the second 
seat (when first person gets the first seat).
*/
class _1227_AirplaneSeatAssignmentProbability {
    public:
        double nthPersionGetsNthSeat(int n);

};

/*
Given a function  f(x, y) and a value z, return all positive integer pairs x and y where f(x,y) == z.
The function is constantly increasing, i.e.:
f(x, y) < f(x + 1, y)
f(x, y) < f(x, y + 1)
The function interface is defined like this:
interface CustomFunction {
public:
  // Returns positive integer f(x, y) for any given positive integer x and y.
  int f(int x, int y);
};
For custom testing purposes you're given an integer function_id and a target z as input, where 
function_id represent one function from an secret internal list, on the examples you'll know only two 
functions from the list.

You may return the solutions in any order.

Input: function_id = 1, z = 5
Output: [[1,4],[2,3],[3,2],[4,1]]
Explanation: function_id = 1 means that f(x, y) = x + y

Input: function_id = 2, z = 5
Output: [[1,5],[5,1]]
Explanation: function_id = 2 means that f(x, y) = x * y

Constraints:

1 <= function_id <= 9
1 <= z <= 100
It's guaranteed that the solutions of f(x, y) == z will be on the range 1 <= x, y <= 1000
It's also guaranteed that f(x, y) will fit in 32 bit signed integer if 1 <= x, y <= 1000
*/
class _1237_FindPositiveIntegerSolutionForAGivenEquation {
public:
    class CustomFunction;
    std::vector<std::vector<int>> findSolution(CustomFunction& customfunction, int z);
};

/*
1238. Circular Permutation in Binary Representation 
Given 2 integers n and start. Your task is return any permutation p of (0,1,2.....,2^n -1) such that :
    p[0] = start
    p[i] and p[i+1] differ by only one bit in their binary representation.
    p[0] and p[2^n -1] must also differ by only one bit in their binary representation.

Input: n = 2, start = 3
Output: [3,2,0,1]
Explanation: The binary representation of the permutation is (11,10,00,01). 
All the adjacent element differ by one bit. Another valid permutation is [3,1,0,2]

Input: n = 3, start = 2
Output: [2,6,7,5,4,0,1,3]
Explanation: The binary representation of the permutation is (010,110,111,101,100,000,001,011).

Constraints:

    1 <= n <= 16
    0 <= start < 2 ^ n
*/
class _1238_CicularPermutationInBinaryRepresentation {
  public:
    std::vector<int> circularPermutation(int n, int start);
  private:
    std::vector<int> grayVector(int n);
};

/*
You are given two strings s1 and s2 of equal length consisting of 
letters "x" and "y" only. Your task is to make these two strings 
equal to each other. You can swap any two characters that belong 
to different strings, which means: swap s1[i] and s2[j].

Return the minimum number of swaps required to make s1 and s2 equal, 
or return -1 if it is impossible to do so.

Input: s1 = "xx", s2 = "yy"
Output: 1
Explanation: 
Swap s1[0] and s2[1], s1 = "yx", s2 = "yx".

Input: s1 = "xy", s2 = "yx"
Output: 2
Explanation: 
Swap s1[0] and s2[0], s1 = "yy", s2 = "xx".
Swap s1[0] and s2[1], s1 = "xy", s2 = "xy".
Note that you can't swap s1[0] and s1[1] to make s1 equal to "yx", cause we can only swap chars in different strings.

Input: s1 = "xx", s2 = "xy"
Output: -1

Input: s1 = "xxyyxyxyxx", s2 = "xyyxyxxxyx"
Output: 4

Constraints:

1 <= s1.length, s2.length <= 1000
s1, s2 only contain 'x' or 'y'.
*/
class _1247_MinimumSwapsToMakeStringsEqual {
public:
    int minimumSwap(std::string s1, std::string s2);
};

/*
Given n and m which are the dimensions of a matrix 
initialized by zeros and given an array indices 
where indices[i] = [ri, ci]. For each pair of [ri, ci] 
you have to increment all cells in row ri and 
column ci by 1.
Return the number of cells with odd values in the matrix 
after applying the increment to all indices. 

Input: n = 2, m = 3, indices = [[0,1],[1,1]]
Output: 6
Explanation: Initial matrix = [[0,0,0],[0,0,0]].
After applying first increment it becomes [[1,2,1],[0,1,0]].
The final matrix will be [[1,3,1],[1,3,1]] which contains 6 odd numbers.

Input: n = 2, m = 2, indices = [[1,1],[0,0]]
Output: 0
Explanation: Final matrix = [[2,2],[2,2]]. There is no odd number in the final matrix.
*/
class _1252_CellsWithOddValuesInAMatrix {
public:
    int oddCells(int n, int m, std::vector<std::vector<int>>& indices);
};


/*
1254 Number of closed islands
     Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally 
connected group of 0s and a closed island is an island totally (all left, top, right, bottom) 
surrounded by 1s.

Return the number of closed islands.

Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation: 
Islands in gray are closed because they are completely surrounded by water (group of 1s).

Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
Output: 1

Input: grid = [[1,1,1,1,1,1,1],
               [1,0,0,0,0,0,1],
               [1,0,1,1,1,0,1],
               [1,0,1,0,1,0,1],
               [1,0,1,1,1,0,1],
               [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
Output: 2

Constraints:

    1 <= grid.length, grid[0].length <= 100
    0 <= grid[i][j] <=1
*/
class _1254_NumberOfClosedIslands {
    int M;
    int N;
    int count;
  public:
    int closedIsland(std::vector<std::vector<int>>& grid);
    void DFS(std::vector<std::vector<int>>& grid, int I, int J, bool& touchEdge);
};

/*
Given a list of words, list of  single letters (might be repeating) and score of every 
character. Return the maximum score of any valid set of words formed by using the given 
letters (words[i] cannot be used two or more times).

It is not necessary to use all characters in letters and each letter can only be used 
once. Score of letters 'a', 'b', 'c', ... ,'z' is given by 
score[0], score[1], ... , score[25] respectively.

Input: 
words = ["dog","cat","dad","good"], 
letters = ["a","a","c","d","d","d","g","o","o"], 
score = [1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0]
Output: 23
Explanation:
Score  a=1, c=9, d=5, g=3, o=2
Given letters, we can form the words "dad" (5+1+5) and "good" (3+2+2+5) with a score of 23.
Words "dad" and "dog" only get a score of 21.

Example 2:
Input: 
words = ["xxxz","ax","bx","cx"], 
letters = ["z","a","b","c","x","x","x"], 
score = [4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10]
Output: 27
Explanation:
Score  a=4, b=4, c=4, x=5, z=10
Given letters, we can form the words "ax" (4+5), "bx" (4+5) and "cx" (4+5) with a score of 27.
Word "xxxz" only get a score of 25.

Example 3:
Input: 
words = ["leetcode"], 
letters = ["l","e","t","c","o","d"], 
score = [0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0]
Output: 0
Explanation:
Letter "e" can only be used once.
 
Constraints:
1 <= words.length <= 14
1 <= words[i].length <= 15
1 <= letters.length <= 100
letters[i].length == 1
score.length == 26
0 <= score[i] <= 10
words[i], letters[i] contains only lower case English letters.
*/
class _1255_MaximumScoreWordsFormedByLetters {
private:
    int maxScore = 0;
public:
    int maxScoreWords(std::vector<std::string>& words, std::vector<char>& letters, std::vector<int>& score);
private:
    int getWordScore(const std::vector<int>& word, const std::vector<int>& score);    
    bool canCreateAWord(const std::vector<int>& letterMap, const std::vector<int>& word);    
    void createAWord(std::vector<int>& letterMap, const std::vector<int>& word);    
    void removeAWord(std::vector<int>& letterMap, const std::vector<int>& word);    
    bool noMoreWordsCanGenerated(const std::vector<std::vector<int>>& words,int startIdx, const std::vector<int>& letterMap);
    void scoreWords(std::vector<std::vector<int>>& words, int startIdx, std::vector<int>& letterMap,
                   std::vector<int>& score, int& myScore);
};

/*
Given a 2D grid of size m x n and an integer k. You need to shift the grid k times.
In one shift operation:
    Element at grid[i][j] becomes at grid[i][j + 1].
    Element at grid[i][n - 1] becomes at grid[i + 1][0].
    Element at grid[n - 1][n - 1] becomes at grid[0][0].
Return the 2D grid after applying shift operation k times.

Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
Output: [[9,1,2],[3,4,5],[6,7,8]]

Input: grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
Output: [[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]

Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 9
Output: [[1,2,3],[4,5,6],[7,8,9]]

Constraints:

m == grid.length
n == grid[i].length
1 <= m <= 50
1 <= n <= 50
-1000 <= grid[i][j] <= 1000
0 <= k <= 100
*/
class _1260_Shift2DGrid {
public:
    std::vector<std::vector<int>> shiftGrid(std::vector<std::vector<int>>& grid, int K);        
};

/*
Given a binary tree with the following rules:
root.val == 0
If treeNode.val == x and treeNode.left != null, 
then treeNode.left.val == 2 * x + 1
If treeNode.val == x and treeNode.right != null, 
then treeNode.right.val == 2 * x + 2

Now the binary tree is contaminated, which means all 
treeNode.val have been changed to -1.

You need to first recover the binary tree and then 
implement the FindElements class:

FindElements(TreeNode* root) Initializes the object 
with a contamined binary tree, you need to recover it 
first.
bool find(int target) Return if the target value 
exists in the recovered binary tree.
 
Input
["FindElements","find","find"]
[[[-1,null,-1]],[1],[2]]
Output
[null,false,true]
Explanation
FindElements findElements = new FindElements([-1,null,-1]); 
findElements.find(1); // return False 
findElements.find(2); // return True 

Example 2:
Input
["FindElements","find","find","find"]
[[[-1,-1,-1,-1,-1]],[1],[3],[5]]
Output
[null,true,true,false]
Explanation
FindElements findElements = new FindElements([-1,-1,-1,-1,-1]);
findElements.find(1); // return True
findElements.find(3); // return True
findElements.find(5); // return False


Example 3:
Input
["FindElements","find","find","find","find"]
[[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]
Output
[null,true,false,false,true]
Explanation
FindElements findElements = new FindElements([-1,null,-1,-1,null,-1]);
findElements.find(2); // return True
findElements.find(3); // return False
findElements.find(4); // return False
findElements.find(5); // return True

Constraints:

TreeNode.val == -1
The height of the binary tree is less than or equal to 20
The total number of nodes is between [1, 10^4]
Total calls of find() is between [1, 10^4]
0 <= target <= 10^6
*/
class _1261_FindElementsInAContaminatedBinaryTree {
    TreeNode<int>* rot;
    std::unordered_set<int> res;
public:
    _1261_FindElementsInAContaminatedBinaryTree(TreeNode<int>* root);
    bool find(int target);
    void recover(TreeNode<int>* root);
};

/*
On a plane there are n points with integer coordinates 
points[i] = [xi, yi]. Your task is to find the minimum 
time in seconds to visit all points.

You can move according to the next rules:
1. In one second always you can either move vertically, 
horizontally by one unit or diagonally (it means to move 
one unit vertically and one unit horizontally in 
one second).
2. You have to visit the points in the same order as 
they appear in the array. 
*/
class _1266_MinimumTimeVisitingAllPoints {
public:
    int minTimeToVisitAllPoints(std::vector<std::vector<int>>& points);
};


/*
You are given a map of a server center, represented as a m * n integer matrix grid, 
where 1 means that on that cell there is a server and 0 means that it is no server. 
Two servers are said to communicate if they are on the same row or on the same column.
Return the number of servers that communicate with any other server.

Input: grid = [[1,0],[0,1]]
Output: 0
Explanation: No servers can communicate with others.

Input: grid = [[1,0],[1,1]]
Output: 3
Explanation: All three servers can communicate with at least one other server.

Input: grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
Output: 4
Explanation: The two servers in the first row can communicate with each other. 
The two servers in the third column can communicate with each other. The server 
at right bottom corner can't communicate with any other server.
*/
class _1267_CountServersThatCommunicate {
public:
    int countServers(std::vector<std::vector<int>>& grid);
};

/*
You have a pointer at index 0 in an array of size arrLen. 
At each step, you can move 1 position to the left, 1 position 
to the right in the array or stay in the same place  
(The pointer should not be placed outside the array at any time).
Given two integers steps and arrLen, return the number of ways 
such that your pointer still at index 0 after exactly steps steps.

Since the answer may be too large, return it modulo 10^9 + 7.

Input: steps = 3, arrLen = 2
Output: 4
Explanation: There are 4 differents ways to stay at index 0 after 3 steps.
Right, Left, Stay
Stay, Right, Left
Right, Stay, Left
Stay, Stay, Stay

Input: steps = 2, arrLen = 4
Output: 2
Explanation: There are 2 differents ways to stay at index 0 after 2 steps
Right, Left
Stay, Stay

Input: steps = 4, arrLen = 2
Output: 8

Constraints:

1 <= steps <= 500
1 <= arrLen <= 10^6
*/
class _1269_NumberOfWaysToStayInTheSamePlaceAfterSomeSteps {
private:
    int MOD = (1000000000 + 7);
    void updateDP(std::vector<long long>& cur, std::vector<long long>& nex, const int N);
public:
    int numWays(int steps, int arrLen);
};

/*
Given two integers tomatoSlices and cheeseSlices. The ingredients of different burgers are as follows:
Jumbo Burger: 4 tomato slices and 1 cheese slice.
Small Burger: 2 Tomato slices and 1 cheese slice.
Return [total_jumbo, total_small] so that the number of remaining tomatoSlices equal to 0 and the 
number of remaining cheeseSlices equal to 0. If it is not possible to make the remaining tomatoSlices 
and cheeseSlices equal to 0 return [].

Input: tomatoSlices = 16, cheeseSlices = 7
Output: [1,6]
Explantion: To make one jumbo burger and 6 small burgers we need 4*1 + 2*6 = 16 tomato and 1 + 6 = 7 
cheese. There will be no remaining ingredients.

Input: tomatoSlices = 17, cheeseSlices = 4
Output: []
Explantion: There will be no way to use all ingredients to make small and jumbo burgers.

Input: tomatoSlices = 4, cheeseSlices = 17
Output: []
Explantion: Making 1 jumbo burger there will be 16 cheese remaining and making 2 small burgers there 
will be 15 cheese remaining.

Input: tomatoSlices = 0, cheeseSlices = 0
Output: [0,0]

Input: tomatoSlices = 2, cheeseSlices = 1
Output: [0,1]
*/
class _1276_NumberofBurgersWithNoWasteOfIngredients {
public:
    std::vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices);
};

/*
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.

Constraints:
1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1
*/
class _1277_CountSquareSubmatricesWithAllOnes {
public:
    int countSquares(std::vector<std::vector<int>>& matrix);
};

/*
There are n people whose IDs go from 0 to n - 1 and each person belongs exactly 
to one group. Given the array groupSizes of length n telling the group size each 
person belongs to, return the groups there are and the people's IDs each group 
includes.
You can return any solution in any order and the same applies for IDs. Also, it 
is guaranteed that there exists at least one solution. 

Input: groupSizes = [3,3,3,3,3,1,3]
Output: [[5],[0,1,2],[3,4,6]]
Explanation: 
Other possible solutions are [[2,1,6],[5],[0,4,3]] and [[5],[0,6,2],[4,3,1]].

Input: groupSizes = [2,1,3,3,3,2]
Output: [[1],[0,5],[2,3,4]]

Constraints:

groupSizes.length == n
1 <= n <= 500
1 <= groupSizes[i] <= n
*/
class _1282_GroupThePeopleGivenTheGroupSizeTheyBelongTo {
public:
    std::vector<std::vector<int>> groupThePeople(std::vector<int>& groupSizes);
};

/*
Given a m x n binary matrix mat. In one step, you can choose one cell and flip 
it and all the four neighbours of it if they exist (Flip is changing 1 to 0 and 
0 to 1). A pair of cells are called neighboors if they share one edge.
Return the minimum number of steps required to convert mat to a zero matrix or 
-1 if you cannot.
Binary matrix is a matrix with all cells equal to 0 or 1 only.
Zero matrix is a matrix with all cells equal to 0.

Input: mat = [[0,0],[0,1]]
Output: 3
Explanation: One possible solution is to flip (1, 0) then (0, 1) and finally (1, 1) as shown.

Input: mat = [[0]]
Output: 0
Explanation: Given matrix is a zero matrix. We don't need to change it.

Input: mat = [[1,1,1],[1,0,1],[0,0,0]]
Output: 6

Input: mat = [[1,0,0],[1,0,0]]
Output: -1
Explanation: Given matrix can't be a zero matrix

Constraints:

m == mat.length
n == mat[0].length
1 <= m <= 3
1 <= n <= 3
mat[i][j] is 0 or 1.
*/
class _1284_MinimumNumberOfFlipsToConvertBinaryMatrixToZeroMatrix {
private:
    int M;
    int N;

public:
    int minFlips(std::vector<std::vector<int>>& mat);
    int getInteger(std::vector<std::vector<int>>& mat);
    int oneFlip(int i, int j, int num);
};

/*
Design an Iterator class, which has:

A constructor that takes a string characters of sorted 
distinct lowercase English letters and a number 
combinationLength as arguments.

A function next() that returns the next combination of 
length combinationLength in lexicographical order.
A function hasNext() that returns True if and only if 
there exists a next combination.

CombinationIterator iterator = new CombinationIterator("abc", 2); // creates the iterator.

iterator.next(); // returns "ab"
iterator.hasNext(); // returns true
iterator.next(); // returns "ac"
iterator.hasNext(); // returns true
iterator.next(); // returns "bc"
iterator.hasNext(); // returns false

1 <= combinationLength <= characters.length <= 15
There will be at most 10^4 function calls per test.
It's guaranteed that all calls of the function next are valid.
*/
class _1286_IteratorForCombination {
private:
    std::string characters;
    int combinationLength;
    std::vector<int> combinIndex;
    bool isFirstCombination;
    int charactersLength;
public:
    _1286_IteratorForCombination(std::string cs, int cl);
    std::string next();
    bool hasNext();
};

/*
Given an integer array sorted in non-decreasing order, there is exactly one 
integer in the array that occurs more than 25% of the time.
Return that integer.

Input: arr = [1,2,2,6,6,6,6,7,10]
Output: 6

Constraints:
1 <= arr.length <= 10^4
0 <= arr[i] <= 10^5
*/
class _1287_ElementAppearingMoreThan25PercentInSortedArray {
public:
    int findSpecialInteger(std::vector<int>& arr);
};

/*
Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.
Return the decimal value of the number in the linked list.

Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
Example 2:

Input: head = [0]
Output: 0
Example 3:

Input: head = [1]
Output: 1
Example 4:

Input: head = [1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]
Output: 18880
Example 5:

Input: head = [0,0]
Output: 0
 

Constraints:

The Linked List is not empty.
Number of nodes will not exceed 30.
Each node's value is either 0 or 1.
*/
class _1290_ConvertBinaryNumberInALinkedListToInteger {
public:
    int getDecimalValue(ListNode<int>* head);
};

/*
Given an array nums of integers, return how many of them contain an even number of digits.

Input: nums = [12,345,2,6,7896]
Output: 2
Explanation: 
12 contains 2 digits (even number of digits). 
345 contains 3 digits (odd number of digits). 
2 contains 1 digit (odd number of digits). 
6 contains 1 digit (odd number of digits). 
7896 contains 4 digits (even number of digits). 
Therefore only 12 and 7896 contain an even number of digits.

Input: nums = [555,901,482,1771]
Output: 1 
Explanation: 
Only 1771 contains an even number of digits.

Constraints:
1 <= nums.length <= 500
1 <= nums[i] <= 10^5
*/
class _1295_FindNumbersWithEvenNumberOfDigits {
public:
    int findNumber(std::vector<int>& nums);
};


/*
Given an array arr, replace every element in that array with the 
greatest element among the elements to its right, and replace the 
last element with -1.

After doing so, return the array.

Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]

Constraints:
1 <= arr.length <= 10^4
1 <= arr[i] <= 10^5
*/
class _1299_ReplaceElementsWithGreatestElementOnRightSide {
public:
    std::vector<int> replaceElements(std::vector<int>& arr);
};

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

} // namespace LeetCode





















































namespace LintCode {

    /*
    Write a function that add two numbers A and B. There is no need to read data 
    from standard input stream. Both parameters are given in function aplusb, your 
    job is to calculate the sum and return it.
    
    Have you met this question in a real interview?  
    Clarification
    Are a and b both 32-bit integers? Yes.
    
    Can I use bit operation? Sure you can.
    
    Input:  a = 1, b = 2
    Output: 3	
    Explanation: return the result of a + b.
    
    Example 2:
    Input:  a = -1, b = 1
    Output: 0	
    Explanation: return the result of a + b.
    Challenge
    Of course you can just return a + b to get accepted. But Can you challenge not 
    do it like that?(You should not use + or any arithmetic operators.)
    */    
    class _0001_APlusBProblem {
        public:
            int aplusb(int a, int b);
    };

    /*
    Write an algorithm which computes the number of trailing zeros in n factorial. 
    
    Example 1:
	Input:  11         :        Output: 2	
	Explanation: 
	11! = 39916800, so the output should be 2

	Input:  5          :        Output: 1	
	Explanation: 
	5! = 120, so the output should be 1.

    Challenge   O(log N) time
    还没有理解为什么，可以用笔一点一点照着solution写出来看看
    */
    class _0002_TrailingZeros {
        public:
            long long trailingZeros(long long n);
    };

/*
Ugly number is a number that only have prime factors 2, 3 and 5.

Design an algorithm to find the nth ugly number. The first 10 ugly numbers are 1, 2, 3, 4, 5, 6, 8, 9, 10, 12...

Note that 1 is typically treated as an ugly number.

Have you met this question in a real interview?  
Example
Example 1:

Input: 9
Output: 10
Example 2:

Input: 1
Output: 1
Challenge
O(n log n) or O(n) time.
*/
class _0004_UglyNumberII {
public:
    /**
     * @param n: An integer
     * @return: return a  integer as description.
     */
    int nthUglyNumber(int n);
};

/*
Merge two given sorted ascending integer array A and B into a new sorted integer array.
Have you met this question in a real interview?  

Input:  A=[1], B=[1]        :        Output: [1,1]	
Input:  A=[1,2,3,4], B=[2,4,5,6]  :  Output: [1,2,2,3,4,4,5,6]	

How can you optimize your algorithm if one array is very large and the other is very small?
Related Problems
*/
class _0006_MergeTwoSortedArrays {
public:
    std::vector<int> mergeSortedArray(std::vector<int> &A, std::vector<int> &B);
};

/*
Description
Given a string(Given in the way of char array) and an offset, rotate the string by offset in place. (rotate from left to right).

offset >= 0
the length of str >= 0
Make changes on the original input data

Have you met this question in a real interview?  
Example

Input: str="abcdefg", offset = 3
Output: str = "efgabcd"	

Input: str="abcdefg", offset = 0
Output: str = "abcdefg"	

Input: str="abcdefg", offset = 1
Output: str = "gabcdef"	

Input: str="abcdefg", offset =2
Output: str = "fgabcde"	

Input: str="abcdefg", offset = 10
Output: str = "efgabcd"	
Explanation: Note that it is rotated in place, that is, after str is rotated, it becomes "efgabcd".
Challenge
Rotate in-place with O(1) extra memory.
*/
class _0008_RotateString {
public:
    void rotateString(std::string &str, int offset);
};


/*
Description
Given number n. Print number from 1 to n. But:

when number is divided by 3, print "fizz".
when number is divided by 5, print "buzz".
when number is divided by both 3 and 5, print "fizz buzz".
when number can't be divided by either 3 or 5, print the number itself.
Have you met this question in a real interview?
Example
If n = 15, you should return:
[
  "1", "2", "fizz",
  "4", "buzz", "fizz",
  "7", "8", "fizz",
  "buzz", "11", "fizz",
  "13", "14", "fizz buzz"
]

If n = 10, you should return:
[
  "1", "2", "fizz",
  "4", "buzz", "fizz",
  "7", "8", "fizz",
  "buzz"
]
Challenge : Can you do it with only one if statement?
*/
class _0009_FizzBuzz {
public:
    std::vector<std::string> fizzBuzz(int n);
};


    /*
    Description
    In a 2D array grid, each value grid[i][j] represents the height of a building 
    located there. We are allowed to increase the height of any number of buildings, 
    by any amount (the amounts can be different for different buildings). Height 
    0 is considered to be a building as well.
    
    At the end, the "skyline" when viewed from all four directions of the grid, i.e. 
    west, east, north, and south, must be the same as the skyline of the original 
    grid. A city's skyline is the outer contour of the rectangles formed by all the 
    buildings when viewed from a distance. See the following example.
    
    What is the maximum total sum that the height of the buildings can be increased?
    1 < grid.length = grid[0].length <= 50.
    All heights grid[i][j] are in the range [0, 100].
    All buildings in grid[i][j] occupy the entire grid cell: that is, they are a 1 x 1 x grid[i][j] rectangular prism.
    Have you met this question in a real interview?  
    
    Example
    Input: 
    [   [3,0,8,4],
        [2,4,5,7],
        [9,2,6,3],
        [0,3,1,0] ]
        
    Output: 35
    Explanation: 
        The skyline viewed from north or south is: [9, 4, 8, 7]
        The skyline viewed from west or right is: [8, 7, 9, 3]
        The grid after increasing the height of buildings without affecting skylines is:
        [ [8,4,8,7],
          [7,4,7,7],
          [9,4,8,7],
          [3,3,3,3] ]
    */
    class _1010_MaxIncreaseToKeepCitySkyline {
        public:
            int maxIncreaseKeepingSkyline(std::vector<std::vector<int>> &grid);
    };

    class _1207_UniqueNumberOfOccurances {
        public:
            bool uniqueOccurrences(std::vector<int>& arr);
    };
    
    /* Description
    You're given strings J representing the types of stones that are jewels, and S 
    representing the stones you have. Each character in S is a type of stone you have. 
    You want to know how many of the stones you have are also jewels.
    
    The letters in J are guaranteed distinct, and all characters in J and S are letters. 
    Letters are case sensitive, so "a" is considered a different type of stone from "A".
    S and J will consist of letters and have length at most 50.
    
    The characters in J are distinct.
    Example
    Example 1:
    Input: J = "aA", S = "aAAbbbb"
    
    Output: 3
    Example 2:
    Input: J = "z", S = "ZZ"
    Output: 0
    */
    class _1038_JewelsAndStones{
        public:
            int numJewelInStones(std::string& J, std::string& S);
    };

    /*
    Initially, there is a Robot at position (0, 0). Given a 
    sequence of its moves, judge if this robot makes a circle, 
    which means it moves back to the original place finally.
    The move sequence is represented by a string. And each move 
    is represent by a character. The valid robot moves are R 
    (Right), L (Left), U (Up) and D (down). The output should be 
    true or false representing whether the robot makes a circle.

    Example 1: Input: "UD"      Output: true
    Example 2: Input: "LL"      Output: false
    */
    class _1104_JudgeRouteCircle {
        public:
            bool judgeCircle(std::string& moves);
    };

    /*
    Given a non-empty binary tree, return the average value of the nodes on each level 
    in the form of an array. The range of node's value is in the range of 32-bit signed 
    integer. 
    Example
    Example 1:
    Input:
        3
       / \'
      9  20
        /  \
       15   7
    Output: [3, 14.5, 11]
    */
    class _1115_AverageOfLevelsInBinaryTree{
        public:
            std::vector<double> averageOfLevels(TreeNode<int>* root);
    };

    /*
    Given two binary trees and imagine that when you put one of them 
    to cover the other, some nodes of the two trees are overlapped 
    while the others are not.
    
    You need to merge them into a new binary tree. The merge rule is 
    that if two nodes overlap, then sum node values up as the new 
    value of the merged node. Otherwise, the NOT null node will be 
    used as the node of new tree.
    
    The merging process must start from the root nodes of both trees.
    
    Example
    Example1
    Input: 
    {1,3,2,5}
    {2,1,3,#,4,#,7}
    Output:
    {3,4,5,5,4,#,7}
    Explanation:
    	Tree 1                     Tree 2                  
                  1                         2                             
                 / \                       / \                            
                3   2                     1   3                        
               /                           \   \                     
              5                             4   7                  
    Merged tree:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7
    */

    class _1126_MergeTwoBinaryTrees{
        public:
            TreeNode<int> * mergeTrees(TreeNode<int> * t1, TreeNode<int> * t2);
    };

    /*
    Given a complete binary tree, count the number of nodes.
    */
    class _1317_CountCompleteTreeNodes {
        public:
            int countNodes(TreeNode<int>* root);
    };

    /*
    Write a function that takes an unsigned integer and returns the number of ’1' bits the 
    corresponding binary number has (also known as the Hamming weight).
    
    Input：n = 11
    Output：3
    Explanation：11(10) = 1011(2), so return 3
    */
    class _1332_NumberOf1Bits{
        public:
            int hammingWeight(unsigned int n);
    };

    /*
    Given a non-negative integer numRows, generate the first numRows of 
    Pascal's triangle.
    In Pascal's triangle, each number is the sum of the two numbers 
    directly above it.
    
    Input: 5
    Output:
    [
    [1],
    [1,1],
    [1,2,1],
    [1,3,3,1],
    [1,4,6,4,1]]
    
    Input: 3
    Output:
    [
    [1],
    [1,1],
    [1,2,1]
    ]
    */
    class _1355_PascalsTriangle{
        public:
            std::vector<std::vector<int>> generate(int numRows);
    };

    /*
    Description: We have a two dimensional matrix A where
    each value is 0 or 1. A move consists of choosing any 
    row or column, and toggling each value in that row or
    column: changing all 0s to 1s, and all 1s to 0s.
    After making any number of moves, every row of this 
    matrix is interpreted as a binary number, and the 
    score of the matrix is the sum of these numbers.
    
    Return the highest possible score.
    1 <= A.length <= 20
    1 <= A[0].length <= 20
    A[i][j] is 0 or 1.
    
    
    Example 1:
    Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
    Output: 39
    
    Explanation:
    Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
    0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39

    Example 2:
    Input: [[1,1],[0,0],[1,0],[1,0],[1,1]]
    Output: 13
    Explanation:
    Toggled to [[1,1],[1,1],[1,0],[1,0],[1,1]].
    0b11 + 0b11 + 0b10 + ob10 + ob11 = 3 + 3 + 2 + 2 + 3= 13
    */
    class _1508_ScoreAfterFlippingMatrix{
        public:
            int matrixScore(std::vector<std::vector<int>>& A);

        private:
            void flipRow(std::vector<std::vector<int>>& A, int rowIdx);
            void flipCol(std::vector<std::vector<int>>& A, int colIdx);
            int countOnes(std::vector<std::vector<int>>& A, int colIdx);
            int toNum(std::vector<int>& v);
    };


    /*
    There is a special square room with mirrors on each of the four walls. 
    Except for the southwest corner, there are receptors on each of the 
    remaining corners, numbered 0, 1, and 2.
    
    The square room has walls of length p, and a laser ray from the southwest 
    corner first meets the east wall at a distance q from the 0th receptor.
    
    Return the number of the receptor that the ray meets first. (It is 
    guaranteed that the ray will meet a receptor eventually.)

    Input: p = 2, q = 1
    Output: 2
    Explanation: The ray meets receptor 2 the first time it gets reflected 
    back to the left wall.

    Input: p = 3, q = 1
    Output: 1
    Explanation: The ray meets receptor 1 the first time it gets reflected 
    back to the left wall.
    这道题完全抄答案的
    */
    class _1511_MirrorReflection {
        public:
            int mirrorReflection(int p, int q);
        private:
            int gcd(int p, int q);

    };

    /*
    Implement function ToLowerCase() that has a string parameter str, 
    and returns the same string in lowercase.
    */
    class _1535_ToLowerCase {
        public:
            std::string toLowerCase(std::string &str);
    };

    /*
    You have a list of words and a pattern, and you want to know which words
    in words matches the pattern. A word matches the pattern if there exists 
    a permutation of letters p so that after replacing every letter x in the 
    pattern with p(x), we get the desired word.
    (Recall that a permutation of letters is a bijection from letters to letters: 
    every letter maps to another letter, and no two letters map to the same letter.)
    
    Return a list of the words in words that match the given pattern.
    You may return the answer in any order.
    
    1 <= words.length <= 501<=words.length<=50
    1 <= pattern.length = words[i].length <= 201<=pattern.length=words[i].length<=20
    
    Example
    Example 1:
    Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
    Output: ["aqq","mee"]
    
    Explanation: 
    "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
    "ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation,
    since a and b map to the same letter.
    
    Example 2:
    Input: words = ["a","b","c"], pattern = "a"
    Output: ["a","b","c"]
    */
    class _1592_FindAndReplacePattern {
        public:
            std::vector<std::string> findAndReplacePattern(std::vector<std::string> &words, std::string &pattern);
        private:
            bool samePattern(std::string& A, std::string& B);
    };
}

#endif
