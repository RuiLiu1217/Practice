#include "headers.hpp"
// Copy from solution
int LeetCode::_0318_MaximumProductOfWordLengths::maxProduct(std::vector<std::string>& words) {
    if(words.size() == 0) {
        return 0;
    }
    const int len = words.size();
    std::vector<int> myMap(len);
    for(int i = 0; i < len; ++i) {
        std::string tmp = words[i];
        myMap[i] = 0;
        for(int j = 0; j != tmp.length(); ++j) {
            myMap[i] |= (1 << (tmp[i] - 'a')); // convert a string to a number;
        }
    }
    int maxProduct = 0;
    for(int i = 0; i < len; ++i) {
        for(int j = i + 1; j < len; ++j) {
            if(int(myMap[i] & myMap[j]) == 0) {
                int prod = words[i].length() * words[j].length();
                if(prod > maxProduct) {
                    maxProduct = prod;
                }
            }
        }
    }
    return maxProduct;
}