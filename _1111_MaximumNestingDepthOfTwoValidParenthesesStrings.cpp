#include "headers.hpp"

/* 这道题是抄答案的，没有明白到底在说什么
   这道题题目看着非常confusing, 读懂题目后，意思就是说把每个左右括号标记成0,1 意思就是
   分别分配到第一组A还是第二组B，得到最终的分配后使得 A B的括号嵌套深度最小
*/
std::vector<int> LeetCode::_1111_MaximumNestingDepthOfTwoValidParenthesesStrings::maxDepthAfterSplit(std::string seq) {
    const int N = seq.size();
    std::vector<int> res(seq.size(), 0);
    std::vector<int> curDepth(seq.size(), 0);

    int maxDepth = 0;
    int curD = 0;
    for(int i = 0; i < seq.size(); ++i) {
        if(seq[i] == '(') {
            curD++;
            curDepth[i] = curD;
            if(curD > maxDepth) {
                maxDepth = curD;
            }
        } else {
            curDepth[i] = curD;
            --curD;
        }
    }
    if(maxDepth < 2) {
        return res;
    }

    int hafDepth = maxDepth / 2;
    for(int i = 0; i < curDepth.size(); ++i) {
        if(curDepth[i] > hafDepth) {
            res[i] = 1;
        }
    }
    return res;
}