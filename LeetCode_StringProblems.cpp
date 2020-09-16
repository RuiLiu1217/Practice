#include "LeetCode_StringProblems.hpp"
#include <functional>
#include <climits>
#include <algorithm>
#include <cctype>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <string>

std::string LC::_0005_LongestPalindromicSubstring::longestPalidrome(std::string s) {
    if(s.size() == 0) {
        return "";
    }
    int start = 0;
    int end = 0;

    std::function<int(int, int)> expandAroundCent = [&](int i, int j){
        while(i >= 0 && j < s.size() && s[i] == s[j]) {
            --i;
            ++j;
        }
        return j - i - 1; // not + 1 because both i and j are one step outside the palindromic.
    };

    for(int i = 0; i < s.size(); ++i) {
        int len1 = expandAroundCent(i, i); // Expand with one core center;
        int len2 = expandAroundCent(i, i + 1); // Expand with neighbor same;
        int l = std::max(len1, len2);
        if(l > end - start) {
            // The difficulty is how to calculate the start and end 
            // index according to the given center index
            start = i - (l - 1) / 2; 
            end = i + l / 2;
        }
    }
    return s.substr(start, end - start + 1);
}



std::string LC::_0006_ZigZagConversion::convert(std::string s, int numRows)
{
    if (numRows == 1)
    {
        return s;
    }
    int period = numRows + numRows - 2; // The big loop will be 0 1 2 3 2 1 | 0 1 2 3 2 1 ...
    int k = period / 2;                 // k = P / 2;
    std::vector<std::string> subRows(numRows, "");
    int rowIdx = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        rowIdx = k - std::abs(k - i % period);   // rowIdx = k - |k - i % P|;
        subRows[rowIdx] += s[i];
    }
    std::string res;
    for (auto su : subRows)
    {
        res += su;
    }
    return res;
}


/*
Google
This is not a good problem, like handing writing different edge cases
*/
int LC::_0008_StringToInteger::myAtoi(std::string str) {
    int i = 0;
    int num = 0;
    // Remove extra spaces
    while(i < str.length() && str[i] == ' ') {
        ++i;
    }
    // whether it is a negative number
    bool isNegative = false;
    if(str[i] == '-' || str[i] == '+') {
        isNegative = str[i] == '-'; // Whether it is a negative value
        i++;
    }

    // remove heading 0s
    while(i < str.length() && str[i] == '0') {
        ++i;
    }
    // Start converting
    while(i < str.length() && (str[i] - '0') <= 9 && (str[i] - '0') >= 0) {
        // !! This is very tricky!! See just before overflow, judge whether the last digit is larger than 7
        if((num > INT_MAX / 10 || (num == INT_MAX / 10 && str[i] - '0' > 7)))
            return isNegative ? INT_MIN :INT_MAX;
        num = ((num * 10) + (str[i] - '0'));
        ++i;
    }
    
    return isNegative ? (num * -1) : num; 
}



std::string LC::_0014_LongestCommonPrefix::longestCommonPrefix(std::vector<std::string>& strs) {
    std::string res;
    if(strs.empty()){
        return res;
    }

    size_t minL = strs[0].size();
    for(int i = 0; i != strs.size(); ++i) {
        if(strs[i].size() < minL) {
            minL = strs[i].size();
        }
    }

    if(minL == 0) {
        return res;
    }

    for(int j = 0; j != minL; ++j) {
        char key = strs[0][j];
        for(int i = 0; i != strs.size(); ++i) {
            if(strs[i][j] != key) {
                return res;
            }
        }
        res += key;
    }
    return res;
}


