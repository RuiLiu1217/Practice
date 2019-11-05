#include "headers.hpp"
#include <string>
//抄答案的，把字符串看成一个栈，每次栈顶与将要入栈的比，如果一样就出栈，否则入栈。
std::string LeetCode::_1047_RemoveAllAdjacentDuplicatesInString::removeDuplicates(std::string S) {
    std::string a;
    for (auto& c : S) 
        if (a.size() && a.back() == c) a.pop_back();
        else a.push_back(c);
    return a;
}