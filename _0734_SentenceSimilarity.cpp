#include "headers.hpp"
#include <map>
#include <set>
bool LeetCode::_0734_SentenceSimilarity::areSentencesSimilar(std::vector<std::string>& words1, std::vector<std::string>& words2,
    std::vector<std::vector<std::string>>& pairs) 
{
    if (words1.size() != words2.size()) {
        return false;
    }
    std::map<std::string, std::set<std::string>> map;
    for (auto& p : pairs)
        map[p[0]].insert(p[1]);

    for (int i = 0; i < words1.size(); i++)
        if (words1[i] != words2[i] && !map[words1[i]].count(words2[i]) && !map[words2[i]].count(words1[i]))
            return false;
    return true;
}