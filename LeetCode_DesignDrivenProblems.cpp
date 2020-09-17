#include "LeetCode_DesignDrivenProblems.hpp"
#include <string>
#include <sstream>
#include <iostream>

std::vector<std::string> LC::_0588_DesignInMemoryFileSystem::ls(std::string path) {
    if(files.count(path)) { // 是个文件
        int idx = path.find_last_of('/'); // 找最后一 '/' 的位置
        return {path.substr(idx+1)};
    }
    auto t = dirs[path];
    return std::vector<std::string>(begin(t), end(t)); // return a vector of all sub directories from a set
}

void LC::_0588_DesignInMemoryFileSystem::mkdir(std::string path) {
    std::istringstream is(path);
    std::string t = "";
    std::string dir = "";
    while(std::getline(is, t, '/')) {
        if(t.empty()) {
            continue;
        }
        if(dir.empty()) {
            dir += "/";
        }
        dirs[dir].insert(t);
        if(dir.size() > 1) {
            dir += "/";
        }
        dir += t;
    }
}

void LC::_0588_DesignInMemoryFileSystem::addContentToFile(std::string filePath, std::string content) {
    int idx = filePath.find_last_of('/');
    std::string dir = filePath.substr(0, idx);
    std::string file = filePath.substr(idx+1);
    if(dir.empty()) {
        dir += "/";
    }
    if(!dirs.count(dir)) {
        mkdir(dir);
    }
    dirs[dir].insert(file);
    files[filePath].append(content);
}

std::string LC::_0588_DesignInMemoryFileSystem::readContentFromFile(std::string filePath) {
    return files[filePath];
}