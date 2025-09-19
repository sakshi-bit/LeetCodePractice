class Solution {
public:
    typedef vector<double> V;  // V = {fraction_value, numerator_index, denominator_index}

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();

        // Min-heap to store fractions {value, i, j}
        // Start with fractions of the form arr[i]/arr[n-1] (smallest denominator)
        priority_queue<V, vector<V>, greater<V>> pq;  // O(n) space for heap

        for (int i = 0; i < n - 1; i++) {
            pq.push({1.0 * arr[i] / arr[n - 1], double(i), double(n - 1)});  // O(log n) push
        }

        int smallest = 1;
        // Extract smallest fractions one by one until reaching the k-th
        while (smallest < k) {  // Loop runs k times → O(k log n)
            V vec = pq.top();   // Get smallest fraction → O(1)
            pq.pop();           // Remove from heap → O(log n)

            int i = vec[1];
            int j = vec[2] - 1; // Move denominator index one step left

            // Push next fraction arr[i]/arr[j] into heap
            pq.push({1.0 * arr[i] / arr[j], double(i), double(j)});  // O(log n)
            smallest++;
        }

        // The top of the heap is the k-th smallest fraction
        V vec = pq.top();
        int i = vec[1];
        int j = vec[2];
        return {arr[i], arr[j]};
    }
};

/*
Time Complexity (TC):
- Initial heap construction with (n-1) elements → O(n log n)
- Each of the k iterations does: pop (O(log n)) + push (O(log n)) → O(k log n)
- Total: O(n log n + k log n)

Space Complexity (SC):
- Heap stores at most O(n) fractions
- Result uses O(1)
- Overall: O(n)
*/
