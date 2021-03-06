#ifndef PROBLEM_SET11_HPP
#define PROBLEM_SET11_HPP

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
    In a social group, there are N people, with unique integer ids from 0 
    to N-1. We have a list of logs, where each logs[i] = [timestamp, id_A, 
    id_B] contains a non-negative integer timestamp, and the ids of two 
    different people.
    Each log represents the time in which two different people became 
    friends.  Friendship is symmetric: if A is friends with B, then B is 
    friends with A.
    Let's say that person A is acquainted with person B if A is friends 
    with B, or A is a friend of someone acquainted with B.
    Return the earliest time for which every person became acquainted with 
    every other person. Return -1 if there is no such earliest time.
    
    Input: logs = [[20190101,0,1],[20190104,3,4],[20190107,2,3],[20190211,1,5],[20190224,2,4],[20190301,0,3],[20190312,1,2],[20190322,4,5]], N = 6
    Output: 20190301
    Explanation: 
    The first event occurs at timestamp = 20190101 and after 0 and 1 become friends we have the following friendship groups [0,1], [2], [3], [4], [5].
    The second event occurs at timestamp = 20190104 and after 3 and 4 become friends we have the following friendship groups [0,1], [2], [3,4], [5].
    The third event occurs at timestamp = 20190107 and after 2 and 3 become friends we have the following friendship groups [0,1], [2,3,4], [5].
    The fourth event occurs at timestamp = 20190211 and after 1 and 5 become friends we have the following friendship groups [0,1,5], [2,3,4].
    The fifth event occurs at timestamp = 20190224 and as 2 and 4 are already friend anything happens.
    The sixth event occurs at timestamp = 20190301 and after 0 and 3 become friends we have that all become friends.


    Note:

    2 <= N <= 100
    1 <= logs.length <= 10^4
    0 <= logs[i][0] <= 10^9
    0 <= logs[i][1], logs[i][2] <= N - 1
    It's guaranteed that all timestamps in logs[i][0] are different.
    logs are not necessarily ordered by some criteria.
    logs[i][1] != logs[i][2]
    */
    class _1011_TheEarliestMomentWhenEveryoneBecomeFriends {
    public:
        int earliestAcq(std::vector<std::vector<int>>& logs, int N);
    };
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
The k-digit number N is an Armstrong number if and only if the k-th power of each digit sums to N.
Given a positive integer N, return true if and only if it is an Armstrong number.

Input: 153
Output: true
Explanation: 
153 is a 3-digit number, and 153 = 1^3 + 5^3 + 3^3.