std::string LC::_0038_CountAndSay::countAndSay(int n) {
    std::string s = "1";
    std::function<std::string()> countOnce = [&](){
        int i = 0;
        int j = 0;
        std::string res;
        int c = 0;
        while(i < s.size()) {
            c = 0;
            while(j < s.size() && s[i] == s[j]) {
                ++j;
                ++c;
            }

            res += std::to_string(c);
            res += s[i];
            i = j;
        }
        return res;
    };

    for(int i = 0; i < n; ++i) {
        s = countOnce();
    }
    return s;
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
std::string LC::_0043_MultiplyStrings::multiply(std::string num1, std::string num2)
{
    const int L1 = num1.size();
    const int L2 = num2.size();
    if(num1 == "0" || num2 == "0") {
        return "0";
    }

    std::function<std::string(int)> mult = [&num1, &num2](int idx) {
        const int ic = num2[idx] - '0';
        std::string res;
        int carry = 0;
        for (int i = num1.size() - 1; i >= 0; --i) {
            int curC = (num1[i] - '0');
            int prd = curC * ic + carry;
            if (prd >= 10) {
                carry = prd / 10;
                prd = prd % 10;
            } else {
                carry = 0;
            }
            res += (prd + '0');
        }

        if (carry) {
            res += (carry + '0');
            carry = 0;
        }

        std::reverse(res.begin(), res.end());
        res += std::string(num2.size() - 1 - idx, '0');
        return res;
    };

    std::function<std::string(std::string, std::string)> add = [](std::string num1, std::string num2) {
        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());
        int minL = std::min(num1.size(), num2.size());
        int carry = 0;
        int i = 0;
        std::string res;
        for (i = 0; i < minL; ++i) {
            int v = ((num1[i] - '0') + (num2[i] - '0') + carry);
            if (v >= 10) {
                carry = 1;
                v -= 10;
            } else {
                carry = 0;
            }
            res += ('0' + v);
        }
        if (minL < num1.size()) {
            for (; i < num1.size(); ++i) {
                int v = (carry + (num1[i] - '0'));
                if (v >= 10) {
                    carry = 1;
                    v -= 10;
                } else {
                    carry = 0;
                }
                res += ('0' + v);
            }
            if (carry) {
                res += (carry + '0');
            }
        } else if (minL < num2.size()) {
            for (; i < num2.size(); ++i) {
                int v = (carry + (num2[i] - '0'));
                if (v >= 10) {
                    carry = 1;
                    v -= 10;
                } else {
                    carry = 0;
                }
                res += ('0' + v);
            }
            if (carry) {
                res += (carry + '0');
            }
        } else if (carry != 0) {
            res += (carry + '0');
        }

        std::reverse(res.begin(), res.end());
        return res;
    };


    if (L2 < L1) {
        return multiply(num2, num1);
    } else {
        std::string res;
        for (int i = 0; i < L2; ++i) {
            std::string p = mult(L2 - 1 - i);
            res = add(res, p);
        }
        return res;
    }
}

int LC::_0058_LengthOfLastWord::lengthOfLastWord(std::string s) {
    int len = 0;
    int t = s.size() - 1;
    while(t >= 0 && s[t] == ' ') {
        --t;
    }
    while(t >= 0 && s[t] != ' ') {
        ++len;
        --t;
    }
    return len;
}


// Facebook, Microsoft
// note: usage of "std::isalnum" is a alphabetical or number "toupper, tolower"
bool LC::_0125_ValidPalindrome::isPalindrome(std::string s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) { // Move 2 pointers from each end until they collide
        while (!std::isalnum(s[i]) && i < j) i++; // Increment left pointer if not alphanumeric
        while (!std::isalnum(s[j]) && i < j) j--; // Decrement right pointer if no alphanumeric
        if (std::toupper(s[i]) != std::toupper(s[j])) return false; // Exit and return error if not match
    }
    return true;
}


int LC::_0150_EvaluateReversePolishNotation::evalRPN(std::vector<std::string>& tokens) {
    std::stack<int> res;
    for(auto s : tokens) {
        if(s == "+" || s == "-" || s == "*" || s == "/") {
            if(res.empty()) {
                return INT_MIN;
            } else {
                int b = res.top();
                res.pop();
                if(res.empty()) {
                    return INT_MIN;
                }
                int a = res.top();
                res.pop();
                
                int c = 0;
                if(s == "+") {
                    c = a + b;
                } else if(s == "-") {
                    c = a - b;
                } else if(s == "*") {
                    c = a * b;
                } else if(s == "/") {
                    c = a / b;
                }
                res.push(c);
            }
        } else {
            res.push(std::stoi(s));
        }
    }
    return res.top();
}

