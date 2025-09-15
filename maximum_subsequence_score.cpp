class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int,int>> vec; 
        vec.reserve(n); // reserve to avoid reallocation

        // Build pairs (nums1[i], nums2[i])
        for(int i=0; i<n; i++) {
            vec.push_back({nums1[i], nums2[i]});
        }

        // Sort by nums2 descending (since nums2[i] will act as the "multiplier")
        auto lambda = [&](auto &p1, auto &p2) {
            return p1.second > p2.second;
        };
        sort(begin(vec), end(vec), lambda);

        // Min-heap to keep track of the top k elements of nums1
        priority_queue<int, vector<int>, greater<int>> pq;
        long long Ksum = 0;

        // Take the first k elements (largest nums2 values after sorting)
        for(int i=0; i<k; i++) {
            Ksum += vec[i].first;
            pq.push(vec[i].first);
        }

        // Initial result = sum(nums1 of first k) * smallest nums2 among them
        long long result = Ksum * vec[k-1].second;

        // Iterate through remaining elements
        for(int i=k; i<n; i++) {
            // Replace the smallest element in heap with current one if beneficial
            Ksum += vec[i].first - pq.top();
            pq.pop();
            pq.push(vec[i].first);

            // Update result with current sum * current nums2 (since nums2 sorted descending)
            result = max(result, Ksum * vec[i].second);
        }

        return result;
    }
};

/**
 * Time Complexity:
 * - Building vec: O(n)
 * - Sorting vec: O(n log n)
 * - Heap operations: O(n log k)
 * - Total: O(n log n + n log k), which simplifies to O(n log n)
 * 
 * Space Complexity:
 * - O(n) for vec
 * - O(k) for the heap
 * - Overall: O(n)
 */
