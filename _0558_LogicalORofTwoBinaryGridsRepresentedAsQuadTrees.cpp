#include "headers.hpp"

LeetCode::_0558_LogicalORofTwoBinaryGridsRepresentedAsQuadTrees::Node* LeetCode::_0558_LogicalORofTwoBinaryGridsRepresentedAsQuadTrees::intersect(
    LeetCode::_0558_LogicalORofTwoBinaryGridsRepresentedAsQuadTrees::Node* quadTree1, 
    LeetCode::_0558_LogicalORofTwoBinaryGridsRepresentedAsQuadTrees::Node* quadTree2) {
    if(quadTree1->isLeaf && quadTree1->val) return quadTree1;
    if(quadTree2->isLeaf && quadTree2->val) return quadTree2;
    if(quadTree1->isLeaf && !quadTree1->val) return quadTree2;
    if(quadTree2->isLeaf && !quadTree2->val) return quadTree1;     
    
    auto tl = intersect(quadTree1->topLeft, quadTree2->topLeft);
    auto tr = intersect(quadTree1->topRight, quadTree2->topRight);
    auto bl = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
    auto br = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
    
    if(tl->val == tr->val && tl->val == bl->val && tl->val == br->val && tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf)
        return new LeetCode::_0558_LogicalORofTwoBinaryGridsRepresentedAsQuadTrees::Node(tl->val, true, nullptr, nullptr, nullptr, nullptr);
    else         
        return new LeetCode::_0558_LogicalORofTwoBinaryGridsRepresentedAsQuadTrees::Node(false, false, tl, tr, bl, br);
}