class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& min_wage,
                                int k) {
        int n = quality.size();
        double result = DBL_MAX;

        // Try each worker as the "manager" that sets the pay ratio
        for (int manager = 0; manager < n; manager++) {
            // Ratio = wage/quality for this manager
            double manager_ratio = (double)min_wage[manager] / quality[manager];

            vector<double> group;
            // Compute the wage of every worker under this ratio
            for (int worker = 0; worker < n; worker++) {
                double worker_wage = manager_ratio * quality[worker];

                // Worker only qualifies if this wage is >= their min_wage
                if (worker_wage >= min_wage[worker]) {
                    group.push_back(worker_wage);
                }
            }

            // If we can't form a group of size k, skip
            if (group.size() < k) {
                continue;
            }

            // Use a max-heap to always drop the most expensive workers 
            // when group size exceeds k
            priority_queue<double, vector<double>> pq;
            double sum = 0;
            for (auto& wage : group) {
                pq.push(wage);
                sum += wage;

                // If more than k workers, remove the most expensive one
                if (pq.size() > k) {
                    sum -= pq.top();
                    pq.pop();
                }
            }

            // Track the minimum total wage for valid groups
            result = min(result, sum);
        }
        return result;
    }
};

/*
Time Complexity (TC):
- Outer loop: O(n) (each worker can be manager)
- Inner loop: O(n) (computing wages for all workers)
- Heap operations: O(n log k) in worst case
=> Total: O(n^2 log k)

Space Complexity (SC):
- O(n) for storing group wages
- O(k) for the priority queue
=> Overall: O(n)
*/
