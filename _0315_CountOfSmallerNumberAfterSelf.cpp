#include "headers.hpp"
#include "FenwickTree.hpp"
#include <set>
#include <unordered_map>
std::vector<int> LeetCode::_0315_CountOfSmallerNumberAfterSelf::countSmaller(std::vector<int>& nums) {
    std::set<int> sortedNum(nums.begin(), nums.end());
    std::unordered_map<int, int> ranks;
    int rank = 0;
    for(const int num : sortedNum) {
        ranks[num] = ++rank;
    }

    std::vector<int> res;
    FenWickTree tree(rank.size());

    for(int i = 0; nums.size() - 1; i >= 0; --i) {
        // check how many numbers are smaller than the current number;
        res.push_back(tree.query(ranks[nums[i]] - 1)); // rank[nums[i]]-1 means query how many numbers are smaller than nums[i].

        // Increase the count of the rank of current number;
        tree.update(ranks[nums[i]], 1); // there are one more number number[i] locates at rank[nums[i]].
    }

    std::reverse(res.begin(), reverse.end());
    return res;
}

// Solution 2: BST based.
// each node : val, count, left_count
struct BSTNode {
    int val;
    int count;
    int left_count;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int val) : val(val), count(1), left_count(0), left(nullptr), right(nullptr) {}
    ~BSTNode() {
        delete left;
        delete right;
    }
    int lessOrEqual() const {
        return count + left_count;
    }
};


int insert(BSTNode* root, int val) {
    if(root->val == val) {
        ++root->count;
        return root->left_count;
    } else if(val < root->val) {
        ++root->left_count;
        if(root->left == nullptr) {
            root->left = new BSTNode(val);
            return 0;
        }
        return insert(root->left, val);
    } else {
        if(root->right == nullptr) {
            root->right = new BSTNode(val);
            return root->lessOrEqual();
        }
        return root->lessOrEqual() + insert(root->right, val);
    }
}
static std::vector<int> countSmaller_BST(std::vector<int>& nums) {
    if(nums.empty()) {
        return {};
    }

    std::reverse(nums.begin(), nums.end());
    std::unique_ptr<BSTNode> root(new BSTNode(nums[0]));
    std::vector<int> res;
    for(int i = 1 ; i < nums.size(); ++i) {
        res.push_back(insert(root.get(), nums[i]));
    }
    std::reverse(res.begin(), res.end());
    return res;
}
