#include "headers.hpp"
// See the solution: https://leetcode.com/problems/number-of-digit-one/solution/

/* 
 一道找规律的题目：
|number of "1"    |    number contains "1"                                          |                    The range of numbers    |
|_________________|_________________________________________________________________|____________________________________________|
|    1            |    1                                                            |                          [1, 9]            |
|    11           |    10  11  12  13  14  15  16  17  18  19                       |                          [10, 19]          |
|    1            |    21                                                           |                          [20, 29]          |
|    1            |    31                                                           |                          [30, 39]          |
|    1            |    41                                                           |                          [40, 49]          |
|    1            |    ...                                                          |                          [50, 59]          |
|                 |    ...                                                          |                          ...               |
|    1            |    91                                                           |                          [90, 99]          |
|    11           |    100  101  102  103  104  105  106  107  108  109             |                          [100, 109]        |
|    21           |    110  111  112  113  114  115  116  117  118  119             |                          [110, 119]        |
|    11           |    120  121  122  123  124  125  126  127  128  129             |                          [120, 129]        |

通过上面的列举我们可以发现，100以内的数字，除了10-19之间有11个‘1’之外，其余都只有1个。

如果我们不考虑[10, 19]区间上那多出来的10个‘1’的话，那么我们在对任意一个两位数，
十位数上的数字 + 1 就代表1出现的个数，这时候我们再把多出的10个加上即可。比如56就有(5+1)+10=16个。

如何知道是否要加上多出的10个呢，我们就要看十位上的数字是否大于等于2，是的话就要加上多余的10个'1'。
那么我们就可以用(x+8)/10来判断一个数是否大于等于2。

对于三位数区间 [100, 199] 内的数也是一样，除了[110, 119]之间多出的10个数之外，共21个‘1’，其余的
每10个数的区间都只有11个‘1’，所以 [100, 199] 内共有21 + 11 * 9 = 120个‘1’。那么现在想想[0, 999]
区间内‘1’的个数怎么求？根据前面的结果，[0, 99] 内共有20个，[100, 199] 内共有120个，而其他每100个
数内‘1’的个数也应该符合之前的规律，即也是20个，那么总共就有 120 + 20 * 9 = 300 个‘1’。那么还是可
以用相同的方法来判断并累加1的个数.
*/

int LeetCode::_0233_NumberOfDigitOne::countDigitOne(int n) {
    int res = 0;
    int a = 1;
    int b = 1;
    while(n > 0) {
        res += (n + 8) / 10 * a + (n % 10 == 1) * b;
        b += n % 10 * a;
        a *= 10;
        n /= 10;
    }
    return res;
}