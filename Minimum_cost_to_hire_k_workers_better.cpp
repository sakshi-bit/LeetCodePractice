class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& min_wage,
                                int k) {
        int n = quality.size();
        double result = DBL_MAX;

        // Store each worker as {ratio = min_wage/quality, quality}
        vector<pair<double, int>> worker_ratio(n);
        for (int worker = 0; worker < n; worker++) {
            worker_ratio[worker] = make_pair(
                (double)min_wage[worker] / quality[worker], quality[worker]);
        }

        // Sort workers by ratio in ascending order
        sort(begin(worker_ratio), end(worker_ratio));

        // Try each worker as the manager (highest ratio in the group of size k)
        for (int manager = k - 1; manager < n; manager++) {
            double manager_ratio = worker_ratio[manager].first;

            vector<double> group;
            // Consider all workers with ratio <= manager's ratio
            for (int worker = 0; worker <= manager; worker++) {
                double worker_wage =
                    manager_ratio * worker_ratio[worker].second;
                group.push_back(worker_wage);
            }

            // Use max-heap to keep only k smallest wages
            priority_queue<double, vector<double>> pq;
            double sum = 0;
            for (auto& wage : group) {
                pq.push(wage);
                sum += wage;
                if (pq.size() > k) {
                    sum -= pq.top(); // remove most expensive worker
                    pq.pop();
                }
            }

            // Track minimum total wage
            result = min(result, sum);
        }
        return result;
    }
};

/*
Time Complexity (TC):
- Building worker_ratio: O(n)
- Sorting workers by ratio: O(n log n)
- Outer loop (n-k+1 managers):
    * Inner loop builds group: O(n)
    * Heap operations: O(n log k)
=> Overall: O(n^2 log k) (still quadratic, can be optimized further)

Space Complexity (SC):
- worker_ratio: O(n)
- group vector: O(n)
- priority_queue: O(k)
=> Overall: O(n)
*/
