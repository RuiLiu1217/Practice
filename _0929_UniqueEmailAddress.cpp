#include "headers.hpp"
#include <unordered_set>
int numUniqueEmails(std::vector<std::string>& emails) {
    std::unordered_set<std::string> dict;
    for(auto& em : emails) {
        std::string firstPart = "";
        int i = 0;
        for(i = 0; i < em.size(); ++i) {
            if(em[i] == '@' || em[i] == '+') {
                break;
            } else if (em[i] == '.') {
                continue;
            } else {
                firstPart = firstPart + em[i];
            }
        }
        while(em[i] != '@') {
            ++i;
        }
        std::string second(em.begin()+i, em.end());
        std::string email = firstPart+second;
        if(dict.find(email) == dict.end()) {
            dict.insert(email);
        }
    }
    return dict.size();
}