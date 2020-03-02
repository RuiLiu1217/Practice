#include "headers.hpp"
#include <algorithm>
#include <numeric>
std::string LeetCode::_0269_AlienDictionary::alienOrder(std::vector<std::string>& words) {
    std::unordered_map<char, int> charToIndex;
    std::unordered_map<int, char> IndexToChar;
    int index = 0;
    for(auto s : words) {
        for(int i = 0; i < s.size(); ++i) {
            if(charToIndex.find(s[i]) == charToIndex.end()) {
                charToIndex[s[i]] = index;
                IndexToChar[index] = s[i];
                ++index;
            }
        }
    }

    std::vector<std::vector<int>> adjList(index);
    for(int i = 0; i < words.size() - 1; ++i) {
        std::string smallWord = words[i];
        std::string biggerWord = words[i+1];

        int idx = 0;
        while(idx < std::min(smallWord.size(), biggerWord.size()) &&
        smallWord[idx] == biggerWord[idx]) {
            ++idx;
        }
        if(idx < std::min(smallWord.size(), biggerWord.size())) {
            adjList[charToIndex[smallWord[idx]]].push_back(charToIndex[biggerWord[idx]]);
        }
    }

    std::vector<int> idxes = topologicalSort(adjList);
    std::string res;
    for(int i : idxes) {
        res += IndexToChar[i];
    }
    return res;
}

std::vector<int> LeetCode::_0269_AlienDictionary::topologicalSort(std::vector<std::vector<int>>& adjList) {
    std::vector<int> visited(adjList.size(), 0);
    std::vector<int> indegree(adjList.size(), 0);
    std::vector<int> res;
    std::queue<int> q;
    for(int i = 0; i < adjList.size(); ++i) {
        for(int j = 0; j < adjList[i].size(); ++j) {
            ++indegree[adjList[i][j]];
        }
    }
    for(int i = 0; i < indegree.size(); ++i) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        const int N = q.size();
        for(int i = 0; i < N; ++i) {
            int idx = q.front();
            q.pop();
            visited[idx] = 1;
            res.push_back(idx);
            
            std::vector<int>& adjNodes = adjList[idx];
            for(int kk = 0; kk < adjNodes.size(); ++kk) {
                --indegree[adjNodes[kk]];
                if(!visited[adjNodes[kk]] && indegree[adjNodes[kk]] == 0) {
                    q.push(adjNodes[kk]);
                }
            }
        }
    }
    int remain = std::accumulate(begin(indegree), end(indegree), 0);
    return remain == 0 ? res : std::vector<int>();
}