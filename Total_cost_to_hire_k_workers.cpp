class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans = 0;  // store the total hiring cost
        int hired = 0;      // number of workers hired
        int i = 0;          // left pointer
        int j = costs.size() - 1; // right pointer

        // Two min-heaps for left and right candidate windows
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;

        // Keep hiring until we have hired k workers
        while(hired < k){
            // Fill pq1 (left side) with up to 'candidates' workers
            while(pq1.size() < candidates && i <= j){
                pq1.push(costs[i]);
                i++;
            }

            // Fill pq2 (right side) with up to 'candidates' workers
            while(pq2.size() < candidates && j >= i){
                pq2.push(costs[j]);
                j--;
            }

            // Get the smallest available cost from both sides
            int min_pq1 = pq1.size() > 0 ? pq1.top() : INT_MAX;
            int min_pq2 = pq2.size() > 0 ? pq2.top() : INT_MAX;

            // Hire the cheaper worker and remove from that heap
            if(min_pq1 <= min_pq2){
                ans += min_pq1;
                pq1.pop();
            }else{
                ans += min_pq2;
                pq2.pop();
            }

            hired++; // increment count of hired workers
        }

        return ans;
    }
};

/**
 * Time Complexity (TC):
 * - Each worker is pushed/popped into a priority queue at most once.
 * - Push/Pop operation in a heap: O(log c), where c = candidates.
 * - For k hires → O(k log c).
 * - Also initial iteration over costs with i and j is O(n).
 * => Overall: O(n + k log c)

 * Space Complexity (SC):
 * - Two heaps of size at most 'candidates'.
 * - O(c) additional space.
 */
