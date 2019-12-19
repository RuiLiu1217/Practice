#include "headers.hpp"
#include <map>

std::vector<std::string> subdomainVisits(std::vector<std::string>& cpdomains) {
    std::map<std::string, int> mp;
    for(auto domain : cpdomains) {
        std::size_t found = domain.find(' ');
        //ASSERT(found!=std::string::npos);
            
        std::string countStr(domain.begin(), domain.begin() + found);
        int count = stoi(countStr);
        std::string dom(domain.begin() + found+1, domain.end());
        
        while(!dom.empty()) {
            if(mp.find(dom) == mp.end()) {
                mp[dom] = count;
            } else {
                mp[dom] += count;
            }
            
            std::size_t fd = dom.find('.');
            if(fd != std::string::npos) {
                dom = dom.substr(fd+1);                 
            } else {
                break;
            }                
        }
    }
    std::vector<std::string> res;
    for(auto mpe : mp){
        res.push_back(std::to_string(mpe.second) + ' ' + mpe.first);
    }
    return res;
}