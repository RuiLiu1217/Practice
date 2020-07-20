#include "LeetCode_BFS.hpp"
#include <unordered_set>
#include <queue>
#include <functional>
// Graph based implementation 

int LC::_0127_Wordladder::ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {

    static std::function<bool(std::string&, std::string& )> isOneDist = [](std::string& s, std::string& v){
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != v[i]) {
                count++;
            }
            if (count > 1) {
                return false;
            }
        }
        return count == 1;
    };

    struct IndexNode { // index node
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
        explicit LstNode(std::string dat) : color(0), distance(0), prefix(INT_MIN), data(dat), node(nullptr) {}
    };

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
        Graph(std::vector<std::string>& strVec) { // Create graph
            G.resize(strVec.size());
            int idx = 0;
            std::fill(begin(G), end(G), strVec[idx++]);
            
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

    return destDis == INT_MAX ? 0 : destDis;
}







// BFS in one direction
static int ladderLengthv1(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
    std::unordered_set<std::string> dict(wordList.begin(), wordList.end());
    std::queue<std::string> todo;
    todo.push(beginWord);
    int ladder = 1;
    while (!todo.empty()) {
        const int n = todo.size();
        for (int i = 0; i < n; i++) {
            std::string word = todo.front();
            todo.pop();
            if (word == endWord) {
                return ladder;
            }
            dict.erase(word); // The met words should be removed from the dictionary
            for (int j = 0; j < word.size(); j++) {
                const char c = word[j];
                for (int k = 0; k < 26; k++) {
                    word[j] = 'a' + k;
                    if (word[j] != c && dict.count(word)) {
                        todo.push(word);
                    }
                }
                word[j] = c;
            }
        }
        ladder++;
    }
    return 0;
}
// Bidirectional BFS
static int ladderLengthBiBFS(std::string beginWord, std::string endWord,
    std::vector<std::string>& wordList) {
    std::unordered_set<std::string> dict(begin(wordList), end(wordList));
    std::unordered_set<std::string> head;
    std::unordered_set<std::string> tail;

    if(!dict.count(endWord)) {
        return 0;
    }

    head.insert(beginWord);
    tail.insert(endWord);
    int ladder = 2;
    while(!head.empty() && !tail.empty()) {
        if(head.size() < tail.size()) {
            std::swap(head, tail);
        }
        std::unordered_set<std::string> temp;
        for(auto it : head) {
            std::string word = it;
            for(int i = 0; i < word.size(); ++i) {
                const char t = word[i];
                for(int j = 0; j < 26; ++j) {
                    word[i] = 'a' + j;
                    if(word[i] != t && tail.count(word)) {
                        return ladder;
                    }
                    if(dict.count(word)) {
                        temp.insert(word);
                        dict.erase(word);
                    }
                }
                word[i] = t;
            }

        }
        ++ladder;
        std::swap(temp, head);
    }
    return 0;
}
