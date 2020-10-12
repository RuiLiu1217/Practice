#ifndef LEETCODE_MATHPROBLEMS_HPP
#define LEETCODE_MATHPROBLEMS_HPP
#include "HeaderFiles.hpp"
namespace LC {
/*
Tag: stack, numeric
Given a 32-bit signed integer, reverse digits of an integer.

Input: 123       :       Output: 321
Input: -123      :       Output: -321
Input: 120       :       Output: 21
*/
class _0007_ReverseInteger {
public:
    int reverse(int x);
};

/* Tag: string, palindrome
Determine whether an integer is a palindrome. An integer is a 
palindrome when it reads the same backward as forward.

Input: 121             Output: true
Input: -121            Output: false
Explanation: From left to right, it reads -121. From right to left, 
it becomes 121-. Therefore it is not a palindrome.

Input: 10              Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/
class _0009_PalindromeNumber {
public:
    bool isPalindrome(int x);
};


//! TODO: need review it again
/*
Tag: Binary search, math
Given two integers dividend and divisor, divide two integers without 
using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.
The integer division should truncate toward zero.

Input: dividend = 10, divisor = 3
Output: 3

Input: dividend = 7, divisor = -3
Output: -2
Note:

Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store 
integers within the 32-bit signed integer range: [−2^31, 2^31 − 1]. 
For the purpose of this problem, assume that your function returns 
2^31 − 1 when the division result overflows.
*/
class _0029_DivideTwoIntegers {
public:
    int divide(int dividend, int divisor);
};


/*
Given a column title as appear in an Excel sheet, return its corresponding column number.
For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
Example 1:

Input: "A"
Output: 1
Example 2:

Input: "AB"
Output: 28
Example 3:

Input: "ZY"
Output: 701
*/
class _0171_ExcellSheetColumnNumber {
public:
    int titleToNumber(std::string s);
};

/*
Given an integer n, return the number of trailing zeroes in n!.

Example 1:

Input: 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: 5
Output: 1
Explanation: 5! = 120, one trailing zero.
Note: Your solution should be in logarithmic time complexity.
*/
class _0172_FactorialTrailingZeroes {
public:
    int trailingZeroes(int n);
};

/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...
Example 1:

Input: 1
Output: "A"
Example 2:

Input: 28
Output: "AB"
Example 3:

Input: 701
Output: "ZY"
*/
class _0168_ExcelSheetColumnTitle {
public:
    std::string convertToTitle(int n);
};



/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive 
integer, replace the number by the sum of the squares of its digits, and repeat the 
process until the number equals 1 (where it will stay), or it loops endlessly in a cycle 
which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 

Input: 19
Output: true
Explanation: 
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
*/
class _0202_HappyNumber {
private:
    int gat(int n);
public:
    bool isHappy(int n);
};



/*
Count the number of prime numbers less than a non-negative number, n.
Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
*/
class _0204_CountPrimes {
public:
    int countPrimes(int n);
};

/*
Find the total area covered by two rectilinear rectangles 
in a 2D plane. Each rectangle is defined by its bottom left 
corner and top right corner as shown in the figure.
*/
class _0223_RectangleArea {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H);
};



/*
Given an integer, write a function to determine if it is a power of two.

Input: 1
Output: true 
Explanation: 20 = 1

Input: 16
Output: true
Explanation: 24 = 16

Input: 218
Output: false
*/
class _0231_PowerOfTwo {
public:
    bool isPowerOfTwo(int n);
};


/*
Given a non-negative integer num, repeatedly add all its digits until the 
result has only one digit.

Input: 38
Output: 2 
Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
    Since 2 has only one digit, return it.
*/
class _0258_AddDigits {
public:
    int addDigits(int num);
};

/*
Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.

Example 1:

Input: 6
Output: true
Explanation: 6 = 2 × 3
Example 2:

Input: 8
Output: true
Explanation: 8 = 2 × 2 × 2
Example 3:

Input: 14
Output: false 
Explanation: 14 is not ugly since it includes another prime factor 7.
Note:

1 is typically treated as an ugly number.
Input is within the 32-bit signed integer range: [−231,  231 − 1].
*/
class _0263_UglyNumber {
public:
    bool isUgly(int num);
};

