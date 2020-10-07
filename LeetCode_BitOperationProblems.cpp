#include "LeetCode_BitOperationProblems.hpp"
#include <bitset>
#include <algorithm>
#include <functional>
int LC::_0136_SingleNumber::singleNumber(std::vector<int>& nums) {
    int v = nums[0];
    for(int i = 1; i != nums.size(); ++i)
    {
        v ^= nums[i];
    }
    return v;
}

/*
这道题是之前那道 Single Number 的延伸，那道题的解法就比较独特，
是利用计算机按位储存数字的特性来做的，这道题就是除了一个单独的数
字之外，数组中其他的数字都出现了三次，还是要利用位操作 Bit Manipulation 
来解。可以建立一个 32 位的数字，来统计每一位上1出现的个数，如果
某一位上为1的话，那么如果该整数出现了三次，对3取余为0，这样把每
个数的对应位都加起来对3取余，最终剩下来的那个数就是单独的数字。
代码如下：
*/
int LC::_0137_SingleNumberII::singleNumberV1(std::vector<int>& nums) {
    int res = 0;
    for (int i = 0; i < 32; ++i) {
        int sum = 0;
        for (int j = 0; j < nums.size(); ++j) {
            sum += (nums[j] >> i) & 1;
        }
        res |= (sum % 3) << i;
    }
    return res;
}

/*

还有一种解法，思路很相似，用3个整数来表示 INT 的各位的出现次数情况，
one 表示出现了1次，two 表示出现了2次。当出现3次的时候该位清零。
最后答案就是one的值。

ones   代表第 ith 位只出现一次的掩码变量
twos  代表第 ith 位只出现两次次的掩码变量
threes  代表第 ith 位只出现三次的掩码变量
假设现在有一个数字1，更新 one 的方法就是 ‘亦或’ 这个1，则 one 
就变成了1，而 two 的更新方法是用上一个状态下的 one 去 ‘与’ 上数字
1，然后 ‘或’ 上这个结果，这样假如之前 one 是1，那么此时 two 也会变成
1，这 make sense，因为说明是当前位遇到两个1了；反之如果之前 one 是0，
那么现在 two 也就是0。注意更新的顺序是先更新 two，再更新 one，不理解
的话只要带个只有一个数字1的输入数组看一下就不难理解了。然后更新 three，
如果此时 one 和 two 都是1了，由于先更新的 two，再更新的 one，two 为1，
说明此时至少有两个数字1了，而此时 one 为1，说明了此时已经有了三个数字1，
这块要仔细想清楚，因为 one 是要 ‘亦或’ 一个1的，值能为1，说明之前 one 
为0，实际情况是，当第二个1来的时候，two 先更新为1，此时 one 再更新为0，
下面 three 就是0了，那么 ‘与’ 上t hree 的相反数1不会改变 one 和 two 
的值；那么当第三个1来的时候，two 还是1，此时 one 就更新为1了，那么 
three 就更新为1了，此时就要清空 one 和 two 了，让它们 ‘与’ 上 three 
的相反数0即可，最终结果将会保存在 one 中，参见代码如下：
*/
int LC::_0137_SingleNumberII::singleNumberV2(std::vector<int>& nums) {
    int one = 0, two = 0, three = 0;
    for (int i = 0; i < nums.size(); ++i) {
        two |= one & nums[i];
        one ^= nums[i];
        three = one & two;
        one &= ~three;
        two &= ~three;
    }
    return one;
}
/*
下面这种解法思路也十分巧妙，根据上面解法的思路，我们把数组中数字的每一位
累加起来对3取余，剩下的结果就是那个单独数组该位上的数字，由于累加的过程
都要对3取余，那么每一位上累加的过程就是 0->1->2->0，换成二进制的表示为 
00->01->10->00，可以写出对应关系：

00 (+) 1 = 01

01 (+) 1 = 10

10 (+) 1 = 00 ( mod 3)

用 ab 来表示开始的状态，对于加1操作后，得到的新状态的 ab 的算法如下：

b = b xor r & ~a;

a = a xor r & ~b;

这里的 ab 就是上面的三种状态 00，01，10 的十位和各位，刚开始的时候，
a和b都是0，当此时遇到数字1的时候，b更新为1，a更新为0，就是 01 的状态；
再次遇到1的时候，b更新为0，a更新为1，就是 10 的状态；再次遇到1的时候，
b更新为0，a更新为0，就是 00 的状态，相当于重置了；最后的结果保存在b中，
明白了上面的分析过程，就能写出代码如下；
*/

int LC::_0137_SingleNumberII::singleNumberV3(std::vector<int>& nums) {
    int a = 0, b = 0;
    for (int i = 0; i < nums.size(); ++i) {
        b = (b ^ nums[i]) & ~a;
        a = (a ^ nums[i]) & ~b;
    }
    return b;
}
   
int LC::_0137_SingleNumberII::singleNumber(std::vector<int>& nums) {
    int res = 0;
    for (int i = 0; i < 32; ++i) {
        int sum = 0;
        for (int j = 0; j < nums.size(); ++j) {
            sum += (nums[j] >> i) & 1;
        }
        res |= (sum % 3) << i;
    }
    return res;
}



// Bit operations
//! This problem is to practice to use the library bitset
uint32_t LC::_0190_ReverseBits::reverseBits(uint32_t n) {
    std::bitset<32> bit(n);
    std::bitset<32> ans;
    for (int i = 0; i < 32; ++i) {
        ans[i] = bit[32 - i];
    }
    return ans.to_ullong();
}


