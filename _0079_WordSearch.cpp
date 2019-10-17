#include "headers.hpp"

bool LeetCode::_0079_WordSearch::exist(std::vector<std::vector<char>>& board, std::string word) {
    bool res = false;
    for(int i = 0; i < board.size(); ++i) {
        for(int j = 0; j < board[i].size(); ++j) {
            exist(board, i, j, word, 0, word.size(), res);
            if(res) {
                return true;
            }
        }
    }
    return res;
}
void LeetCode::_0079_WordSearch::exist(std::vector<std::vector<char>>& board, int i, int j, std::string& word, int start, int end, bool& res) {
    if(res) {
        return;
    }
    if(start == end) {
        res = true;
        return;
    }
    if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) {
        return;
    }

    if(board[i][j] == word[start]) {
        char t = board[i][j];
        board[i][j] = '1';
        exist(board, i + 1, j, word, start + 1, end, res);
        exist(board, i - 1, j, word, start + 1, end, res);
        exist(board, i, j + 1, word, start + 1, end, res);
        exist(board, i, j - 1, word, start + 1, end, res);
        board[i][j] = t;
    }
}