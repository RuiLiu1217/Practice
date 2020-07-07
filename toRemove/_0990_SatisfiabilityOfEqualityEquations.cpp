#include "headers.hpp"

struct Union {
    std::vector<int> parent;
    Union() {
        parent.resize(26);
        for(int i = 0; i < 26; ++i) {
            parent[i] = i;
        }
    }
    int find(int v) {
        if(parent[v] != v) { // it is "if" not "while" !!!
            parent[v] = find(parent[v]);
        }
        return parent[v];
    }
    void un(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if(pa == pb) {
            return;
        }
        parent[pa] = pb;
    }
};


bool LeetCode::_0990_SatisfiabilityOfEqualityEquations::equationPossible(std::vector<std::string>& equations) {
    Union u;
    for(auto eq : equations) {
        char l = eq[0];
        char r = eq[3];
        int vl = static_cast<int>(l-'a');
        int vr = static_cast<int>(r-'a');
        if(eq[1] == '=') {
            u.un(vl, vr);
        }
    }
    for(auto eq : equations) {
        char l = eq[0];
        char r = eq[3];
        int vl = static_cast<int>(l-'a');
        int vr = static_cast<int>(r-'a');
        if(eq[1] == '!') {
            int pl = u.find(vl);
            int pr = u.find(vr);
            if(pl == pr) {
                return false;
            }
        }
    }
    return true;
}