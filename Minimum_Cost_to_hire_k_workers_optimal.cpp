class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& min_wage,
                                int k) {
        int n = quality.size();
        double result = DBL_MAX;

        // Step 1: Store workers as {ratio, quality}
        vector<pair<double, int>> worker_ratio(n);
        for (int worker = 0; worker < n; worker++) {
            worker_ratio[worker] = make_pair(
                (double)min_wage[worker] / quality[worker], quality[worker]);
        }

        // Step 2: Sort workers by increasing ratio
        sort(begin(worker_ratio), end(worker_ratio));

        // Max-heap to maintain k smallest qualities
        priority_queue<int, vector<int>> pq;
        double sum_quality = 0;

        // Step 3: Initialize first k workers
        for (int i = 0; i < k; i++) {
            pq.push(worker_ratio[i].second);
            sum_quality += worker_ratio[i].second;
        }

        // First valid group: cost = (sum of qualities) * highest ratio
        double manager_ratio = worker_ratio[k - 1].first;
        result = manager_ratio * sum_quality;

        // Step 4: Try remaining workers as manager
        for (int manager = k; manager < n; manager++) {
            manager_ratio = worker_ratio[manager].first;

            // Add this worker's quality
            pq.push(worker_ratio[manager].second);
            sum_quality += worker_ratio[manager].second;

            // Keep only k smallest qualities
            if (pq.size() > k) {
                sum_quality -= pq.top();
                pq.pop();
            }

            // Update result with new cost
            result = min(result, sum_quality * manager_ratio);
        }

        return result;
    }
};

/*
Time Complexity (TC):
- Building worker_ratio: O(n)
- Sorting workers: O(n log n)
- Iterating workers: O(n log k) (heap push/pop at most n times)
=> Total: O(n log n + n log k), dominated by O(n log n)

Space Complexity (SC):
- worker_ratio: O(n)
- priority_queue: O(k)
=> Total: O(n + k)
*/
