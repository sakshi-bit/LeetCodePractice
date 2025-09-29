class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();
        if (n == 0) {
            return cnt; // No elements → no operations
        }

        // Min-heap initialized with all elements
        priority_queue<long, vector<long>, greater<>> pq(begin(nums), end(nums));

        // Process until all elements >= k or only 1 left
        while (pq.size() >= 2 && pq.top() < k) {
            long smallest_elem = pq.top(); 
            pq.pop();

            long second_smallest_elem = pq.top(); 
            pq.pop();

            // Merge two smallest elements and push back
            pq.push(smallest_elem * 2 + second_smallest_elem);
            cnt++;
        }

        return cnt;
    }
};

/*
 Time Complexity:
- Building the heap: O(n)
- Each operation: pop 2 + push 1 → O(log n)
- At most n-1 operations (each reduces size by 1 in worst case)
=> Overall: O(n log n)

Space Complexity:
- Heap stores up to n elements: O(n)
- No extra data structures apart from counters
=> Overall: O(n)
*/
