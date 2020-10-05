#include "LeetCode_StringProblems.hpp"
#include <functional>
#include <climits>
#include <numeric>
#include <algorithm>
#include <cctype>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <sstream>
#include <functional>
#include <string>
#include <math.h>


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


std::vector<std::string> LC::_0293_FlipGame::generatePossibleNextMoves(std::string s) {
    std::vector<std::string> res;
    if(s.empty()) {
        return {};
    }

    for(int i = 0; i < s.size() - 1; ++i) {
        if(s[i] == '+' && s[i+1] == '+') {
            s[i] = '-';
            s[i+1] = '-';
            res.push_back(s);
            s[i] = '+'; // recover
            s[i+1] = '+';
        }
    }
    return res;
}

void LC::_0344_ReverseString::reverseString(std::vector<char>& s) {
    int i = 0;
    int j = s.size() - 1;
    while(i < j) {
        std::swap(s[i++], s[j--]);
    }
}

std::string LC::_0345_ReverseVowelsOfAString::reverseVowels(std::string s) {
    int i = 0;
    int j = s.size() - 1;
    while(i < j) {
        while(i < j && !isVowel(s[i])) {
            ++i;
        }
        while(i < j && !isVowel(s[j])) {
            --j;
        }
        if(i < j) {
            std::swap(s[i], s[j]);
            ++i;
            --j;
        }
    }
    return s;
}

bool LC::_0383_RansomNote::canConstruct(std::string ransomNote, std::string magazine) {
    if(ransomNote.size() > magazine.size()) {
        return false;
    }
    
    std::unordered_map<char, int> magMap;
    for(char c : magazine) {
        ++magMap[c];
    }
    
    for(char c : ransomNote) {
        if(magMap[c] <= 0) {
            return false;
        } else {
            --magMap[c];
        }
    }
    return true;
}

int LC::_0387_FirstUniqueCharacterInAString::firstUniqChar(std::string s) {
    std::vector<std::pair<int, int>> index(26);
    for(int i = 0; i < s.size(); ++i) {
        if(index[s[i] - 'a'].second == 0) {
            index[s[i] - 'a'] = {i, 1};
        } else {
            ++index[s[i] - 'a'].second;
        }
    }
    int idx = INT_MAX;
    for(int i = 0; i < 26; ++i) {
        if(index[i].second == 1) {
            idx = std::min(idx, index[i].first);
        }
    }
    return idx == INT_MAX ? -1 : idx;
}

int LC::_0409_LongestPalindrome::longestPalindrome(std::string s) {
    std::unordered_map<char, int> M;
    for(char c : s) {
        ++M[c];
    }
    int length = 0;
    for(auto& m : M) {
        if(m.second % 2 == 0) {
            length += m.second;
            m.second = 0;
        } else {
            if(m.second >= 3) {
                length += ((m.second / 2) * 2);
                m.second = 1;                    
            }
        }
    }
    
    for(auto& m : M) {
        if(m.second == 1) {
            length += 1;
            break;
        }
    }
    return length;
}

std::vector<std::string> LC::_0412_FizzBuzz::fizzBuzz(int n) {
    std::vector<std::string> res;
    for(int i = 1; i <= n; ++i) {
        if(!(i%15)) {
            res.push_back("FizzBuzz");
            continue;
        }
        if(!(i%3)) {
            res.push_back("Fizz");
            continue;
        }
        if(!(i%5)) {
            res.push_back("Buzz");
            continue;
        }
        res.push_back(std::to_string(i));
    }
    return res;
}

// Facebook
std::string LC::_0415_AddStrings::addStrings(std::string num1, std::string num2) {
    std::reverse(begin(num1), end(num1));
    std::reverse(begin(num2), end(num2));
    const int minL = std::min(num1.size(), num2.size());
    int carry = 0;
    std::string res;
    int i = 0;
    for(i = 0; i < minL; ++i) {
        int t = (num1[i] - '0' + num2[i] - '0' + carry);
        if(t >= 10) {
            carry = 1;
            t -= 10;
        } else {
            carry = 0;
        }
        res += ('0' + t);
    }
    while(i < num1.size()) {
        int t = (num1[i] - '0' + carry);
        if(t >= 10) {
            carry = 1;
            t -= 10;
        } else {
            carry = 0;
        }
        res += ('0' + t);
        ++i;
    }
    while(i < num2.size()) {
        int t = (num2[i] - '0' + carry);
        if(t >= 10) {
            carry = 1;
            t -= 10;
        } else {
            carry = 0;
        }
        res += ('0' + t);
        ++i;
    }
    if(carry) {
        res += '1';
    }
    std::reverse(begin(res), end(res));
    return res;
}