// Not O(1) space complexity solution is much easier than O(1) space complexity
std::string LC::_0151_ReverseWordsInAString::reverseWords(std::string s) {
    int i = 0;
    std::stack<char> st;
    std::string res;
    s += " ";
    while(i < s.size()) {
        if(s[i] == ' ') {
            std::string temp;
            while(!st.empty()) {
                temp += st.top();
                st.pop();
            }
            if(temp.size() > 0) {
                if(res.size() > 0) {
                    res += " ";
                }
                res += temp;
            }
        } else {
            st.push(s[i]);
        }
        ++i;
    }
    std::reverse(res.begin(), res.end());
    return res;
}

std::string LC::_0151_ReverseWordsInAString::reverseWords_O1(std::string s) {
    int i = 0;
    int j = 0;
    int l = 0;
    int len = s.length();
    int wordcount = 0;

    std::function<void(std::string& , int , int )> reverseW = [&](std::string& s, int i, int j) {
        while(i < j) {
            std::swap(s[i],s[j]);
            ++i;
            --j;
        }
    };

    while(true) {
        while(i < len && s[i] == ' ') {
            ++i;
        }
        if(i == len) {
            break;
        }
        if(wordcount) {
            s[j++] = ' ';
        }
        l = j;
        while(i < len && s[i] != ' ') {
            s[j] = s[i];
            j++;
            i++;
        }
        reverseW(s, l, j-1);
        wordcount++;
    }
    return s;
}


void LC::_0186_ReverseWordsInAStringII::reverseWords(std::vector<char>& s) {
    int startIdx = 0;
    int endIdx = 0;
    while(endIdx < s.size()) {
        while(endIdx < s.size() && s[endIdx] != ' ') {
            ++endIdx;
        }

        int i = startIdx;
        int j = endIdx - 1;
        while(i < j) {
            std::swap(s[i++], s[j--]);
        }
        startIdx = endIdx + 1;
        endIdx = startIdx;
    }

    int i = 0;
    int j = s.size() - 1;
    while(i < j) {
        std::swap(s[i++], s[j--]);
    }
}


std::vector<std::string> LC::_0187_RepeatedDNASequences::findRepeatedDNASequences(std::string s) {
    std::string tmp;
    for(int i = 0; i < 10; ++i) {
        tmp += s[i];
    }
    std::unordered_set<std::string> strPatt;
    std::unordered_set<std::string> res;
    strPatt.insert(tmp);
    for(int i = 10; i < s.size(); ++i) {
        tmp += s[i];
        tmp = tmp.substr(1);
        if(strPatt.count(tmp)) {
            res.insert(tmp);
        } else {
            strPatt.insert(tmp);
        }
    }
    return std::vector<std::string>(begin(res), end(res));
}

// AGCT 四个字母的ascii码的二进制表示最后三位不一样，因此每个字母只需要三个位就能区分，因此10个字母就可以表示成不长于32位的int32
// 一个字母的最后三位可以用 x[i] & 7 来提取.
std::vector<std::string> LC::_0187_RepeatedDNASequences::findRepeatedDNASequence_NoMap(std::string s) {
    std::unordered_map<int, int> m;
    std::vector<std::string> r;
    int t = 0;
    int i = 0;
    int ss = s.size();
    if(s.size() < 10) {
        return {};
    }
    while(i < 9) {
        t = t << 3 | s[i++] & 7; // Calculate the first 10 character's map
    }
    while(i < ss) {
        if(m[t = t << 3 & 0x3FFFFFFF | s[i++] & 7]++ == 1) {
            r.push_back(s.substr(i - 10, 10));
        }
        return r;
    }
    return r;
}


// Tag: hash, double hash
bool LC::_0205_IsomorphicStrings::isIsomorphic(std::string s, std::string t) {
    if(s.size() != t.size()) {
        return false;
    }
    std::map<char, char> strMap;
    std::map<char, char> strMap2;
    for(int i = 0; i != s.size(); ++i) {
        auto iter = strMap.find(s[i]);
        auto iter2 = strMap2.find(t[i]);
        if(iter == strMap.end()) {
            strMap[s[i]] = t[i];
        } else {
            if (iter->second != t[i]) {
                return false;
            }
        }
        if(iter2 == strMap2.end()) {
            strMap2[t[i]] = s[i];
        } else {
            if(iter2->second != s[i]) {
                return false;
            }
        }
    }
    return true;
}

