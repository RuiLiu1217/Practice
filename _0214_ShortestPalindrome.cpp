#include "headers.hpp"
/* KMP based solution: 
   把s和其转置r连接起来，中间加上一个其他字符，形成一个新的字符串t，
   还需要一个和t长度相同的一位数组 next，其中 next[i] 表示从 t[i] 
   到开头的子串的相同前缀后缀的个数，具体可参考 KMP 算法中解释。最后
   把不相同的个数对应的字符串添加到s之前即可，代码如下：
*/
std::string LeetCode::_0214_ShortestPalindrome::shortestPalindrome(std::string s) {
    std::string r = s;
    std::reverse(begin(r), end(r));
    std::string t = s + "#" + r;
    std::vector<int> next(t.size(), 0);
    for(int i = 1; i < next.size(); ++i) {
        int j = next[i - 1];
        while(j > 0 && t[i] != t[j]) {
            j = next[j - 1];
        }
        next[i] = (j += t[i] == t[j]);
    }
    return r.substr(0, s.size() - next.back()) + s;
}