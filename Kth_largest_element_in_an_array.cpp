class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Min-heap of size k to track the k largest elements
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int &num : nums) {
            pq.push(num);              // push current number into heap
            if (pq.size() > k) {       // if heap grows larger than k
                pq.pop();              // remove the smallest element
            }
        }

        // The root of the heap (smallest among k largest) is the kth largest element
        return pq.top();
    }
};

/**
 * Time Complexity:
 *   - Building the heap: O(n log k), since each push/pop operation is O(log k).
 *   - Final retrieval of top element: O(1).
 *   - Overall: O(n log k).
 *
 * Space Complexity:
 *   - Heap stores at most k elements: O(k).
 */
