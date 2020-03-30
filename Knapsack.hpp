#ifndef KNAPSACK_HPP
#define KNAPSACK_HPP
#include <vector>
#include <algorithm>
#include <math.h>
#include <functional>
class KnapSack {
protected:
    std::vector<int> w;
    std::vector<int> v;
    std::vector<int> DP;
    int W; // weight limit
    int N; // number of items;

    std::function<int,int> knapsackComplete = [&](int w, int v) {
        for(int j = w; j <= W; ++j) {
        DP[j] = std::max(DP[j], DP[j-w] + v);
    }
    std::function<int,int> knapsackO1 = [&](int w, int v) {
        for(int j = W; j >= w; --j) {
        DP[j] = std::max(DP[j], DP[j-w] + v);
    }
    int get() const {
        return *std::max_element(begin(DP), end(DP));
    }
public:
    void reset() {
        DP = std::vector<int>(W+1, 0);
    }

    KnapSack(std::vector<int> weight, std::vector<int> value, int WeightLimit) : w(weight), v(value), W(WeightLimit) {
        N = w.size();
        reset();
    }
    virtual int knapSack() {
        for(int i = 0; i < N; ++i) {
            knapsackO1(w[i], v[i]);
        }
        return get();
    }
};

class KnapSackUnBounded :public KnapSack {
public:
    virtual int knapSack() override {
        for(int i = 0; i < N; ++i) {
            for(int k = 0; k <= std::log(W / w[i]); ++k) {
                knapsackO1(w[i]<<k, v[i]<<k);
            }
        }
        return get();
    }
};


class KnapSackComplete : public KnapSack {
public:
    virtual int knapSack() override {
        for(int i = 0; i < N; ++i) {
            knapsackComplete(w[i], v[i]);
        }
        return get();
    }
};

class KnapSackBounded : public KnapSack {
private:
    std::vector<int> times;
public:
    KnapSackBounded(std::vector<int>& weight, std::vector<int>& value, int WeightLimit, std::vector<int>& times) : KnapSack{weight, value, WeightLimit}, times(times) {}

    virtual int knapSack() override {
        for(int i = 0; i < N; ++i) {
            if(times[i] * w[i] >= W) {
                knapsackComplete(w[i], v[i]);
            }
            int left = times[i];
            for(int k = 0; k <= std::log(times[i]); ++k) {
                knapsack01(w[i] << k, v[i] << k);
                left -= (1 << k);
            }
            knapsack01(w[i] * left, v[i] * left)
        }
    }
};

#endif