std::string LC::_0423_ReconstructOriginalDigitFromEnglish::originalDigits(std::string s) {
    std::unordered_map<char, int> Map;
    std::vector<int> resCount(10, 0);
    for(auto& c : s) {
        ++Map[c];
    }
    if(Map.find('z') != Map.end() && Map['z'] > 0) {
        int count = Map['z'];
        resCount[0] += count;
        Map['z'] = 0;
        Map['e'] -= count;
        Map['r'] -= count;
        Map['o'] -= count;            
    }
    if(Map.find('w') != Map.end() && Map['w'] > 0) {
        int count = Map['w'];
        resCount[2] += count;
        Map['w'] = 0;
        Map['t'] -= count;
        Map['o'] -= count;
    }
    if(Map.find('u') != Map.end() && Map['u'] > 0) {
        int count = Map['u'];
        resCount[4] += count;
        Map['u'] = 0;
        Map['f'] -= count;
        Map['o'] -= count;
        Map['r'] -= count;
    }
    if(Map.find('x') != Map.end() && Map['x'] > 0) {
        int count = Map['x'];
        resCount[6] += count;
        Map['x'] = 0;
        Map['s'] -= count;
        Map['i'] -= count;
    }
    if(Map.find('g') != Map.end() && Map['g'] > 0) {
        int count = Map['g'];
        resCount[8] += count;
        Map['g'] = 0;
        Map['e'] -= count;
        Map['i'] -= count;
        Map['h'] -= count;
        Map['t'] -= count;
    }
    if(Map.find('r') != Map.end() && Map['r'] > 0) {
        int count = Map['r'];
        resCount[3] += count;
        Map['r']  = 0;
        Map['t'] -= count;
        Map['h'] -= count;
        Map['e'] -= count;
        Map['e'] -= count;
    }
    if(Map.find('s') != Map.end() && Map['s'] > 0) {
        int count = Map['s'];
        resCount[7] += count;
        Map['s'] = 0;
        Map['e'] -= count;
        Map['v'] -= count;
        Map['e'] -= count;
        Map['n'] -= count;
    }
    if(Map.find('v') != Map.end() && Map['v'] > 0) {
        int count = Map['v'];
        resCount[5] += count;
        Map['v'] = 0;
        Map['f'] -= count;
        Map['i'] -= count;
        Map['e'] -= count;
    }
    if(Map.find('o') != Map.end() && Map['o'] > 0) {
        int count = Map['o'];
        resCount[1] += count;
        Map['o'] = 0;
        Map['n'] -= count;
        Map['e'] -= count;
    }
    if(Map.find('i') != Map.end() && Map['i'] > 0) {
        int count = Map['i'];
        resCount[9] += count;
        Map['i'] = 0;
        Map['n'] -= count;
        Map['n'] -= count;
        Map['e'] -= count;
    }
    std::string res;
    for(int i = 0; i < 10; ++i) {
        if(resCount[i] > 0) {
            for(int r = 0; r < resCount[i]; ++r) {
                res += std::to_string(i);
            }
        }
    }
    return res;
}


// Facebook 
std::vector<int> LC::_0438_FindAllAnagramsInAString::findAnagrams(std::string s, std::string p) {
    std::vector<int> sv(26, 0);
    std::vector<int> pv(26, 0);
    
    std::vector<int> res;
    if(s.size() < p.size())
        return res;
    
    for(int i = 0; i < p.size(); ++i) {
        ++sv[s[i] - 'a'];
        ++pv[p[i] - 'a'];
    }
    if(pv == sv) {
        res.push_back(0);
    }
    
    for(size_t i = p.size(); i < s.size(); ++i) {
        ++sv[s[i] - 'a'];
        --sv[s[i-p.size()] - 'a'];
        if(sv == pv) {
            res.push_back(i-p.size()+1);
        }
    }
    return res;        
}

