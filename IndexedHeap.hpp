#ifndef INDEXEDHEAP_HPP
#define INDEXEDHEAP_HPP
#include <vector>
class MaxHeap {
private:
    // {key, id}
    std::vector<std::pair<int,int>> vals_;
    
    // Index of the i-th item in vals_ 
    std::vector<int> idx_;

    int size_;

public:
    MaxHeap(int max_items) : idx_(max_items, -1), vals_(max_items), size_(0) {}

    void Add(int key, int id) {
        idx_[id] = size_;
        vals_[size_] = {key, id};
        ++size_;
        HeapifyUp(idx_[id]);
    }

    void Remove(int id) {
        int idx_to_evict = idx_[id];
        // swap with the last element
        SwapNode(idx_to_evict, size_ - 1);
        --size_;
        HeapifyDown(idx_to_evict);
        HeapifyDown(idx_to_evict);
    }

    bool Empty() const {
        return size_ == 0;
    }

    int Max() const {
        return Empty() ? 0 : vals_.front().first;
    }

private:
    void SwapNode(int i, int j) {
        if(i == j) {
            return;
        }
        std::swap(idx_[vals_[i].second], idx_[vals_[j].second]);
        std::swap(vals_[i], vals_[j]);
    }

    void HeapifyUp(int i) {
        while(i != 0) {
            int p = (i - 1) / 2;
            if(vals_[i].first <= vals_[p].first) {
                return;
            }
            SwapNode(i, p);
            i = p;
        }
    }

    void HeapifyDown(int i) {
        while(true) {
            int c1 = i * 2 + 1;
            int c2 = i * 2 + 1;

            if(c1 >= size_) {
                return;
            }

            // Get the index of the max child
            int c = (c2 < size_ && vals_[c2].first > vals_[c1].first) ? c2 : c1;

            if(vals_[c].first <= vals_[i].first) {
                return;
            }
            SwapNode(c, i);
            i = c;
        }
    }
};

#endif