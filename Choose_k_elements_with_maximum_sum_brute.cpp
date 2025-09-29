class Solution {
public:
    typedef long long ll;

    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<ll> result(n, 0); // Result array to store sum for each index

        // Iterate for each index i
        for (int i = 0; i < n; i++) {
            // Min-heap to maintain top k largest nums2[j] values
            priority_queue<int, vector<int>, greater<int>> pq;

            // Iterate through all possible j
            for (int j = 0; j < n; j++) {
                if (nums1[j] < nums1[i]) { // Only consider valid candidates
                    pq.push(nums2[j]);     // Push nums2[j] into heap
                    if (pq.size() > k) {   // Keep only k largest elements
                        pq.pop();
                    }
                }
            }

            // Compute sum of top k elements
            ll sum = 0;
            while (!pq.empty()) {
                sum += pq.top();
                pq.pop();
            }
            result[i] = sum; // Store the sum for current i
        }

        return result;
    }
};

/*
 Time Complexity:
- Outer loop runs n times.
- Inner loop runs n times → O(n).
- Each push/pop in heap is O(log k), and at most n pushes per i → O(n log k).
- Summing heap elements is O(k), but k ≤ n, so it’s O(n) worst-case.
=> Total per i = O(n log k)
=> Overall = O(n^2 log k)

 Space Complexity:
- Result array: O(n)
- Min-heap: O(k)
=> Overall = O(n + k)
*/
