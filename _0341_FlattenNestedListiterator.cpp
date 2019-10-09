#include "headers.hpp"

LeetCode::_0341_FlattenNestedListIterator::_0341_FlattenNestedListIterator(std::vector<NestedIterator>& nestedList) : nl(nestedList){
    increaseIndex();
}

int LeetCode::_0341_FlattenNestedListIterator::next() {
    int result;
    if(nl[index].isInteger()) {
        result = nl[index].getInteger();
        increaseIndex();
    } else {
        result = itr->next();
        if(!itr->hasNext()) {
            itr = nullptr;
            increaseIndex();
        }
    }
    return result;
}
bool LeetCode::_0341_FlattenNestedListIterator::hasNext() {
    return (index < nl.size());
}

bool LeetCode::_0341_FlattenNestedListIterator::hasContent(std::vector<NestedInteger> V) {
    for(NestedInteger v : V) {
        if(v.isInteger()) {
            return true;
        } else {
            if(hasContent(v.getList())) {
                return true;
            }
        }
    }
    return false;
}

void LeetCode::_0341_FlattenNestedListIterator::increaseIndex() {
    ++index;
    while(hasNext() && !nl[index].isInteger() && !hasContent(nl[index].getList())) {
        index++;
    }
    if(hasNext() && !nl[index].isInteger()) {
        itr = new NestedInteger(nl[index].getList());
    } else {
        itr = nullptr;
    }
    return;
}


// Another Solution

// class NestedIterator {
// public:
//     // copy from the solution
//     NestedIterator(vector<NestedInteger> &nestedList) {
//         for(auto it = nestedList.rbegin(); it != nestedList.rend(); ++it){
//             s.push(*it);
//         }
//     }

//     int next() {
//         NestedInteger t = s.top();
//         s.pop();
//         return t.getInteger();
//     }

//     bool hasNext() {
//         while(!s.empty()) {
//             NestedInteger t = s.top();
//             if(t.isInteger()) {
//                 return true;
//             }
//             s.pop();
//             auto& list = t.getList();
//             for(auto it = list.rbegin(); it != list.rend(); ++it) {
//                 s.push(*it);
//             }
//         }
//         return false;
//     }
// private:
//     std::stack<NestedInteger> s;
// };