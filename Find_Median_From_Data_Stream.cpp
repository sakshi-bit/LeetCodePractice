class MedianFinder {
private:
    // Max-heap to store the smaller half of numbers
    priority_queue<int> left_max_heap;  
    
    // Min-heap to store the larger half of numbers
    priority_queue<int, vector<int>, greater<int>> right_min_heap;  

public:
    // Constructor
    MedianFinder() {
        // No initialization required as heaps are automatically empty
    }
    
    // Adds a number into the data structure
    void addNum(int num) {
        // If left heap is empty or num is smaller than max of left heap, push to left heap
        if(left_max_heap.empty() || num < left_max_heap.top()) {
            left_max_heap.push(num);
        } else {
            // Otherwise, push to right heap
            right_min_heap.push(num);
        }

        // Balance the heaps if their sizes differ by more than 1
        if((int)left_max_heap.size() - (int)right_min_heap.size() > 1) {
            right_min_heap.push(left_max_heap.top());
            left_max_heap.pop();
        } else if(right_min_heap.size() > left_max_heap.size()) {
            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
        }
    }
    
    // Returns the median of current numbers
    double findMedian() {
        // If heaps are equal in size, median is average of tops
        if(left_max_heap.size() == right_min_heap.size()) {
            return (double)(left_max_heap.top() + right_min_heap.top()) / 2;
        }
        // Otherwise, median is the top of left heap (max of smaller half)
        return left_max_heap.top();
    }
};

/**
 * Time Complexity (TC):
 * addNum(): O(log n) — insertion into heap
 * findMedian(): O(1) — top of heaps
 *
 * Space Complexity (SC):
 * O(n) — storing all numbers in two heaps
 */

/**
 * Usage:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double median = obj->findMedian();
 */
