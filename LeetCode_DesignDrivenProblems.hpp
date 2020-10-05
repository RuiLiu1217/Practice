#ifndef LEETCODE_DESIGNDRIVENPROBLEMS_HPP
#define LEETCODE_DESIGNDRIVENPROBLEMS_HPP
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <set>
#include <stack>
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


    // ! copy from the soltuion
    /*
    622. Design Circular Queue
    Design your implementation of the circular queue. The circular queue is a 
    linear data structure in which the operations are performed based on FIFO 
    (First In First Out) principle and the last position is connected back to 
    the first position to make a circle. It is also called "Ring Buffer".

    One of the benefits of the circular queue is that we can make use of the 
    spaces in front of the queue. In a normal queue, once the queue becomes full, 
    we cannot insert the next element even if there is a space in front of the 
    queue. But using the circular queue, we can use the space to store new values.

    Your implementation should support following operations:

    MyCircularQueue(k): Constructor, set the size of the queue to be k.
    Front: Get the front item from the queue. If the queue is empty, return -1.
    Rear: Get the last item from the queue. If the queue is empty, return -1.
    enQueue(value): Insert an element into the circular queue. Return true if the operation is successful.
    deQueue(): Delete an element from the circular queue. Return true if the operation is successful.
    isEmpty(): Checks whether the circular queue is empty or not.
    isFull(): Checks whether the circular queue is full or not.
    

    Example:

    MyCircularQueue circularQueue = new MyCircularQueue(3); // set the size to be 3
    circularQueue.enQueue(1);  // return true
    circularQueue.enQueue(2);  // return true
    circularQueue.enQueue(3);  // return true
    circularQueue.enQueue(4);  // return false, the queue is full
    circularQueue.Rear();  // return 3
    circularQueue.isFull();  // return true
    circularQueue.deQueue();  // return true
    circularQueue.enQueue(4);  // return true
    circularQueue.Rear();  // return 4
    */
    class _0622_DesignCircularQueue {
        std::vector<int> q;
        int head, tail, N;
        bool empty;
    public:
        /** Initialize your data structure here. Set the size of the queue to be k. */
        _0622_DesignCircularQueue(int k) {
            head = 0;
            tail = 0;
            N = k; // capacity of the queue
            q = std::vector<int>(k);
            empty = true;
        }
        
        /** Insert an element into the circular queue. Return true if the operation is successful. */
        bool enQueue(int value) {
            if(isFull()) { return false; }
            empty = false;
            q[tail] = value;
            tail = (tail + 1) % N;
            return true;        
        }
        
        /** Delete an element from the circular queue. Return true if the operation is successful. */
        bool deQueue() {
            if(isEmpty()) { return false; }
            q[head] = 0;
            head = (head + 1) % N;
            if(head == tail) {
                empty = true;
            }
            return false;
        }
        
        /** Get the front item from the queue. */
        int Front() {
            if(isEmpty()) {
                return INT_MIN;
            }
            return q[head];
        }
        
        /** Get the last item from the queue. */
        int Rear() {
            if(isEmpty()) {
                return INT_MIN;
            }
            return q[(tail-1+N)%N];
        }
        
        /** Checks whether the circular queue is empty or not. */
        bool isEmpty() {
            return empty;
        }
        
        /** Checks whether the circular queue is full or not. */
        bool isFull() {
            return (empty) ? false : head == tail;
        }
    };

    // ! copy from the soltuion
    /* 
    Design your implementation of the circular double-ended queue (deque).

    Your implementation should support following operations:

    MyCircularDeque(k): Constructor, set the size of the deque to be k.
    insertFront(): Adds an item at the front of Deque. Return true if the operation is successful.
    insertLast(): Adds an item at the rear of Deque. Return true if the operation is successful.
    deleteFront(): Deletes an item from the front of Deque. Return true if the operation is successful.
    deleteLast(): Deletes an item from the rear of Deque. Return true if the operation is successful.
    getFront(): Gets the front item from the Deque. If the deque is empty, return -1.
    getRear(): Gets the last item from Deque. If the deque is empty, return -1.
    isEmpty(): Checks whether Deque is empty or not. 
    isFull(): Checks whether Deque is full or not.
    

    Example:

    MyCircularDeque circularDeque = new MycircularDeque(3); // set the size to be 3
    circularDeque.insertLast(1);			// return true
    circularDeque.insertLast(2);			// return true
    circularDeque.insertFront(3);			// return true
    circularDeque.insertFront(4);			// return false, the queue is full
    circularDeque.getRear();  			// return 2
    circularDeque.isFull();				// return true
    circularDeque.deleteLast();			// return true
    circularDeque.insertFront(4);			// return true
    circularDeque.getFront();			// return 4
    

    Note:

    All values will be in the range of [0, 1000].
    The number of operations will be in the range of [1, 1000].
    Please do not use the built-in Deque library.
    */
class _0641_DesignCircularDeque {
private:
    std::vector<int> q;
    int start;
    int end;
    int K;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    _0641_DesignCircularDeque(int k) {
        q = std::vector<int>(k + 1, -1);
        start = 0;
        end = 0;
        K = k + 1;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(isFull()) {
            return false;
        } else {
            start = (start + K - 1) % K;  // Calculate the index
            q[start] = value;
            return true;
        }
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
            if(isFull()) {
                return false;
            } else {
                q[end] = value;
                end = (end + 1) % K;
                return true;
            }
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(isEmpty()) {
            return false;
        } else {
            q[start] = -1;
            start = (start + 1) % K;
            return true;
        }
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(isEmpty()) {
            return false;
        } else {
            q[(end - 1 + K) % K] = -1;
            end = (end - 1 + K) % K;
            return true;
        }
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        return q[start];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        return q[(end-1+K) % K];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return start == end;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return (end+1) % K == start;
    }
};


/*
Design a max stack that supports push, pop, top, peekMax and popMax.

push(x) -- Push element x onto stack.
pop() -- Remove the element on top of the stack and return it.
top() -- Get the element on the top.
peekMax() -- Retrieve the maximum element in the stack.
popMax() -- Retrieve the maximum element in the stack, and remove it. 
If you find more than one maximum elements, only remove the top-most one.

MaxStack stack = new MaxStack();
stack.push(5); 
stack.push(1);
stack.push(5);
stack.top(); -> 5
stack.popMax(); -> 5
stack.top(); -> 1
stack.peekMax(); -> 5
stack.pop(); -> 1
stack.top(); -> 5
Note:
-1e7 <= x <= 1e7
Number of operations won't exceed 10000.
The last four operations won't be called when stack is empty.
*/
class _0716_MaxStack {
private:
    std::stack<int> normal;
    std::stack<int> maximu;
public:
    _0716_MaxStack() {}
    void push(int x) {
        normal.push(x);
        int max = maximu.empty() ? x : maximu.top();
        maximu.push(max > x ? max : x);
    }

    int pop() {
        maximu.pop();
        int v = normal.top();
        normal.pop();
        return v;
    }

    int top() {
        return normal.top();
    }
    int peekMax() {
        return maximu.top();
    }
    int popMax() {
        int max = peekMax();
        std::stack<int> temp;
        while(top() != max) {
            temp.push(pop());
        }
        pop();
        while(!temp.empty()) {
            push(temp.top());
            temp.pop();
        }
        return max;
    }
};


}
#endif