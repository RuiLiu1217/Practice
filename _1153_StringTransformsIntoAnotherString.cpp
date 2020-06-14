#include "headers.hpp"

/* Copy from the solution: 
https://leetcode.com/problems/string-transforms-into-another-string/discuss/355382/JavaC%2B%2BPython-Need-One-Unused-Character

Explanation
Scan s1 and s2 at the same time, record the transform 
mapping into a map/array. The same char should transform 
to the same char. Otherwise we can directly return false.

To realise the transformation:
transformation of link link, like a -> b -> c:
we do the transformation from end to begin, 
that is b -> c then a -> b 

transformation of cycle, like a -> b -> c -> a:
in this case we need a tmp
c->tmp, b->c a->b and tmp->a
Same as the process of swap two variable.

In both case, there should at least one character that 
is unused, to use it as the tmp for transformation. So 
we need to return if the size of set of unused 
characters < 26.

Complexity
Time O(N) for scanning input
Space O(26) to record the mapping
running time can be improved if count available character during the scan.
*/
bool LeetCode::_1153_StringTransformsIntoAnotherString::canConvert(std::string str1, std::string str2) {
    if(str1 == str2) {
        return true;
    }
    if(str1.size() != str2.size()) {
        return false;
    }

    std::unordered_map<char, char> map;
    for(int i = 0; i < str1.size(); ++i) {
        if(map.find(str1[i]) == map.end()) {
            map[str1[i]] = str2[i];
        } else {
            if(map[str1[i]] != str2[i]) {
                return false;
            }
        }
    }
    return std::unordered_set<char>(begin(str2), end(str2)).size() < 26;
}