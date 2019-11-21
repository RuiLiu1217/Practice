#include "headers.hpp"


LeetCode::_1146_SnapshotArray::_1146_SnapshotArray(int length) {
    A.resize(length);
    for(int i = 0; i < length; ++i) {
        A[i][0] = 0;
    }
}
    
void LeetCode::_1146_SnapshotArray::set(int index, int val) {
    A[index][snap_id] = val;
}
    
int LeetCode::_1146_SnapshotArray::snap() {
    return snap_id++;        
}
    
int LeetCode::_1146_SnapshotArray::get(int index, int snaid) {
    while(A[index].find(snaid) == A[index].end() && snaid > 0) {
        --snaid;
    }
    auto it = A[index].find(snaid);
    return it->second;
}