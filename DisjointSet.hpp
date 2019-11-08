#ifndef DISJOINTSET_HPP
#define DISJOINTSET_HPP
#include <vector>
class DisjointSet {
public:
    struct Elem {
        int parent;
        int rank;
        int size;
    };
    std::vector<Elem> mSet;
    DisjointSet(int n) {
        mSet.resize(n);
        for(int i = 0; i < n; ++i) {
            mSet[i].parent = i;
            mSet[i].rank = 0;
            mSet[i].size = 1;
        }
    }

    /*
    find(x) follows the chain of parent pointers 
    from x up the tree until it reaches a root 
    element, whose parent is itself. This root 
    element is the representative member of the 
    set to which x belongs, and may be x itself.
    */
    int find_PathCompression(int x) {
        if(mSet[x].parent != x) {
            mSet[x].parent = find_PathCompression(mSet[x].parent);
        }
        return mSet[x].parent;
    }

    int find_PathHalving(int x) {
        while(mSet[x].parent != x) {
            mSet[x].parent = mSet[mSet[x].parent].parent;
            x = mSet[x].parent;
        }
        return x;
    }

    int find_PathSplitting(int x) {
        while(mSet[x].parent != x) {
            x = mSet[x].parent;
            mSet[x].parent = mSet[mSet[x].parent].parent;
        }
        return x;
    }

    int find_PathSplitting_2(int x) {
        while(mSet[x].parent != x) {
            int next = mSet[x].parent;
            mset[x].parent = mSet[next].parent;
            x = next;
        }
        return x;
    }

    int find_PathSplitting_3(int x) {
        while(mSet[x].parent != x) {
            int prev = x;
            x = mSet[x].parent;
            mSet[prev].parent = mSet[x].parent;
        }
        return x;
    }

    // Union
    /*
    Union(x,y) uses Find to determine the roots of the trees x and y belong to. 
    If the roots are distinct, the trees are combined by attaching the root of 
    one to the root of the other. If this is done naively, such as by always 
    making x a child of y, the height of the trees can grow as O(n). To prevent 
    this union by rank or union by size is used.
    */

    // Union by rank always attaches the shorter tree to the root of the taller 
    // tree. Thus, the resulting tree is no taller than the originals unless 
    // they were of equal height, in which case the resulting tree is taller 
    // by one node.
    // To implement union by rank, each element is associated with a rank. Initially 
    // a set has one element and a rank of zero. If two sets are unioned and have 
    // the same rank, the resulting set's rank is one larger; otherwise, if two 
    // sets are unioned and have different ranks, the resulting set's rank is the 
    // larger of the two. Ranks are used instead of height or depth because path 
    // compression will change the trees' heights over time.
    void UnionByRank(int x, int y) {
        int xRoot = find_PathCompression(x);
        int yRoot = find_PathCompression(y);

        if(xRoot == yRoot) {
            return;
        }

        if(mSet[xRoot].rank < mSet[yRoot].rank) {
            std::swap(xRoot, yRoot);
        }
        mSet[yRoot].parent = xRoot;
        if(mSet[xRoot].rank == mSet[yRoot].rank) {
            mSet[xRoot].rank = mSet[xRoot].rank + 1;
        }
    }

    void UnionBySize(int x, int y) {
        int xRoot = find_PathCompression(x);
        int yRoot = find_PathCompression(y);

        if(xRoot == yRoot) {
            return;
        }

        if (mSet[xRoot].size < mSet[yRoot].size) {
            std::swap(xRoot, yRoot);
        }

        mSet[yRoot].parent = xRoot;
        mSet[xRoot].size = mSet[xRoot].size + mSet[yRoot].size;
    }
     
   
};

#endif