// Tag: Trie, string
// Todo: important
LC::_0208_ImplementTrie::_0208_ImplementTrie() {}    
void LC::_0208_ImplementTrie::insert(std::string word) {
    _0208_ImplementTrie* p = this;
    for(int i = 0; i < word.size(); ++i) {
        if(p->children.find(word[i]) == p->children.end()) {
            p->children[word[i]] = new _0208_ImplementTrie();
        }
        p = p->children[word[i]];
    }
    p->isWord = true;   
}
    
bool LC::_0208_ImplementTrie::search(std::string word) {
    _0208_ImplementTrie* p = this;
    for(int i = 0; i < word.size(); ++i) {
        if(p->children.find(word[i]) == p->children.end()) {
            return false;
        } else {
            p = p->children[word[i]];
        }
    }
    return p && p->isWord;
}

bool LC::_0208_ImplementTrie::startsWith(std::string prefix) {
    _0208_ImplementTrie* p = this;
    for(int i = 0; i < prefix.size(); ++i) {
        if(p->children.find(prefix[i]) == p->children.end()) {
            return false;
        } else {
            p = p->children[prefix[i]];
        }
    }
    return (p != nullptr);
}


// Copy from a solution
// Trie implementation
void LC::_0211_AddAndSearchWordDataStructureDesign::addWord(std::string word) {
    TrieNode* node = root;
    for(char c : word) {
        if(!node->children[c - 'a']) {
            node->children[c - 'a'] = new TrieNode();
        }
        node = node->children[c - 'a'];
    }
    node->word = true;
}

bool LC::_0211_AddAndSearchWordDataStructureDesign::search(std::string word) {
    return search(word.c_str(), root);
}

bool LC::_0211_AddAndSearchWordDataStructureDesign::search(const char* word, TrieNode* node) {
    for(int i = 0; word[i] && node; ++i) {
        if(word[i] != '.') {
            node = node->children[word[i] - 'a'];
        } else {
            TrieNode* tmp = node;
            for(int j = 0; j < 26; ++j) {
                node = tmp->children[j];
                if(search(word + i + 1, node)) {
                    return true;
                }
            }
        }
    }
    return node && node->word;
}

// There is also dynamic programming solution which is very elegant: 
// https://leetcode.com/problems/sliding-window-maximum/solution/
std::vector<int> LC::_0239_SlidingWindowMaximum::maxSlidingWindow(std::vector<int>& nums, int k) {
    if(k == 1) {
        return nums;
    }
    std::deque<int> qIndex; // 双向队列
    std::vector<int> result;
    for(int i = 0; i < nums.size(); ++i) {
        if(qIndex.empty()) {
            qIndex.push_back(i);
        } else {
            while(!qIndex.empty() && nums[qIndex.back()] < nums[i]) {
                qIndex.pop_back();
            }
            qIndex.push_back(i);
        }
        
        while(!qIndex.empty() && i - qIndex.front() >= k) {
            qIndex.pop_front();
        }
        if(i >= k - 1) {
            result.push_back(nums[qIndex.front()]);
        }
        
    }
    return result;
}


bool LC::_0242_ValidAnagram::isAnagram(std::string s, std::string t) {
    int c1[26] = {0};
    int c2[26] = {0};
    if(s.size() != t.size()) {
        return false;
    }
    for(int i = 0; i < s.size(); ++i) {
        ++c1[s[i] - 'a'];
        ++c2[t[i] - 'a'];
    }
    for(int i = 0; i < 26; ++i) {
        if(c1[i] != c2[i]) {
            return false;
        }
    }
    return true;
}

bool LC::_0246_StrobogrammaticNumber::isStrobogrammatic(std::string num) {
    std::unordered_map<char, char> map;
    map['0'] = '0';
    map['1'] = '1';
    map['2'] = '#';
    map['3'] = '#';
    map['4'] = '#';
    map['5'] = '#';
    map['6'] = '9';
    map['7'] = '#';
    map['8'] = '8';
    map['9'] = '6';
    std::string res;
    for(auto c : num) {
        if(map[c] == '#') {
            return false;
        }
        res += map[c];            
    }
    std::reverse(begin(res), end(res));
    return res == num;
}


