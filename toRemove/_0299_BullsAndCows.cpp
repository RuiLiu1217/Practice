#include "headers.hpp"

std::string LeetCode::_0299_BullsAndCows::getHint(std::string secret, std::string guess) {
    std::unordered_map<char, int> secretMap;
    for(char c : secret) {
        ++secretMap[c];
    }
    
    std::unordered_map<char, int> guessedMap;
    int B = 0;
    for(char c : guess) {
        if(secretMap.count(c)) {
            ++guessedMap[c];
            ++B;
            --secretMap[c];
        }
        if(secretMap[c] == 0) {
            secretMap.erase(c);
        }
    }
    int A = 0;
    for(int i = 0; i < secret.size(); ++i) {
        if(secret[i] == guess[i]) {
            ++A;
            --B;
            --guessedMap[secret[i]];
            if(guessedMap[secret[i]] == 0) {
                guessedMap.erase(secret[i]);
            }
        }
    }
    return std::to_string(A) + "A" + std::to_string(B) + "B";
}