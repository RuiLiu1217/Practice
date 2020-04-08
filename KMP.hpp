#ifndef KMP_HPP
#define KMP_HPP
#include <vector>
#include <string>
class KMP {
    std::vector<int> next;
    std::string p;
public:
    KMP() {
        
    }
    void build(std::string& P) {
        p = P;
        int m = p.length();
        next.clear();
        next.push_back(0);
        next.push_back(0);
        int j = 0;
        for(int i = 1; i <= m; ++i) {
            while(j > 0 && p[i] != p[j]) {
                j = next[j];
            }
            if(p[j] == p[i]) {
                j += 1;
            }
            next.push_back(j);
        }
    }
    void reset() {
        next.clear();
    }
    std::vector<int> match(std::string s, std::string p) {
        int n = s.length();
        int m = p.length();
        std::vector<int> ans;
        int j = 0;
        for(int i = 0; i <= n; ++i) {
            while(j > 0 && s[i] != p[j]) {
                j = next[j];
            }
            if(s[i] == p[j]) {
                j += 1;
            }
            if (j == m) {
                ans.push_back(i - m + 1);
                j = next[j];
            }
        }
        return ans;
    }
};

#endif