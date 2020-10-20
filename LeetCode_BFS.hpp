#ifndef LEETCODE_BFS_HPP
#define LEETCODE_BFS_HPP
#include <string>
#include <vector>
namespace LC {
/*
Tag: BFS, bidirect-BFS
TODO
Given two words (beginWord and endWord), and a dictionary's word list, find the 
length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a 
transformed word.

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5

Explanation: As one shortest transformation is 
"hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
Output: 0

Explanation: The endWord "cog" is not in wordList, 
therefore no possible transformation.
*/
class _0127_Wordladder {
public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList);
};

/*
You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

Example: 

Given the 2D grid:

INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
After running your function, the 2D grid should be:

  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
*/
class _0286_WallsAndGates {
public:
    void wallsAndGates(std::vector<std::vector<int>>& rooms);
};

/*
A frog is crossing a river. The river is divided into x units and at each unit there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.

Given a list of stones' positions (in units) in sorted ascending order, determine if the frog is able to cross the river by landing on the last stone. Initially, the frog is on the first stone and assume the first jump must be 1 unit.

If the frog's last jump was k units, then its next jump must be either k - 1, k, or k + 1 units. Note that the frog can only jump in the forward direction.

Note:

The number of stones is ≥ 2 and is < 1,100.
Each stone's position will be a non-negative integer < 231.
The first stone's position is always 0.
Example 1:

[0,1,3,5,6,8,12,17]

There are a total of 8 stones.
The first stone at the 0th unit, second stone at the 1st unit,
third stone at the 3rd unit, and so on...
The last stone at the 17th unit.

Return true. The frog can jump to the last stone by jumping 
1 unit to the 2nd stone, then 2 units to the 3rd stone, then 
2 units to the 4th stone, then 3 units to the 6th stone, 
4 units to the 7th stone, and 5 units to the 8th stone.
Example 2:

[0,1,2,3,4,8,9,11]

Return false. There is no way to jump to the last stone as 
the gap between the 5th and 6th stone is too large.
*/
class _0403_FrogJump {
public:
    bool canCross(std::vector<int>& stones);
};

/*
There are N rooms and you start in room 0. Each room has a distinct number in 0, 
1, 2, ..., N-1, and each room may have some keys to access the next room. 
Formally, each room i has a list of keys rooms[i], and each key rooms[i][j] is an 
integer in [0, 1, ..., N-1] where N = rooms.length. A key rooms[i][j] = v opens 
the room with number v.
Initially, all the rooms start locked (except for room 0). You can walk back and 
forth between rooms freely.
Return true if and only if you can enter every room.

Input: [[1],[2],[3],[]]
Output: true
Explanation:  
We start in room 0, and pick up key 1.
We then go to room 1, and pick up key 2.
We then go to room 2, and pick up key 3.
We then go to room 3.  Since we were able to go to every room, we return true.

Input: [[1,3],[3,0,1],[2],[0]]
Output: false
Explanation: We can't enter the room with number 2.
Note:

1 <= rooms.length <= 1000
0 <= rooms[i].length <= 1000
The number of keys in all rooms combined is at most 3000.
*/
class _0841_KeysAndRooms {
public:
     bool canVisitAllRooms(std::vector<std::vector<int>>& rooms);
};


/*
In an N by N square grid, each cell is either empty (0) or blocked (1).
A clear path from top-left to bottom-right has length k if and only if 
it is composed of cells C_1, C_2, ..., C_k such that:
Adjacent cells C_i and C_{i+1} are connected 8-directionally (ie., they 
are different and share an edge or corner)

C_1 is at location (0, 0) (ie. has value grid[0][0])
C_k is at location (N-1, N-1) (ie. has value grid[N-1][N-1])
If C_i is located at (r, c), then grid[r][c] is empty (ie. grid[r][c] == 0).
Return the length of the shortest such clear path from top-left to 
bottom-right. If such a path does not exist, return -1.

Note:
1 <= grid.length == grid[0].length <= 100
grid[r][c] is 0 or 1
*/
class _1091_ShortestPathInBinaryMatrix {
public:
    int shortestPathBinaryMatrix(std::vector<std::vector<int>>& grid);
};


}
#endif