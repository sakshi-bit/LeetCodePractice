class Solution {
public:
    typedef long long ll;

    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();

        // vec[i] = {nums1[i], index, nums2[i]}
        vector<vector<int>> vec(n);
        for (int i = 0; i < n; i++) {
            vec[i] = {nums1[i], i, nums2[i]};
        }

        // Sort by nums1[i] (ascending order)
        sort(begin(vec), end(vec));

        vector<ll> result(n, 0);

        // Min-heap to maintain top k elements from nums2
        priority_queue<int, vector<int>, greater<int>> pq;
        ll sum = 0; // running sum of elements inside pq

        for (int i = 0; i < n; i++) {
            if (i > 0 && vec[i - 1][0] == vec[i][0]) {
                // If nums1[i] is same as previous, reuse result
                ll ans = result[vec[i - 1][1]];
                result[vec[i][1]] = ans;
            } else {
                // Otherwise, result is current sum of top k nums2 values
                result[vec[i][1]] = sum;
            }

            // Add current nums2 value into heap
            pq.push(vec[i][2]);
            sum += vec[i][2];

            // Keep only k largest elements in heap
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
        }

        return result;
    }
};

/*
 Time Complexity:
- Building vec: O(n)
- Sorting vec: O(n log n)
- Iterating through vec: O(n log k) 
    (each heap push/pop is O(log k))
=> Overall: O(n log n + n log k)

 Space Complexity:
- vec stores triplets: O(n)
- result array: O(n)
- heap: O(k)
=> Overall: O(n + k)
*/
