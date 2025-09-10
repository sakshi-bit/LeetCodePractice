class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        // Max-heap to always remove stones from the largest pile
        priority_queue<int> pq(begin(piles), end(piles));

        // Calculate initial sum of all stones
        int sum = 0;
        for(int pile : piles) {
            sum += pile;
        }

        // Perform k operations
        for(int i = 0; i < k; i++) {
            int max_elem = pq.top(); // largest pile
            pq.pop();

            int remove = max_elem / 2; // stones to remove (floor division)
            sum -= remove;             // reduce sum accordingly
            max_elem -= remove;        // update pile
            pq.push(max_elem);         // push updated pile back into heap
        }

        return sum; // remaining total stones
    }
};

/**
 * Time Complexity (TC):
 * - Building the heap: O(n), n = piles.size()
 * - Each operation: O(log n) for pop + push, total k operations => O(k log n)
 * => Overall: O(n + k log n)
 *
 * Space Complexity (SC):
 * - Heap stores all piles: O(n)
 * => Overall: O(n)
 */