int LC::_0191_NumberOf1Bits::hammingWeight(uint32_t n) {
    int res = 0;
    while(n) {
        n = n & (n - 1);
        ++res;
    }
    return res;
}

/*
Solution: 我们知道，数组的数字是连续的，那么m,n范围内的二进制表示的末尾
相同位置一定会出现不同的0,1.我们只要找出m,n的做左边起的最长相同的二进制头
部即可呀。

如[5, 7]里共有三个数字，分别写出它们的二进制为：
101　　110　　111
相与后的结果为100，仔细观察我们可以得出，最后的数是该数字范围内所有的数的
左边共同的部分（即m,n左边的共同部分），如果上面那个例子不太明显，我们再来
看一个范围[26, 30]，它们的二进制如下：
11010　　11011　　11100　　11101　　11110

也是前两位是11，后面3位在不同数字中一定会出现0和1、相与即为0了。

我的做法是把m,n同时向右平移，直到两者相等（头部相同了），再把最后的结果向左平移相同的步数。
*/
int LC::_0201_BitwiseANDofNumbersRange::rangeBitwiseAnd(int m, int n) {
    int i = 0;

    while(m != n) {
        m >>= 1;
        n >>= 1;
        ++i;
    }
    return m << i;
}


/*
Solution
    1. assume that A and B are the two elements which we want to find;
    2. use XOR for all elements,the result is : r = A^B,we just need 
    to distinguish A from B next step;
    3. if we can find a bit '1' in r,then the bit in corresponding 
        position in A and B must be different.We can use 
        {last = r & (~(r-1))} to get the last bit 1 int r;
    4. we use last to divide all numbers into two groups,then A and B 
        must fall into the two distrinct groups. XOR elements in eash 
        group,get the A and B.
*/
std::vector<int> LC::_0260_SingleNumberII::singleNumber(const std::vector<int> &nums) {
    int r = 0;
    std::for_each(begin(nums), end(nums), [&](auto n){ r ^= n;});
    int lasDigit = r & (~(r - 1)); //! Find the last bit that the only two values must be different
    std::vector<int> res(2, 0);
    std::for_each(begin(nums), end(nums), [&](auto n){
        res[(lasDigit & n) == 0] ^= n;
    });
    return res;
}

int LC::_0371_SumOfTwoIntegers::getSum(int a, int b) {
    const int max_bits = 32;
    auto carry = 0;
    int _sum = 0;
    for (int i = 0; i < max_bits; ++i)
    {
        auto a_bit = (a >> i) & 1;
        auto b_bit = (b >> i) & 1;
        auto tmp = (a_bit ^ b_bit ^ carry) << i;
        _sum |= tmp;
        carry = ((a_bit & b_bit) ||
                    (a_bit & carry) ||
                    (b_bit & carry))
                    ? 1
                    : 0;
    }
    return _sum;
}




std::vector<std::string> LC::_0401_BinaryWatch::readBinaryWatch(int num) {
    std::vector<std::string> res;
    for(int h = 0; h < 12; ++h) {
        for(int m = 0; m < 60; ++m) {
            if(std::bitset<10>(h << 6 | m).count() == num) { // Why not 11, <<7?
                res.emplace_back(std::to_string(h) + ":" +
                (m < 10? "0" : "") + std::to_string(m));
            }
        }
    }
    return res;
}

// easier understand solution
std::vector<std::string> LC::_0401_BinaryWatch::readBinaryWatch_Solution2(int num) {
    std::vector<std::string> res;
    std::function<int(int)> numOf1 = [](int n) {
        int c = 0;
        while(n) {
            n &= (n - 1);
            ++c;
        }
        return c;
    };

    for(int h = 0; h < 23; ++h) {
        int hn = numOf1(h);
        if(hn > num) {
            continue;
        }
        for(int m = 0; m < 60; ++m) {
            int mn = numOf1(m);
            if(mn + hn == num) {
                if(m < 10) {
                    res.push_back(std::to_string(h) + ":0" + std::to_string(m));
                } else {
                    res.push_back(std::to_string(h) + ":" + std::to_string(m));
                }
            }
        }
    }
    return res;
}


std::string LC::_0405_ConvertANumberToHexadecimal::toHex(int num) {
    std::string res;
    int count = 0;
    do {
        char n = (num & 0x0000000f);
        if(n < 10) {
            res = (char)(n + '0') + res;
        } else {
            res = (char)(n - 10 + 'a') + res;
        }
        num >>= 4;
        ++count;
    } while (count < 8 && num);
    return res;
}

int LC::_0461_HammingDistance::hammingDistance(int x, int y) {
    int val = x ^ y;
    int dis = 0;
    while(val) {
        dis += (val & 1);
        val >>= 1;
    }
    return dis;
}

// Copy from the solution
int LC::_0477_TotalHammingDistance::totalHammingDistance(std::vector<int>& nums) {
    int size = nums.size();
    if (size < 2) return 0;
    int ans = 0;
    int *zeroOne = new int[2];
    while (true) {
        int zeroCount = 0;
        zeroOne[0] = 0;
        zeroOne[1] = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0) zeroCount++;
            zeroOne[nums[i] % 2]++;
            nums[i] = nums[i] >> 1;
        }
        ans += zeroOne[0] * zeroOne[1];
        if (zeroCount == nums.size()) return ans;
    }
}


int LC::_1009_CompletementOfBase10Integer::bitwiseComplement(int N) {
    if(N == 0) { // Special case;
        return 1;
    }
    int res = 0;
    int i = 0;
    while(N) {
        res |= ((N & 1) ^ 1) << i;
        ++i;
        N >>= 1;
    }
    return res;
}