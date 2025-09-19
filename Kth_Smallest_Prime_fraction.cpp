class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        
        // Max-heap priority_queue (default is max-heap)
        // Each element is {fraction_value, numerator, denominator}
        priority_queue<vector<double>> pq;

        // Generate all fractions arr[i]/arr[j] where i < j
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                double div = (double)arr[i] / arr[j];
                pq.push({div, (double)arr[i], (double)arr[j]});  // push fraction

                // Maintain only k smallest fractions in the heap
                if (pq.size() > k) {
                    pq.pop();  // remove the largest fraction
                }
            }
        }

        // The top element is the k-th smallest fraction
        auto vec = pq.top();
        vector<int> result(2);
        result[0] = (int)vec[1];  // numerator
        result[1] = (int)vec[2];  // denominator
        return result;
    }
};

/*
Time Complexity (TC):
- Generating all fractions → O(n^2)
- Each heap push/pop takes O(log k)
- Overall: O(n^2 * log k)

Space Complexity (SC):
- Heap stores at most k elements → O(k)
- Output vector uses O(1)
- Overall: O(k)
*/
