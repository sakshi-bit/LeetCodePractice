class Solution {
public:
    typedef pair<int,int> P;  // alias for (capital, profit)

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<P> vec;
        int n = profits.size();

        // Step 1: Store projects as (capital required, profit)
        for (int i = 0; i < n; i++) {
            vec.push_back({capital[i], profits[i]});
        }

        // Step 2: Sort projects by required capital (ascending order)
        sort(begin(vec), end(vec));

        int i = 0;
        priority_queue<int, vector<int>> pq; // max-heap to pick project with max profit

        // Step 3: Repeat at most k times (max number of projects allowed)
        while (k--) {
            // Add all affordable projects into max-heap
            while (i < n && vec[i].first <= w) {
                pq.push(vec[i].second);
                i++;
            }

            // If no project is affordable, break early
            if (pq.empty()) {
                break;
            }

            // Select the most profitable project
            w += pq.top();
            pq.pop();
        }

        // Return final capital after at most k projects
        return w;
    }
};

/**
 * Time Complexity (TC):
 *  - Sorting projects: O(n log n)
 *  - Each project inserted into heap once: O(n log n)
 *  - Up to k heap pops: O(k log n)
 *  => Overall: O(n log n + k log n)

 * Space Complexity (SC):
 *  - Storing projects: O(n)
 *  - Heap storage: O(n) in worst case
 *  => Overall: O(n)
 */
