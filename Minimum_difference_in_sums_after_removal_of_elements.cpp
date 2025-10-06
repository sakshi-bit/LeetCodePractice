class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int N = nums.size();
        int n = N / 3;

        // Stores prefix minimal sum for first 2n elements 
        vector<long long> leftMinSum(N, 0);

        // Stores suffix maximal sum for last 2n elements 
        vector<long long> rightMaxSum(N, 0);

        // Max-heap to keep smallest possible sum on the left side
        priority_queue<int, vector<int>> maxheap;
        long long leftsum = 0;

        // Step 1: Compute prefix minimal sum for first 2n elements
        for (int i = 0; i < 2 * n; i++) {
            maxheap.push(nums[i]);       // Add current number to heap
            leftsum += nums[i];          // Include in running sum

            if (maxheap.size() > n) {    // Keep only n smallest elements
                leftsum -= maxheap.top(); // Remove the largest one
                maxheap.pop();
            }
            leftMinSum[i] = leftsum;     // Store minimal sum for prefix ending at i
        }

        // Min-heap to keep largest possible sum on the right side
        priority_queue<int, vector<int>, greater<int>> minheap;
        long long rightsum = 0;

        // Step 2: Compute suffix maximal sum for last 2n elements
        for (int i = N - 1; i >= n; i--) {
            minheap.push(nums[i]);       // Add current number to heap
            rightsum += nums[i];         // Include in running sum

            if (minheap.size() > n) {    // Keep only n largest elements
                rightsum -= minheap.top(); // Remove the smallest one
                minheap.pop();
            }
            rightMaxSum[i] = rightsum;   // Store maximal sum for suffix starting at i
        }

        // Step 3: Compute minimum difference between left and right partitions
        long long result = LLONG_MAX;
        for (int i = n - 1; i <= 2 * n - 1; i++) {
            // leftMinSum[i] => sum of smallest n numbers in first part (0..i)
            // rightMaxSum[i+1] => sum of largest n numbers in last part (i+1..N-1)
            result = min(result, leftMinSum[i] - rightMaxSum[i + 1]);
        }

        return result;
    }
};
