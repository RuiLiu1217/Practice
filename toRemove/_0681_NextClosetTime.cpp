#include "headers.hpp"
#include <set>
#include <string>
// Copy from the solution,
// Totally in chaos of my mind when solve this problem

/* Store the available <4 digit in set(sorted from minimum to maximum natrually);
// Start from end of the time string, replace it with the next larger number 
// in the set. If available and a legal time(min < 60 && hh <24), return the 
// result; 
// Else replace it the smalleset number int the set , go to the next digit in
// the time string. 
// Space is O(1), because <4 characters set; time is O(1), which goes through 
// 4 characters in the string
*/
std::string LeetCode::_0681_NextClosetTime::nextClosetTime(std::string time) {
    std::set<char> sorted;
    for(auto c:time){
        if(c==':') continue;
        sorted.insert(c);
    }

    std::string res = time;
    for(int i = time.size() - 1; i >= 0; i--) {
        if(time[i] == ':' ) continue;
        auto it = sorted.find(time[i]);
        if(*it != *sorted.rbegin()){// not the largest number
            it++; // go to the next element
            res[i] = *it;
            if((i >= 3 && std::stoi(res.substr(3,2)) < 60) || (i < 2 && std::stoi(res.substr(0,2))<24))
                return res;      
        } 
        res[i]=*sorted.begin(); // take the smallest number
    }
    return res;
}