Input: 123
Output: false
Explanation: 
123 is a 3-digit number, and 123 != 1^3 + 2^3 + 3^3 = 36.
*/
class _1134_ArmstrongNumber {
public:
    bool isArmstrong(int N);
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
Tag: Transform
Google

Given two strings str1 and str2 of the same length, determine 
whether you can transform str1 into str2 by doing zero or more 
conversions. In one conversion you can convert all occurrences
of one character in str1 to any other lowercase English character.
Return true if and only if you can transform str1 into str2.

Input: str1 = "aabcc", str2 = "ccdee"
Output: true
Explanation: Convert 'c' to 'e' then 'b' to 'd' then 'a' to 'c'. 
Note that the order of conversions matter.

Input: str1 = "leetcode", str2 = "codeleet"
Output: false
Explanation: There is no way to transform str1 to str2.

1 <= str1.length == str2.length <= 10^4
Both str1 and str2 contain only lowercase English letters.
*/
class _1153_StringTransformsIntoAnotherString {
public:
    bool canConvert(std::string str1, std::string str2);
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
    int dayOfYear(std::string dt);
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
You have some sticks with positive integer lengths.
You can connect any two sticks of lengths X and Y into one 
stick by paying a cost of X + Y.  You perform this action until there is one stick remaining.

Return the minimum cost of connecting all the given sticks into one stick in this way.

Input: sticks = [2,4,3]
Output: 14

Input: sticks = [1,8,3,5]
Output: 30
*/
class _1167_MinimumCostToConnectSticks {
public:
    int connectSticks(std::vector<int>& sticks);
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
Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.

After doing so, return the head of the final linked list.  You may return any such answer.

 

(Note that in the examples below, all sequences are serializations of ListNode objects.)

Example 1:

Input: head = [1,2,-3,3,1]
Output: [3,1]
Note: The answer [1,2,1] would also be accepted.
Example 2:

Input: head = [1,2,3,-3,4]
Output: [1,2,4]
Example 3:

Input: head = [1,2,3,-3,-2]
Output: [1]
 

Constraints:

The given linked list will contain between 1 and 1000 nodes.
Each node in the linked list has -1000 <= node.val <= 1000.
*/
class _1171_RemoveZeroSumConsecutiveNodesFromLinkedList {
public:
    ListNode<int>* removeZeroSumSublists(ListNode<int>* head);
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
Tag: array
Amazon
A dieter consumes calories[i] calories on the i-th day. 

Given an integer k, for every consecutive sequence of k days (calories[i], calories[i+1], ..., calories[i+k-1] for all 0 <= i <= n-k), they look at T, the total calories consumed during that sequence of k days (calories[i] + calories[i+1] + ... + calories[i+k-1]):

If T < lower, they performed poorly on their diet and lose 1 point; 
If T > upper, they performed well on their diet and gain 1 point;
Otherwise, they performed normally and there is no change in points.
Initially, the dieter has zero points. Return the total number of points the dieter has after dieting for calories.length days.

Note that the total points can be negative.

Example 1:

Input: calories = [1,2,3,4,5], k = 1, lower = 3, upper = 3
Output: 0
Explanation: Since k = 1, we consider each element of the array separately and compare it to lower and upper.
calories[0] and calories[1] are less than lower so 2 points are lost.
calories[3] and calories[4] are greater than upper so 2 points are gained.
Example 2:

Input: calories = [3,2], k = 2, lower = 0, upper = 1
Output: 1
Explanation: Since k = 2, we consider subarrays of length 2.
calories[0] + calories[1] > upper so 1 point is gained.
Example 3:

Input: calories = [6,5,0,0], k = 2, lower = 1, upper = 5
Output: 0
Explanation:
calories[0] + calories[1] > upper so 1 point is gained.
lower <= calories[1] + calories[2] <= upper so no change in points.
calories[2] + calories[3] < lower so 1 point is lost.
 

Constraints:

1 <= k <= calories.length <= 10^5
0 <= calories[i] <= 20000
0 <= lower <= upper
*/
class _1176_DietPlanPerformance {
public:
    int dietPlanPerformance(std::vector<int>& calories, int k, int lower, int upper);
};

/*
You are given an array colors, in which there are three colors: 1, 2 and 3.

You are also given some queries. Each query consists of two integers i and c, return the shortest distance between the given index i and the target color c. If there is no solution return -1.


Example 1:

Input: colors = [1,1,2,1,3,2,2,3,3], queries = [[1,3],[2,2],[6,1]]
Output: [3,0,3]
Explanation: 
The nearest 3 from index 1 is at index 4 (3 steps away).
The nearest 2 from index 2 is at index 2 itself (0 steps away).
The nearest 1 from index 6 is at index 3 (3 steps away).
Example 2:

Input: colors = [1,2], queries = [[0,3]]
Output: [-1]
Explanation: There is no 3 in the array.
 

Constraints:

1 <= colors.length <= 5*10^4
1 <= colors[i] <= 3
1 <= queries.length <= 5*10^4
queries[i].length == 2
0 <= queries[i][0] < colors.length
1 <= queries[i][1] <= 3
*/
class _1182_ShortestDistanceToTargetColor {
public:
    std::vector<int> shortestDistanceColor(std::vector<int>& colors, std::vector<std::vector<int>>& queries);
    std::vector<int> calDistance(std::vector<int>& colors, int targetColor);
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

}
#endif