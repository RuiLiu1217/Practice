#include "headers.hpp"

std::vector<std::string> LeetCode::_0212_WordSearchII::findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words) {
    for(auto& w : words) {
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                if(board[i][j] == w[0]) {
                    findWords(board, i, j, w, 0);
                }
            }
        }
    }

    std::vector<std::string>myRes;
    for(auto& v : res) {
        myRes.push_back(v);
    }
    return myRes;
}

void LeetCode::_0212_WordSearchII::findWords(std::vector<std::vector<char>>& board, int i, int j, const std::string& word, int idx) {
    if(idx == word.size() - 1 && !(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) && board[i][j] == word[idx]) {
        res.insert(word);
        return;
    }
    if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) {
        return;
    }
    if(board[i][j] == word[idx]) {
        board[i][j] = '.';
        findWords(board, i - 1, j, word, idx + 1);
        findWords(board, i + 1, j, word, idx + 1);
        findWords(board, i, j - 1, word, idx + 1);
        findWords(board, i, j + 1, word, idx + 1);
        board[i][j] = word[idx];
    }
}
