class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        // Max-heap to store active queries by right endpoint (latest deadline first)
        priority_queue<int, vector<int>> maxHeap;

        // Min-heap to keep track of queries that are already "used" (expire order)
        priority_queue<int, vector<int>, greater<int>> past;

        // Sort queries by their left endpoint
        sort(begin(queries), end(queries));

        int j = 0;          // pointer for queries
        int usedcount = 0;  // how many queries we have used

        for (int i = 0; i < n; i++) {

            // Add all queries starting at index i
            while (j < queries.size() && queries[j][0] == i) {
                maxHeap.push(queries[j][1]);  // store their right endpoint
                j++;
            }

            // Reduce nums[i] by number of past queries already affecting this index
            nums[i] -= past.size();

            // While we still need to reduce nums[i] and have valid queries
            while (nums[i] > 0 && !maxHeap.empty() && maxHeap.top() >= i) {
                int r = maxHeap.top();   // take the query with largest right endpoint
                maxHeap.pop();
                past.push(r);            // mark it as active
                usedcount++;             // count this query usage
                nums[i]--;               // satisfy one removal requirement
            }

            // If still leftover nums[i] > 0 → impossible
            if (nums[i] > 0) {
                return -1;
            }

            // Remove expired queries (those whose right endpoint == i)
            while (!past.empty() && past.top() == i) {
                past.pop();
            }
        }

        // Answer = total queries - used queries
        return queries.size() - usedcount;
    }

/*
Time Complexity: O(Q log Q + N log Q)
  - Sorting queries: O(Q log Q)
  - Each query pushed/popped at most once in heaps: O(Q log Q)
  - Iterating over nums: O(N log Q)
Overall: O((N + Q) log Q)

Space Complexity: O(Q)
  - maxHeap and past can store up to Q queries
*/
};