std::vector<std::string> LC::_0247_StrobogrammaticNumberII::findStrobogrammatic(int n) {
    if(n == 0) {
        return {};
    }
    if(n == 1) {
        return {"0", "1", "8"};
    }
    if(n == 2) {
        return {"69", "96", "88", "11"};
    }
    std::unordered_set<char> set{'0', '1', '6', '8', '9'};
    std::unordered_map<char, char> map;
    map['0'] = '0';
    map['1'] = '1';
    map['6'] = '9';
    map['8'] = '8';
    map['9'] = '6';

    int N = n / 2;
    std::vector<std::string> halfRes;
    std::string tmp;
    DFS(set, 0, N, tmp, halfRes);
    std::vector<std::string> res;

    for(int i = 0; i < halfRes.size(); ++i) {
        std::string left = halfRes[i];
        std::string right;
        for(char c : left) {
            right += map[c];
        }
        std::reverse(begin(right), end(right));
        if(n % 2) {
            res.push_back(left + "1" + right);
            res.push_back(left + "8" + right);
            res.push_back(left + "0" + right);
        } else {
            res.push_back(left + right);
        }
    }
    return res;

}

void LC::_0247_StrobogrammaticNumberII::DFS(std::unordered_set<char> set, int curLen, int n, std::string tmp, std::vector<std::string>& res) {
    if(curLen == n) {
        res.push_back(tmp);
        return;
    }

    for(char c : set) {
        if(curLen == 0 && c == '0') { //!! number cannot start with 0
            continue;
        }
        tmp.push_back(c);
        DFS(set, curLen+1, n, tmp, res);
        tmp.pop_back();
    }
}

bool LC::_0266_PalinndromePermutation::canPermutePalindrome(std::string s) {
    std::vector<int> charMap(256, 0);
    for(char c : s) {
        if(charMap[c] == 1) {
            --charMap[c];
        } else {
            charMap[c] = 1;
        }
    }

    int countOne = 0;
    for(int i = 0; i < 256; ++i) {
        if(charMap[i] == 1) {
            ++countOne;
            if(countOne > 1) {
                return false;
            }
        }
    }
    return true;
}

std::string LC::_0544_OutputContestMatches::findContestMatch(int n) {
    std::vector<std::string> t;
    for(int i = 0; i < n; ++i) {
        t.emplace_back(std::to_string(i+1));
    }

    std::function<void()> half = [&](){
        int i = 0;
        int j = t.size() - 1;
        while(i < j) {
            t[i] = "(" + t[i] + "," + t[j] + ")";
            ++i;
            --j;
        }
        t.resize(t.size()/2);
    };

    while(t.size() > 1) {
        half();
    }
    return t[0];
}

std::vector<std::string> LC::_0816_AmbiguousCoordinates::ambiguousCoordinates(std::string S) {
    std::function<bool(const std::string&)> isAllZero = [] (const std::string& s) {
        for(char c : s) {
            if(c != '0') {
                return false;
            }
        }
        return true;
    };

    std::function<bool(const std::string&)> endWithZero = [] (const std::string& s) {
        return s.back() == '0';
    };

    // Edge cases driven problem!
    std::function<std::vector<std::string>(std::string)> validNum = [&] (std::string s) {
        std::vector<std::string> res;
        if(s.length() == 1) {
            return std::vector<std::string>{s};
        } else {
            if(s[0] == '0') {
                if(!isAllZero(s.substr(1)) && !endWithZero(s.substr(1))) {
                    std::string t = s.substr(0, 1) + "." + s.substr(1);
                    return std::vector<std::string>{t};
                } else {
                    return std::vector<std::string>{};
                }
            } else {
                res.push_back(s);
                for(int l = 1; l < s.size(); ++l) {
                    if(!isAllZero(s.substr(1)) && !endWithZero(s.substr(1))) {
                        std::string t = s.substr(0, l) + "." + s.substr(l);
                        res.push_back(t);
                    }                    
                }
                return res;
            }
        }
    };


    std::string subS = S.substr(1, S.size()-2);
    std::vector<std::string> res;
    for(int l = 1; l < subS.size(); ++l) {
        std::string lft = subS.substr(0, l);
        std::string rgh = subS.substr(l);
        std::vector<std::string> lv = validNum(lft);
        std::vector<std::string> rv = validNum(rgh);
        if(!lv.empty() && !rv.empty()) {
            for(auto& l : lv) {
                for(auto& r : rv) {
                    std::string t = "(" + l + ", " + r + ")";
                    res.push_back(t);
                }
            }
        }
    }
    return res;
}