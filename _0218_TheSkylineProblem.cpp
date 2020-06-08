#include "headers.hpp"
// !!! Copy from the solution. The difficulty of this problem is how to 
// !!! implement an efficient algorithm and data structure to finish it.
class Event {
  public:
    int id;
    int x;
    int h;
    int type; // 1: enter, -1 left
    bool operator<(const Event& e) const { // used for sorting
        if(x == e.x) {
            // Entering event h from large to small
            // Leaving event h from small to large
            return type * h > e.type * e.h;
        }
        return x < e.x;
    }
};

class MaxHeap {
public:
    MaxHeap(int max_items) : idx_(max_items, -1), vals_(max_items), size_(0) {}
    
    // Add an item into the heap. O(log(N))
    void Add(int key, int id) {
        idx_[id] = size_;
        vals_[size_] = {key, id};
        ++size_;
        HeapifyUp(idx_[id]);
    }

    // Remove an item. O(log(n))
    void Remove(int id) {
        int idx_to_evict = idx_[id];
        // swap with the last element
        SwapNode(idx_to_evict, size_ - 1);
        --size_;
        HeapifyDown(idx_to_evict);
    }

    bool Empty() const {
        return size_ == 0;
    }

    // Return the max of heap
    int Max() const {
        return Empty() ? 0 : vals_.front().first;
    }
private:

    void SwapNode(int i, int j) {
        if (i == j) return;
        std::swap(idx_[vals_[i].second], idx_[vals_[j].second]);
        std::swap(vals_[i], vals_[j]);
    }

    void HeapifyUp(int i) {
        while (i != 0)  {            
            int p = (i - 1) / 2;
            if (vals_[i].first <= vals_[p].first) 
                return;

            SwapNode(i, p);                
            i = p;
        }
    }

    // Make the heap valid again. O(log(n))
    void HeapifyDown(int i) {
        while (true) {
            int c1 = i*2 + 1;
            int c2 = i*2 + 2;

            // No child
            if (c1 >= size_) return;

            // Get the index of the max child
            int c = (c2 < size_ 
                  && vals_[c2].first > vals_[c1].first ) ? c2 : c1;

            // If key[c] is greater than key[i], swap them and
            // continue to HeapifyDown(c)
            if (vals_[c].first <= vals_[i].first) 
                return;

            SwapNode(c, i);
            i = c;
        }
    }

    // {key, id}
    std::vector<std::pair<int, int>> vals_;

    // Index of the i-th item in vals_
    std::vector<int> idx_;

    int size_; // size of the heap;
};


std::vector<std::vector<int>> getSkyline(std::vector<std::vector<int>>& buildings) {
    std::vector<Event> events;
    int id = 0;
    for(const auto& b : buildings) {
        events.push_back(Event{id, b[0], b[2], 1});
        events.push_back(Event{id, b[0], b[2], -1});
    }
    std::sort(events.begin(), events.end());

    MaxHeap heap(buildings.size());

}