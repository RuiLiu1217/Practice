#ifndef BINARYHEAP_HPP
#define BINARYHEAP_HPP

class BinaryHeap{
public:
    std::vector<int> mH;
    void MaxHeapify(int i) {
        int left = i << 1;
        int right = left + 1;
        int largest = i;

        if(left < mH.size() && mH[left] > mH[largest]) {
            largest = left;
        }
        if(right < mH.size() && mH[right] > mH[largest]) {
            largest = right;
        }
        if(largest != i) {
            std::swap(mH[largest], mH[i]);
            MaxHeapify(largest);
        }
    }
    void BuildMaxHeap(const std::vector<int>& v) {
        mH.resize(v.size() + 1);
        for(int i = 0; i < v.size(); ++i) {
            mH[i+1] = v[i];
        }
        for(int i = v.size() / 2; i >= 1; --i) {
            MaxHeapify(i);
        }
    }
}

#endif