std::string LC::_0482_LicenseKeyFormatting::licenseKeyFormatting(std::string S, int K) {
    std::string res;
    int count = 0;
    for(int i = S.size() - 1; i >= 0; --i) {
        if(S[i] == '-') {
            continue;
        } else {
            if(S[i] <= 'z' && S[i] >= 'a') {
                S[i] += ('A' - 'a');
            }
            res += S[i];
            ++count;
            if(count == K) {
                res += '-';
                count = 0;
            }
        }
    }
    std::reverse(begin(res), end(res));
    int i = 0;
    while(res[i] == '-') {
        ++i;
    }
    return res.substr(i);
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


// Sorting the string from large to small, there is a tricky point
std::string LC::_0179_LargestNumber::largestNumber(std::vector<int>& nums) {
    std::vector<std::string> numstr;
    std::for_each(begin(nums), end(nums), [&](int n){
        numstr.emplace_back(std::to_string(n));
    });
    std::sort(begin(numstr), end(numstr), [](std::string& s1, std::string& s2){
        return s1 + s2 > s2 + s1;
    });
    std::string res;
    for(auto& n : numstr) {
        res += n;
    }
    int i = 0;
    while(res[i] == '0' && i < res.size() - 1) {
        ++i;
    }
    return res.substr(i);
}


int LC::_0165_CompareVersionNumbers::compareVersion(std::string version1, std::string version2) {
    std::function<std::vector<int>(std::istringstream& iss)> convert = [](std::istringstream& iss) {
        std::vector<int> res;
        std::string token;
        while(getline(iss, token, '.')) {
            res.push_back(std::stoi(token));
        }
        return res;
    };

    std::istringstream iss1(version1);
    std::istringstream iss2(version2);
    std::vector<int> vs1 = convert(iss1);
    std::vector<int> vs2 = convert(iss2);
    int minL = std::min(vs1.size(), vs2.size());
    int i = 0;
    for(; i < minL; ++i) {
        if(vs1[i] < vs2[i]) {
            return -1;
        } else if(vs1[i] > vs2[i]) {
            return 1;
        }
    }
    if(vs1.size() > minL) {
        for(i = minL; i < vs1.size(); ++i) {
            if(vs1[i] != 0) {
                return 1;
            }
        }
    }
    if(vs2.size() > minL) {
        for(i = minL; i < vs2.size(); ++i) {
            if(vs2[i] != 0) {
                return -1;
            }
        }
    }
    return 0;
}


// Simple Calculator 
// !Copy from the solution, need to review carefully.
void LC::_0224_BasicCalculator::pushNum(std::stack<double>& numStack, std::string& tmp) {
    if(!tmp.empty()) {
        numStack.push(std::stod(tmp));
        tmp.clear();
    }
}

void LC::_0224_BasicCalculator::cal(std::stack<double>& numStack, char op) {
    double rOpNum = numStack.top();
    numStack.pop();
    double lOpNum = numStack.top();
    numStack.pop();
    int res = 0;
    switch(op) {
        case '+' :
            res = lOpNum + rOpNum;
            break;
        case '-' :
            res = lOpNum - rOpNum;
            break;
        case '*' :
            res = lOpNum * rOpNum;
            break;
        case '/' :
            res = lOpNum / rOpNum;
            break;
    }
    numStack.push(res);
}

int LC::_0224_BasicCalculator::priority(char op) {
    int p = 0;
    if(op == '(') {
        p = 1;
    }
    if(op == '+' || op == '-') {
        p = 2;
    }
    if(op == '*' || op == '/') {
        p = 3;
    }
    return p;
}

int LC::_0224_BasicCalculator::calculate(std::string s) {
    size_t startIdx = 0;
    size_t endIdx = s.size() - 1;
    while(s[startIdx] == ' ') {
        ++startIdx;
    }
    while(s[endIdx] == ' ') {
        --endIdx;
    }

    std::stack<double> numStack;
    std::stack<char> opStack;
    std::string tmp;
    for(size_t i = startIdx; i <= endIdx; ++i) {
        char token = s[i];
        if(token == '+' || token == '-' || token == '*' || token == '/') { // is operator
            pushNum(numStack, tmp);
            if(opStack.empty()) {
                opStack.push(token);
            } else {
                int curPri = priority(token); // current operator's priority
                char topOp = opStack.top();   // operator in the opStack
                int topPri = priority(topOp); // opStack top operator's priority
                if(curPri > topPri) {         // if current operator's priority is higher than opStack top operator's priority
                    opStack.push(token);      // push current operator to the stack
                } else {                      // otherwise 
                    while(curPri <= topPri) { // calculate based on the topPriority until the current operator's priority is higher than opStack top operator's priority
                        opStack.pop();
                        cal(numStack, topOp);
                        if(opStack.size() > 0) {
                            topOp = opStack.top();
                            topPri = priority(topOp);
                        } else {
                            break;
                        }
                    }
                    opStack.push(token);
                }
            }
        } else if(token == '(') {
            pushNum(numStack, tmp);
            opStack.push(token); // always push "(" to the stack
        } else if(token == ')') {
            pushNum(numStack, tmp);
            // Calculate until see the '('
            while(!opStack.empty() && opStack.top() != '(') {
                char topOp = opStack.top();
                cal(numStack, topOp);
                opStack.pop();
            }
            opStack.pop(); // pop "(";
        } else if(token >= '0' && token <= '9') {
            tmp += token;
        } else {
            continue;
        }
    }

    if(!tmp.empty()) {
        numStack.push(std::stod(tmp));
        tmp.clear();
    }
    while(!opStack.empty()) {
        char topOp = opStack.top();
        cal(numStack, topOp);
        opStack.pop();
    }
    return numStack.top();
}


std::vector<int> LC::_0241_DifferentWaysToAddParentheses::diffWaysToCompute(std::string input) {
    return diffWaysToComp(input, 0, input.size());;
}

std::vector<int> LC::_0241_DifferentWaysToAddParentheses::diffWaysToComp(const std::string& input, int start, int end) {
    if(map.find(input.substr(start, end-start)) != map.end()) { // if the expression is already evaluated
        return map[input.substr(start, end-start)];
    }
    if(start == end) {
        return {};
    }
    
    std::string su = input.substr(start, end-start); 
    if(su.find("+") == std::string::npos && su.find("-") == std::string::npos && su.find("*") == std::string::npos) { // it is a number
        return map[su] = {std::stoi(su)};
    }

    std::vector<int> res;
    for(int i = start; i < end; ++i) {
        if(input[i] == '+' || input[i] == '-' || input[i] == '*') { // if we saw an operator, split it there
            const auto& left = diffWaysToComp(input, start, i);
            const auto& right = diffWaysToComp(input, i+1, end);
            for(auto l : left) { //for each left evaluated value
                for(auto r : right) { // for each right evaluated value
                    if(input[i] == '+') {
                        res.push_back(l + r);
                    }
                    if(input[i] == '-') {
                        res.push_back(l - r);
                    }
                    if(input[i] == '*') {
                        res.push_back(l * r);
                    }
                }
            }
            
        }
    }
    return map[input.substr(start, end-start)] = res; // put the evaluated value to a map
}

int LC::_0467_UniqueSubstringsInWraparoundString::findSubstringInWraproundString(std::string p) {
    std::vector<int> cnt(26, 0);
    int len = 0;
    for (int i = 0; i < p.size(); ++i) {
        if (i > 0 && (p[i] == p[i - 1] + 1 || p[i - 1] - p[i] == 25)) {
            ++len;
        } else {
            len = 1;
        }
        // Inspired by one trick!
        // 我们看abcd这个字符串，以d结尾的子字符串有abcd, bcd, cd, d，
        // 那么我们可以发现bcd或者cd这些以d结尾的字符串的子字符串都包含
        // 在abcd中，那么我们知道以某个字符结束的最大字符串包含其他以该
        // 字符结束的字符串的所有子字符串
        cnt[p[i] - 'a'] = std::max(cnt[p[i] - 'a'], len);
    }
    return std::accumulate(cnt.begin(), cnt.end(), 0);
}

bool LC::_0567_PermutationInString::checkInclusion(std::string s1, std::string s2) {
    std::vector<int> patS1(26, 0);
    for(int i = 0; i < s1.size(); ++i) {
        ++patS1[s1[i] - 'a'];
    }
    if(s2.size() < s1.size()) {
        return false;
    }
    std::vector<int> patS2(26, 0);
    for(int i = 0; i < s1.size(); ++i) {
        ++patS2[s2[i] - 'a'];
    }
    
    for(int i = s1.size(); i < s2.size(); ++i) {
        if(patS1 == patS2) {
            return true;
        }
        ++patS2[s2[i] - 'a'];
        --patS2[s2[i-s1.size()] - 'a'];
    }
    return patS1 == patS2;
}

// Use stringstream to simplify the problem.
std::string LC::_0592_FractionAdditionAndSubtraction::fractionAddition(std::string expression) {
    std::stringstream iss(expression);
    int A = 0;
    int B = 1;
    int a = 0;
    int b = 0;
    char slash;
    while(iss>>a>>slash>>b) {
        A = A * b + B * a;
        B = B * b;
        int g = std::gcd(std::abs(A), std::abs(B));
        A /= g;
        B /= g;
    }
    return std::to_string(A) + "/" + std::to_string(B);
}


// use mask to help solve problems we can also use the interval 
// merge technique to solve it.
std::string LC::_0616_AddBoldTagInString::addBoldTag(std::string s, std::vector<std::string>& dict) {
    std::vector<std::vector<int>> intervals = generateIntervals(s, dict);
    intervals = mergeIntervals(intervals);

    std::string res = s;
    for(auto it = intervals.crbegin(); it != intervals.crend(); ++it) { // add the tag in a reverse order
        res.insert((*it)[1], "</b>");
        res.insert((*it)[0], "<b>");
    }
    return res;
}

// ! Can be extend to multiple char delete solution
// ! inspired by the solution
bool LC::_0680_ValidPalindromeII::validPalindrome(std::string s) {
    std::function<bool(int, int, int)> isvalid = [&](int i, int j, int d) {
        if(i >= j) {
            return true;
        }
        if(s[i] == s[j]) {
            return isvalid(i + 1, j - 1, d);
        } else {
            if(d == 0) {
                return false;
            } else {
                return isvalid(i + 1, j, d-1) || isvalid(i, j-1, d-1);
            }
        }
    };

    return isvalid(0, s.size() - 1, 1);
}

std::string LC::_0709_ToLowerCase::toLowerCase(std::string str) {
    for(char& c : str) {
        if(c >= 'A' && c <= 'Z') {
            c += ('a' - 'A');
        } 
    }
    return str;
}

std::string LC::_0758_BoldWordsInString::boldWords(std::vector<std::string>& words, std::string S) {
    std::vector<bool> isBold(S.length(), false);
    for(int i = 0; i < S.length(); ++i) {
        for(std::string& w : words) {
            int wl = w.length();
            if(S.substr(i, wl) == w) {
                setBold(isBold, i, wl);
            }
        }
    }
    
    std::string res;
    for(int i = 0; i < S.size(); ++i) {
        if(!isBold[i]) {
            res += S[i];
            continue;
        }
        int endP = i;
        while(endP < S.length() && isBold[endP]) {
            ++endP;
        }
        res += "<b>" + S.substr(i, endP - i) + "</b>";
        i = endP - 1;
    }
    return res;
}

void LC::_0758_BoldWordsInString::setBold(std::vector<bool>& isBold, int i, int wl) {
    for(int t = 0; t < wl; ++t) {
        if(t + i < isBold.size()) {
            isBold[t + i] = true;
        }
    }
}

int LC::_0804_UniqueMorseCodeWords::uniqueMorseRepresentations(std::vector<std::string>& words) {
    std::unordered_map<char, std::string> mmap;
    mmap['a'] = ".-";
    mmap['b'] = "-..."; 
    mmap['c'] = "-.-.";
    mmap['d'] = "-..";
    mmap['e'] = ".";
    mmap['f'] = "..-.";
    mmap['g'] = "--.";
    mmap['h'] = "....";
    mmap['i'] = "..";
    mmap['j'] = ".---";
    mmap['k'] = "-.-";
    mmap['l'] = ".-..";
    mmap['m'] = "--";
    mmap['n'] = "-.";
    mmap['o'] = "---";
    mmap['p'] = ".--.";
    mmap['q'] = "--.-";
    mmap['r'] = ".-.";
    mmap['s'] = "...";
    mmap['t'] = "-";
    mmap['u'] = "..-";
    mmap['v'] = "...-";
    mmap['w'] = ".--";
    mmap['x'] = "-..-";
    mmap['y'] = "-.--";
    mmap['z'] = "--..";
    int totalCount = 0;
    std::unordered_set<std::string> resString;
    for(std::string& word : words) {
        std::string res = "";
        for(char c : word) {
            res += mmap[c];
        }
        resString.insert(res);
    }
    return resString.size();
}