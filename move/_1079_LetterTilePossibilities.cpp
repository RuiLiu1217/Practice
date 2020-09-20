#include "headers.hpp"

static int DFS(std::unordered_map<char, int>& map) {
    int sum = 0;
    for(auto& a : map) {
        if(a.second == 0) {
            continue;
        }
        ++sum;
        a.second--;
        sum += DFS(map);
        a.second++;
    }
    return sum;
}

int LeetCode::_1079_LetterTilePossibilities::numTilePossibilities(std::string tiles) {
    std::unordered_map<char, int> map;
    for(int i = 0; i < tiles.size(); ++i) {
        if(map.find(tiles[i]) == map.end()) {
            map[tiles[i]] = 1;
        } else {
            ++map[tiles[i]];
        }
    }

    int res = DFS(map);
    return res;
}


