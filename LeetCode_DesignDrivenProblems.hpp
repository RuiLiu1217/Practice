#ifndef LEETCODE_DESIGNDRIVENPROBLEMS_HPP
#define LEETCODE_DESIGNDRIVENPROBLEMS_HPP
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <set>
namespace LC {
    /*
    !! Copy from the solution
    Design an in-memory file system to simulate the following functions:
        ls: Given a path in string format. If it is a file path, return a list that only contains 
        this file's name. If it is a directory path, return the list of file and directory names 
        in this directory. Your output (file and directory names together) should in lexicographic 
        order.
        
        mkdir: Given a directory path that does not exist, you should make a new directory according 
        to the path. If the middle directories in the path don't exist either, you should create them 
        as well. This function has void return type.
        
        addContentToFile: Given a file path and file content in string format. If the file doesn't 
        exist, you need to create that file containing given content. If the file already exists, you 
        need to append given content to original content. This function has void return type.
        
        readContentFromFile: Given a file path, return its content in string format.
        
        Input: 
            ["FileSystem","ls","mkdir","addContentToFile","ls","readContentFromFile"]
            [[],["/"],["/a/b/c"],["/a/b/c/d","hello"],["/"],["/a/b/c/d"]]
            
        Output:
            [null,[],null,null,["a"],"hello"]
        
        Note:
            You can assume all file or directory paths are absolute paths which begin with / and do not 
            end with / except that the path is just "/".
            You can assume that all operations will be passed valid parameters and users will not attempt 
            to retrieve file content or list a directory or file that does not exist.
            You can assume that all directory names and file names only contain lower-case letters, and 
            same names won't exist in the same directory.
    */
    class _0588_DesignInMemoryFileSystem {
    private:
        std::unordered_map<std::string, std::set<std::string>> dirs; // string to directory map
        std::unordered_map<std::string, std::string> files; // string to files map
    public:
        _0588_DesignInMemoryFileSystem() {
            dirs["/"];  // setup a root directory which contains nothing
        }

        std::vector<std::string> ls(std::string path);
        void mkdir(std::string path);
        void addContentToFile(std::string filePath, std::string content);
        std::string readContentFromFile(std::string filePath);
    };
}
#endif