/*
Given two sparse matrices A and B, return the result of AB.
You may assume that A's column number is equal to B's row number.

Input:

A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]

Output:

     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |
*/
class _0311_SparseMatrixMultiplication {
public:
    std::vector<std::vector<int>> multiply(std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& B);

};


/*
Given an integer, write a function to determine if it is a power of three.

Input: 27              :            Output: true
Input: 0               :            Output: false
Input: 9               :            Output: true
Input: 45              :            Output: false
Follow up: Could you do it without using any loop / recursion?
*/
class _0326_PowerOfThree {
public:
    bool isPowerOfThree(int n);
};


/*
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Input: 16           :           Output: true
Input: 5            :           Output: false
Follow up: Could you solve it without loops/recursion?
*/
class _0342_PowerOfFour {
public:
    bool isPowerOfFour(int num);
};

/*
Given a positive integer num, write a function which returns True if num is a 
perfect square else False. Note: Do not use any built-in library function such 
as sqrt.

Input: 16
Returns: True

Input: 14
Returns: False
Credits:
Special thanks to @elmirap for adding this problem and creating all test cases.
*/
class _0367_ValidPerfectSquare {
public:
    bool isPerfectSquare(int x);
};


/*
Your task is to calculate ab mod 1337 where a is a positive integer 
and b is an extremely large positive integer given in the form of an array.

Input: a = 2, b = [3]
Output: 8

Input: a = 2, b = [1,0]
Output: 1024
*/
class _0372_SuperPow {
public:
//! Copy from the solution
    int superPow(int a, std::vector<int>& b);
};

/*
Given the coordinates of four points in 2D space, return whether the four points could construct a square.
The coordinate (x,y) of a point is represented by an integer array with two integers.

Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: True

Note:
All the input integers are in the range [-10000, 10000].
A valid square has four equal sides with positive length and four equal angles (90-degree angles).
Input points have no order.
*/
class _0593_ValidSquare {
public:
    bool validSquare(std::vector<int>& p1, std::vector<int>& p2, std::vector<int>& p3,
    std::vector<int>& p4);
};


/*
Given an array consists of non-negative integers, your task is to count the number of triplets 
chosen from the array that can make triangles if we take them as side lengths of a triangle.
Example 1:
Input: [2,2,3,4]
Output: 3
Explanation:
Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
Note:
The length of the given array won't exceed 1000.
The integers in the given array are in the range of [0, 1000].
*/
// ! Copy from the solution. I have no idea how to solve it.
class _0611_ValidTriangleNumber {
public:
    int triangleNumber(std::vector<int>& nums);
};

/*
Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.

Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5

Input: 3
Output: False
*/
class _0633_SumOfSquareNumbers {
public:
    bool judgeSquareSum(int c);
};

/*
There is a robot starting at position (0, 0), the origin, on a 2D plane. 
Given a sequence of its moves, judge if this robot ends up at (0, 0) after 
it completes its moves.
The move sequence is represented by a string, and the character moves[i] 
represents its ith move. Valid moves are R (right), L (left), U (up), 
and D (down). If the robot returns to the origin after it finishes all of 
its moves, return true. Otherwise, return false.
Note: The way that the robot is "facing" is irrelevant. "R" will always 
make the robot move to the right once, "L" will always make it move left, 
etc. Also, assume that the magnitude of the robot's movement is the same 
for each move.

Input: "UD"
Output: true 
Explanation: The robot moves up once, and then down once. All moves have 
the same magnitude, so it ended up at the origin where it started. 
Therefore, we return true.

Input: "LL"
Output: false
Explanation: The robot moves left twice. It ends up two "moves" to the 
left of the origin. We return false because it is not at the origin at 
the end of its moves.
*/
class _0657_RobotReturnToOrigin {
public:
    bool judgeCircle(std::string moves);
};

