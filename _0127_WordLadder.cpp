#include "headers.hpp"

struct IndexNode {
    int idx;
    IndexNode* next;
    IndexNode(int v) : idx(v) {}
};

struct LstNode {
    int color;
    int distance;
    int prefix;

    std::string data;
    IndexNode* node;
};

bool isOneDist(std::string& s, std::string& v) {
    int count = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != v[i]) {
            count++;
        }
        if (count > 1) {
            return false;
        }
    }
    if (count == 1) {
        return true;
    }
    else {
        return false;
    }
}

class Graph {
    std::vector<LstNode> G;
    void addEdge(int i, int j) {
        IndexNode* p = new IndexNode(j);
        p->next = G[i].node;
        G[i].node = p;

        IndexNode* q = new IndexNode(i);
        q->next = G[j].node;
        G[j].node = q;
    }
public:
    Graph(std::vector<std::string>& strVec) {
        G.resize(strVec.size());
        for (int i = 0; i < strVec.size(); ++i) {
            G[i].color = 0;
            G[i].distance = 0;
            G[i].prefix = INT_MIN;
            G[i].data = strVec[i];
            G[i].node = nullptr;
        }

        for (int i = 0; i < strVec.size(); ++i) {
            for (int j = i + 1; j < strVec.size(); ++j) {
                if (isOneDist(strVec[i], strVec[j])) {
                    addEdge(i, j);
                }
            }
        }
    }

    int BFS(int startIdx, std::string destStr) {
        G[startIdx].color = 1;
        G[startIdx].distance = 1;
        G[startIdx].prefix = INT_MIN;
        std::queue<int> Q;
        Q.push(startIdx);
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            IndexNode* p = G[u].node;
            while (p != nullptr) {
                if (G[p->idx].color == 0) {
                    G[p->idx].color = 1;
                    G[p->idx].distance = G[u].distance + 1;
                    G[p->idx].prefix = u;

                    if (G[p->idx].data == destStr) {
                        return G[p->idx].distance + 1;
                    }
                    Q.push(p->idx);
                }
                p = p->next;
            }
            G[u].color = 2;
        }
        return INT_MAX;
    }
};

int LeetCode::_0127_Wordladder::ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
    Graph g(wordList);
    int destDis = INT_MAX;
    for (int i = 0; i < wordList.size(); ++i) {
        if (isOneDist(beginWord, wordList[i])) {
            int dis = g.BFS(i, endWord);
            if (destDis > dis) {
                destDis = dis;
            }
        }
    }
    if (destDis == INT_MAX) {
        return 0;
    }
    else {
        return destDis;
    }
}


