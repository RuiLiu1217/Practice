#include "headers.hpp"
#include <unordered_set>

// This solution is BFS based
int LeetCode::_0752_OpenTheLock::openLock(std::vector<std::string>& deadends, std::string target) {
    std::unordered_set<std::string> deadEnds(deadends.begin(), deadends.end());
    std::unordered_set<std::string> visited;

    std::queue<std::string> bfs;

    std::string init = "0000";
    if(deadEnds.find(init) != deadEnds.end()) {
        return -1;
    }

    visited.insert(init);
    bfs.push(init);
    int res = 0;

    while(!bfs.empty()) {
        const int N = bfs.size();
        for(int i = 0; i < N; ++i) {
            std::string t = bfs.front();
            bfs.pop();

            // Get all "neighbor" string
            std::vector<std::string> nbrStr = nextNeighborString(t);
            for(auto& s : nbrStr) {
                if(s == target) {
                    return ++res;
                }
                if(visited.find(s) != visited.end()) {
                    continue;
                }
                if(dds.find(s) == dds.end()) {
                    bfs.push(s);
                    visited.insert(s);
                }
            }
        }
        ++res;
    }
    return -1;
}

// Bidirectional BFS
int bidirectionalBFS(std::vector<std::string>& deadends, std::string target) {
    std::unordered_set<std::string> deadEnds(deadends.begin(), deadends.end());
    std::unordered_set<std::string> visited;

    std::unordered_set<std::string> q1;
    std::unordered_set<std::string> q2;
    std::unordered_set<std::string> pass;

    std::string init = "0000";
    if(deadEnds.find(init) != deadEnds.end() || deadEnds.find(target) != deadEnds.end()) {
        return -1;
    }

    visited.insert(init);
    q1.insert(init);
    q2.insert(target);

    int res = 0;
    while(!q1.empty() && !q2.empty()) {
        if(q1.size() > q2.size()) {
            std::swap(q1, q2);
        }
        pass.clear();

        for(auto ss : q1) {
            std::vector<std::string> nbrStr = nextNeighborString(ss);

            for(auto a : nbrStr) {
                if(q2.find(a) != q2.end()) {
                    return res + 1;
                }
                if(visited.find(a) != visited.end()) {
                    continue;
                }
                if(deadEnds.find(a) == deadEnds.end()) {
                    pass.insert(a);
                    visited.insert(s);
                }
            }    
        }
        std::swap(q1, pass);
        ++res;
    }
    return -1;
}


std::vector<std::string> LeetCode::_0752_OpenTheLock::nextNeighborString(std::string& key) {
    std::vector<std::string> res;
    for(int i = 0; i < 4; ++i) {
        std::string tmp = key;
        tmp[i] = (key[i] - '0' + 1) % 10 + '0';
        res.push_back(tmp);

        tmp[i] = (key[i] - '0' + 10 - 1) % 10 + '0';
        res.push_back(tmp);
    }
    return res;
}