/*
Given a positive integer K, you need find the smallest positive 
integer N such that N is divisible by K, and N only contains the 
digit 1.
Return the length of N.  If there is no such N, return -1.

Input: 1
Output: 1
Explanation: The smallest answer is N = 1, which has length 1.

Input: 2
Output: -1
Explanation: There is no such positive integer N divisible by 2.

Input: 3
Output: 3
Explanation: The smallest answer is N = 111, which has length 3.

Note:
1 <= K <= 10^5
*/
class _1015_SmallestIntegerDivisibleByK {
public:
    int smallestRepunitDivByK(int K);
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
In some array arr, the values were in arithmetic progression: the values arr[i+1] - arr[i] are all equal for every 0 <= i < arr.length - 1.
Then, a value from arr was removed that was not the first or last value in the array.
Return the removed value.

Input: arr = [5,7,11,13]
Output: 9
Explanation: The previous array was [5,7,9,11,13].

Input: arr = [15,13,12]
Output: 14
Explanation: The previous array was [15,14,13,12].
*/
class _1228_MissingNumberInArithmeticProgression {
public:
    int missingNumber(std::vector<int>& arr);
};


/*
You are given an array coordinates, coordinates[i] = [x, y], 
where [x, y] represents the coordinate of a point. Check if 
these points make a straight line in the XY plane.

Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false

Constraints:
2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates contains no duplicate point.
*/
class _1232_CheckIfItIsAStraightLine {
public:
    bool checkStraightLine(std::vector<std::vector<int>>& coordinates);
};

/*
On a plane there are n points with integer coordinates points[i] = [xi, yi]. Your task is to find the minimum time in seconds to visit all points.

You can move according to the next rules:

In one second always you can either move vertically, horizontally by one unit or diagonally (it means to move one unit vertically and one unit horizontally in one second).
You have to visit the points in the same order as they appear in the array.
Input: points = [[1,1],[3,4],[-1,0]]
Output: 7
Explanation: One optimal path is [1,1] -> [2,2] -> [3,3] -> [3,4] -> [2,3] -> [1,2] -> [0,1] -> [-1,0]   
Time from [1,1] to [3,4] = 3 seconds 
Time from [3,4] to [-1,0] = 4 seconds
Total time = 7 seconds
Example 2:

Input: points = [[3,2],[-2,2]]
Output: 5
 

Constraints:

points.length == n
1 <= n <= 100
points[i].length == 2
-1000 <= points[i][0], points[i][1] <= 1000
*/
class _1266_MinimumTimeVisitingAllPoints {
public:
    int minTimeToVisitAllPoints(std::vector<std::vector<int>>& points) {
        int res = 0;
        std::function<int(std::vector<int>&, std::vector<int>&)> minTimeBetweenTwoPoints = [](std::vector<int>& Pa, std::vector<int>& Pb){
            return std::max(std::abs(Pa[0] - Pb[0]), std::abs(Pa[1] - Pb[1]));
        };
        for(int i = 1; i < points.size(); ++i) {
            res += minTimeBetweenTwoPoints(points[i], points[i-1]);
        }
        return res;
    }
};


/*
Given an integer number n, return the difference between the product of its digits and the sum of its digits.

Input: n = 234
Output: 15 
Explanation: 
Product of digits = 2 * 3 * 4 = 24 
Sum of digits = 2 + 3 + 4 = 9 
Result = 24 - 9 = 15
Example 2:

Input: n = 4421
Output: 21
Explanation: 
Product of digits = 4 * 4 * 2 * 1 = 32 
Sum of digits = 4 + 4 + 2 + 1 = 11 
Result = 32 - 11 = 21
Constraints:

1 <= n <= 10^5
*/
class _1281_SubstractTheProductAndSumOfDigitsOfAnInteger {
public:
    int subtractProductAndSum(int n) {
        int sum = 0;
        int prd = 1;
        while(n) {
            int d = n % 10;
            n /= 10;
            sum += d;
            prd *= d;
        }
        return prd - sum;
    }
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
    std::vector<int> sumZero(int n) {
        if(n == 1) {
            return {0};
        } else if(n == 2) {
            return {-1, 1};
        } else {
            std::vector<int> cur = sumZero(n - 2);
            cur.push_back(n);
            cur.push_back(-n);
            return cur;
        }
    }
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
Given a non-negative integer num, return the number of steps to reduce it to zero. 
If the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.

Input: num = 14
Output: 6
Explanation: 
Step 1) 14 is even; divide by 2 and obtain 7. 
Step 2) 7 is odd; subtract 1 and obtain 6.
Step 3) 6 is even; divide by 2 and obtain 3. 
Step 4) 3 is odd; subtract 1 and obtain 2. 
Step 5) 2 is even; divide by 2 and obtain 1. 
Step 6) 1 is odd; subtract 1 and obtain 0.
Example 2:

