#include "headers.hpp"

int LeetCode::_1255_MaximumScoreWordsFormedByLetters::maxScoreWords(std::vector<std::string>& words, std::vector<char>& letters, std::vector<int>& score) {
    std::vector<int> letterMap(26, 0);
    for(int i = 0; i < letters.size(); ++i) {
        ++letterMap[letters[i] - 'a'];
    }
    
    std::vector<std::vector<int>> wordsIntExp(words.size());
    for(int i = 0; i < words.size(); ++i) {
        wordsIntExp[i].resize(26);
        for(char c : words[i]) {
            ++wordsIntExp[i][c - 'a'];
        }
    }
    
    int myScore = 0;
    scoreWords(wordsIntExp, 0, letterMap, score, myScore);
    return maxScore;
}


int LeetCode::_1255_MaximumScoreWordsFormedByLetters::getWordScore(const std::vector<int>& word, const std::vector<int>& score) {
    int totScore = 0;
    for(int i = 0; i < 26; ++i) {
        totScore += word[i] * score[i];            
    }
    return totScore;
}

bool LeetCode::_1255_MaximumScoreWordsFormedByLetters::canCreateAWord(const std::vector<int>& letterMap, const std::vector<int>& word) {
    for(int i = 0; i < 26; ++i) {
        if(letterMap[i] < word[i]) {
            return false;
        }
    }
    
    return true;
}
    
void LeetCode::_1255_MaximumScoreWordsFormedByLetters::createAWord(std::vector<int>& letterMap, const std::vector<int>& word) {
    for(int i = 0; i < 26; ++i) {
        letterMap[i] -= word[i];
    }
}

void LeetCode::_1255_MaximumScoreWordsFormedByLetters::removeAWord(std::vector<int>& letterMap, const std::vector<int>& word) {
    for(int i = 0; i < 26; ++i) {
        letterMap[i] += word[i];
    }
}

bool LeetCode::_1255_MaximumScoreWordsFormedByLetters::noMoreWordsCanGenerated(const std::vector<std::vector<int>>& words,int startIdx, const std::vector<int>& letterMap) {
    for(int i = startIdx; i < words.size(); ++i) {
        if(canCreateAWord(letterMap, words[i])) {
            return false;
        }
    }
    return true;
}

void LeetCode::_1255_MaximumScoreWordsFormedByLetters::scoreWords(std::vector<std::vector<int>>& words, int startIdx, std::vector<int>& letterMap,
                std::vector<int>& score, int& myScore) {
    if(startIdx == words.size() || noMoreWordsCanGenerated(words, startIdx, letterMap)) {
        return;
    }
    
    for(int i = startIdx; i < words.size(); ++i) {
        if(canCreateAWord(letterMap, words[i])) {
            createAWord(letterMap, words[i]);
            int curScore = getWordScore(words[i], score);;
            myScore += curScore;
            if(myScore > maxScore) {
                maxScore = myScore;
            }
            scoreWords(words, i + 1, letterMap, score, myScore);
            
            removeAWord(letterMap, words[i]);
            myScore -= curScore;
        }
    }
}
