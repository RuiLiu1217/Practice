#include "headers.hpp"
#include <unordered_map>
#include <unordered_set>
std::pair<std::string, std::string> LeetCode::_0609_FindDuplicateFileInSystem::separateFileNameAndContent(const std::string& pf) {
    std::string fn;
    int i = 0;
    for(; i < pf.size(); ++i) {
        if(pf[i] != '(') {
            fn += pf[i];
        } else {
            break;
        }
    }
    ++i;
    std::string content;
    while(i < pf.size() && pf[i] != ')') {
        content += pf[i++];
    }
    return {fn, content};
}

std::vector<std::pair<std::string, std::string>> LeetCode::_0609_FindDuplicateFileInSystem::getOneFoldersFiles(const std::string& path) {
    std::vector<std::pair<std::string, std::string>> res;
    std::vector<std::string> pf;
    std::string temp;
    for(int i = 0; i < path.size(); ++i) {
        if(path[i] == ' ') {
            if(temp.size() > 0) {
                pf.push_back(temp);
                temp.clear();
            }
        } else {
            temp += path[i];
        }
    }

    if(temp.size() > 0) {
        pf.push_back(temp);
        temp.clear();
    }

    std::string filePath = pf[0];
    for(int i = 1; i < pf.size(); ++i) {
        std::pair<std::string, std::string> fnAndfc = separateFileNameAndContent(pf[i]);
        res.push_back({fnAndfc.second, filePath + "/" + fnAndfc.first});
    }
    return res;
}

std::vector<std::vector<std::string>> LeetCode::_0609_FindDuplicateFileInSystem::findDuplicate(std::vector<std::string>& paths) {
    std::unordered_map<std::string, std::unordered_set<std::string>> preRes;
    for(int i = 0; i < paths.size(); ++i) {
        std::vector<std::pair<std::string, std::string>> content2Files = getOneFoldersFiles(paths[i]);
        for(auto& c : content2Files) {
            preRes[c.first].insert(c.second);
        }
    }
    
    std::vector<std::vector<std::string>> res;
    int i = 0;
    for(auto& p : preRes) {
        if (p.second.size() > 1) {
            res.push_back({});
            for(auto& ps : p.second) {
                res[i].push_back(ps);
            }
            ++i;
        }
    }
    return res;
}