Input: num = 8
Output: 4
Explanation: 
Step 1) 8 is even; divide by 2 and obtain 4. 
Step 2) 4 is even; divide by 2 and obtain 2. 
Step 3) 2 is even; divide by 2 and obtain 1. 
Step 4) 1 is odd; subtract 1 and obtain 0.
Example 3:

Input: num = 123
Output: 12

Constraints:
0 <= num <= 10^6
*/
class _1342_NumberOfStepsToReduceANumberToZero {
public:
    int numberOfSteps (int num) {
        if(num == 0) { return 0; }
        if(num % 2) {
            return numberOfSteps(num-1) + 1;
        } else {
            return numberOfSteps(num / 2) + 1;
        }
    }
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
Given an integer n, return a list of all simplified fractions between 0 and 1 (exclusive) 
such that the denominator is less-than-or-equal-to n. The fractions can be in any order.

Input: n = 2
Output: ["1/2"]
Explanation: "1/2" is the only unique fraction with a denominator less-than-or-equal-to 2.

Input: n = 3
Output: ["1/2","1/3","2/3"]

Input: n = 4
Output: ["1/2","1/3","1/4","2/3","3/4"]
Explanation: "2/4" is not a simplified fraction because it can be simplified to "1/2".

Input: n = 1
Output: []

Constraints:

1 <= n <= 100
*/
class _1447_SimplifiedFractions {
public:
    std::vector<std::string> simplifiedFractions(int n);
};


/*
Given two sparse vectors, compute their dot product.

Implement class SparseVector:

SparseVector(nums) Initializes the object with the vector nums
dotProduct(vec) Compute the dot product between the instance of SparseVector and vec
A sparse vector is a vector that has mostly zero values, you should store the sparse vector efficiently and compute the dot product between two SparseVector.

Follow up: What if only one of the vectors is sparse?

 

Example 1:

Input: nums1 = [1,0,0,2,3], nums2 = [0,3,0,4,0]
Output: 8
Explanation: v1 = SparseVector(nums1) , v2 = SparseVector(nums2)
v1.dotProduct(v2) = 1*0 + 0*3 + 0*0 + 2*4 + 3*0 = 8
Example 2:

Input: nums1 = [0,1,0,0,0], nums2 = [0,0,0,0,2]
Output: 0
Explanation: v1 = SparseVector(nums1) , v2 = SparseVector(nums2)
v1.dotProduct(v2) = 0*0 + 1*0 + 0*0 + 0*0 + 0*2 = 0
Example 3:

Input: nums1 = [0,1,0,0,2,0,0], nums2 = [1,0,0,0,3,0,4]
Output: 6
 

Constraints:

n == nums1.length == nums2.length
1 <= n <= 10^5
0 <= nums1[i], nums2[i] <= 100
*/
class _1570_DotProductOfTwoSparseVectors {
private:
    std::unordered_map<int, int> nonZeroValues;
public:
    const std::unordered_map<int, int> getValues() const {
        return nonZeroValues;
    }
    _1570_DotProductOfTwoSparseVectors(std::vector<int> &nums) {
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] != 0) {
                nonZeroValues[i] = nums[i];
            }            
        }        
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(_1570_DotProductOfTwoSparseVectors& vec) {
        int res = 0;
        for(const auto& v : vec.getValues()) {
            if(nonZeroValues.find(v.first) != nonZeroValues.end()) {
                res += nonZeroValues[v.first] * v.second;
            }
        }
        return res;
    }
};

}
#endif