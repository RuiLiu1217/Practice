#include "headers.hpp"
#include <unordered_map>
#include <unordered_set>
// Hint: Bit mask based DP
// DP[skill_set] is a sufficient team to cover the skill_set

std::vector<int> LeetCode::_1125_SmallestSufficientTeam::smallestSufficientTeam(
    std::vector<std::string>& req_skills, 
    std::vector<std::vector<std::string>>& people) {
        std::unordered_map<std::string, int> skill2IdxMap;
        for(int i = 0; i < req_skills.size(); ++i) {
            skill2IdxMap[req_skills[i]] = i;
        }

        std::unordered_map<int, std::vector<int>> DP;
        DP[0] = {};
        for(int i = 0; i < people.size(); ++i) {
            auto& peopleSkill = people[i];
            int hisSkill = 0;
            for(auto& skill : peopleSkill) {
                hisSkill |= (1<<skill2IdxMap[skill]);
            }

            for(auto& curdp : DP) {
                int skillSet = curdp.first;
                int withHim = skillSet | hisSkill;
                if(withHim == skillSet) {
                    continue;
                }
                if(DP.find(withHim) == DP.end() || DP[withHim].size() > (curdp.second.size() + 1)) {
                    std::vector<int> t = curdp.second;
                    t.push_back(i);
                    DP[withHim] = std::move(t);
                }
            }
        }
        return DP[1 << static_cast<int>(req_skills.size()) - 1];
}